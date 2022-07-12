include_directories(${scratchbase_SOURCE_DIR})
include_directories(${scratchbase_SOURCE_DIR}/../highwayhash)

add_executable(003a-hashing-benefits 003a-hashing-benefits/main.cpp)
set_property(TARGET 003a-hashing-benefits PROPERTY FOLDER Samples)
target_compile_features(003a-hashing-benefits PRIVATE cxx_std_17)
install(TARGETS 003a-hashing-benefits
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR} 
)
