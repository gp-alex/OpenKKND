cmake_minimum_required(VERSION 2.8 FATAL_ERROR)


set(INFRASTRUCTURE_SOURCES
	File.cpp
	Input.cpp
    Netz.cpp
)

set(INFRASTRUCTURE_HEADERS
	File.h
    Input.h
    Netz.h
)

if(WIN32)
else()
endif()

add_library(Infrastructure STATIC ${INFRASTRUCTURE_SOURCES} ${INFRASTRUCTURE_HEADERS})
