cmake_minimum_required(VERSION 3.8.0 FATAL_ERROR)

set(VCPKG_ROOT "$ENV{VCPKG_ROOT}")
if(DEFINED ENV{VCPKG_ROOT} AND NOT DEFINED CMAKE_TOOLCHAIN_FILE)
  set(CMAKE_TOOLCHAIN_FILE "${VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake")
endif()

#get_cmake_property(_variableNames VARIABLES)
#list (SORT _variableNames)
#foreach (_variableName ${_variableNames})
#    message(STATUS "${_variableName}=${${_variableName}}")
#endforeach()

message("VCPKG_ROOT=${VCPKG_ROOT}")
message("VCPKG_TARGET_TRIPLET=${VCPKG_TARGET_TRIPLET}")
message("CMAKE_TOOLCHAIN_FILE=${CMAKE_TOOLCHAIN_FILE}")


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

find_path(SDL2_INCLUDE_DIR SDL2/SDL.h)
find_library(SDL2_LIBRARY SDL2)
find_library(SDL2_MAIN SDL2main)
message("SDL2_INCLUDE_DIR=${SDL2_INCLUDE_DIR}")
message("SDL2_LIBRARY=${SDL2_LIBRARY}")
message("SDL2_MAIN=${SDL2_MAIN}")


add_executable(OpenKKND ./src/Application/Game.cpp)

target_include_directories(OpenKKND PRIVATE ${SDL2_INCLUDE_DIR})

target_link_libraries(OpenKKND Application Engine Infrastructure Unsorted ${SDL2_LIBRARY} ${SDL2_MAIN})
