#ifndef SEARCHSERVER_H
#define SEARCHSERVER_H

#include <iostream>
#include <utility>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
#include <unordered_set>
#include <sstream>
#include "InvertedIndex.h"


struct RelativeIndex{
    std::size_t m_doc_id;
    float m_rank;
    bool operator ==(const RelativeIndex& other) const {
        return ( (m_doc_id == other.m_doc_id) && (m_rank-other.m_rank)<0.1f);
    }
    RelativeIndex(size_t docid , float rank): m_doc_id(docid), m_rank(rank){}
};

class SearchServer {
private:
    InvertedIndex index_;
public:
    explicit SearchServer(InvertedIndex& idx) : index_(std::move(idx)){}
    std::vector<std::vector<RelativeIndex>> search(const std::vector<std::string>& queries_input);
};

#endif
