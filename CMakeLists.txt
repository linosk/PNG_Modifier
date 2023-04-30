cmake_minimum_required(VERSION 3.16.3)

project(pngmodifier CXX)

set(CMAKE_CXX _STANDARD 17)

#enable_testing()

#add_subdirectory(tests)

#https://www.youtube.com/watch?v=Lp1ifh9TuFI&t=912s&ab_channel=Rhymu%27sVideos
#add_library($)

#include_directories(include, src)

#set(Headers
#    include/png_chunk.h
#)

#THIS!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
#https://www.youtube.com/watch?v=BCY3gagHX8w&ab_channel=LearnQtGuide

set(SOURCES
    png_chunk.cpp
    main.cpp
)

add_executable(${NAME})

target_sources(${NAME} PRIVATE ${SOURCES})

target_include_directories(${NAME} PRIVATE include)
#add_library(${This} STATIC ${Sources} ${Headers})

#add_executable(${PROJECT_NAME} main.cpp)