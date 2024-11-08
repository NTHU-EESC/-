cmake_minimum_required(VERSION 3.0)

set(PROJECT_NAME cache_sim)
project(${PROJECT_NAME} CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
## make VERBOSE=1
set(CMAKE_VERBOSE_MAKEFILE on)

## compiler option setting
set(CMAKE_BUILD_TYPE "DEBUG")

set(CMAKE_CXX_FLAGS_NONE "${CMAKE_CXX_FLAGS_NONE} -O3 -pedantic -fstack-check -fsanitize=address")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -pedantic -fstack-check -Wall -fsanitize=address -Werror -Wextra -Wno-unused-variable -Wno-unused-parameter")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE}")
## Use C++17 std
set(CMAKE_CXX_STANDARD 17)
## Use clang instead of gcc
set(CMAKE_CXX_COMPILER "clang++")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -m64 ${OPT_CFLAGS}")
set(CMAKE_LD_FLAGS "${CMAKE_LD_FLAGS} -m64")

add_subdirectory(src)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR})
