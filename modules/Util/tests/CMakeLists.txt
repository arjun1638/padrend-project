#
# This file is part of the Util library.
# Copyright (C) 2011-2015 Benjamin Eikel <benjamin@eikel.org>
#
# This library is subject to the terms of the Mozilla Public License, v. 2.0.
# You should have received a copy of the MPL along with this library; see the 
# file LICENSE. If not, you can obtain one at http://mozilla.org/MPL/2.0/.
#
cmake_minimum_required(VERSION 3.1.0)

if(UTIL_BUILD_TESTS)
	add_executable(UtilTest 
		BidirectionalMapTest.cpp
		EncodingTest.cpp
		FactoryTest.cpp
		FileUtilsTest.cpp
		GenericAttributeSerializationTest.cpp
		GenericAttributeTest.cpp
		GenericConversionTest.cpp
		GenericTest.cpp
		NetworkTest.cpp
		RegistryTest.cpp
		StringUtilsTest.cpp
		TimerTest.cpp
		TriStateTest.cpp
		UpdatableHeapTest.cpp
		WrapperFactoryTest.cpp
		ZIPTest.cpp
		UtilTestMain.cpp
	)

	target_link_libraries(UtilTest PRIVATE Util)

	# Dependency to CppUnit
	set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_LIST_DIR}/cmake)
	find_package(CppUnit REQUIRED)
	target_include_directories(UtilTest PRIVATE ${CPPUNIT_INCLUDE_DIRS})
	target_link_libraries(UtilTest PRIVATE ${CPPUNIT_LIBRARIES})

	# Dependency to pthread
	set(CMAKE_THREAD_PREFER_PTHREAD ON)
	find_package(Threads)
	if(CMAKE_USE_PTHREADS_INIT AND (NOT DEFINED XCODE_VERSION OR XCODE_VERSION LESS 5.0))
		target_link_libraries(UtilTest PRIVATE ${CMAKE_THREAD_LIBS_INIT})
	endif()

	install(TARGETS UtilTest
		RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR} COMPONENT tests
		LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR} COMPONENT tests
		ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR} COMPONENT tests
	)

	add_test(NAME BidirectionalUnorderedMapTest COMMAND UtilTest BidirectionalUnorderedMapTest)
	add_test(NAME EncodingTest COMMAND UtilTest EncodingTest)
	add_test(NAME FactoryTest COMMAND UtilTest FactoryTest)
	add_test(NAME FileUtilsTest COMMAND UtilTest FileUtilsTest)
	add_test(NAME GenericAttributeSerializationTest COMMAND UtilTest GenericAttributeSerializationTest)
	add_test(NAME GenericAttributeTest COMMAND UtilTest GenericAttributeTest)
	add_test(NAME GenericConversionTest COMMAND UtilTest GenericConversionTest)
	add_test(NAME GenericTest COMMAND UtilTest GenericTest)
	add_test(NAME NetworkTest COMMAND UtilTest NetworkTest)
	add_test(NAME RegistryTest COMMAND UtilTest RegistryTest)
	add_test(NAME StringUtilsTest COMMAND UtilTest StringUtilsTest)
	add_test(NAME TimerTest COMMAND UtilTest TimerTest)
	add_test(NAME TriStateTest COMMAND UtilTest TriStateTest)
	add_test(NAME UpdatableHeapTest COMMAND UtilTest UpdatableHeapTest)
	add_test(NAME WrapperFactoryTest COMMAND UtilTest WrapperFactoryTest)
	add_test(NAME ZIPTest COMMAND UtilTest ZIPTest)
endif()
