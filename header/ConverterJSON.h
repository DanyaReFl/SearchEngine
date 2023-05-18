//-----------------------------------------------------------------------
//  Header      : ConverterJSON.h
//  Created     : 07.05.2023
//  Modified    : 18.05.2023
//  Author      : Danilov Daniil
//-----------------------------------------------------------------------

#ifndef CONVERTERJSON_H
#define CONVERTERJSON_H

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include "nlohmann/json.hpp"
#include "SearchServer.h"


///To save the configuration from a file "json_files/config.json".
struct config_json {
    struct {
        std::string m_name;
        std::string m_version;
        int unsigned long m_max_responses;
    } config;
    std::vector<std::string> m_files_path;
};

///To save requests from the file "json_files/requests.json"
struct request_json {
    std::vector<std::string> m_requests;
};

///Class for working with json-files
class ConverterJSON{
public:
    config_json configJson_;
    request_json requestJson_;
    ConverterJSON() = default;
    ~ConverterJSON() = default;

    /**
    * The method reads and checks the "json_files/config.json" file so that it conforms to the specification
    * @return returns true if the file meets the specification and it was possible to write
    */
    bool LoadConfig();

    /**
    * The method reads the file "json_files/requests.json" if it opens
    * @return returns true if the file was read
    */
    bool LoadRequests();

    /**
    * Method for getting file contents
    * @return Returns a list with the contents of the files listed
    * in json_files/config.json
    */
    std::vector<std::string> GetTextDocuments();

    /**
    * The method returns the max_responses field to determine the limit
    * number of responses per request
    * @return max_response
    */
    [[nodiscard]] int unsigned long GetResponsesLimit() const;

    /**
    * Method for getting requests from the requests.json file
    * @return returns a list of requests from the requests.json file
    */
    [[nodiscard]] std::vector<std::string> GetRequests() const;

    /**
    * Put in the file "json_files/answers.json" search query results
    * @param answers as a parameter, we take a set of all
    * responses to queries with their rank and number
    */
    static void PutAnswers(const std::vector<std::vector<RelativeIndex>>& answers);

};

#endif