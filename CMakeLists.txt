cmake_minimum_required(VERSION 3.25)
project(TinyCompiler)

set(CMAKE_CXX_STANDARD 14)

add_executable(TinyCompiler
        main.cpp AbstractSyntaxTree.cpp Tree.cpp)
