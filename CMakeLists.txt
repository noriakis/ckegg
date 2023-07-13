set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -O0")
cmake_minimum_required(VERSION 3.0)  # or 3.10, see below

project(ckegg VERSION 1.0.0)

find_package(CURL REQUIRED) 
find_package(LibXml2 REQUIRED)
include_directories(${LIBXML2_INCLUDE_DIRS})

add_executable(ckegg
    ckegg.c
)

target_link_libraries(ckegg CURL::libcurl ${LIBXML2_LIBRARY})
