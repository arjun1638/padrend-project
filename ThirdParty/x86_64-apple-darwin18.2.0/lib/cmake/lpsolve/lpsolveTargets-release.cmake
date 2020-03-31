#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "lpsolve55" for configuration "Release"
set_property(TARGET lpsolve55 APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(lpsolve55 PROPERTIES
  IMPORTED_LINK_INTERFACE_LIBRARIES_RELEASE "m;dl"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/liblpsolve55.5.5.2.dylib"
  IMPORTED_SONAME_RELEASE "liblpsolve55.5.dylib"
  )

list(APPEND _IMPORT_CHECK_TARGETS lpsolve55 )
list(APPEND _IMPORT_CHECK_FILES_FOR_lpsolve55 "${_IMPORT_PREFIX}/lib/liblpsolve55.5.5.2.dylib" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
