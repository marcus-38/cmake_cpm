cmake_minimum_required(VERSION 4.0)
project(cmake_cpm)

set(CMAKE_CXX_STANDARD 20)

# -- add cpm --
include(cmake/CPM.cmake)

# -- add dependencies --
CPMAddPackage("gh:gabime/spdlog@1.15.2")

# -- executable --
add_executable(cmake_cpm main.cpp)

# -- link libraries --
target_link_libraries(${CMAKE_PROJECT_NAME} spdlog)