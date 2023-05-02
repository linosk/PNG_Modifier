cmake_minimum_required(VERSION 3.16.3)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(PNGModfier VERSION 1.0)
add_executable(pngmodifier src/main.cpp src/png_chunk.cpp)

target_include_directories(pngmodifier PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

#OG
#https://www.youtube.com/watch?v=mKZ-i-UfGgQ&ab_channel=kandodev

#project(pngmodifier VERSION 0.0.1 LANGUAGES CXX)

#https://www.youtube.com/watch?v=Lp1ifh9TuFI&t=912s&ab_channel=Rhymu%27sVideos

#THIS!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
#https://www.youtube.com/watch?v=BCY3gagHX8w&ab_channel=LearnQtGuidecd w