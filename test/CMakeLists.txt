cmake_minimum_required (VERSION 3.25)

add_executable(GtestTests
		InvertedIndexTest.cpp
		SearchServerTest.cpp
		${MY_SRC_DIR}/InvertedIndex.cpp
		${MY_SRC_DIR}/ConverterJSON.cpp
		${MY_SRC_DIR}/SearchServer.cpp
		)

target_include_directories(GtestTests PUBLIC ${MY_INCLUDE_DIR})
target_link_libraries(GtestTests nlohmann_json::nlohmann_json GTest::gtest_main)
include(GoogleTest)
gtest_discover_tests(GtestTests)