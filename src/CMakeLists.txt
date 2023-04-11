cmake_minimum_required(VERSION 3.23)

set(JSON_BuildTests OFF CACHE INTERNAL "")
set(CMAKE_CXX_STANDARD 17)

add_executable(${PROJECT_NAME} main.cpp ConverterJSON.cpp ../header/ConverterJSON.h)

target_link_libraries(${PROJECT_NAME} PRIVATE nlohmann_json::nlohmann_json)

enable_testing()

target_link_libraries(search_engine PRIVATE gtest_main)
include(GoogleTest)
gtest_discover_tests(search_engine)