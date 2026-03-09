cmake_minimum_required(VERSION 3.10)
project(AtomCPP)

add_executable(main main.cpp src/glad.c)

target_include_directories(main PRIVATE dependencies/include)

target_link_directories(main PRIVATE ${CMAKE_SOURCE_DIR}/dependencies/lib)
target_link_libraries(main PRIVATE glfw3dll opengl32 gdi32)