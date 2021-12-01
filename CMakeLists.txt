cmake_minimum_required(VERSION 3.0)

project(advent-of-code-2021)

set(CMAKE_CXX_STANDARD 17)
set(OPTFLAGS -g -O3)
set(WARNINGS -Wall -Wextra -Werror -pedantic-errors -Wno-missing-field-initializers)

file(GLOB_RECURSE SRCS src/*.cpp)
add_executable(${PROJECT_NAME} ${SRCS})
target_include_directories(${PROJECT_NAME} BEFORE PUBLIC ${CMAKE_SOURCE_DIR}/include)
