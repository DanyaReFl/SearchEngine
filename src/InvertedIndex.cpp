//-----------------------------------------------------------------------
//  Header      : InvertedIndex.cpp
//  Created     : 03.05.2023
//  Modified    : 18.05.2023
//  Author      : Danilov Daniil
//-----------------------------------------------------------------------

#include "InvertedIndex.h"

std::mutex mutex_index;

void InvertedIndex::UpdateDocumentBase(const std::vector<std::string>& input_docs){

    if (input_docs.empty()){
        std::cerr << "\t- Indexing: no content in docs content base\n";
        return;
    }

    indexingIsOngoing_ = true ;

    frequency_dictionary_.clear();
    size_t docId = 0;

    std::vector<std::thread> threads;
    for (const auto& content : input_docs){
        threads.emplace_back(&InvertedIndex::indexTheFile, this , content , docId);
        ++docId;
    }
    indexingIsOngoing_ = false;

    for (auto &it : threads) it.join();

}


void InvertedIndex::indexTheFile(const std::string& oneTextFile, size_t docId){

    std::map<std::string, Entry> fileFreqDirectory;
    Entry entry{};
    entry.m_doc_id = docId;
    entry.m_count = 1;
    std::istringstream ist(oneTextFile);

    for (std::string word; ist >>word; ){
        std::transform(word.begin(),word.end(), word.begin(), [](unsigned char ch){
            return std::tolower(ch);
        });
        std::pair<std::string, Entry> file_word_frequency {word,entry};
        if (!fileFreqDirectory.emplace(file_word_frequency).second){
            fileFreqDirectory.find(word)->second.m_count +=1;
        }
    }

    const std::lock_guard<std::mutex> lock(mutex_index);

    for (const auto& wordIterator : fileFreqDirectory){
        std::pair<std::string,std::vector<Entry>> wordFrequency;
        wordFrequency.first = wordIterator.first;
        std::vector<Entry> &&entryVector {wordIterator.second};
        wordFrequency.second = entryVector;
        if (!frequency_dictionary_.emplace(wordFrequency).second){
            frequency_dictionary_.find(wordFrequency.first)->second.push_back(wordIterator.second);
        }
    }
}


std::vector<Entry> InvertedIndex::GetWordCount(const std::string &word){

    if (indexingIsOngoing_){
        std::cout << "Index is ongoing , please repeat the request later.\n";
        return{};
    }
    auto it = frequency_dictionary_.find(word);
    if(it != frequency_dictionary_.end()){
        return it->second;
    }else{
        return {};
    }
    
}