#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "Detri" for configuration "Release"
set_property(TARGET Detri APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(Detri PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libDetri.2.6.b.dylib"
  IMPORTED_SONAME_RELEASE "libDetri.2.dylib"
  )

list(APPEND _IMPORT_CHECK_TARGETS Detri )
list(APPEND _IMPORT_CHECK_FILES_FOR_Detri "${_IMPORT_PREFIX}/lib/libDetri.2.6.b.dylib" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
