cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

add_subdirectory(PlatformSpecific)
add_subdirectory(Renderer)
add_subdirectory(Window)


#set(INFRASTRUCTURE_SOURCES
#	DependencyInjection.cpp
#	File.cpp
#	Input.cpp
#	Log.cpp
#    Netz.cpp
#)

#set(INFRASTRUCTURE_HEADERS
#	DependencyInjection.h
#	File.h
#    Input.h
#	Log.h
#    Netz.h
#)


#add_library(Infrastructure STATIC ${INFRASTRUCTURE_SOURCES} ${INFRASTRUCTURE_HEADERS})


add_library(Infrastructure "")
target_sources(Infrastructure
    INTERFACE
        "${CMAKE_CURRENT_LIST_DIR}/DependencyInjection.h"
        "${CMAKE_CURRENT_LIST_DIR}/File.h"
        "${CMAKE_CURRENT_LIST_DIR}/Input.h"
        "${CMAKE_CURRENT_LIST_DIR}/Log.h"
        "${CMAKE_CURRENT_LIST_DIR}/Netz.h"
    PRIVATE
        "${CMAKE_CURRENT_LIST_DIR}/DependencyInjection.cpp"
        "${CMAKE_CURRENT_LIST_DIR}/File.cpp"
        "${CMAKE_CURRENT_LIST_DIR}/Input.cpp"
        "${CMAKE_CURRENT_LIST_DIR}/Log.cpp"
        "${CMAKE_CURRENT_LIST_DIR}/Netz.cpp"
)

target_link_libraries(
    Infrastructure
    InfrastructureWindow
    InfrastructureRenderer
    InfrastructurePlatformSpecific
)