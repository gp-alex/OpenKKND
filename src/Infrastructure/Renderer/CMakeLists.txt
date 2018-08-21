cmake_minimum_required(VERSION 2.8 FATAL_ERROR)


#set(INFRASTRUCTURE_RENDERER_SOURCES
#    RendererFactory.cpp
#    SdlRenderer.cpp
#)

#set(INFRASTRUCTURE_RENDERER_HEADERS
#    RendererConfig.h
#    RendererConfigFactory.h
#    Renderer.h
#    RendererFactory.h
#    SdlRenderer.h
#)

#add_library(InfrastructureRenderer STATIC ${INFRASTRUCTURE_RENDERER_SOURCES} ${INFRASTRUCTURE_RENDERER_HEADERS})


add_library(InfrastructureRenderer "")
target_sources(InfrastructureRenderer
    INTERFACE
        "${CMAKE_CURRENT_LIST_DIR}/RendererConfig.h"
        "${CMAKE_CURRENT_LIST_DIR}/RendererConfigFactory.h"
        "${CMAKE_CURRENT_LIST_DIR}/Renderer.h"
        "${CMAKE_CURRENT_LIST_DIR}/RendererFactory.h"
    PRIVATE
        "${CMAKE_CURRENT_LIST_DIR}/SdlRenderer.h"
        "${CMAKE_CURRENT_LIST_DIR}/SdlRenderer.cpp"
        "${CMAKE_CURRENT_LIST_DIR}/RendererFactory.cpp"
)

