cmake_minimum_required ( VERSION 2.8 )
project ( KnowledgeExtractor )

set ( KnowledgeExtractor_VERSION_MAJOR 1 )
set ( KnowledgeExtractor_VERSION_MINOR 0 )

set ( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x -g -gdwarf-2" )

if ( EXISTS "${PROJECT_SOURCE_DIR}/config/vim.cmake" )
	include (${PROJECT_SOURCE_DIR}/config/vim.cmake)
endif()
include (${PROJECT_SOURCE_DIR}/config/macros.cmake)

# Locations for compiled libraries and binaries
set ( LIBRARY_OUTPUT_PATH "${CMAKE_BINARY_DIR}/lib" )
set ( EXECUTABLE_OUTPUT_PATH "${CMAKE_BINARY_DIR}/bin" )

find_package(Boost 1.55.0 REQUIRED COMPONENTS serialization)
find_package(PythonInterp 2.7 REQUIRED)

# TODO
#find_package(Siox REQUIRED) 

set (KE_INSTALL_LIBRARY_DIR lib${LIBRARY_INSTALL_SUFFIX})

add_subdirectory(src)
add_subdirectory(tools)
