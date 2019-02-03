cmake_minimum_required(VERSION 3.7)
project(PruebaED2)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp DataFile.cpp DataFile.h FixedSize_Register.cpp FixedSize_Register.h DelimiterVarSize_Register.cpp DelimiterVarSize_Register.h KnownVarSize_Register.cpp KnownVarSize_Register.h)
add_executable(PruebaED2 ${SOURCE_FILES})