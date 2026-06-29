cmake_minimum_required(VERSION 3.15)
project(VisageGraph VERSION 1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Aggressive optimizations for the bare-metal math and I/O loops
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -march=native -flto")
set(CMAKE_CXX_FLAGS_DEBUG "-g -O0 -Wall -Wextra")

# We will need standard threading for the Producer/Consumer NVMe ring
find_package(Threads REQUIRED)

# Setup the include directory for our headers (like stb_image)
include_directories(include)

# The main executable
add_executable(VisageGraph src/main.cpp)
target_link_libraries(VisageGraph PRIVATE Threads::Threads)
