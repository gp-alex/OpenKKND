cmake_minimum_required(VERSION 2.8 FATAL_ERROR)


add_library(InfrastructurePlatformSpecific "")


target_sources(InfrastructurePlatformSpecific
    INTERFACE
        "${CMAKE_CURRENT_LIST_DIR}/OsTools.h"
    PRIVATE
        "${CMAKE_CURRENT_LIST_DIR}/OsTools.cpp"
)


if (WIN32)
    target_sources(InfrastructurePlatformSpecific
        PRIVATE
            "${CMAKE_CURRENT_LIST_DIR}/OsToolsWindows.cpp"
    )
    target_link_libraries(InfrastructurePlatformSpecific
        winmm.lib # timeGetTime
    )
else()
    target_sources(InfrastructurePlatformSpecific
        PRIVATE
            "${CMAKE_CURRENT_LIST_DIR}/OsToolsLinux.cpp"
    )
endif()
