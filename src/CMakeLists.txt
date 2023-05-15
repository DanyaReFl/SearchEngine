cmake_minimum_required(VERSION 3.25)

add_executable(${PROJECT_NAME}
        ${MY_SRC_DIR}/main.cpp
        ${MY_SRC_DIR}/InvertedIndex.cpp
        ${MY_SRC_DIR}/ConverterJSON.cpp
        ${MY_SRC_DIR}/SearchServer.cpp
        ${MY_INCLUDE_DIR}/InvertedIndex.h
        ${MY_INCLUDE_DIR}/ConverterJSON.h
        ${MY_INCLUDE_DIR}/SearchServer.h
        )

target_include_directories(${PROJECT_NAME} PUBLIC ${MY_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} nlohmann_json::nlohmann_json)



