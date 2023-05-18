//-----------------------------------------------------------------------
//  Header      : ConverterJSON.cpp
//  Created     : 08.05.2023
//  Modified    : 18.05.2023
//  Author      : Danilov Daniil
//-----------------------------------------------------------------------

#include "ConverterJSON.h"

///returns "true" if the file was read and corresponds to the specification
bool ConverterJSON::LoadConfig(){
    std::ifstream config_file("../../json_files/config.json");

    if (!config_file.is_open()){
        std::cerr << "Config file is missing." << std::endl;
        return false;
    }

    nlohmann::json config_json;
    config_file >> config_json;

    if (config_json["config"].is_null()){
        std::cerr << "config file is empty" << std::endl;
        return false;
    }

    if(!config_json["config"]["name"].is_null() && config_json["config"]["name"].is_string()){
        configJson_.config.m_name = config_json["config"]["name"];
    }else{
        configJson_.config.m_name = "Undefined";
    }

    if (!config_json["config"]["version"].is_null() && config_json["config"]["version"].is_string()){
        configJson_.config.m_version = config_json["config"]["version"];
    }else{
        configJson_.config.m_version = "1.0";
    }

    if(!config_json["config"]["max_responses"].is_null() && config_json["config"]["max_responses"].is_number()){
        configJson_.config.m_max_responses = config_json["config"]["max_responses"];
    }else{
        configJson_.config.m_max_responses = 3 ;
    }

    for (const auto& it : config_json["files"]) configJson_.m_files_path.push_back(it);

    return true;
}


std::vector<std::string> ConverterJSON::GetTextDocuments() {
    auto response_text = std::vector<std::string>();

    for (const auto& path : configJson_.m_files_path){
        auto file_resource = std::ifstream(path);
        std::string str((std::istreambuf_iterator<char>(file_resource)),
                        std::istreambuf_iterator<char>());
        response_text.push_back(str);
    }
    return response_text;
}


int unsigned long ConverterJSON::GetResponsesLimit() const {
    return configJson_.config.m_max_responses;
}


std::vector<std::string> ConverterJSON::GetRequests() const {
    return requestJson_.m_requests;
}


void ConverterJSON::PutAnswers(const std::vector<std::vector<RelativeIndex>>& answers_relative) {
    
    nlohmann::json answer_json;
    size_t index = 1;
    auto answer_file = std::ofstream("../../json_files/answers.json",std::ios::trunc);

    if(!answer_file.is_open()){
        std::cerr << "Cannot generate a answers.json file." << std::endl;
    }

    for (const auto& answers : answers_relative){
        nlohmann::json requests_json;
        requests_json["result"] = !answers.empty();
        for (const auto& answer : answers){
            nlohmann::json dict_pair;
            dict_pair["docid"] = answer.m_doc_id;
            dict_pair["rank"] = answer.m_rank;
            requests_json["relevance"].push_back(dict_pair);
        }
        if (index<10) {
            std::string name = "request00"+std::to_string(index);
            answer_json[name] = requests_json;
        } else {
            std::string name = "request0"+std::to_string(index);
            answer_json[name] = requests_json;
        }
        index++;
    }

    nlohmann::json insert_json_file;
    insert_json_file["answers"] = answer_json;
    answer_file << insert_json_file.dump(4);
}

///Reads requests into the structure (requestJson_)
bool ConverterJSON::LoadRequests(){
    auto requests_file = std::ifstream("../../json_files/requests.json");

    if(!requests_file.is_open()){
        std::cerr << "Requests file is missing." << std::endl;
        return false;
    }

    nlohmann::json requests_json;
    requests_file >> requests_json;

    if (requests_json["requests"].is_null()){
        std::cerr << "Requests file is empty." << std::endl;
        return false;
    }

    for (const auto& req_json: requests_json["requests"]){
        requestJson_.m_requests.push_back(req_json);
    }
    return true;
}

