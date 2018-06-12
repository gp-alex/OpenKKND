cmake_minimum_required(VERSION 2.8 FATAL_ERROR)
project("OpenKKND")
set(PROJECT_VERSION "0.2.0")

if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
  set(CMAKE_CXX_FLAGS "-std=gnu++11 ${CMAKE_CXX_FLAGS}")
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
  set(CMAKE_CXX_FLAGS "-std=c++11 -stdlib=libc++ ${CMAKE_CXX_FLAGS}")
endif()



include_directories(${INCLUDE_DIRECTORIES} ./)
include_directories(${INCLUDE_DIRECTORIES} ./src)
add_subdirectory(src)



set (CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")
SET (CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /SAFESEH:NO")



add_executable(OpenKKND MACOSX_BUNDLE WIN32 ./src/Application/Game.cpp)
target_link_libraries(OpenKKND Application Engine Infrastructure Unsorted)



if(WIN32)
  if(CMAKE_SIZEOF_VOID_P EQUAL 8)
    set(VC_LIB_PATH_SUFFIX Win64)
    set(VC_LIB_PATH_SUFFIX2 x64)
  else()
    set(VC_LIB_PATH_SUFFIX Win32)
    set(VC_LIB_PATH_SUFFIX2 x86)
  endif()
endif()
