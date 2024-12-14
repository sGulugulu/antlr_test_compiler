cmake_minimum_required(VERSION 3.16)
project(anuc)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_CXX_COMPILER "g++")

file(GLOB_RECURSE LIB_SRC "lib/*.cpp")
#测试修改
file(GLOB_RECURSE GERATED "generated_test/*.cpp")

#include_directories(third_party/antlr4-runtime
#        generated)
#测试
include_directories(third_party/antlr4-cpp-runtime-4.13.2
       generated_test  generated)
link_directories(third_party/lib)

add_executable(a main.cpp MyCVisitor.cpp ${LIB_SRC} ${GERATED} )
target_link_libraries(a libantlr4-runtime.a)

#google test
#set(GTest_DIR /usr/local/lib/cmake/GTest)
#find_package(GTest REQUIRED)
#include_directories(${GTEST_INCLUDE_DIRS})
#enable_testing()

#测试ir
#add_executable(irtest _unittest/IR/test.cc ${LIB_SRC})
#target_link_libraries(irtest GTest::gtest GTest::gtest_main)
#add_test(AllTest irtest)

