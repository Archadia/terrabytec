cmake_minimum_required(VERSION 3.17)

project(terrabytec)

# Add our own additional includes
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

# Add glfw submodule
set( GLFW_BUILD_DOCS OFF CACHE BOOL  "GLFW lib only" )
set( GLFW_INSTALL OFF CACHE BOOL  "GLFW lib only" )
add_subdirectory(dependencies/glfw)

# Add data_desk submodule
add_subdirectory(dependencies/data_desk)

# Set SOURCE to all .h, .cpp and .c files.
file(GLOB SOURCE
    "src/*.h"
    "src/*.cpp"
    "src/*.c"
)

add_executable(${PROJECT_NAME} ${SOURCE})
target_link_libraries(${PROJECT_NAME} glfw)


