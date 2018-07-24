cmake_minimum_required(VERSION 2.8 FATAL_ERROR)


add_subdirectory(Renderer)
add_subdirectory(Window)


set(INFRASTRUCTURE_SOURCES
	DependencyInjection.cpp
	File.cpp
	Input.cpp
	Log.cpp
    Netz.cpp
)

set(INFRASTRUCTURE_HEADERS
	DependencyInjection.h
	File.h
    Input.h
	Log.h
    Netz.h
)


add_library(Infrastructure STATIC ${INFRASTRUCTURE_SOURCES} ${INFRASTRUCTURE_HEADERS})
