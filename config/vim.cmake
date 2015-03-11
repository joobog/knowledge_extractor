

message(STATUS "loading knowledge_extractor paths")
set (CMAKE_BUILD_TYPE debug)
set (CMAKE_INSTALL_PREFIX "/scratch/pool/CIS/m215026/install/predictor")
set (Shogun_INCLUDEDIR = "/scratch/pool/CIS/m215026/install/shogun/usr/local/include" )
set (Shogun_LIBDIR "/scratch/pool/CIS/m215026/install/shogun/usr/local/lib" )
set (BOOST_ROOT "/scratch/pool/CIS/m215026/install/boost" )
set (BOOST_INCLUDEDIR "/scratch/pool/CIS/m215026/install/boost/include/" )
set (BOOST_LIBRARYDIR "/scratch/pool/CIS/m215026/install/boost/lib/" )
set (Boost_NO_SYSTEM_PATHS ON)

set ( INSTALL_ROOT_DIR "/scratch/pool/CIS/m215026/install/" )
set ( DEV_ROOT "/scratch/pool/CIS/m215026/" )
set ( Siox_ROOT_DIR "${INSTALL_ROOT_DIR}/siox" )
set ( Siox_DEV_ROOT_DIR "${DEV_ROOT}/git/deps/cache_siox/siox-dev" )
set ( Siox_INCLUDE_DIR "${Siox_ROOT_DIR}/include" )
set ( Siox_LIBRARY_DIR "${Siox_ROOT_DIR}/lib" )
