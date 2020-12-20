cmake_minimum_required(VERSION 3.16)

set(PROJECT voidworks-debugclient)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-O3 -s -DDEBUG=2")

project(${PROJECT} C CXX ASM)

include_directories(../../include)
add_subdirectory(../../src voidworks)
set(SOURCES ${SOURCES} debugclient.cpp)

add_library(${PROJECT} SHARED ${SOURCES})
target_link_libraries(${PROJECT} msvcrt ntdll winmm)
target_link_options(${PROJECT} PRIVATE -static -Wno-multichar -Wl,--image-base,0x190000000,-e,DllMain)

set_target_properties(${PROJECT} PROPERTIES PREFIX "")
set_target_properties(${PROJECT} PROPERTIES OUTPUT_NAME ${PROJECT})
set_target_properties(${PROJECT} PROPERTIES SUFFIX ".dll")
