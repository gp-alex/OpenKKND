cmake_minimum_required(VERSION 2.8 FATAL_ERROR)


set(ENGINE_SOURCES
	BuildingLimits.cpp
	Entity.cpp
    EntityFactory.cpp
	Infrastructure/EntityRepository.cpp
)

set(ENGINE_HEADERS
	BuildingLimits.h
	Entity.h
    EntityFactory.h
	Infrastructure/EntityRepository.h
)

if(WIN32)
else()
endif()

add_library(Engine STATIC ${ENGINE_SOURCES} ${ENGINE_HEADERS})
