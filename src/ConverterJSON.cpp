#include "../header/ConverterJSON.h"

//Returns the text of the "config" file
std::vector<std::string> ConverterJSON::GetTextDocuments(){
    std::ifstream inConfigText{"../json_files/config.json"};
    std::istream_iterator<std::string> start(inConfigText), end;
    std::vector<std::string> textConfig(start, end);
    if (!inConfigText.is_open())  LOG(ERROR) << "The \"config\" file does not open.";
    else {
        std::copy(textConfig.begin(), textConfig.end(),
        std::ostream_iterator<std::string>(std::cout));
        return textConfig;
    }
}

//The function returns the value of the number of responses to the request
int ConverterJSON::GetResponsesLimit() {
    nlohmann::json ConfigJSON;
    std::vector<std::string> configText = GetTextDocuments();
    ConfigJSON = configText;
    return ConfigJSON.find("max_responses").value();
}

//Returns the text of the "requests file
std::vector<std::string> ConverterJSON::GetRequests() {
    std::ifstream inRequestsText{"../json_files/config.json"};
    std::istream_iterator<std::string> start(inRequestsText), end;
    std::vector<std::string> textRequests(start, end);
    if (!inRequestsText.is_open())  LOG(ERROR) << "The \"requests\" file does not open.";
    else {
        std::copy(textRequests.begin(), textRequests.end(),
        std::ostream_iterator<std::string>(std::cout));
        return textRequests;
    }
}

//Положить в файл answers.json результаты поисковых запросов
void ConverterJSON::putAnswers(std::vector<std::vector<std::pair<int, float>>> answers) {

}

