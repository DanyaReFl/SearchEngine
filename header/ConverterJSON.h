#pragma once
#include <vector>
#include <string>
#include "nlohmann/json.hpp"
#include <fstream>
#include "gtest/gtest.h"
#include "../easyloggingpp-master/src/easylogging++.h"



class ConverterJSON{
private:

public:
    ConverterJSON() = default;
    static std::vector<std::string> GetTextDocuments();
    int GetResponsesLimit();
    std::vector<std::string> GetRequests();
    void putAnswers(std::vector<std::vector<std::pair<int, float>>> answers);

    void configurationsData();
    void transformationRequest();
    void formingResponse();
    ~ConverterJSON();
};