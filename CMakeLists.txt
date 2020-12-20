cmake_minimum_required(VERSION 3.16)

set(PROJECT voidworks)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-O3 -s")
set(CMAKE_CXX_FLAGS_DEBUG "-DDEBUG=2")

project(${PROJECT} C CXX ASM)

include_directories(include)
add_subdirectory(src)
add_subdirectory(include)

add_library(${PROJECT} SHARED ${SOURCES} ${HEADERS})
target_link_libraries(${PROJECT} msvcrt ntdll winmm)
target_link_options(${PROJECT} PRIVATE -static -Wno-multichar -Wl,--image-base,0x190000000,-e,DllMain)
target_include_directories(${PROJECT} PUBLIC include)
