cmake_minimum_required(VERSION 3.10)

project(ProjectOne)

file(GLOB SOURCES "src/*.cpp", "src/*/*.cpp")

add_executable(${PROJECT_NAME}  ${SOURCES})

target_include_directories(ProjectOne PUBLIC 
$<INSTALL_INTERFACE:include>
$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>)