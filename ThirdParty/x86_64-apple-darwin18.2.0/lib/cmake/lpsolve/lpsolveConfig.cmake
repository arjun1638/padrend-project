# - Configuration file for the lpsolve library
# It defines the target "lpsolve55".
#

####### Expanded from @PACKAGE_INIT@ by configure_package_config_file() #######
####### Any changes to this file will be overwritten by the next CMake run ####
####### The input file was lpsolveConfig.cmake.in                            ########

get_filename_component(PACKAGE_PREFIX_DIR "${CMAKE_CURRENT_LIST_DIR}/../../../" ABSOLUTE)

####################################################################################

# Import the exported targets
include("${PACKAGE_PREFIX_DIR}/lib/cmake/lpsolve/lpsolveTargets.cmake")
