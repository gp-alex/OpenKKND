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
    Script.cpp
    ScriptEvent.cpp
	stru29.cpp
	stru31.cpp
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
	Script.h
	ScriptEvent.h
	stru29.h
	stru31.h
)

if(WIN32)
else()
endif()

add_library(Unsorted STATIC ${UNSORTED_SOURCES} ${UNSORTED_HEADERS})
