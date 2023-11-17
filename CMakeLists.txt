cmake_minimum_required(VERSION 3.25)
project(GraphicsAssignment2)

set(CMAKE_CXX_STANDARD 17)

set(ROOT_DIR ${CMAKE_CURRENT_SOURCE_DIR})

file(GLOB_RECURSE HEADER_FILES src/*.h)
file(GLOB_RECURSE SOURCE_FILES src/*.cpp)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/resources DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

add_executable(GraphicsAssignment2 ${HEADER_FILES} ${SOURCE_FILES})

if (APPLE)
    include_directories(include)

    target_link_libraries(GraphicsAssignment2 "-framework OpenGL")
    target_link_libraries(GraphicsAssignment2 "-framework GLUT")

    target_link_libraries(GraphicsAssignment2 "-F ${ROOT_DIR}/Frameworks")

    target_link_libraries(GraphicsAssignment2 "-framework SFML")
    target_link_libraries(GraphicsAssignment2 "-framework SFML-audio")
    target_link_libraries(GraphicsAssignment2 "-framework SFML-graphics")
    target_link_libraries(GraphicsAssignment2 "-framework SFML-network")
    target_link_libraries(GraphicsAssignment2 "-framework SFML-system")
    target_link_libraries(GraphicsAssignment2 "-framework SFML-window")

    target_link_libraries(GraphicsAssignment2 "-framework FLAC")
    target_link_libraries(GraphicsAssignment2 "-framework ogg")
    target_link_libraries(GraphicsAssignment2 "-framework vorbis")
    target_link_libraries(GraphicsAssignment2 "-framework vorbisenc")
    target_link_libraries(GraphicsAssignment2 "-framework vorbisfile")
    target_link_libraries(GraphicsAssignment2 "-framework OpenAL")

    # add lc_rpath
    set_target_properties(
            GraphicsAssignment2
            PROPERTIES
            BUILD_WITH_INSTALL_RPATH 1
            INSTALL_RPATH "@executable_path/../Frameworks"
    )
endif ()