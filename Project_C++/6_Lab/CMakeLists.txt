cmake_minimum_required(VERSION 3.28.3)
project(6_Lab)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
file(GLOB_RECURSE SOURCES "src/*.cpp")

include_directories(include)

add_executable(main ${SOURCES} main.cpp)

set_target_properties(main PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}"
)