#Should there be unique cmake files for app and testing?
cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(PNGModfier VERSION 1.0)

set(Sources
    src/png_chunk.cpp
    src/png_place_holder.cpp)

set(Tests
    tests/test_png_chunk.cpp
    tests/test_png_place_holder.cpp)

add_executable(pngmodifier 
                src/main.cpp 
                ${Sources}
                )

target_include_directories(pngmodifier PUBLIC include)

#TESTING SHOULD BE LATER DONE BY CTEST - MAYBE?
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

add_executable(testpngmodifier 
                ${Sources}
                ${Tests}
                )

target_link_libraries(testpngmodifier gtest_main gmock_main)

target_include_directories(testpngmodifier PUBLIC include)