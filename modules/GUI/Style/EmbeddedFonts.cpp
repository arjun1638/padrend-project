/*
	This file is part of the GUI library.
	Copyright (C) 2008-2012 Benjamin Eikel <benjamin@eikel.org>
	Copyright (C) 2008-2012 Claudius Jähn <claudius@uni-paderborn.de>
	Copyright (C) 2008-2012 Ralf Petring <ralf@petring.net>
	
	This library is subject to the terms of the Mozilla Public License, v. 2.0.
	You should have received a copy of the MPL along with this library; see the 
	file LICENSE. If not, you can obtain one at http://mozilla.org/MPL/2.0/.
*/
#include "EmbeddedFonts.h"
#include "../Base/Fonts/BitmapFont.h"
#include <Util/Graphics/Bitmap.h>
#include <Util/Graphics/BitmapUtils.h>
#include <Util/Graphics/PixelFormat.h>

namespace GUI{

//! (static)
BitmapFont * EmbeddedFonts::createFont(){
// resources/Fonts/pf_tempesta_seven_condensed.fnt
	static const uint8_t bitmapData [] = {
		 0x60, 0x8d, 0x11, 0x8a, 0x21, 0x8, 0xc4, 0x11, 0x8, 0x42, 0x98, 0xc4, 0x91, 0x16, 0x22, 0x54, 0x42, 0x11, 0x22, 0x20, 0x84, 0x25, 0x25, 0x28, 0x60, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
		 0x0, 0x0, 0x0, 0x0, 0x4, 0x51, 0x4b, 0xcc, 0xf4, 0x99, 0x26, 0x33, 0xd2, 0x63, 0x18, 0xc8, 0x62, 0x99, 0x4a, 0x12, 0x84, 0xa5, 0x29, 0x4a, 0x12, 0x94, 0xa5, 0x28, 0x92, 0x95, 0x4a, 0x12,
		 0x84, 0xa5, 0x29, 0x4a, 0x12, 0x94, 0xa5, 0x28, 0x91, 0x15, 0x4b, 0x9e, 0xe4, 0xa5, 0x29, 0x7b, 0x92, 0xf4, 0xbd, 0x28, 0xf1, 0x15, 0x4a, 0x12, 0x83, 0xa5, 0x29, 0x4a, 0x12, 0x94, 0xa5, 0x28,
		 0x91, 0x13, 0x4a, 0x12, 0x80, 0xa5, 0x29, 0x4a, 0x12, 0x94, 0xa5, 0x28, 0x91, 0x11, 0x33, 0xd2, 0xf3, 0x18, 0xc6, 0x4b, 0xcc, 0x93, 0x24, 0xc8, 0x90, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
		 0x0, 0x0, 0x0, 0x0, 0x0, 0x3, 0xc1, 0xe0, 0x87, 0xa4, 0xc8, 0x31, 0xd2, 0x94, 0xa4, 0x50, 0x87, 0x84, 0x22, 0x11, 0xee, 0x81, 0x2e, 0x4a, 0x0, 0x0, 0x0, 0x88, 0x48, 0x49, 0xd4, 0xca,
		 0x8e, 0xa4, 0xc9, 0x22, 0x1e, 0x63, 0x24, 0x88, 0x17, 0x2a, 0x14, 0x2a, 0x8e, 0xa4, 0x9, 0x52, 0x10, 0x94, 0xa4, 0x88, 0x94, 0xaa, 0x14, 0xe9, 0xc6, 0xa4, 0xc9, 0x4a, 0x10, 0x94, 0xa5, 0x4,
		 0x97, 0x2a, 0x15, 0x28, 0xa2, 0xa4, 0x29, 0x2a, 0x1c, 0x97, 0xa4, 0x88, 0x94, 0xa9, 0x94, 0xe8, 0xa2, 0xa4, 0xe9, 0x11, 0xd0, 0x94, 0x9c, 0x88, 0x94, 0xa4, 0x62, 0x13, 0xc2, 0xa5, 0x2e, 0x48,
		 0x90, 0x94, 0x84, 0x88, 0x88, 0x43, 0xc1, 0xc0, 0x82, 0x98, 0xe8, 0x31, 0x1e, 0x64, 0x98, 0x50, 0x87, 0x80, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x80, 0x5, 0x57, 0x18,
		 0x44, 0x29, 0x8c, 0x22, 0x14, 0x86, 0x11, 0x4c, 0xa, 0x61, 0x14, 0xa4, 0x82, 0x52, 0x52, 0x41, 0x28, 0x49, 0x22, 0x92, 0xd1, 0x29, 0x54, 0x80, 0x0, 0x0, 0x12, 0x0, 0x0, 0x0, 0x0, 0x0,
		 0x91, 0x29, 0x55, 0x25, 0x29, 0x31, 0x92, 0x63, 0x38, 0xc6, 0x31, 0x8c, 0x91, 0x28, 0x54, 0xa5, 0x29, 0x4a, 0x52, 0x94, 0xa5, 0x29, 0x48, 0x42, 0x91, 0x29, 0x54, 0xa5, 0x29, 0x4a, 0x52, 0x94,
		 0xa5, 0xef, 0x79, 0xce, 0x91, 0x29, 0x55, 0x25, 0x29, 0x4a, 0x4c, 0x94, 0xa5, 0x8, 0x42, 0x52, 0x91, 0x29, 0x54, 0x1c, 0xe7, 0x31, 0x82, 0x63, 0x24, 0xc6, 0x31, 0xce, 0x91, 0x29, 0x50, 0x0,
		 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x8a, 0x60, 0x0, 0x6, 0x8, 0xc2, 0x1f, 0x91, 0x22, 0xa, 0x28, 0x22, 0xc0, 0x2, 0xb0, 0x81, 0x10, 0x44, 0x24, 0x2a, 0x14, 0x11, 0x44, 0x32,
		 0x2, 0x24, 0x11, 0x2, 0x12, 0x44, 0xa4, 0x12, 0x8, 0x11, 0x44, 0x2a, 0x21, 0x10, 0x91, 0x61, 0x26, 0x49, 0xbf, 0x4, 0x3e, 0x20, 0x82, 0x2a, 0x40, 0x4, 0x92, 0x16, 0x4a, 0x52, 0xa4, 0x9,
		 0x8, 0x40, 0x81, 0x2a, 0x3, 0x24, 0x94, 0x20, 0x4e, 0x13, 0xa4, 0xa, 0xbe, 0x40, 0x81, 0x26, 0x60, 0xa4, 0x84, 0x40, 0x82, 0x20, 0xa7, 0x91, 0x8, 0x80, 0x80, 0xa2, 0x13, 0xa4, 0x88, 0x70,
		 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x74, 0xa4, 0x80, 0x2, 0x25, 0x38, 0xe9, 0x4b, 0xd0, 0x13, 0xa1, 0x2, 0x93, 0xa0, 0x3e, 0x73, 0x65, 0x25, 0x9, 0x48, 0x50, 0x14, 0xa1, 0x4,
		 0x70, 0x0, 0x8, 0x4a, 0xaf, 0xa5, 0x9, 0x48, 0x9c, 0x74, 0xb9, 0x2e, 0x1, 0xa8, 0x88, 0x4a, 0x25, 0x38, 0xc9, 0x31, 0x12, 0x94, 0xa5, 0x44, 0xaa, 0x48, 0x88, 0xea, 0x2f, 0xa4, 0x29, 0x49,
		 0x12, 0x93, 0xa5, 0x84, 0xaa, 0x45, 0x8, 0x4a, 0x25, 0x24, 0x29, 0x4a, 0x12, 0x90, 0xa5, 0x44, 0xaa, 0xa5, 0x8, 0x4a, 0x25, 0x25, 0xc6, 0x4b, 0xdc, 0x73, 0x25, 0x24, 0xa9, 0x25, 0x8, 0x70,
		 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xa9, 0x22, 0x0, 0x0, 0x8c, 0x67, 0x38, 0x4f, 0x49, 0x8e, 0x63, 0x24, 0xaa, 0xc2, 0x22, 0x18, 0x10, 0x90, 0x84, 0xc8, 0x2, 0x10, 0x94, 0x80,
		 0x50, 0x0, 0x7, 0x20, 0x90, 0x90, 0x85, 0x48, 0x32, 0x10, 0x94, 0x98, 0x0, 0x25, 0xea, 0x21, 0xa, 0x93, 0x19, 0x4e, 0xb, 0x90, 0x63, 0xa4, 0xe3, 0xa4, 0x2a, 0x72, 0x14, 0x94, 0x5, 0xe1,
		 0x3a, 0x4e, 0x90, 0xbc, 0x94, 0xa4, 0x4a, 0x22, 0x14, 0x94, 0x4, 0x41, 0x4a, 0x44, 0x90, 0xa0, 0x94, 0xa4, 0x47, 0x21, 0xca, 0x67, 0xb8, 0x4e, 0x39, 0x88, 0x63, 0x18, 0x94, 0x9c, 0x42, 0x78,
		 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xe3, 0x84, 0x80, 0x3, 0xde, 0x93, 0xa5, 0x29, 0x32, 0x1c, 0x82, 0xca, 0x80, 0x98, 0x87, 0x72, 0x10, 0x4, 0x25, 0x40, 0x4b, 0x92, 0x82, 0x42,
		 0x80, 0x80, 0x8, 0x4a, 0x10, 0x64, 0x25, 0x49, 0x4a, 0x52, 0x82, 0x52, 0x0, 0x5, 0xc8, 0x4b, 0x9c, 0x95, 0xbd, 0x89, 0x4a, 0x5c, 0x82, 0x52, 0xe3, 0x1d, 0x28, 0x4a, 0x10, 0x94, 0xa5, 0x49,
		 0x4a, 0x50, 0x82, 0x52, 0x14, 0x85, 0x28, 0x4a, 0x10, 0x94, 0xa5, 0x49, 0x4b, 0x90, 0x82, 0x52, 0x14, 0x9d, 0xc8, 0x4b, 0xd0, 0x63, 0xa5, 0x27, 0x32, 0x10, 0xec, 0x52, 0x27, 0xa5, 0x27, 0x70,
		 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x44, 0xa5, 0x20, 0x1, 0xb0, 0x94, 0x88, 0xaa, 0x21, 0xa2, 0x22, 0x22, 0x4, 0x9d, 0xcb, 0xb0, 0x49, 0x22, 0x47, 0x2a, 0x2, 0x4f, 0x94, 0x20,
		 0x44, 0x80, 0x2, 0x49, 0xfa, 0x41, 0x25, 0x2a, 0xfa, 0xa2, 0x8, 0xf8, 0x0, 0x24, 0x8a, 0x4a, 0x41, 0x22, 0x47, 0x2a, 0x1, 0x20, 0x14, 0x20, 0xaa, 0xa5, 0xc2, 0x49, 0xb0, 0x94, 0x88, 0x94,
		 0x22, 0xcf, 0xa2, 0x22, 0x22, 0x24, 0x82, 0x48, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xaa, 0xa4, 0x80, 0x1, 0xc9, 0x49, 0xd9, 0x85, 0x1d, 0xdb, 0x93, 0x92, 0xaa, 0xbc, 0x8a, 0x99,
		 0x29, 0x4a, 0x4, 0x48, 0x85, 0x8, 0xa8, 0x2a, 0xaa, 0xa0, 0xd2, 0xa5, 0x29, 0x49, 0x88, 0x90, 0x49, 0x8, 0x93, 0x90, 0x8a, 0x80, 0x0, 0x25, 0x29, 0x48, 0x50, 0x48, 0x91, 0x8, 0x0, 0x0,
		 0xaa, 0x8e, 0x64, 0xa5, 0x26, 0x3b, 0x9d, 0x85, 0x1d, 0x8, 0x0, 0x0, 0x0, 0x10, 0x14, 0x98, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x21, 0x90, 0x73, 0x0, 0x77, 0x0, 0x0, 0x0,
		 0x0, 0x0, 0x0, 0x0, 0xaa, 0x50, 0x94, 0x85, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x73, 0xce, 0x74, 0x80, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xaa, 0x0, 0x0, 0x0,
		 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x21, 0x82, 0x51, 0x70, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x4, 0x8a, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
		 0x65, 0x20, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xaa, 0x50, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xe0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
		 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
		 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
		 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
		 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
		 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
	};
	Util::Reference<Util::Bitmap> bitmap = Util::BitmapUtils::createBitmapFromBitMask(96,96,Util::PixelFormat::RGBA,sizeof(bitmapData),bitmapData);
	Util::Reference<BitmapFont> font = new BitmapFont(new ImageData(bitmap.get()),13);
	font->addGlyph(32,1,1,Geometry::Vec2i(41,74),Geometry::Vec2i(0,10), 3);
	font->addGlyph(33,1,7,Geometry::Vec2i(2,66),Geometry::Vec2i(0,2), 2);
	font->addGlyph(34,3,2,Geometry::Vec2i(22,69),Geometry::Vec2i(0,2), 4);
	font->addGlyph(35,5,7,Geometry::Vec2i(36,38),Geometry::Vec2i(0,2), 6);
	font->addGlyph(36,5,9,Geometry::Vec2i(30,11),Geometry::Vec2i(0,1), 6);
	font->addGlyph(37,7,7,Geometry::Vec2i(58,30),Geometry::Vec2i(0,2), 8);
	font->addGlyph(38,4,7,Geometry::Vec2i(35,46),Geometry::Vec2i(0,2), 5);
	font->addGlyph(39,1,2,Geometry::Vec2i(94,68),Geometry::Vec2i(0,2), 2);
	font->addGlyph(40,2,9,Geometry::Vec2i(3,22),Geometry::Vec2i(0,1), 3);
	font->addGlyph(41,2,9,Geometry::Vec2i(6,22),Geometry::Vec2i(0,1), 3);
	font->addGlyph(42,5,5,Geometry::Vec2i(0,74),Geometry::Vec2i(0,3), 6);
	font->addGlyph(43,5,5,Geometry::Vec2i(88,62),Geometry::Vec2i(0,3), 6);
	font->addGlyph(44,2,2,Geometry::Vec2i(13,78),Geometry::Vec2i(0,8), 3);
	font->addGlyph(45,3,1,Geometry::Vec2i(37,74),Geometry::Vec2i(0,6), 4);
	font->addGlyph(46,1,1,Geometry::Vec2i(18,47),Geometry::Vec2i(1,8), 3);
	font->addGlyph(47,5,7,Geometry::Vec2i(72,30),Geometry::Vec2i(0,2), 6);
	font->addGlyph(48,4,7,Geometry::Vec2i(40,46),Geometry::Vec2i(0,2), 5);
	font->addGlyph(49,2,7,Geometry::Vec2i(88,54),Geometry::Vec2i(0,2), 3);
	font->addGlyph(50,4,7,Geometry::Vec2i(45,46),Geometry::Vec2i(0,2), 5);
	font->addGlyph(51,4,7,Geometry::Vec2i(50,46),Geometry::Vec2i(0,2), 5);
	font->addGlyph(52,4,7,Geometry::Vec2i(55,46),Geometry::Vec2i(0,2), 5);
	font->addGlyph(53,4,7,Geometry::Vec2i(60,46),Geometry::Vec2i(0,2), 5);
	font->addGlyph(54,4,7,Geometry::Vec2i(70,46),Geometry::Vec2i(0,2), 5);
	font->addGlyph(55,4,7,Geometry::Vec2i(15,49),Geometry::Vec2i(0,2), 5);
	font->addGlyph(56,4,7,Geometry::Vec2i(80,46),Geometry::Vec2i(0,2), 5);
	font->addGlyph(57,4,7,Geometry::Vec2i(85,46),Geometry::Vec2i(0,2), 5);
	font->addGlyph(58,1,5,Geometry::Vec2i(94,62),Geometry::Vec2i(1,4), 3);
	font->addGlyph(59,2,6,Geometry::Vec2i(19,65),Geometry::Vec2i(0,4), 3);
	font->addGlyph(60,3,5,Geometry::Vec2i(59,68),Geometry::Vec2i(0,3), 4);
	font->addGlyph(61,3,3,Geometry::Vec2i(86,68),Geometry::Vec2i(0,4), 4);
	font->addGlyph(62,3,5,Geometry::Vec2i(63,68),Geometry::Vec2i(0,3), 4);
	font->addGlyph(63,4,7,Geometry::Vec2i(0,58),Geometry::Vec2i(0,2), 5);
	font->addGlyph(64,8,9,Geometry::Vec2i(21,11),Geometry::Vec2i(0,1), 9);
	font->addGlyph(65,4,7,Geometry::Vec2i(5,58),Geometry::Vec2i(0,2), 5);
	font->addGlyph(66,4,7,Geometry::Vec2i(15,57),Geometry::Vec2i(0,2), 5);
	font->addGlyph(67,4,7,Geometry::Vec2i(20,55),Geometry::Vec2i(0,2), 5);
	font->addGlyph(68,4,7,Geometry::Vec2i(25,55),Geometry::Vec2i(0,2), 5);
	font->addGlyph(69,4,7,Geometry::Vec2i(30,54),Geometry::Vec2i(0,2), 5);
	font->addGlyph(70,4,7,Geometry::Vec2i(35,54),Geometry::Vec2i(0,2), 5);
	font->addGlyph(71,4,7,Geometry::Vec2i(45,54),Geometry::Vec2i(0,2), 5);
	font->addGlyph(72,4,7,Geometry::Vec2i(50,54),Geometry::Vec2i(0,2), 5);
	font->addGlyph(73,1,7,Geometry::Vec2i(6,66),Geometry::Vec2i(0,2), 2);
	font->addGlyph(74,3,7,Geometry::Vec2i(84,54),Geometry::Vec2i(0,2), 4);
	font->addGlyph(75,4,7,Geometry::Vec2i(55,54),Geometry::Vec2i(0,2), 5);
	font->addGlyph(76,3,7,Geometry::Vec2i(80,54),Geometry::Vec2i(0,2), 4);
	font->addGlyph(77,5,7,Geometry::Vec2i(30,38),Geometry::Vec2i(0,2), 6);
	font->addGlyph(78,5,7,Geometry::Vec2i(90,30),Geometry::Vec2i(0,2), 6);
	font->addGlyph(79,4,7,Geometry::Vec2i(65,54),Geometry::Vec2i(0,2), 5);
	font->addGlyph(80,4,7,Geometry::Vec2i(75,54),Geometry::Vec2i(0,2), 5);
	font->addGlyph(81,4,8,Geometry::Vec2i(51,21),Geometry::Vec2i(0,2), 5);
	font->addGlyph(82,4,7,Geometry::Vec2i(42,38),Geometry::Vec2i(0,2), 5);
	font->addGlyph(83,4,7,Geometry::Vec2i(47,38),Geometry::Vec2i(0,2), 5);
	font->addGlyph(84,5,7,Geometry::Vec2i(18,39),Geometry::Vec2i(0,2), 6);
	font->addGlyph(85,4,7,Geometry::Vec2i(52,38),Geometry::Vec2i(0,2), 5);
	font->addGlyph(86,5,7,Geometry::Vec2i(12,41),Geometry::Vec2i(0,2), 6);
	font->addGlyph(87,5,7,Geometry::Vec2i(0,42),Geometry::Vec2i(0,2), 6);
	font->addGlyph(88,4,7,Geometry::Vec2i(57,38),Geometry::Vec2i(0,2), 5);
	font->addGlyph(89,5,7,Geometry::Vec2i(78,30),Geometry::Vec2i(0,2), 6);
	font->addGlyph(90,4,7,Geometry::Vec2i(62,38),Geometry::Vec2i(0,2), 5);
	font->addGlyph(91,2,9,Geometry::Vec2i(0,23),Geometry::Vec2i(0,1), 3);
	font->addGlyph(92,5,7,Geometry::Vec2i(84,30),Geometry::Vec2i(0,2), 6);
	font->addGlyph(93,2,9,Geometry::Vec2i(9,22),Geometry::Vec2i(0,1), 3);
	font->addGlyph(94,3,2,Geometry::Vec2i(9,80),Geometry::Vec2i(0,2), 4);
	font->addGlyph(95,3,1,Geometry::Vec2i(25,78),Geometry::Vec2i(0,8), 4);
	font->addGlyph(96,2,2,Geometry::Vec2i(19,78),Geometry::Vec2i(0,-1), 3);
	font->addGlyph(97,4,5,Geometry::Vec2i(16,72),Geometry::Vec2i(0,4), 5);
	font->addGlyph(98,4,7,Geometry::Vec2i(67,38),Geometry::Vec2i(0,2), 5);
	font->addGlyph(99,4,5,Geometry::Vec2i(11,72),Geometry::Vec2i(0,4), 5);
	font->addGlyph(100,4,7,Geometry::Vec2i(72,38),Geometry::Vec2i(0,2), 5);
	font->addGlyph(101,4,5,Geometry::Vec2i(6,74),Geometry::Vec2i(0,4), 5);
	font->addGlyph(102,3,7,Geometry::Vec2i(92,38),Geometry::Vec2i(0,2), 4);
	font->addGlyph(103,4,7,Geometry::Vec2i(77,38),Geometry::Vec2i(0,4), 5);
	font->addGlyph(104,4,7,Geometry::Vec2i(82,38),Geometry::Vec2i(0,2), 5);
	font->addGlyph(105,1,7,Geometry::Vec2i(0,66),Geometry::Vec2i(0,2), 2);
	font->addGlyph(106,1,8,Geometry::Vec2i(16,31),Geometry::Vec2i(0,2), 2);
	font->addGlyph(107,4,7,Geometry::Vec2i(87,38),Geometry::Vec2i(0,2), 5);
	font->addGlyph(108,1,7,Geometry::Vec2i(94,54),Geometry::Vec2i(0,2), 2);
	font->addGlyph(109,7,5,Geometry::Vec2i(22,63),Geometry::Vec2i(0,4), 8);
	font->addGlyph(110,4,5,Geometry::Vec2i(31,68),Geometry::Vec2i(0,4), 5);
	font->addGlyph(111,4,5,Geometry::Vec2i(26,69),Geometry::Vec2i(0,4), 5);
	font->addGlyph(112,4,7,Geometry::Vec2i(0,50),Geometry::Vec2i(0,4), 5);
	font->addGlyph(113,4,7,Geometry::Vec2i(5,50),Geometry::Vec2i(0,4), 5);
	font->addGlyph(114,3,5,Geometry::Vec2i(71,68),Geometry::Vec2i(0,4), 4);
	font->addGlyph(115,4,5,Geometry::Vec2i(46,68),Geometry::Vec2i(0,4), 5);
	font->addGlyph(116,3,6,Geometry::Vec2i(15,65),Geometry::Vec2i(0,3), 4);
	font->addGlyph(117,4,5,Geometry::Vec2i(41,68),Geometry::Vec2i(0,4), 5);
	font->addGlyph(118,4,5,Geometry::Vec2i(36,68),Geometry::Vec2i(0,4), 5);
	font->addGlyph(119,5,5,Geometry::Vec2i(58,62),Geometry::Vec2i(0,4), 6);
	font->addGlyph(120,4,5,Geometry::Vec2i(21,72),Geometry::Vec2i(0,4), 5);
	font->addGlyph(121,4,7,Geometry::Vec2i(10,49),Geometry::Vec2i(0,4), 5);
	font->addGlyph(122,3,5,Geometry::Vec2i(67,68),Geometry::Vec2i(0,4), 4);
	font->addGlyph(123,3,9,Geometry::Vec2i(87,11),Geometry::Vec2i(0,1), 4);
	font->addGlyph(124,1,9,Geometry::Vec2i(19,21),Geometry::Vec2i(0,1), 2);
	font->addGlyph(125,3,9,Geometry::Vec2i(91,11),Geometry::Vec2i(0,1), 4);
	font->addGlyph(126,4,2,Geometry::Vec2i(4,80),Geometry::Vec2i(0,2), 5);
	return font.detachAndDecrease();
}
//- ---------------------------------------------------------------------------------------------------------
//! (static)
BitmapFont * EmbeddedFonts::createBoldFont(){
	// resources/Fonts/pf_tempesta_seven_wide_bold.fnt
	static const uint8_t bitmapData [] = {
		 0x10, 0x18, 0xa, 0x6, 0x6, 0x2, 0x2, 0x3, 0x6, 0x83, 0x6, 0x6, 0x82, 0x3, 0x6, 0x18, 0x28, 0x10, 0x14, 0x4, 0x2, 0x5, 0x5, 0x2, 0xb, 0x2, 0x2, 0xb, 0x5, 0x2, 0x2, 0x4,
		 0x10, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xc3, 0x61, 0xb0, 0xcf, 0x8f, 0x9f, 0xcf, 0x8f, 0x8f, 0x8f, 0x8f, 0x98, 0xd8, 0xd8, 0xd8,
		 0x7c, 0x66, 0x71, 0x99, 0x98, 0xd8, 0xd8, 0x18, 0xd8, 0xd8, 0xd8, 0xd8, 0xd8, 0xd8, 0xd8, 0xd8, 0xc6, 0x3c, 0x79, 0x99, 0x98, 0xd8, 0xd8, 0x18, 0xd8, 0xd8, 0xd8, 0xd8, 0xd8, 0xd8, 0xd8, 0xd8,
		 0xc6, 0x18, 0x6d, 0x8f, 0x18, 0xdf, 0xdf, 0x98, 0xdf, 0xdf, 0xdf, 0xd8, 0xd8, 0xd8, 0xd8, 0xd8, 0xfe, 0x18, 0x67, 0x86, 0x18, 0xd8, 0xd8, 0x18, 0xd8, 0xd8, 0xd8, 0xd8, 0xd8, 0xd8, 0xd8, 0xd8,
		 0xc6, 0x18, 0x63, 0x86, 0x18, 0xd8, 0xd8, 0x18, 0xd8, 0xd8, 0xd8, 0xd8, 0xd8, 0xd8, 0xd8, 0xd8, 0xc6, 0x18, 0x61, 0x8c, 0xf, 0x98, 0xdf, 0xcf, 0x98, 0xd8, 0xd8, 0xcf, 0x8f, 0x8f, 0x8f, 0x98,
		 0xc6, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x10, 0x30, 0x2d, 0x99, 0x87, 0x83, 0xc1, 0xe1, 0xf9, 0xf1, 0xf9, 0xb3, 0x1, 0xb1, 0xb0,
		 0x18, 0x28, 0x10, 0x28, 0x80, 0x8, 0x44, 0x22, 0x13, 0x3, 0x1b, 0xd8, 0x3, 0xf0, 0x0, 0x0, 0x10, 0x0, 0x0, 0x0, 0x30, 0xd3, 0x2b, 0x94, 0xeb, 0x1, 0xc3, 0xd9, 0xf3, 0x19, 0xf3, 0xf8,
		 0x0, 0x7c, 0xfe, 0xcd, 0x99, 0x90, 0xaa, 0x55, 0xb, 0x3, 0xf3, 0xdb, 0x1b, 0x1b, 0x1b, 0x0, 0xfe, 0xc6, 0xc0, 0xcd, 0x99, 0x93, 0xab, 0x95, 0xb, 0x3, 0x19, 0xdb, 0x1b, 0x1b, 0x1b, 0x0,
		 0xc0, 0xc6, 0xc0, 0xcd, 0x8f, 0x14, 0xaa, 0x55, 0xb, 0x1, 0xf8, 0xdb, 0xfb, 0x1b, 0x1b, 0xf0, 0xc0, 0xc6, 0xfc, 0xcd, 0x86, 0x13, 0xaa, 0x54, 0xc9, 0xf8, 0x70, 0xdb, 0x1b, 0x1b, 0x1b, 0x0,
		 0xfc, 0xc6, 0xc0, 0xcd, 0x86, 0x8, 0x44, 0x22, 0x30, 0x63, 0x18, 0xdb, 0x1b, 0xf3, 0x1b, 0x0, 0xc0, 0xc6, 0xc0, 0xcd, 0x8c, 0x7, 0x3, 0xc1, 0xe0, 0x41, 0xf0, 0xdb, 0x1b, 0x1, 0xf3, 0xf8,
		 0xc0, 0x7c, 0xfe, 0xcd, 0x80, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xfe, 0x0, 0x0, 0x0, 0x7, 0x73, 0x6d, 0xbf, 0xc, 0x1f, 0x4, 0xd, 0x6, 0x6, 0x4, 0x30,
		 0x0, 0x6c, 0x30, 0x6c, 0x66, 0x36, 0xd, 0xb1, 0x84, 0x31, 0x8a, 0x16, 0x4, 0x4, 0xa, 0x8, 0x10, 0x0, 0x7c, 0xc6, 0x36, 0x36, 0x6d, 0xb1, 0x80, 0x31, 0x80, 0x0, 0x0, 0x0, 0x0, 0x0,
		 0x28, 0xc6, 0xd0, 0xc6, 0x36, 0x36, 0x6d, 0xb7, 0x1f, 0x31, 0x9f, 0x1f, 0x1f, 0x1f, 0x1f, 0x30, 0x10, 0xc6, 0xd0, 0xc6, 0x36, 0x36, 0x6c, 0x31, 0xb1, 0xb1, 0x81, 0x81, 0x81, 0xb1, 0xb1, 0xb0,
		 0x0, 0xc6, 0x79, 0x83, 0x36, 0x36, 0x6d, 0xb1, 0xbf, 0xb1, 0x9f, 0x9f, 0x9f, 0xbf, 0xbf, 0xb0, 0x7c, 0xc6, 0x2c, 0xc6, 0x36, 0x36, 0x6d, 0xb7, 0x30, 0x1f, 0x31, 0xb1, 0xb1, 0xb0, 0x30, 0x30,
		 0x6, 0xc6, 0x2c, 0xc6, 0x36, 0x36, 0x6d, 0xb0, 0x1f, 0x1, 0x9f, 0x9f, 0x9f, 0x9f, 0x1f, 0x30, 0x7e, 0xc6, 0xf8, 0xc6, 0x37, 0x73, 0x4d, 0x80, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
		 0xc6, 0x7c, 0x30, 0x6c, 0x60, 0x0, 0x0, 0x0, 0x30, 0x2d, 0xb8, 0x30, 0x70, 0xc1, 0xc3, 0x6, 0x7e, 0x0, 0x0, 0x0, 0x0, 0x30, 0x18, 0x10, 0x10, 0x25, 0xc, 0x60, 0x31, 0x80, 0xc6, 0x6,
		 0x0, 0x30, 0x18, 0x10, 0x34, 0x10, 0x10, 0x28, 0x0, 0x0, 0x18, 0x67, 0x31, 0x9c, 0xc6, 0xe6, 0x34, 0x10, 0x10, 0x28, 0x58, 0x0, 0x0, 0x0, 0x7c, 0xcd, 0x8c, 0xcf, 0x33, 0x3c, 0xcc, 0x36,
		 0x58, 0x0, 0x0, 0x0, 0x0, 0xc6, 0xc6, 0xc6, 0x6, 0xcd, 0xb9, 0x9b, 0x36, 0x6c, 0xd8, 0x66, 0x0, 0x7c, 0x7c, 0x7c, 0x7c, 0xc6, 0xc6, 0xc6, 0x7e, 0xcd, 0x81, 0x9f, 0x6, 0x7c, 0x18, 0xc6,
		 0xfc, 0xc6, 0xc6, 0xc6, 0xc6, 0xc6, 0xc6, 0xc6, 0xc6, 0xcd, 0x83, 0x3, 0xc, 0xc, 0x30, 0xf6, 0xc6, 0xc6, 0xc6, 0xc6, 0xc6, 0xc6, 0xc6, 0xc6, 0x7e, 0xcd, 0x80, 0x0, 0x0, 0x0, 0x0, 0x0,
		 0xc6, 0xc6, 0xc6, 0xc6, 0xc6, 0x7e, 0x7e, 0x7e, 0x0, 0x0, 0x0, 0xc3, 0x23, 0x31, 0x9f, 0x38, 0xc6, 0x7c, 0x7c, 0x7c, 0x7c, 0x0, 0x0, 0x0, 0x3, 0xd, 0x86, 0xe3, 0x56, 0x33, 0x31, 0x98,
		 0xc6, 0x0, 0x0, 0x0, 0x0, 0x18, 0x6f, 0xf6, 0x19, 0x98, 0xcc, 0xf3, 0x26, 0x36, 0x31, 0x98, 0x0, 0x6, 0x66, 0xc1, 0x9f, 0x8f, 0xc1, 0x83, 0x30, 0xf0, 0x78, 0xdb, 0xc, 0x3c, 0x31, 0x98,
		 0x7f, 0xf6, 0x66, 0xe3, 0x98, 0xc3, 0x1, 0x83, 0x30, 0x60, 0x30, 0xcf, 0x19, 0x36, 0x31, 0x98, 0xc6, 0x6, 0x66, 0xf7, 0x98, 0xdf, 0xe1, 0x81, 0xe0, 0xf0, 0x30, 0xc7, 0x1a, 0xb3, 0x31, 0x98,
		 0xc6, 0x6, 0x66, 0xdd, 0xbe, 0xc3, 0x1, 0x80, 0xc1, 0x98, 0x30, 0xc3, 0x31, 0x31, 0x9f, 0x18, 0xff, 0xe6, 0x66, 0xc9, 0x98, 0xdf, 0xe1, 0x80, 0xc3, 0xc, 0x30, 0x0, 0x0, 0x0, 0x0, 0x0,
		 0xc6, 0x6, 0x66, 0xc1, 0x98, 0xc3, 0x1, 0x81, 0x80, 0x0, 0x0, 0x7e, 0xfe, 0x18, 0x3e, 0x18, 0xc6, 0x3, 0xfc, 0xc1, 0x9f, 0x80, 0x0, 0x0, 0x0, 0xc0, 0xfc, 0xc6, 0x6, 0x7e, 0x60, 0x0,
		 0xc7, 0xf0, 0x0, 0x0, 0x0, 0x0, 0x6, 0x7e, 0xc0, 0xc0, 0xc6, 0xc6, 0xc, 0xd8, 0x60, 0x18, 0x0, 0x0, 0x7e, 0xc6, 0xc6, 0xc0, 0x6, 0xc6, 0xc0, 0xc6, 0xc6, 0xc6, 0x18, 0xd8, 0xfc, 0x70,
		 0xfc, 0xfc, 0xc0, 0xc6, 0xc6, 0xc0, 0x7e, 0xc6, 0xfc, 0xdc, 0xc6, 0x7e, 0x18, 0xd8, 0x60, 0xc0, 0xc6, 0xc6, 0xc0, 0xc6, 0xc6, 0xfc, 0xc6, 0xc6, 0xc6, 0xf0, 0xfc, 0x6, 0x30, 0x7e, 0x60, 0xc0,
		 0xc6, 0xc6, 0x7c, 0xc6, 0xc6, 0xc6, 0xc6, 0x7e, 0xc6, 0xdc, 0xc0, 0x6, 0x30, 0x18, 0xfe, 0x7e, 0xfc, 0xfc, 0x6, 0xc6, 0x6c, 0xc6, 0xc6, 0x6, 0xc6, 0xc6, 0xc0, 0x0, 0x0, 0x0, 0x0, 0x0,
		 0xc0, 0xc6, 0x6, 0xc6, 0x38, 0xc6, 0x7e, 0x7c, 0xc6, 0x0, 0x0, 0x7c, 0x6, 0x7c, 0xfc, 0x7c, 0xc0, 0xc6, 0xfc, 0x7c, 0x10, 0xfc, 0x0, 0x0, 0x0, 0xfe, 0x7c, 0xc6, 0x3e, 0xc6, 0x6, 0xc6,
		 0xc0, 0xc6, 0x0, 0x0, 0x0, 0x0, 0xfc, 0x6c, 0xc, 0xc0, 0xc0, 0xc6, 0x6, 0xc6, 0x6, 0xc6, 0x0, 0x0, 0x6c, 0x7c, 0x7e, 0xfc, 0x6, 0x0, 0x1c, 0xc0, 0xc0, 0x7c, 0x7e, 0x7e, 0x1c, 0xfe,
		 0x7a, 0x6c, 0x0, 0xc6, 0xc0, 0x6, 0x6, 0x7c, 0x3c, 0xfc, 0xfc, 0xc6, 0xc6, 0x6, 0x30, 0xc6, 0xce, 0x6c, 0x7c, 0xc6, 0xc0, 0x6, 0x7c, 0xc6, 0x6c, 0x6, 0xc6, 0xc6, 0xc6, 0x6, 0x0, 0xc6,
		 0xcc, 0xfe, 0x6, 0xc6, 0xc0, 0x7c, 0x6, 0xfe, 0xfe, 0x6, 0xc6, 0x7c, 0x7e, 0x7c, 0x30, 0xc6, 0xd6, 0x6c, 0x7e, 0xc6, 0x7e, 0xc0, 0x6, 0xc0, 0xc, 0xfc, 0x7c, 0x0, 0x0, 0x0, 0x0, 0x0,
		 0x66, 0xfe, 0xc6, 0xc6, 0x18, 0xc0, 0xfc, 0x7c, 0xc, 0x0, 0x0, 0x3, 0x7, 0xec, 0xf, 0x36, 0xe6, 0x6c, 0x7e, 0x7c, 0x10, 0xfe, 0x0, 0x0, 0x0, 0xc6, 0xc, 0x79, 0x80, 0x6c, 0x18, 0x0,
		 0xbc, 0x6c, 0x0, 0x0, 0x0, 0x0, 0x6c, 0x7e, 0xc0, 0xc6, 0xc, 0xc1, 0x80, 0xcc, 0x18, 0x36, 0x0, 0x0, 0x6c, 0xfc, 0xfe, 0xfe, 0x0, 0xc0, 0xfc, 0xc6, 0xd, 0xf8, 0xc1, 0x8c, 0xf, 0xb6,
		 0xfc, 0x7e, 0x0, 0xc6, 0xc0, 0xc0, 0xc6, 0xc0, 0xc6, 0xfe, 0xc, 0xc0, 0x63, 0xc, 0x1b, 0x36, 0xc6, 0xc0, 0x7c, 0xc6, 0xc0, 0xc0, 0xc6, 0xde, 0xc6, 0xc6, 0xc, 0xc0, 0x66, 0xc, 0x1b, 0x36,
		 0xc6, 0xc0, 0xc6, 0xc6, 0xfc, 0xfc, 0xc6, 0xc6, 0xc6, 0xc6, 0xc, 0xc0, 0x37, 0xef, 0xcf, 0xb6, 0xfc, 0xc0, 0xc6, 0xc6, 0xc0, 0xc0, 0xc6, 0xc6, 0xfc, 0xc6, 0xf8, 0xc0, 0x0, 0x0, 0x0, 0x0,
		 0xc6, 0xc0, 0xc6, 0xc6, 0xc0, 0xc0, 0x7e, 0x7e, 0xc0, 0x0, 0x0, 0x0, 0x7, 0xe7, 0xc7, 0xce, 0xc6, 0xc0, 0x7c, 0xfc, 0xfe, 0xc0, 0x0, 0x0, 0x0, 0x6, 0x6f, 0xc7, 0xcc, 0xc, 0x60, 0x66,
		 0xfc, 0x7e, 0x0, 0x0, 0x0, 0x0, 0x1, 0x99, 0xb3, 0xc, 0xcc, 0x6c, 0x6c, 0xc, 0x67, 0xe6, 0x0, 0x0, 0x3, 0xc, 0xff, 0xcf, 0xb9, 0x99, 0x99, 0x99, 0x8c, 0x6f, 0xec, 0xc, 0x6c, 0x66,
		 0xd, 0xb6, 0x37, 0xe0, 0xc, 0x6c, 0xcd, 0x99, 0x8c, 0xcc, 0xcc, 0x6c, 0x7, 0xe7, 0xc7, 0xe6, 0x19, 0xb6, 0x33, 0x0, 0xff, 0xec, 0xcd, 0x99, 0x99, 0x86, 0x6c, 0x67, 0xc0, 0x0, 0x0, 0x0,
		 0x19, 0xb6, 0x33, 0x1, 0x8c, 0xc, 0xcc, 0xff, 0x33, 0x0, 0x0, 0x0, 0x0, 0xe7, 0x37, 0xbc, 0x31, 0xb6, 0x33, 0xc, 0xff, 0xcc, 0xcc, 0x0, 0x0, 0x0, 0x7e, 0x88, 0xd8, 0x31, 0x80, 0xc,
		 0x61, 0xb7, 0xf3, 0xe8, 0x0, 0x0, 0x0, 0x3, 0xf, 0xb3, 0x60, 0x71, 0x8c, 0x63, 0x7, 0x8c, 0x61, 0x86, 0x0, 0x0, 0x30, 0x60, 0xc7, 0xef, 0xdb, 0x1e, 0x60, 0x53, 0x6, 0xc1, 0x80, 0x0,
		 0xc1, 0xb0, 0x0, 0x7e, 0x31, 0x68, 0x0, 0xc3, 0x1f, 0x8c, 0x60, 0x71, 0x8c, 0xf7, 0x30, 0x0, 0x0, 0x0, 0xc6, 0xc0, 0xfc, 0xf3, 0xf1, 0x80, 0xd, 0x9e, 0x60, 0x88, 0xd8, 0x0, 0x0, 0x0,
		 0xc6, 0xc6, 0x6c, 0x7c, 0x31, 0x68, 0x3, 0xf, 0xdf, 0x33, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xc6, 0xc6, 0x38, 0x6, 0x30, 0x60, 0xc7, 0xe0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
		 0xc6, 0x6c, 0x6c, 0xfc, 0x0, 0x0, 0x0, 0x1, 0xb0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xc6, 0x38, 0xc6, 0x0, 0x6d, 0xb6, 0xf7, 0xbc, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
		 0x7e, 0x10, 0x0, 0x1b, 0x45, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x14, 0x93, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
		 0x64, 0x4d, 0xa9, 0x40, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xaa, 0xad, 0x80, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
		 0xe4, 0x40, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
		 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
		 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
	};
	Util::Reference<Util::Bitmap> bitmap = Util::BitmapUtils::createBitmapFromBitMask(128,96,Util::PixelFormat::RGBA,sizeof(bitmapData),bitmapData);
	Util::Reference<BitmapFont> font = new BitmapFont(new ImageData(bitmap.get()),13);
	font->addGlyph(32,1,1,Geometry::Vec2i(126,11),Geometry::Vec2i(0,10), 5);
	font->addGlyph(33,2,7,Geometry::Vec2i(10,74),Geometry::Vec2i(0,2), 3);
	font->addGlyph(34,5,2,Geometry::Vec2i(12,88),Geometry::Vec2i(0,2), 6);
	font->addGlyph(35,7,7,Geometry::Vec2i(8,58),Geometry::Vec2i(0,2), 8);
	font->addGlyph(36,6,9,Geometry::Vec2i(16,22),Geometry::Vec2i(0,1), 7);
	font->addGlyph(37,8,7,Geometry::Vec2i(97,38),Geometry::Vec2i(0,2), 9);
	font->addGlyph(38,6,7,Geometry::Vec2i(115,62),Geometry::Vec2i(0,2), 7);
	font->addGlyph(39,2,2,Geometry::Vec2i(30,86),Geometry::Vec2i(0,2), 3);
	font->addGlyph(40,3,9,Geometry::Vec2i(45,21),Geometry::Vec2i(0,1), 4);
	font->addGlyph(41,3,9,Geometry::Vec2i(33,22),Geometry::Vec2i(0,1), 4);
	font->addGlyph(42,6,5,Geometry::Vec2i(39,79),Geometry::Vec2i(0,3), 7);
	font->addGlyph(43,6,5,Geometry::Vec2i(32,79),Geometry::Vec2i(0,3), 7);
	font->addGlyph(44,2,2,Geometry::Vec2i(39,85),Geometry::Vec2i(0,8), 3);
	font->addGlyph(45,4,1,Geometry::Vec2i(58,85),Geometry::Vec2i(0,6), 5);
	font->addGlyph(46,2,1,Geometry::Vec2i(66,84),Geometry::Vec2i(0,8), 3);
	font->addGlyph(47,6,7,Geometry::Vec2i(0,74),Geometry::Vec2i(0,2), 7);
	font->addGlyph(48,7,7,Geometry::Vec2i(24,57),Geometry::Vec2i(0,2), 8);
	font->addGlyph(49,3,7,Geometry::Vec2i(122,38),Geometry::Vec2i(0,2), 4);
	font->addGlyph(50,7,7,Geometry::Vec2i(40,57),Geometry::Vec2i(0,2), 8);
	font->addGlyph(51,7,7,Geometry::Vec2i(48,56),Geometry::Vec2i(0,2), 8);
	font->addGlyph(52,7,7,Geometry::Vec2i(64,56),Geometry::Vec2i(0,2), 8);
	font->addGlyph(53,7,7,Geometry::Vec2i(72,55),Geometry::Vec2i(0,2), 8);
	font->addGlyph(54,7,7,Geometry::Vec2i(80,55),Geometry::Vec2i(0,2), 8);
	font->addGlyph(55,7,7,Geometry::Vec2i(96,46),Geometry::Vec2i(0,2), 8);
	font->addGlyph(56,7,7,Geometry::Vec2i(88,54),Geometry::Vec2i(0,2), 8);
	font->addGlyph(57,7,7,Geometry::Vec2i(104,54),Geometry::Vec2i(0,2), 8);
	font->addGlyph(58,2,5,Geometry::Vec2i(114,76),Geometry::Vec2i(0,4), 3);
	font->addGlyph(59,2,6,Geometry::Vec2i(28,73),Geometry::Vec2i(0,4), 3);
	font->addGlyph(60,4,5,Geometry::Vec2i(94,77),Geometry::Vec2i(0,3), 5);
	font->addGlyph(61,4,3,Geometry::Vec2i(117,76),Geometry::Vec2i(0,4), 5);
	font->addGlyph(62,4,5,Geometry::Vec2i(99,77),Geometry::Vec2i(0,3), 5);
	font->addGlyph(63,7,7,Geometry::Vec2i(112,54),Geometry::Vec2i(0,2), 8);
	font->addGlyph(64,8,9,Geometry::Vec2i(43,11),Geometry::Vec2i(0,1), 9);
	font->addGlyph(65,7,7,Geometry::Vec2i(120,54),Geometry::Vec2i(0,2), 8);
	font->addGlyph(66,7,7,Geometry::Vec2i(0,66),Geometry::Vec2i(0,2), 8);
	font->addGlyph(67,7,7,Geometry::Vec2i(8,66),Geometry::Vec2i(0,2), 8);
	font->addGlyph(68,7,7,Geometry::Vec2i(24,65),Geometry::Vec2i(0,2), 8);
	font->addGlyph(69,7,7,Geometry::Vec2i(32,65),Geometry::Vec2i(0,2), 8);
	font->addGlyph(70,7,7,Geometry::Vec2i(40,65),Geometry::Vec2i(0,2), 8);
	font->addGlyph(71,7,7,Geometry::Vec2i(56,64),Geometry::Vec2i(0,2), 8);
	font->addGlyph(72,7,7,Geometry::Vec2i(72,63),Geometry::Vec2i(0,2), 8);
	font->addGlyph(73,2,7,Geometry::Vec2i(7,74),Geometry::Vec2i(0,2), 3);
	font->addGlyph(74,6,7,Geometry::Vec2i(80,63),Geometry::Vec2i(0,2), 7);
	font->addGlyph(75,7,7,Geometry::Vec2i(106,38),Geometry::Vec2i(0,2), 8);
	font->addGlyph(76,6,7,Geometry::Vec2i(108,62),Geometry::Vec2i(0,2), 7);
	font->addGlyph(77,9,7,Geometry::Vec2i(24,41),Geometry::Vec2i(0,2), 10);
	font->addGlyph(78,8,7,Geometry::Vec2i(88,38),Geometry::Vec2i(0,2), 9);
	font->addGlyph(79,7,7,Geometry::Vec2i(114,38),Geometry::Vec2i(0,2), 8);
	font->addGlyph(80,7,7,Geometry::Vec2i(0,50),Geometry::Vec2i(0,2), 8);
	font->addGlyph(81,7,8,Geometry::Vec2i(74,21),Geometry::Vec2i(0,2), 8);
	font->addGlyph(82,7,7,Geometry::Vec2i(8,50),Geometry::Vec2i(0,2), 8);
	font->addGlyph(83,7,7,Geometry::Vec2i(16,49),Geometry::Vec2i(0,2), 8);
	font->addGlyph(84,8,7,Geometry::Vec2i(52,40),Geometry::Vec2i(0,2), 9);
	font->addGlyph(85,7,7,Geometry::Vec2i(24,49),Geometry::Vec2i(0,2), 8);
	font->addGlyph(86,7,7,Geometry::Vec2i(32,49),Geometry::Vec2i(0,2), 8);
	font->addGlyph(87,10,7,Geometry::Vec2i(13,41),Geometry::Vec2i(0,2), 11);
	font->addGlyph(88,8,7,Geometry::Vec2i(70,39),Geometry::Vec2i(0,2), 9);
	font->addGlyph(89,8,7,Geometry::Vec2i(79,39),Geometry::Vec2i(0,2), 9);
	font->addGlyph(90,6,7,Geometry::Vec2i(101,62),Geometry::Vec2i(0,2), 7);
	font->addGlyph(91,3,9,Geometry::Vec2i(37,21),Geometry::Vec2i(0,1), 4);
	font->addGlyph(92,6,7,Geometry::Vec2i(94,62),Geometry::Vec2i(0,2), 7);
	font->addGlyph(93,3,9,Geometry::Vec2i(41,21),Geometry::Vec2i(0,1), 4);
	font->addGlyph(94,3,2,Geometry::Vec2i(23,87),Geometry::Vec2i(0,2), 4);
	font->addGlyph(95,4,1,Geometry::Vec2i(53,85),Geometry::Vec2i(0,8), 5);
	font->addGlyph(96,2,2,Geometry::Vec2i(36,85),Geometry::Vec2i(0,-1), 3);
	font->addGlyph(97,7,5,Geometry::Vec2i(116,70),Geometry::Vec2i(0,4), 8);
	font->addGlyph(98,7,7,Geometry::Vec2i(40,49),Geometry::Vec2i(0,2), 8);
	font->addGlyph(99,7,5,Geometry::Vec2i(100,70),Geometry::Vec2i(0,4), 8);
	font->addGlyph(100,7,7,Geometry::Vec2i(48,48),Geometry::Vec2i(0,2), 8);
	font->addGlyph(101,7,5,Geometry::Vec2i(92,71),Geometry::Vec2i(0,4), 8);
	font->addGlyph(102,6,7,Geometry::Vec2i(87,63),Geometry::Vec2i(0,2), 7);
	font->addGlyph(103,7,7,Geometry::Vec2i(56,48),Geometry::Vec2i(0,4), 8);
	font->addGlyph(104,7,7,Geometry::Vec2i(64,48),Geometry::Vec2i(0,2), 8);
	font->addGlyph(105,2,7,Geometry::Vec2i(122,62),Geometry::Vec2i(0,2), 3);
	font->addGlyph(106,2,9,Geometry::Vec2i(49,21),Geometry::Vec2i(0,2), 3);
	font->addGlyph(107,7,7,Geometry::Vec2i(72,47),Geometry::Vec2i(0,2), 8);
	font->addGlyph(108,2,7,Geometry::Vec2i(125,30),Geometry::Vec2i(0,2), 3);
	font->addGlyph(109,10,5,Geometry::Vec2i(44,73),Geometry::Vec2i(0,4), 11);
	font->addGlyph(110,7,5,Geometry::Vec2i(84,71),Geometry::Vec2i(0,4), 8);
	font->addGlyph(111,7,5,Geometry::Vec2i(108,70),Geometry::Vec2i(0,4), 8);
	font->addGlyph(112,7,7,Geometry::Vec2i(80,47),Geometry::Vec2i(0,4), 8);
	font->addGlyph(113,7,7,Geometry::Vec2i(88,46),Geometry::Vec2i(0,4), 8);
	font->addGlyph(114,6,5,Geometry::Vec2i(81,77),Geometry::Vec2i(0,4), 7);
	font->addGlyph(115,7,5,Geometry::Vec2i(24,80),Geometry::Vec2i(0,4), 8);
	font->addGlyph(116,6,6,Geometry::Vec2i(21,73),Geometry::Vec2i(0,3), 7);
	font->addGlyph(117,7,5,Geometry::Vec2i(0,82),Geometry::Vec2i(0,4), 8);
	font->addGlyph(118,7,5,Geometry::Vec2i(8,82),Geometry::Vec2i(0,4), 8);
	font->addGlyph(119,10,5,Geometry::Vec2i(55,72),Geometry::Vec2i(0,4), 11);
	font->addGlyph(120,7,5,Geometry::Vec2i(16,81),Geometry::Vec2i(0,4), 8);
	font->addGlyph(121,8,7,Geometry::Vec2i(61,40),Geometry::Vec2i(0,4), 9);
	font->addGlyph(122,6,5,Geometry::Vec2i(53,79),Geometry::Vec2i(0,4), 7);
	font->addGlyph(123,4,9,Geometry::Vec2i(23,22),Geometry::Vec2i(0,1), 5);
	font->addGlyph(124,2,9,Geometry::Vec2i(52,21),Geometry::Vec2i(0,1), 3);
	font->addGlyph(125,4,9,Geometry::Vec2i(28,22),Geometry::Vec2i(0,1), 5);
	font->addGlyph(126,4,2,Geometry::Vec2i(18,87),Geometry::Vec2i(0,2), 5);
	return font.detachAndDecrease();
}


}


