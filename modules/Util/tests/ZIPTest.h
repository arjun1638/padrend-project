/*
	This file is part of the Util library.
	Copyright (C) 2011 Benjamin Eikel <benjamin@eikel.org>
	
	This library is subject to the terms of the Mozilla Public License, v. 2.0.
	You should have received a copy of the MPL along with this library; see the 
	file LICENSE. If not, you can obtain one at http://mozilla.org/MPL/2.0/.
*/
#ifndef ZIPTEST_H_
#define ZIPTEST_H_

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>

class ZIPTest : public CppUnit::TestFixture {
	CPPUNIT_TEST_SUITE(ZIPTest);
	CPPUNIT_TEST(test);
	CPPUNIT_TEST_SUITE_END();

	public:
		void test();
};

#endif /* ZIPTEST_H_ */
