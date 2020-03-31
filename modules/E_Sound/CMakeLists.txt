#
# This file is part of the E_Sound library.
# Copyright (C) 2010-2013 Benjamin Eikel <benjamin@eikel.org>
#
# This library is subject to the terms of the Mozilla Public License, v. 2.0.
# You should have received a copy of the MPL along with this library; see the 
# file LICENSE. If not, you can obtain one at http://mozilla.org/MPL/2.0/.
#
cmake_minimum_required(VERSION 3.1.0)
project(E_Sound VERSION 0.2.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set up install directories
include(GNUInstallDirs)
set(CMAKE_INSTALL_CMAKECONFIGDIR ${CMAKE_INSTALL_LIBDIR}/cmake/E_Sound)

add_library(E_Sound
	E_Buffer.cpp
	E_Listener.cpp
	E_Source.cpp
	ELibSound.cpp
)

# Dependency to EScript
if(NOT TARGET EScript)
	find_package(EScript 0.6.7 REQUIRED NO_MODULE)
endif()
target_link_libraries(E_Sound LINK_PUBLIC EScript)

# Dependency to Sound
if(NOT TARGET Sound)
	find_package(Sound 0.2.0 REQUIRED NO_MODULE)
endif()
target_link_libraries(E_Sound LINK_PUBLIC Sound)

# Dependency to Util
if(NOT TARGET Util)
	find_package(Util 0.2.0 REQUIRED NO_MODULE)
endif()
target_link_libraries(E_Sound LINK_PUBLIC Util)

# Set version of library
set_target_properties(E_Sound PROPERTIES VERSION ${E_Sound_VERSION}
                                         SOVERSION ${E_Sound_VERSION_MAJOR})

# Install the header files
file(GLOB E_SOUND_HEADERS "${CMAKE_CURRENT_SOURCE_DIR}/*.h")
install(FILES ${E_SOUND_HEADERS} DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/E_Sound COMPONENT headers)

# Install the library
install(TARGETS E_Sound EXPORT LibraryExport
	RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR} COMPONENT runtimelibraries
	LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR} COMPONENT runtimelibraries
	ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR} COMPONENT developmentlibraries
)

# Set include directories for users of this library
target_include_directories(E_Sound
                           INTERFACE
                           "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>"
                           "$<INSTALL_INTERFACE:$<INSTALL_PREFIX>/${CMAKE_INSTALL_INCLUDEDIR}>")

# Library export
install(EXPORT LibraryExport DESTINATION ${CMAKE_INSTALL_CMAKECONFIGDIR} FILE E_SoundTargets.cmake COMPONENT developmentlibraries)

# Create the configuration files
include(CMakePackageConfigHelpers)
configure_package_config_file(E_SoundConfig.cmake.in ${CMAKE_CURRENT_BINARY_DIR}/E_SoundConfig.cmake
                              INSTALL_DESTINATION ${CMAKE_INSTALL_CMAKECONFIGDIR}
                              PATH_VARS CMAKE_INSTALL_CMAKECONFIGDIR
                              NO_SET_AND_CHECK_MACRO
                              NO_CHECK_REQUIRED_COMPONENTS_MACRO)
write_basic_package_version_file(${CMAKE_CURRENT_BINARY_DIR}/E_SoundConfigVersion.cmake
                                 VERSION ${E_Sound_VERSION}
                                 COMPATIBILITY SameMajorVersion)

# Install the configuration files
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/E_SoundConfig.cmake ${CMAKE_CURRENT_BINARY_DIR}/E_SoundConfigVersion.cmake
        DESTINATION ${CMAKE_INSTALL_CMAKECONFIGDIR} COMPONENT developmentlibraries)

# Packaging
include(InstallRequiredSystemLibraries)

set(CPACK_PACKAGE_NAME "libsound${E_Sound_VERSION_MAJOR}-escript")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "E_Sound library")
set(CPACK_PACKAGE_VENDOR "Benjamin Eikel; Claudius Jaehn; Ralf Petring")
set(CPACK_PACKAGE_CONTACT "Benjamin Eikel <benjamin@eikel.org>")
set(CPACK_PACKAGE_VERSION_MAJOR ${E_Sound_VERSION_MAJOR})
set(CPACK_PACKAGE_VERSION_MINOR ${E_Sound_VERSION_MINOR})
set(CPACK_PACKAGE_VERSION_PATCH ${E_Sound_VERSION_PATCH})
set(CPACK_PACKAGE_FILE_NAME "libE_Sound")
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/LICENSE")
set(CPACK_STRIP_FILES ON)

include(CPack)
