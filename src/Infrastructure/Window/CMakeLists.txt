cmake_minimum_required(VERSION 2.8 FATAL_ERROR)


add_library(InfrastructureWindow "")

target_sources(InfrastructureWindow
    PUBLIC
        "${CMAKE_CURRENT_LIST_DIR}/InputObserver.h"
        "${CMAKE_CURRENT_LIST_DIR}/WindowConfig.h"
        "${CMAKE_CURRENT_LIST_DIR}/WindowConfigFactory.h"
        "${CMAKE_CURRENT_LIST_DIR}/Window.h"
        "${CMAKE_CURRENT_LIST_DIR}/WindowFactory.h"
        "${CMAKE_CURRENT_LIST_DIR}/WindowObserver.h"
    PRIVATE
        "${CMAKE_CURRENT_LIST_DIR}/SdlWindow.h"
        "${CMAKE_CURRENT_LIST_DIR}/SdlWindow.cpp"
        "${CMAKE_CURRENT_LIST_DIR}/WindowConfigFactory.cpp"
        "${CMAKE_CURRENT_LIST_DIR}/WindowFactory.cpp"
)
