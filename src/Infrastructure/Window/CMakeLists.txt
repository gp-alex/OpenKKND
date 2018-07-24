cmake_minimum_required(VERSION 2.8 FATAL_ERROR)


#set(INFRASTRUCTURE_WINDOW_SOURCES
#	SdlWindow.cpp
#	WindowFactory.cpp
#	WindowConfig.cpp
#	WindowConfigFactory.cpp
#)

#set(INFRASTRUCTURE_WINDOW_HEADERS
#	SdlWindow.h
#    Window.h
#	WindowFactory.h
#	WindowConfig.h
#	WindowConfigFactory.h
#)

#add_library(InfrastructureWindow STATIC ${INFRASTRUCTURE_WINDOW_SOURCES} ${INFRASTRUCTURE_WINDOW_HEADERS})

add_library(InfrastructureWindow "")
target_sources(InfrastructureWindow
    PUBLIC
        "${CMAKE_CURRENT_LIST_DIR}/WindowConfig.h"
        "${CMAKE_CURRENT_LIST_DIR}/WindowConfigFactory.h"
        "${CMAKE_CURRENT_LIST_DIR}/Window.h"
        "${CMAKE_CURRENT_LIST_DIR}/WindowFactory.h"
    PRIVATE
        "${CMAKE_CURRENT_LIST_DIR}/SdlWindow.h"
        "${CMAKE_CURRENT_LIST_DIR}/SdlWindow.cpp"
        "${CMAKE_CURRENT_LIST_DIR}/WindowConfigFactory.cpp"
        "${CMAKE_CURRENT_LIST_DIR}/WindowFactory.cpp"
)
