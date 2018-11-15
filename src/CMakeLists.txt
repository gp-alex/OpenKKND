cmake_minimum_required(VERSION 2.8 FATAL_ERROR)


add_subdirectory(Application)
add_subdirectory(Engine)
add_subdirectory(Infrastructure)


set(UNSORTED_SOURCES
	_unsorted_data.cpp
	Coroutine.cpp
    Cursor.cpp
    kknd.cpp
    Random.cpp
    Render.cpp
    RenderDrawHandlers.cpp
    Script.cpp
    ScriptEvent.cpp
    Sprite.cpp
	stru29.cpp
	stru31.cpp
    Map.cpp
    Pathfind.cpp
    Development.cpp
    Level.cpp
    SaveLoad.cpp
	Sidebar.cpp
)

set(UNSORTED_HEADERS
	_unsorted_data.h
    _unsorted_functions.h
    Coroutine.h
    Cursor.h
    hexrays-defs.h
    kknd.h
    Random.h
    Render.h
    RenderDrawHandlers.h
	Script.h
	ScriptEvent.h
    Sprite.h
	stru29.h
	stru31.h
    Map.h
    Pathfind.h
	Sidebar.h
)

add_library(Unsorted STATIC ${UNSORTED_SOURCES} ${UNSORTED_HEADERS})

add_library(Audio "")
add_library(Video "")
if(WIN32)
    target_sources(Audio
        INTERFACE
            "${CMAKE_CURRENT_LIST_DIR}/Sound.h"
        PRIVATE
            "${CMAKE_CURRENT_LIST_DIR}/Sound.cpp"
    )

    target_sources(Video
        INTERFACE
            "${CMAKE_CURRENT_LIST_DIR}/Video.h"
        PRIVATE
            "${CMAKE_CURRENT_LIST_DIR}/Video.cpp"
    )
else()
endif()
