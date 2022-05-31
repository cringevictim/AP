cmake_minimum_required(VERSION 3.22)
project(17 CXX)

set(CMAKE_CXX_STANDARD 14)
add_executable(${PROJECT_NAME} main.cpp)
set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR /usr/include/SFML)
find_package(SFML COMPONENTS system window graphics REQUIRED)

include_directories(/usr/include/SFML)
target_link_libraries(${PROJECT_NAME} sfml-system sfml-window sfml-graphics)

