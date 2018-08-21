cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

add_subdirectory(Scripts)



add_library(Application "")

target_sources(Application
    PUBLIC
        "${CMAKE_CURRENT_LIST_DIR}/Game.h"
        "${CMAKE_CURRENT_LIST_DIR}/GameConfig.h"
        "${CMAKE_CURRENT_LIST_DIR}/GameConfigFactory.h"
    PRIVATE
        "${CMAKE_CURRENT_LIST_DIR}/GameWindowObserver.h"
        "${CMAKE_CURRENT_LIST_DIR}/Game.cpp"
        "${CMAKE_CURRENT_LIST_DIR}/GameFactory.cpp"
        "${CMAKE_CURRENT_LIST_DIR}/GameConfig.cpp"
        "${CMAKE_CURRENT_LIST_DIR}/GameConfigFactory.cpp"
        "${CMAKE_CURRENT_LIST_DIR}/GameWindowObserver.cpp"
)



target_link_libraries(
    Application
    ApplicationScripts
)