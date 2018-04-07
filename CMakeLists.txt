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
link_libraries(gtests)
add_executable(HelloWorld_GTest src/helloworld_unittest.cc $<TARGET_OBJECTS:HelloWorldObj>)

add_dependencies(HelloWorld_GTest HelloWorld)
