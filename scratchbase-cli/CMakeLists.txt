cmake_minimum_required(VERSION 3.12)

add_executable(scratchbase-cli main.cpp)

target_link_libraries(scratchbase-cli PRIVATE scratchbase)

target_compile_features(scratchbase-cli PRIVATE cxx_std_17)

include_directories(${scratchbase_SOURCE_DIR})

install(TARGETS scratchbase-cli
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR} 
)
