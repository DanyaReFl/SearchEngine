# SearchEngine
Final work on the course "C++ Developer" from [Skillbox](https://skillbox.ru).
## 1. Description
+ In the configuration file [json_files/config.json](https://github.com/DanyaReFl/SearchEngine/blob/master/json_files/config.json)answers, before starting the application, the names of the files that the engine will search for are set.
+ The search engine independently bypasses all files and indexes them like this. to find the most relevant documents for any search query.
+ The user sets a request through a JSON file requests.json. The query consists of words for which you need to find documents.
+ The request is converted into a list of unique words. Compiles a list of documents that contain these words.
+ Search results are ranked, sorted and given to the user.
+ At the end, the program generates a file [json_files/answers.json](https://github.com/DanyaReFl/SearchEngine/blob/master/json_files/answers.json), writes the search results into it.
## 2. Tech
+ [C++17](https://en.cppreference.com/w/cpp/17)
+ [CMake 3.25](https://cmake.org/cmake/help/latest/release/3.25.html)
+ [Nlohmann JSON](https://github.com/nlohmann/json)
+ [GoogleTest](https://github.com/google/googletest)
