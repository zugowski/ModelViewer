cmake_minimum_required(VERSION 3.11)

project( ModelViewer
    VERSION 0.1
    DESCRIPTION "Model Viewer Project"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/CMake")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/CMake")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/CMake")

add_definitions(-D_AFXDLL)
set(CMAKE_MFC_FLAG 1)

set( HEADER_FILES
    include/CDlgDirLight.h
    include/CDlgLighting.h
    include/CDlgPbr.h
    include/CDlgPointLight.h
    include/CDlgSpotLight.h
    include/framework.h
    include/MainFrm.h
    include/ModelViewer.h
    include/ModelViewerDoc.h
    include/ModelViewerView.h
    include/pch.h
    include/resource.h
    include/targetver.h
)

set( SOURCE_FILES
    src/CDlgDirLight.cpp
    src/CDlgLighting.cpp
    src/CDlgPbr.cpp
    src/CDlgPointLight.cpp
    src/CDlgSpotLight.cpp
    src/MainFrm.cpp
    src/ModelViewer.cpp
    src/ModelViewerDoc.cpp
    src/ModelViewerView.cpp
    src/pch.cpp
)

set( RESOURCE_FILES
    res/ModelViewer.ico
    res/ModelViewer.rc
    res/ModelViewer.rc2
    res/ModelViewerDoc.ico
    res/Toolbar.bmp
)

source_group("Resource Files" FILES ${RESOURCE_FILES})

add_executable(${PROJECT_NAME} WIN32 ${HEADER_FILES} ${SOURCE_FILES} ${RESOURCE_FILES})
target_precompile_headers(${PROJECT_NAME} PRIVATE include/pch.h)

target_include_directories( ${PROJECT_NAME} PUBLIC 
    ${CMAKE_SOURCE_DIR}/include
)

add_subdirectory(${CMAKE_SOURCE_DIR}/lib/RenderingEngine)

target_link_libraries(${PROJECT_NAME} RenderingEngine)

if(WIN32)
    target_compile_definitions(${PROJECT_NAME} PRIVATE _UNICODE UNICODE _WIN32_WINNT=0x0A00)
endif()

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME})