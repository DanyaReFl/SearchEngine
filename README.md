# SearchEngine
Final work on the course "C++ Developer" from [Skillbox](https://skillbox.ru).
## 1. Description
+ In the configuration file [json_files/config.json](https://github.com/DanyaReFl/SearchEngine/blob/master/json_files/config.json) answers, before starting the application, the names of the files that the engine will search for are set.
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
## 3. Project components and implementation
</b></details>
<details>
<summary>Src</summary><br><b>
The /Src folder contains implementations of the following service classes:
Convert to json - performs the following functions:

Reads data from JSON, processes data from JSON format, generates responses in JSON format, uses Open Source JSON for Modern C++ Library Copyright © 2013-2022 Niels Lohmann The following files are used in the work :
```json
{
    "config": {
      "name": "SkillboxSearchEngine",
      "version": "1.0.1",
      "max_responses": 5
    },
    "files":[
      "resources/file001.txt",
      "resources/file002.txt",
      "resources/file003.txt",
      "resources/file004.txt"
    ]
}
```
RESTRICTIONS! The presence of fields is mandatory. Control of the match of config versions.json and the project. Content - Each text file consists of no more than 1,000 words, with no more than 100 characters in each word. The program handles the corresponding exceptions. File location - directory with .exe
```json
{
  "requests":[
      "some words..",
      "some words..",
      "some words..",
      "some words.."
      ]
}
```
RESTRICTIONS! The presence of fields is mandatory. The content is no more than 1,000 queries, with no more than 10 words per query. The program handles the corresponding exceptions. File location - directory with .exe
```json
{
    "answers": {
        "request001": {
            "relevance": [
                {
                    "docid": 1,
                    "rank": 1.0
                },
                {
                    "docid": 0,
                    "rank": 0.6111111044883728
                },
                {
                    "docid": 2,
                    "rank": 0.6111111044883728
                },
                {
                    "docid": 3,
                    "rank": 0.6111111044883728
                },
                {
                    "docid": 12,
                    "rank": 0.5555555820465088
                }
            ],
            "result": true
        }
    }
}
```
InvertedIndex - выполняет следующие функции:

получает, подготоваливает и хранит базу текстовых документов,
индексирует документы, заполняет и хранит базу поисковых индексов документов,
получает клиентский запрос (отдельное слово) и возвращает список индексов для каждого документа.
SearchServer - выполняет следующие функции:

получает и подготавливает массив клиентских запросов,
используя экземпляр InvertedIndex формирует и возращает ранжированный массив релевантных документов.
/Tests/...
В папке /Tests сформированы модульные тесты Tests.cpp, использован Google Testing and Mocking Framework с подключением по URL из GitHub.
</b></details>

</b></details>
<details>
<summary>test</summary><br><b>
В папке /test сформированы модульные тесты Tests.cpp, использован Google Testing and Mocking Framework с подключением по URL из GitHub. 
</b></details>
