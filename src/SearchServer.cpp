//-----------------------------------------------------------------------
//  Header      : SearchServer.cpp
//  Created     : 03.05.2023
//  Modified    : 18.05.2023
//  Author      : Danilov Daniil
//-----------------------------------------------------------------------

#include "SearchServer.h"
#include "ConverterJSON.h"


std::vector<std::vector<RelativeIndex>> SearchServer::search(const std::vector<std::string> &queries_input) {

    auto answers = std::vector<std::vector<RelativeIndex>>();

    for (const auto& request: queries_input){
        auto words = std::unordered_set<std::string>();

        bool isWord = false;
        size_t i = 0;
        while (request[i] == ' ' && request[i] != '\0') i++;

        size_t indexWordStart = 0;
        size_t indexWordEnd = 0;
        while (request[i] != '\0') {
            if(request[i] != ' ' && !isWord){
                isWord = true;
                indexWordStart = i;
            }
            else if (request[i] == ' ' || request[i+1] == '\0'){
                isWord = false;
                if(request[i] == ' '){
                    indexWordEnd = i ;
                } else {
                    indexWordEnd = i+1;
                }
                std::string currentWord = request.substr(indexWordStart, indexWordEnd-indexWordStart);
                std::string result(currentWord.size(),' ');
                std::transform(currentWord.begin(), currentWord.end(), result.begin(), tolower );
                currentWord = result;
                words.insert(currentWord);
            }
            i++;
        }

        std::vector<std::pair<std::string,size_t>> wordsCount;

        for(const auto& word: words){
            auto freq_directory = this->index_.GetWordCount(word);
            size_t sum = 0;
            for (const auto& entry: freq_directory){
                sum += entry.m_count;
            }
            wordsCount.emplace_back(word,sum);
        }

        std::sort(wordsCount.begin(), wordsCount.end(),
            [](std::pair<std::string,size_t> const& a, std::pair<std::string,size_t>const& b )->bool {
                 return a.second < b.second; 
                 });
        auto answer = std::vector<RelativeIndex>();

        if (wordsCount[0].second != 0){
            auto docs = std::map<size_t,std::vector<std::pair<std::string,size_t>>>();

            for(const auto& [key,value]: wordsCount){
                auto freq_dictionary = this->index_.GetWordCount(key);
                for(const auto &entry: freq_dictionary){
                    if(docs.count(entry.m_doc_id) == 0){
                        docs[entry.m_doc_id] = std::vector<std::pair<std::string, size_t>>();
                    }
                    docs[entry.m_doc_id].emplace_back(key, entry.m_count);
                }
            }

            float max = 0.0;
            auto rel_map = std::map<size_t ,float>();
            for(const auto& [doc_key,doc_value]: docs){
                rel_map[doc_key] = 0; 
                for(const auto& [key,value]: doc_value){
                    rel_map[doc_key]+= static_cast<float>(value);
                }
                if((static_cast<float>(rel_map[doc_key])) > max) max = (static_cast<float>(rel_map[doc_key]));
            }

            for(const auto& [key,value]: rel_map){
                auto rel = RelativeIndex(key, (value / max));
                answer.push_back(rel);

                std::sort(answer.begin(),answer.end(),[](RelativeIndex const& a, RelativeIndex const& b){
                    return a.m_rank > b.m_rank;
                });

                auto conv = ConverterJSON();
                conv.LoadConfig();
                long unsigned int max_responses = conv.GetResponsesLimit();

                while(answer.size() > max_responses){
                    answer.pop_back();
                }
            }
        }
        answers.push_back(answer);
    }
    return answers;
}
