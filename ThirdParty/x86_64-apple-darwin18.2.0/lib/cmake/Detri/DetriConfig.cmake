# Configuration file for the Detri library
# It defines the following variables:
#  DETRI_INCLUDE_DIR - include directories for Detri
#  DETRI_LIBRARIES - libraries to link against Detri

# Set the version of Detri
set(DETRI_VERSION_MAJOR 2)
set(DETRI_VERSION_MINOR 6)
set(DETRI_VERSION_PATCH b)
set(DETRI_VERSION ${DETRI_VERSION_MAJOR}.${DETRI_VERSION_MINOR}.${DETRI_VERSION_PATCH})


####### Expanded from @PACKAGE_INIT@ by configure_package_config_file() #######
####### Any changes to this file will be overwritten by the next CMake run ####
####### The input file was DetriConfig.cmake.in                            ########

get_filename_component(PACKAGE_PREFIX_DIR "${CMAKE_CURRENT_LIST_DIR}/../../../" ABSOLUTE)

macro(set_and_check _var _file)
  set(${_var} "${_file}")
  if(NOT EXISTS "${_file}")
    message(FATAL_ERROR "File or directory ${_file} referenced by variable ${_var} does not exist !")
  endif()
endmacro()

####################################################################################

# Set the include directory
set_and_check(DETRI_INCLUDE_DIR "${PACKAGE_PREFIX_DIR}/include/Detri")

# Import the exported targets
include("${PACKAGE_PREFIX_DIR}/lib/cmake/Detri/DetriTargets.cmake")

# Set the library variable
set(DETRI_LIBRARIES Detri)
