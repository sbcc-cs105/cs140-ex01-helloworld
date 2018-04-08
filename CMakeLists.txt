cmake_minimum_required(VERSION 3.5)

execute_process(COMMAND uname -s OUTPUT_VARIABLE PLATFORM OUTPUT_STRIP_TRAILING_WHITESPACE)

project (EX01-HelloWorld)

set(EXECUTABLE_OUTPUT_PATH "bin/")

add_executable(HelloWorld src/helloworld.cc include/helloworld.h)
include_directories(include/)

add_library(HelloWorldObj OBJECT src/helloworld.cc)
target_compile_options(HelloWorldObj PRIVATE -Dmain=_main)
include_directories(include/)

link_directories(lib/${PLATFORM})
link_libraries(gtests pthread)
add_executable(HelloWorld_GTest src/helloworld_unittest.cc $<TARGET_OBJECTS:HelloWorldObj>)

add_custom_command(OUTPUT ${CMAKE_HOME_DIRECTORY}/.git/hooks/pre-push COMMAND ln ARGS -s ../../.githooks/pre-push .git/hooks WORKING_DIRECTORY ${CMAKE_HOME_DIRECTORY})
add_custom_target(pre-push-script ALL DEPENDS ${CMAKE_HOME_DIRECTORY}/.git/hooks/pre-push)

add_dependencies(HelloWorld_GTest HelloWorldObj pre-push-script)
add_dependencies(HelloWorld pre-push-script)