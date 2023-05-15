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

//to store the id and the number of matches
struct Entry {
    size_t m_doc_id, m_count;
    //For conducting test scenarios
    bool operator ==(const Entry& other) const {
        return (m_doc_id == other.m_doc_id &&
                m_count == other.m_count);
    }
};

class InvertedIndex {
private:
    std::map<std::string, std::vector<Entry>> frequency_dictionary_;
    bool indexingIsOngoing_{};
public:
    InvertedIndex() = default;
    void indexTheFile(const std::string& fileContent, size_t docId);
    void UpdateDocumentBase(const std::vector<std::string>& input_docs);
    std::vector<Entry> GetWordCount(const std::string& word);
};
#endif
