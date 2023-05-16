# SearchEngine
What is a Search Engine?
Search Engine it's a console application, searching and having the ability to configure through files of the format JSON
____
What's a stack of technologies used?
In the Search Engine project, we use the following list of the technologies:
C++20
CMake 3.22
Nlohmann JSON
GoogleTest

How to build and run this project?
Build the project:
cmake -S . -B "build"
cmake --build build --config Release

Copy files:
requests.json, config.json and resources folder to the Release folder.

Run the application:
Release\SearchEngine.exe

Files description:
config.json
{
  "config": {
    "name": "SkillboxSearchEngine",
    "version": "0.1",
    "max_responses": 5
  },
  "files": [
    "resources/file001.txt",
    "resources/file002.txt",
    "resources/file003.txt",
    "resources/file004.txt"
  ]
}
config - general information.
name - field with the name of the search engine.
version - field with the version number of the search engine.
max_responses - a field that determines the maximum number of responses to one request.
files - contains the paths to the files to be searched. Inside the files list are the paths to the files.

requests.json
{
  "requests": [
    "banana",
    "seven",
    "counter",
    "dog"
  ]
}
requests - consists of a list of requests to be processed search engine.

answers.json
{
    "answers": {
        "request001": {
            "relevance": [
                {
                    "docid": 0,
                    "rank": 1.0
                }
            ],
            "result": true
        },
        "request002": {
            "result": false
        },
        "request003": {
            "result": false
        },
        "request004": {
            "relevance": [
                {
                    "docid": 2,
                    "rank": 1.0
                }
            ],
            "result": true
        }
    }
}
answers - the base field in this file that contains the answers to queries.
request - request001 ... 004 is the identifier of the request for which the response was generated.
result - query search result.
relevance - included in the answers.json file if this query was found more than one document.
docid - the identifier of the document in which found the answer to the query.
rank - search ranking.
