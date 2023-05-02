cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(PNGModfier VERSION 1.0)

#add_library(pngchunk STATIC src/png_chunk.cpp)
add_executable(pngmodifier src/main.cpp src/png_chunk.cpp)

#target_link_libraries(pngmodifier png_chunk)
target_include_directories(pngmodifier PUBLIC include)

include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest
    GIT_TAG release-1.11.0
)
FetchContent_GetProperties(googletest)
if(NOT googletest_POPULATED)
    FetchContent_Populate(googletest)
    add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BUILD_DIR})
endif()

add_executable(testpngmodifier tests/test_png_chunk.cpp src/png_chunk.cpp)

target_link_libraries(testpngmodifier gtest_main gmock_main)

target_include_directories(testpngmodifier PUBLIC include)

#ACTUAL OG
#https://www.youtube.com/watch?v=5wI47v4kuxU&ab_channel=SerbansCodeAcademy

#OG
#https://www.youtube.com/watch?v=mKZ-i-UfGgQ&ab_channel=kandodev

#project(pngmodifier VERSION 0.0.1 LANGUAGES CXX)

#https://www.youtube.com/watch?v=Lp1ifh9TuFI&t=912s&ab_channel=Rhymu%27sVideos

#THIS!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
#https://www.youtube.com/watch?v=BCY3gagHX8w&ab_channel=LearnQtGuidecd w

#cmake_minimum_required(VERSION 3.16.3)
#
#set(CMAKE_CXX_STANDARD 17)
#set(CMAKE_CXX_STANDARD_REQUIRED ON)
#
#project(PNGModfier VERSION 1.0)
#add_executable(pngmodifier src/main.cpp src/png_chunk.cpp)
#
#target_include_directories(pngmodifier PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)