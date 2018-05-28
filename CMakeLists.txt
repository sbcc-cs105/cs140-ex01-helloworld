cmake_minimum_required(VERSION 3.10)

project (EX01-HelloWorld)

set(SOURCE_PREFIX "helloworld")
set(EXEC_NAME "HelloWorld")

if(EXISTS ${CMAKE_HOME_DIRECTORY}/cs140/CMakeLists.txt)
    include(cs140/CMakeLists.txt)
else()
    add_custom_target(submodule-init ALL git submodule init COMMAND git submodule update --recursive WORKING_DIRECTORY ${CMAKE_SOURCE_DIR})
endif()
