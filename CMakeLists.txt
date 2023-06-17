cmake_minimum_required(VERSION 3.9)
project(mayhemCPP)

set(CMAKE_CXX_STANDARD 17)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH  ${CMAKE_BINARY_DIR}/lib)

include_directories(include
        deps/glad/include
        deps/glfw/include)

add_subdirectory(deps/glad)
add_subdirectory(deps/glfw)

add_executable(mayhemCPP
        src/pch.cpp
        src/window.cpp
        test.cpp)

target_link_libraries(mayhemCPP glad glfw)