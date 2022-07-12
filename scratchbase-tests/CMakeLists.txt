cmake_minimum_required(VERSION 3.12)

add_executable(scratchbase-tests
	dbmanagement-tests.cpp
	hashing-tests.cpp
	keyvalue-tests.cpp
	performance-tests.cpp
)

include_directories(${scratchbase_SOURCE_DIR})

# This assume highwayhash is a sub-module of this repo..
include_directories(${scratchbase_SOURCE_DIR}/highwayhash)
# if you have built highwayhash as a peer repo, use this line
#include_directories(${scratchbase_SOURCE_DIR}/../highwayhash)

target_link_libraries(scratchbase-tests PRIVATE scratchbase)

target_compile_features(scratchbase-tests PRIVATE cxx_std_17)
