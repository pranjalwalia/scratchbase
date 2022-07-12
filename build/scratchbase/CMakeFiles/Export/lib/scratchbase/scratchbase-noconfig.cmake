#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "scratchbase::scratchbase" for configuration ""
set_property(TARGET scratchbase::scratchbase APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(scratchbase::scratchbase PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_NOCONFIG "CXX"
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/libscratchbase.a"
  )

list(APPEND _IMPORT_CHECK_TARGETS scratchbase::scratchbase )
list(APPEND _IMPORT_CHECK_FILES_FOR_scratchbase::scratchbase "${_IMPORT_PREFIX}/lib/libscratchbase.a" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
