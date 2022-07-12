cmake_minimum_required(VERSION 3.12)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(GNUInstallDirs)

set(HEADERS 
	include/scratchbase.h
	include/database.h
	include/extensions/extdatabase.h
	include/extensions/highwayhash.h
)

add_library(scratchbase 
	${HEADERS}
	src/database.cpp
	src/filekeyvaluestore.cpp
	src/scratchbase.cpp
	src/highwayhash.cpp
	src/memorykeyvaluestore.cpp
)

set_target_properties(scratchbase PROPERTIES PUBLIC_HEADER "${HEADERS}")

# NB: this assumes google's highwayhash is available as a sub-module of this repo..
include_directories(${scratchbase_SOURCE_DIR}/highwayhash)
# use this version if you have highwayhash as a peer module outside this repo..
#include_directories(${scratchbase_SOURCE_DIR}/../highwayhash)

target_include_directories(scratchbase 
	PUBLIC 
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
	$<INSTALL_INTERFACE:include>
)

target_compile_features(scratchbase PRIVATE cxx_std_17)

# NB: This is here to ensure binaries that link us also link stdc++fs for non-Apple targets
# https://github.com/OpenRCT2/OpenRCT2/pull/10522
if(NOT (APPLE OR MSVC) )
target_link_libraries(scratchbase PRIVATE stdc++fs)
endif(NOT (APPLE OR MSVC) )

install(TARGETS scratchbase 
    EXPORT scratchbase
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}  
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR} 
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/scratchbase
)

install(EXPORT scratchbase 
	NAMESPACE scratchbase::
	DESTINATION ${CMAKE_INSTALL_LIBDIR}/scratchbase
)
