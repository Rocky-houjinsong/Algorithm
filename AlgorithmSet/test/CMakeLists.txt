cmake_minimum_required(VERSION 3.16)
project(test)

#将gTest 添加到项目中 (googletest源码 不在test路径内,需要显式指定)
add_subdirectory(${AlgorithmSet_WORLD_PROJECT_ROOT}/third_party/googletest googletest)

#设定可执行文件
add_executable(test_randomList ${CMAKE_CURRENT_SOURCE_DIR}/test_randomList.cpp)

#添加 依赖的 头文件路径
target_include_directories(test_randomList PUBLIC ${AlgorithmSet_WORLD_PROJECT_ROOT}/third_party/googletest/googletest/include)
target_include_directories(test_randomList PUBLIC ${AlgorithmSet_WORLD_PROJECT_ROOT})
#添加 依赖的 库 (待测试的库, 测试框架)
target_link_libraries(test_randomList PUBLIC randomList GTest::gtest_main GTest::gtest GTest::gmock GTest::gmock_main)

add_test(NAME test_randomList
		COMMAND test_randomList)