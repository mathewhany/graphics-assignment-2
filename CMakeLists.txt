cmake_minimum_required(VERSION 3.25)
project(GraphicsAssignment2)

set(CMAKE_CXX_STANDARD 17)

set(ROOT_DIR ${CMAKE_CURRENT_SOURCE_DIR})

file(GLOB_RECURSE HEADER_FILES src/*.h)
file(GLOB_RECURSE SOURCE_FILES src/*.cpp)

add_executable(GraphicsAssignment2 ${HEADER_FILES} ${SOURCE_FILES})

target_link_libraries(GraphicsAssignment2 "-framework OpenGL")
target_link_libraries(GraphicsAssignment2 "-framework GLUT")
