//-----------------------------------------------------------------------
//  Header      : InvertedIndex.h
//  Created     : 03.05.2023
//  Modified    : 18.05.2023
//  Author      : Danilov Daniil
//-----------------------------------------------------------------------

#ifndef INVERTEDINDEX_H
#define INVERTEDINDEX_H

#include <iostream>
#include <vector>
#include <map>
#include <chrono>
#include <thread>
#include <mutex>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>

///Store the id and the number of matches
struct Entry {
    size_t m_doc_id, m_count;
    ///For conducting test scenarios
    bool operator ==(const Entry& other) const {
        return (m_doc_id == other.m_doc_id &&
                m_count == other.m_count);
    }
};

///System that will allow you to count words found in documents.
class InvertedIndex {
private:
    ///Dictionary for words and their number
    std::map<std::string, std::vector<Entry>> frequency_dictionary_;
    ///Indexing flag
    bool indexingIsOngoing_{};

public:
    InvertedIndex() = default;

    /**
    * Document indexing method
    * @param fileContent file text
    * @param docId index
    */
    void indexTheFile(const std::string& fileContent, size_t docId);

    /**
    * Update or fill in the database of documents on which we will search
    * @param input_docs document content
    */
    void UpdateDocumentBase(const std::vector<std::string>& input_docs);

    /**
    * The method determines the number of occurrences of the word "word" in the downloaded database of documents
    * @param word words for determining quantity
    */
    std::vector<Entry> GetWordCount(const std::string& word);

};
#endif
