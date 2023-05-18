//-----------------------------------------------------------------------
//  Header      : main.cpp
//  Created     : 08.04.2023
//  Modified    : 18.05.2023
//  Author      : Danilov Daniil
//-----------------------------------------------------------------------

#include <iostream>
#include "ConverterJSON.h"

int main() {

    auto* converterJSON = new ConverterJSON;
    auto* invertedIndex = new InvertedIndex;

    if(!converterJSON->LoadConfig()){
        return EXIT_FAILURE;
    }
    if(!converterJSON->LoadRequests()){
        return EXIT_FAILURE;
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