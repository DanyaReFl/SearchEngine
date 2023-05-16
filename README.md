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
В папке /Src собраны реализации следующих сервисных классов:

ConverterJSON - выполняет следующие функции:

считывает данные из JSON,
обрабатывает данные из формата JSON,
формирует ответы в формате JSON,
использует Open Source JSON for Modern C++ Library Copyright © 2013-2022 Niels Lohmann
В работе используются следующие файлы (тестовые варианты представлены в /JSON...):
```json
{
    "config": 
    {
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
ОГРАНИЧЕНИЯ! Наличие полей обязательно. Контроль совпадения версий config.json и проекта. Содержимое - каждый текстовый файл состоит не более чем из 1.000 слов, с не более чем 100 символами в каждом слове. Программа обрабатывает соответствующие исключения. Расположение файла - каталог с .exe
```json{
requests.json (шаблон)
{
  "requests":
    [
      "some words..",
      "some words..",
      "some words..",
      "some words.."
      ]
}
```
ОГРАНИЧЕНИЯ! Наличие полей обязательно. Содержимое - не более чем 1.000 запросов, с не более чем 10 словами в запросе. Программа обрабатывает соответствующие исключения. Расположение файла - каталог с .exe
```json{
answers.json (шаблон)
{
  "answers":
  {
    "request0001":
      {
        "relevance":
          {
            "result": "true"
             },
          [
            "docid: 0, rank: 1.000000",
            "docid: 1, rank: 0.500000",
            "docid: 2, rank: 0.250000",
            "docid: 3, rank: 0.250000",
            "docid: 4, rank: 0.250000"
            ], 
        },
    "request0002":
      {
        "result": "true"
        },
      [
        "docid: 0, “rank: 0.769"
        ]
        },
    "request0003":
      {
        "result": "false"
        }
}
```
При формировании структуры файла (режим перезапись) используются следующие принципы: отсутствие документов релевантных запросу - ["request0003"], при наличии только одного релевантного документа - ["request0002"], наличие множества релевантных документов - ["request0001"]. Расположение файла - каталог с .exe.

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
В папке [/test]{https://github.com/DanyaReFl/SearchEngine/tree/master/test} сформированы модульные тесты Tests.cpp, использован Google Testing and Mocking Framework с подключением по URL из GitHub. 
</b></details>
