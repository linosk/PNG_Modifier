cmake_minimum_required(VERSION 3.16.3)

set(Tests)

set(Sources

)

add_executable(${This} ${Sources})
target_link_libraries(${This} PUBLIC
    gtest_main

)

add_test(
    NAME ${This}
    COMMAND ${This}
)