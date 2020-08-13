cmake_minimum_required(VERSION 3.2)
set( APP_NAME boteditor )
project(${APP_NAME} CXX)

set(CMAKE_CXX_STANDARD 14)
set( CMAKE_VERBOSE_MAKEFILE ON )
#set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-unused-result" )

set( CMAKE_BUILD_TYPE 1 )

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE RELEASE)
endif()

aux_source_directory( ${CMAKE_CURRENT_SOURCE_DIR}/src SRC )
aux_source_directory( ${CMAKE_CURRENT_SOURCE_DIR}/src/Dialog SRC )
aux_source_directory( ${CMAKE_CURRENT_SOURCE_DIR}/src/OperationDataModel SRC )
aux_source_directory( ${CMAKE_CURRENT_SOURCE_DIR}/src/StructModel SRC )
aux_source_directory( ${CMAKE_CURRENT_SOURCE_DIR}/src/windows SRC )


#set( SRC ${SRC}
#    ${CMAKE_CURRENT_SOURCE_DIR}/src/third_party/libscgi/parser.cpp
#    ${CMAKE_CURRENT_SOURCE_DIR}/src/third_party/libscgi/scgiServer.cpp)

set( LIBS
     )


# Find the QtWidgets library
find_package(Qt5 5.3 COMPONENTS
        Core
        Widgets
        Gui
        OpenGL)

# Target paceholder/nodeeditor
include(FetchContent)
FetchContent_Declare(nodes
        GIT_REPOSITORY git://github.com/nerosketch/nodeeditor.git
        GIT_TAG        origin/allow_dc
        )

FetchContent_GetProperties(nodes)
if(NOT nodes_POPULATED)
    FetchContent_Populate(nodes)
    add_subdirectory(${nodes_SOURCE_DIR} ${nodes_BINARY_DIR} EXCLUDE_FROM_ALL)
    set(LIBS ${LIBS} nodes )
endif()


qt5_add_resources(RESOURCES ./resources/resources.qrc)

set(CMAKE_AUTOMOC ON)

add_executable(${APP_NAME} ${SRC})

target_link_libraries( ${APP_NAME}
        ${LIBS} )


if (WIN32) #disable console mode for VC++
    set_target_properties( ${APP_NAME} PROPERTIES WIN32_EXECUTABLE TRUE )
endif(WIN32)
