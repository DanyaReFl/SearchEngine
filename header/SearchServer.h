//-----------------------------------------------------------------------
//  Header      : SearchServer.h
//  Created     : 03.05.2023
//  Modified    : 18.05.2023
//  Author      : Danilov Daniil
//-----------------------------------------------------------------------

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

    /**
    * @param idx reference to the class is passed to the class constructor
    * Inverted Index,
    * so that "SearchServer" can find out the frequency of words encountered in
    * request
    */
    explicit SearchServer(InvertedIndex& idx) : index_(std::move(idx)){}

    /**
    * Method of processing search queries
    * @param queries_input search queries taken from a file request.json
    * @return returns a sorted list of relevant responses for the given queries
    */
    std::vector<std::vector<RelativeIndex>> search(const std::vector<std::string>& queries_input);

};

#endif
