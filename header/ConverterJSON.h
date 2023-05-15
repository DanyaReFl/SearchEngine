#ifndef CONVERTERJSON_H
#define CONVERTERJSON_H

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include "nlohmann/json.hpp"
#include "SearchServer.h"


//For storing configurations
struct config_json {
    struct {
        std::string m_name;
        std::string m_version;
        int unsigned long m_max_responses;
    } config;
    std::vector<std::string> m_files_path;
};

//For storing requests
struct request_json {
    std::vector<std::string> m_requests;
};

//to save the rank and number
struct relevance_json {
    size_t m_doc_id;
    float m_rank;
};

class ConverterJSON{
public:
    config_json configJson_;
    request_json requestJson_;
    ConverterJSON() = default;
    bool LoadConfig();
    bool LoadRequests();
    std::vector<std::string> GetTextDocuments();
    [[nodiscard]] int unsigned long GetResponsesLimit() const;
    [[nodiscard]] std::vector<std::string> GetRequests() const;
    static void PutAnswers(const std::vector<std::vector<RelativeIndex>>& answers);
    ~ConverterJSON() = default;
};

#endif