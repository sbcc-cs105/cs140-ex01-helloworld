cmake_minimum_required(VERSION 3.10)

project (EX01-HelloWorld)
enable_testing()

execute_process(COMMAND uname -s OUTPUT_VARIABLE PLATFORM OUTPUT_STRIP_TRAILING_WHITESPACE)

set(EXECUTABLE_OUTPUT_PATH "bin/")

file(GLOB_RECURSE ASSIGNMENT_SOURCES RELATIVE ${CMAKE_SOURCE_DIR} "src/*.cc")
file(GLOB_RECURSE ASSIGNMENT_INCLUDES RELATIVE ${CMAKE_SOURCE_DIR} "include/*.h")
list(REMOVE_ITEM ASSIGNMENT_SOURCES "src/helloworld_unittest.cc")

add_executable(HelloWorld ${ASSIGNMENT_SOURCES} ${ASSIGNMENT_INCLUDES})
include_directories(include/ cs140/include)

add_library(HelloWorldObj OBJECT ${ASSIGNMENT_SOURCES})
target_compile_options(HelloWorldObj PRIVATE -Dmain=_main)

link_directories(cs140/lib/${PLATFORM})
link_libraries(gtests pthread)
add_executable(HelloWorld_GTest src/helloworld_unittest.cc $<TARGET_OBJECTS:HelloWorldObj>)

add_custom_target(submodule-update ALL git submodule init COMMAND git submodule update --recursive WORKING_DIRECTORY ${CMAKE_SOURCE_DIR})
add_custom_command(OUTPUT ${CMAKE_HOME_DIRECTORY}/.git/hooks/pre-push COMMAND ln ARGS -s ../../.githooks/pre-push .git/hooks WORKING_DIRECTORY ${CMAKE_HOME_DIRECTORY})
add_custom_target(pre-push-script ALL DEPENDS ${CMAKE_HOME_DIRECTORY}/.git/hooks/pre-push)
add_custom_command(OUTPUT ${CMAKE_HOME_DIRECTORY}/.git/hooks/pre-commit COMMAND ln ARGS -s ../../.githooks/pre-commit .git/hooks WORKING_DIRECTORY ${CMAKE_HOME_DIRECTORY})
add_custom_target(pre-commit-script ALL DEPENDS ${CMAKE_HOME_DIRECTORY}/.git/hooks/pre-commit)

add_dependencies(HelloWorld_GTest HelloWorldObj pre-push-script pre-commit-script submodule-update)
add_dependencies(HelloWorld pre-push-script pre-commit-script submodule-update)
