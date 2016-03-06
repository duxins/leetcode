cmake_minimum_required(VERSION 3.3)

project(leetcode)

add_subdirectory(lib/gtest-1.7.0)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories(include)

function(target name)
    add_executable(${name} ${name}.cpp)
    target_link_libraries(${name} gtest gtest_main)
endfunction(target)

target(001-two-sum)
