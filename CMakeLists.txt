cmake_minimum_required(VERSION 3.3)
project(leetcode)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories(include)

function(target name)
    add_executable(${name} ${name}.cpp)
endfunction(target)

target(main)
