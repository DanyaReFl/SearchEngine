#include <iostream>
#include "ConverterJSON.h"

int main() {
    auto* converterJSON = new ConverterJSON;
    auto* invertedIndex = new InvertedIndex;

    if(!converterJSON->LoadConfig()){
        return 1;
    }
    if(!converterJSON->LoadRequests()){
        return 1;
    }

    std::cout << converterJSON->configJson_.config.m_name << ((converterJSON->configJson_.config.m_version.empty())? "" : " version: ")
            << converterJSON->configJson_.config.m_version << std::endl;

    invertedIndex->UpdateDocumentBase(converterJSON->GetTextDocuments());
    auto* srv = new SearchServer(*invertedIndex);
    auto result = srv->search(converterJSON->GetRequests());
    ConverterJSON::PutAnswers(result);

    std::cout << "The search has been completed";

    delete converterJSON;
    delete invertedIndex;
    delete srv;

    return EXIT_SUCCESS;
}