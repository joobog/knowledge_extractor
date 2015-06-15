cmake_minimum_required ( VERSION 2.8 )
project ( KnowledgeExtractor )
#set( CMAKE_VERBOSE_MAKEFILE on )

set ( KnowledgeExtractor_VERSION_MAJOR 1 )
set ( KnowledgeExtractor_VERSION_MINOR 0 )


#set ( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x -static-libstdc++ -static -lstdc++ )
#set ( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -stdlib=libstdc++"  )
#set ( CMAKE_CXX_FLAGS "-I/sw/squeeze-x64/gcc/gcc-4.9.2/include -I/sw/squeeze-x64/gcc/gcc-4.9.2/include/c++/4.9.2 ${CMAKE_CXX_FLAGS}" )
if(EXISTS "${PROJECT_SOURCE_DIR}/config/vim.cmake")
	include (${PROJECT_SOURCE_DIR}/config/vim.cmake)
endif()
include (${PROJECT_SOURCE_DIR}/config/macros.cmake)

set ( CMAKE_CXX_FLAGS "-std=c++11 -g"  )

# Locations for compiled libraries and binaries
set ( LIBRARY_OUTPUT_PATH "${CMAKE_BINARY_DIR}/lib" )
set ( EXECUTABLE_OUTPUT_PATH "${CMAKE_BINARY_DIR}/bin" )

include_directories (
	"${Siox_INCLUDE_DIR}"
	"${PROJECT_SOURCE_DIR}/src"
	)

link_directories (
	${Siox_LIBRARY_DIR}
	${Boost_LIBRARY_DIR}
	${Predictor_LIBRARY_DIR}
	)

find_package(Boost 1.55.0 REQUIRED COMPONENTS serialization)
find_package(PythonInterp 2.7 REQUIRED)

# TODO
#find_package(Siox REQUIRED) 

set (KE_INSTALL_LIBRARY_DIR lib${LIBRARY_INSTALL_SUFFIX})

add_subdirectory(src)
