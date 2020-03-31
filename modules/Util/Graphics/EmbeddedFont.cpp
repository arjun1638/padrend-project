/*
	This file is part of the Util library.
	Copyright (C) 2013 Benjamin Eikel <benjamin@eikel.org>
	
	This library is subject to the terms of the Mozilla Public License, v. 2.0.
	You should have received a copy of the MPL along with this library; see the 
	file LICENSE. If not, you can obtain one at http://mozilla.org/MPL/2.0/.
*/
#include "EmbeddedFont.h"
#include "Bitmap.h"
#include "FontRenderer.h"
#include "PixelFormat.h"
#include <algorithm>
#include <cstdint>

namespace Util {
namespace EmbeddedFont {

std::pair<Reference<Bitmap>, FontInfo> getFont() {
	FontInfo fontInfo{
		11, // ascender
		-2, // descender
		14, // height
		// glyphMap
		{
			// {glyph, {position, size, offset, xAdvance}}
			{0, {{0, 0}, {0, 0}, {0, 0}, 0}},
			{1, {{0, 0}, {0, 0}, {0, 0}, 3}},
			{2, {{0, 0}, {0, 0}, {0, 0}, 3}},
			{3, {{0, 0}, {0, 0}, {0, 0}, 3}},
			{4, {{0, 0}, {0, 0}, {0, 0}, 3}},
			{5, {{0, 0}, {0, 0}, {0, 0}, 3}},
			{6, {{0, 0}, {0, 0}, {0, 0}, 3}},
			{7, {{0, 0}, {0, 0}, {0, 0}, 3}},
			{8, {{0, 0}, {0, 0}, {0, 0}, 3}},
			{9, {{0, 0}, {0, 0}, {0, 0}, 3}},
			{10, {{0, 0}, {0, 0}, {0, 0}, 3}},
			{11, {{0, 0}, {0, 0}, {0, 0}, 3}},
			{12, {{0, 0}, {0, 0}, {0, 0}, 3}},
			{13, {{0, 0}, {0, 0}, {0, 0}, 0}},
			{14, {{0, 0}, {0, 0}, {0, 0}, 3}},
			{15, {{0, 0}, {0, 0}, {0, 0}, 3}},
			{16, {{0, 0}, {0, 0}, {0, 0}, 3}},
			{17, {{0, 0}, {0, 0}, {0, 0}, 3}},
			{18, {{0, 0}, {0, 0}, {0, 0}, 3}},
			{19, {{0, 0}, {0, 0}, {0, 0}, 3}},
			{20, {{0, 0}, {0, 0}, {0, 0}, 3}},
			{21, {{0, 0}, {0, 0}, {0, 0}, 3}},
			{22, {{0, 0}, {0, 0}, {0, 0}, 3}},
			{23, {{0, 0}, {0, 0}, {0, 0}, 3}},
			{24, {{0, 0}, {0, 0}, {0, 0}, 3}},
			{25, {{0, 0}, {0, 0}, {0, 0}, 3}},
			{26, {{0, 0}, {0, 0}, {0, 0}, 3}},
			{27, {{0, 0}, {0, 0}, {0, 0}, 3}},
			{28, {{0, 0}, {0, 0}, {0, 0}, 3}},
			{29, {{0, 0}, {0, 0}, {0, 0}, 3}},
			{30, {{0, 0}, {0, 0}, {0, 0}, 3}},
			{31, {{0, 0}, {0, 0}, {0, 0}, 3}},
			{32, {{0, 0}, {0, 0}, {0, 0}, 3}},
			{33, {{0, 0}, {1, 7}, {0, 7}, 2}},
			{34, {{1, 0}, {3, 2}, {0, 7}, 4}},
			{35, {{4, 0}, {5, 7}, {0, 7}, 6}},
			{36, {{9, 0}, {5, 9}, {0, 8}, 6}},
			{37, {{14, 0}, {7, 7}, {0, 7}, 8}},
			{38, {{21, 0}, {4, 7}, {0, 7}, 5}},
			{39, {{25, 0}, {1, 2}, {0, 7}, 2}},
			{40, {{26, 0}, {2, 9}, {0, 8}, 3}},
			{41, {{28, 0}, {2, 9}, {0, 8}, 3}},
			{42, {{30, 0}, {5, 5}, {0, 6}, 6}},
			{43, {{35, 0}, {5, 5}, {0, 6}, 6}},
			{44, {{40, 0}, {2, 2}, {0, 1}, 3}},
			{45, {{42, 0}, {3, 1}, {0, 3}, 4}},
			{46, {{45, 0}, {1, 1}, {1, 1}, 3}},
			{47, {{46, 0}, {5, 7}, {0, 7}, 6}},
			{48, {{51, 0}, {4, 7}, {0, 7}, 5}},
			{49, {{55, 0}, {2, 7}, {0, 7}, 3}},
			{50, {{57, 0}, {4, 7}, {0, 7}, 5}},
			{51, {{61, 0}, {4, 7}, {0, 7}, 5}},
			{52, {{65, 0}, {4, 7}, {0, 7}, 5}},
			{53, {{69, 0}, {4, 7}, {0, 7}, 5}},
			{54, {{73, 0}, {4, 7}, {0, 7}, 5}},
			{55, {{77, 0}, {4, 7}, {0, 7}, 5}},
			{56, {{81, 0}, {4, 7}, {0, 7}, 5}},
			{57, {{85, 0}, {4, 7}, {0, 7}, 5}},
			{58, {{89, 0}, {1, 5}, {1, 5}, 3}},
			{59, {{90, 0}, {2, 6}, {0, 5}, 3}},
			{60, {{92, 0}, {3, 5}, {0, 6}, 4}},
			{61, {{95, 0}, {3, 3}, {0, 5}, 4}},
			{62, {{98, 0}, {3, 5}, {0, 6}, 4}},
			{63, {{101, 0}, {4, 7}, {0, 7}, 5}},
			{64, {{105, 0}, {8, 9}, {0, 8}, 9}},
			{65, {{113, 0}, {4, 7}, {0, 7}, 5}},
			{66, {{117, 0}, {4, 7}, {0, 7}, 5}},
			{67, {{121, 0}, {4, 7}, {0, 7}, 5}},
			{68, {{125, 0}, {4, 7}, {0, 7}, 5}},
			{69, {{129, 0}, {4, 7}, {0, 7}, 5}},
			{70, {{133, 0}, {4, 7}, {0, 7}, 5}},
			{71, {{137, 0}, {4, 7}, {0, 7}, 5}},
			{72, {{141, 0}, {4, 7}, {0, 7}, 5}},
			{73, {{145, 0}, {1, 7}, {0, 7}, 2}},
			{74, {{146, 0}, {3, 7}, {0, 7}, 4}},
			{75, {{149, 0}, {4, 7}, {0, 7}, 5}},
			{76, {{153, 0}, {3, 7}, {0, 7}, 4}},
			{77, {{156, 0}, {5, 7}, {0, 7}, 6}},
			{78, {{161, 0}, {5, 7}, {0, 7}, 6}},
			{79, {{166, 0}, {4, 7}, {0, 7}, 5}},
			{80, {{170, 0}, {4, 7}, {0, 7}, 5}},
			{81, {{174, 0}, {4, 8}, {0, 7}, 5}},
			{82, {{178, 0}, {4, 7}, {0, 7}, 5}},
			{83, {{182, 0}, {4, 7}, {0, 7}, 5}},
			{84, {{186, 0}, {5, 7}, {0, 7}, 6}},
			{85, {{191, 0}, {4, 7}, {0, 7}, 5}},
			{86, {{195, 0}, {5, 7}, {0, 7}, 6}},
			{87, {{200, 0}, {5, 7}, {0, 7}, 6}},
			{88, {{205, 0}, {4, 7}, {0, 7}, 5}},
			{89, {{209, 0}, {5, 7}, {0, 7}, 6}},
			{90, {{214, 0}, {4, 7}, {0, 7}, 5}},
			{91, {{218, 0}, {2, 9}, {0, 8}, 3}},
			{92, {{220, 0}, {5, 7}, {0, 7}, 6}},
			{93, {{225, 0}, {2, 9}, {0, 8}, 3}},
			{94, {{227, 0}, {3, 2}, {0, 7}, 4}},
			{95, {{230, 0}, {3, 1}, {0, 1}, 4}},
			{96, {{233, 0}, {2, 2}, {0, 10}, 3}},
			{97, {{235, 0}, {4, 5}, {0, 5}, 5}},
			{98, {{239, 0}, {4, 7}, {0, 7}, 5}},
			{99, {{243, 0}, {4, 5}, {0, 5}, 5}},
			{100, {{247, 0}, {4, 7}, {0, 7}, 5}},
			{101, {{251, 0}, {4, 5}, {0, 5}, 5}},
			{102, {{255, 0}, {3, 7}, {0, 7}, 4}},
			{103, {{258, 0}, {4, 7}, {0, 5}, 5}},
			{104, {{262, 0}, {4, 7}, {0, 7}, 5}},
			{105, {{266, 0}, {1, 7}, {0, 7}, 2}},
			{106, {{267, 0}, {2, 9}, {-1, 7}, 2}},
			{107, {{269, 0}, {4, 7}, {0, 7}, 5}},
			{108, {{273, 0}, {1, 7}, {0, 7}, 2}},
			{109, {{274, 0}, {7, 5}, {0, 5}, 8}},
			{110, {{281, 0}, {4, 5}, {0, 5}, 5}},
			{111, {{285, 0}, {4, 5}, {0, 5}, 5}},
			{112, {{289, 0}, {4, 7}, {0, 5}, 5}},
			{113, {{293, 0}, {4, 7}, {0, 5}, 5}},
			{114, {{297, 0}, {3, 5}, {0, 5}, 4}},
			{115, {{300, 0}, {4, 5}, {0, 5}, 5}},
			{116, {{304, 0}, {3, 7}, {0, 7}, 4}},
			{117, {{307, 0}, {4, 5}, {0, 5}, 5}},
			{118, {{311, 0}, {4, 5}, {0, 5}, 5}},
			{119, {{315, 0}, {5, 5}, {0, 5}, 6}},
			{120, {{320, 0}, {4, 5}, {0, 5}, 5}},
			{121, {{324, 0}, {4, 7}, {0, 5}, 5}},
			{122, {{328, 0}, {3, 5}, {0, 5}, 4}},
			{123, {{331, 0}, {3, 9}, {0, 8}, 4}},
			{124, {{334, 0}, {1, 9}, {0, 8}, 2}},
			{125, {{335, 0}, {3, 9}, {0, 8}, 4}},
			{126, {{338, 0}, {4, 2}, {0, 7}, 5}},
			{127, {{342, 0}, {0, 0}, {0, 0}, 3}}
		}
	};

	const uint32_t width = 342;
	const uint32_t height = 9;
	const uint8_t data[width * height] = {
		255, 255, 0, 255, 0, 255, 0, 255, 0, 
		0, 0, 255, 0, 0, 42, 255, 42, 0, 
		0, 255, 0, 42, 255, 255, 0, 255, 42, 
		255, 255, 42, 0, 0, 255, 0, 0, 0, 
		0, 255, 0, 0, 42, 255, 255, 255, 255, 
		255, 0, 0, 0, 0, 255, 42, 255, 255, 
		42, 255, 255, 255, 255, 255, 42, 255, 255, 
		255, 42, 0, 0, 255, 0, 255, 255, 255, 
		255, 42, 255, 255, 42, 255, 255, 255, 255, 
		42, 255, 255, 42, 42, 255, 255, 42, 255, 
		0, 255, 0, 0, 255, 255, 255, 255, 255, 
		0, 0, 255, 255, 255, 42, 0, 42, 255, 
		255, 255, 255, 42, 0, 42, 255, 255, 42, 
		255, 255, 255, 42, 42, 255, 255, 255, 255, 
		255, 255, 42, 255, 255, 255, 255, 255, 255, 
		255, 255, 42, 255, 255, 255, 255, 0, 0, 
		255, 255, 0, 0, 255, 255, 0, 0, 255, 
		255, 0, 0, 255, 0, 0, 0, 255, 255, 
		0, 0, 0, 255, 42, 255, 255, 42, 255, 
		255, 255, 42, 42, 255, 255, 42, 255, 255, 
		255, 42, 42, 255, 255, 255, 255, 255, 255, 
		255, 255, 255, 0, 0, 255, 255, 0, 0, 
		0, 255, 255, 0, 255, 0, 255, 255, 0, 
		0, 255, 255, 0, 0, 0, 255, 255, 255, 
		255, 255, 255, 255, 255, 0, 0, 0, 0, 
		255, 255, 42, 255, 42, 255, 255, 255, 255, 
		42, 42, 255, 255, 42, 162, 0, 0, 0, 
		42, 255, 255, 255, 0, 0, 0, 162, 42, 
		255, 255, 42, 0, 42, 255, 42, 255, 162, 
		255, 162, 0, 0, 0, 255, 0, 255, 162, 
		0, 0, 0, 162, 255, 162, 255, 42, 162, 
		255, 42, 255, 162, 255, 42, 42, 255, 255, 
		42, 255, 162, 255, 42, 42, 255, 162, 255, 
		255, 162, 255, 42, 255, 255, 255, 0, 42, 
		0, 255, 0, 0, 255, 255, 0, 0, 255, 
		255, 0, 255, 0, 255, 255, 0, 0, 255, 
		255, 0, 0, 255, 255, 255, 255, 0, 42, 
		255, 255, 255, 42, 0, 42, 255, 0, 162, 
		255, 255, 0, 255, 0, 255, 0, 255, 0, 
		42, 255, 163, 255, 255, 255, 0, 255, 0, 
		162, 42, 0, 255, 0, 0, 0, 255, 255, 
		0, 0, 255, 255, 0, 255, 0, 255, 0, 
		0, 255, 0, 0, 162, 0, 0, 0, 0, 
		0, 0, 0, 0, 255, 4, 255, 0, 0, 
		255, 0, 255, 0, 0, 0, 255, 0, 0, 
		0, 255, 0, 255, 255, 0, 255, 0, 0, 
		0, 255, 0, 0, 0, 0, 0, 0, 255, 
		255, 0, 0, 255, 255, 0, 0, 255, 0, 
		0, 0, 0, 255, 4, 0, 0, 0, 4, 
		255, 0, 0, 0, 0, 255, 42, 255, 0, 
		0, 0, 0, 255, 42, 255, 0, 0, 255, 
		255, 0, 0, 255, 255, 0, 0, 0, 255, 
		0, 0, 255, 255, 0, 0, 0, 255, 0, 
		0, 0, 255, 0, 0, 0, 255, 0, 0, 
		255, 255, 0, 0, 255, 255, 0, 162, 42, 
		255, 0, 0, 255, 255, 0, 255, 255, 255, 
		255, 0, 0, 255, 255, 0, 0, 255, 255, 
		0, 0, 255, 255, 0, 0, 255, 255, 0, 
		0, 255, 255, 0, 0, 0, 0, 0, 255, 
		0, 0, 255, 0, 0, 255, 255, 0, 0, 
		0, 255, 255, 0, 255, 0, 255, 255, 0, 
		0, 255, 42, 162, 0, 162, 42, 0, 0, 
		0, 255, 255, 0, 42, 162, 0, 0, 0, 
		0, 255, 162, 0, 162, 0, 0, 0, 0, 
		162, 0, 0, 0, 255, 255, 0, 0, 0, 
		255, 0, 0, 0, 0, 0, 0, 255, 255, 
		0, 0, 255, 0, 255, 0, 255, 0, 42, 
		255, 255, 0, 0, 0, 0, 0, 0, 255, 
		0, 0, 0, 255, 255, 42, 0, 255, 42, 
		0, 255, 255, 42, 0, 255, 255, 0, 0, 
		255, 255, 42, 0, 255, 255, 0, 42, 255, 
		255, 42, 0, 255, 0, 0, 0, 0, 255, 
		0, 255, 0, 0, 255, 255, 0, 0, 255, 
		255, 0, 255, 0, 255, 162, 42, 42, 162, 
		255, 0, 0, 255, 0, 0, 255, 0, 255, 
		0, 255, 0, 255, 0, 162, 4, 255, 42, 
		255, 0, 0, 0, 255, 163, 255, 163, 255, 
		255, 4, 255, 4, 4, 42, 255, 42, 0, 
		255, 0, 0, 255, 0, 0, 0, 0, 255, 
		0, 0, 255, 4, 255, 163, 255, 4, 255, 
		255, 163, 255, 255, 0, 0, 0, 0, 0, 
		0, 0, 0, 42, 162, 0, 255, 0, 0, 
		255, 0, 255, 0, 0, 0, 255, 0, 0, 
		0, 255, 162, 42, 255, 0, 255, 0, 0, 
		0, 255, 0, 0, 0, 0, 0, 162, 42, 
		255, 0, 0, 255, 255, 0, 0, 255, 0, 
		0, 0, 255, 4, 0, 255, 255, 255, 0, 
		4, 255, 0, 0, 0, 255, 255, 0, 42, 
		255, 255, 42, 0, 255, 255, 0, 0, 255, 
		255, 0, 0, 255, 255, 0, 0, 0, 255, 
		0, 0, 255, 255, 0, 0, 0, 255, 0, 
		0, 0, 255, 0, 0, 0, 255, 0, 0, 
		255, 255, 0, 0, 255, 255, 0, 255, 0, 
		255, 0, 0, 255, 4, 255, 4, 255, 255, 
		42, 162, 0, 255, 255, 0, 0, 255, 255, 
		0, 0, 255, 255, 0, 0, 255, 255, 0, 
		0, 255, 255, 0, 0, 0, 0, 0, 255, 
		0, 0, 255, 0, 0, 255, 42, 162, 0, 
		162, 42, 255, 0, 255, 0, 255, 162, 42, 
		42, 162, 0, 255, 0, 255, 0, 0, 0, 
		255, 4, 255, 0, 0, 255, 0, 0, 0, 
		0, 255, 0, 0, 0, 0, 0, 0, 0, 
		0, 42, 255, 255, 255, 255, 162, 255, 42, 
		255, 0, 0, 0, 42, 255, 162, 255, 255, 
		255, 255, 255, 255, 163, 255, 255, 0, 0, 
		255, 255, 162, 255, 42, 255, 0, 255, 255, 
		0, 0, 255, 255, 255, 0, 0, 255, 0, 
		0, 255, 255, 0, 0, 255, 255, 0, 0, 
		255, 255, 0, 0, 255, 255, 0, 0, 255, 
		255, 0, 0, 42, 255, 255, 42, 255, 163, 
		255, 255, 0, 0, 255, 255, 0, 0, 255, 
		255, 0, 255, 0, 255, 0, 255, 255, 0, 
		255, 0, 0, 255, 0, 255, 4, 0, 255, 
		0, 255, 0, 255, 0, 0, 0, 0, 0, 
		255, 0, 0, 0, 4, 255, 4, 255, 4, 
		255, 0, 255, 0, 0, 0, 0, 0, 255, 
		4, 0, 0, 42, 255, 42, 255, 0, 255, 
		0, 0, 255, 255, 4, 255, 4, 255, 4, 
		4, 255, 4, 4, 0, 0, 0, 0, 0, 
		0, 0, 0, 255, 0, 0, 255, 0, 0, 
		255, 0, 255, 42, 255, 255, 42, 42, 255, 
		255, 42, 255, 0, 255, 0, 255, 255, 255, 
		42, 255, 255, 255, 42, 0, 0, 255, 0, 
		42, 255, 255, 42, 42, 255, 255, 255, 0, 
		0, 0, 4, 255, 0, 0, 0, 0, 0, 
		255, 4, 0, 42, 255, 42, 255, 0, 0, 
		0, 0, 255, 0, 255, 255, 255, 255, 255, 
		255, 255, 255, 42, 255, 0, 0, 0, 255, 
		0, 0, 255, 255, 255, 255, 42, 255, 255, 
		255, 42, 255, 0, 255, 255, 255, 255, 255, 
		255, 255, 0, 0, 255, 255, 255, 4, 0, 
		255, 0, 0, 255, 0, 0, 0, 255, 255, 
		0, 255, 0, 255, 255, 0, 0, 255, 255, 
		255, 255, 42, 255, 0, 0, 255, 255, 255, 
		255, 42, 42, 255, 255, 42, 0, 0, 255, 
		0, 0, 255, 0, 0, 255, 0, 255, 0, 
		255, 0, 255, 0, 255, 0, 255, 0, 255, 
		255, 0, 0, 4, 255, 4, 0, 0, 162, 
		42, 0, 255, 0, 0, 4, 255, 0, 0, 
		0, 255, 0, 0, 0, 0, 0, 0, 0, 
		0, 255, 0, 0, 255, 255, 42, 0, 255, 
		255, 0, 0, 0, 255, 0, 42, 255, 255, 
		0, 0, 0, 4, 255, 4, 255, 0, 42, 
		255, 255, 42, 0, 255, 255, 0, 255, 255, 
		0, 255, 4, 255, 255, 0, 0, 255, 0, 
		0, 255, 255, 0, 0, 255, 255, 0, 0, 
		255, 255, 42, 0, 255, 255, 0, 42, 255, 
		255, 0, 0, 0, 0, 0, 255, 4, 255, 
		4, 255, 0, 42, 255, 162, 42, 42, 162, 
		255, 0, 255, 0, 255, 162, 42, 42, 162, 
		255, 0, 0, 255, 255, 4, 0, 0, 255, 
		0, 255, 0, 255, 0, 0, 0, 0, 0, 
		255, 0, 0, 0, 255, 163, 255, 163, 255, 
		42, 255, 163, 255, 42, 0, 0, 255, 4, 
		42, 255, 42, 255, 4, 255, 4, 0, 255, 
		0, 0, 255, 0, 0, 255, 0, 0, 0, 
		0, 255, 0, 0, 0, 0, 0, 0, 0, 
		0, 0, 162, 42, 0, 0, 255, 0, 0, 
		255, 0, 255, 255, 0, 0, 0, 0, 4, 
		4, 255, 255, 255, 163, 255, 0, 0, 0, 
		255, 255, 0, 0, 255, 0, 42, 162, 0, 
		255, 4, 4, 255, 0, 0, 0, 255, 255, 
		42, 255, 0, 4, 255, 0, 0, 0, 255, 
		4, 0, 0, 255, 0, 0, 255, 0, 42, 
		255, 255, 255, 0, 255, 255, 0, 0, 255, 
		255, 4, 4, 255, 255, 0, 0, 0, 255, 
		0, 0, 255, 255, 0, 0, 0, 255, 0, 
		0, 0, 255, 0, 0, 255, 255, 0, 0, 
		255, 255, 0, 0, 255, 255, 4, 255, 0, 
		255, 0, 0, 255, 0, 0, 0, 255, 255, 
		0, 162, 42, 255, 255, 0, 0, 255, 255, 
		0, 0, 0, 255, 0, 0, 255, 255, 0, 
		42, 162, 0, 0, 0, 255, 0, 0, 255, 
		0, 0, 255, 0, 0, 255, 0, 162, 42, 
		163, 0, 255, 0, 255, 0, 255, 162, 42, 
		42, 162, 0, 0, 255, 0, 0, 0, 255, 
		0, 0, 255, 0, 0, 0, 4, 255, 0, 
		0, 255, 0, 0, 0, 0, 0, 0, 0, 
		0, 42, 255, 255, 255, 255, 0, 0, 255, 
		42, 255, 255, 255, 255, 0, 0, 255, 42, 
		255, 255, 42, 0, 255, 0, 42, 255, 162, 
		255, 255, 0, 0, 255, 255, 0, 255, 255, 
		255, 4, 0, 255, 255, 0, 0, 255, 0, 
		0, 255, 255, 0, 0, 255, 42, 255, 255, 
		42, 255, 162, 255, 42, 42, 255, 162, 255, 
		255, 0, 0, 255, 255, 255, 42, 0, 255, 
		0, 42, 255, 162, 255, 0, 255, 255, 0, 
		42, 255, 44, 255, 42, 255, 0, 0, 255, 
		42, 255, 255, 255, 255, 255, 255, 255, 4, 
		0, 255, 0, 4, 255, 0, 0, 0, 0, 
		0, 0, 0, 0, 4, 255, 4, 255, 4, 
		0, 4, 255, 4, 255, 0, 42, 162, 0, 
		255, 0, 255, 255, 0, 255, 0, 0, 255, 
		0, 0, 255, 0, 0, 0, 0, 0, 0, 
		0, 0, 0, 0, 0, 0, 0, 0, 0, 
		0, 0, 255, 0, 0, 0, 255, 0, 0, 
		255, 0, 255, 255, 0, 0, 0, 0, 0, 
		0, 255, 4, 4, 255, 4, 0, 0, 0, 
		255, 255, 0, 0, 255, 0, 255, 0, 0, 
		255, 0, 0, 255, 0, 0, 0, 255, 0, 
		162, 0, 0, 0, 0, 0, 0, 0, 0, 
		0, 0, 0, 0, 0, 0, 255, 0, 255, 
		0, 0, 255, 0, 255, 255, 0, 0, 255, 
		255, 0, 0, 255, 255, 0, 0, 0, 255, 
		0, 0, 255, 255, 0, 0, 0, 255, 0, 
		0, 0, 255, 0, 0, 255, 255, 0, 0, 
		255, 255, 0, 0, 255, 255, 0, 162, 42, 
		255, 0, 0, 255, 0, 0, 0, 255, 255, 
		0, 0, 255, 255, 255, 0, 0, 255, 255, 
		0, 0, 0, 255, 0, 0, 255, 255, 0, 
		0, 255, 0, 0, 0, 255, 0, 0, 255, 
		0, 0, 255, 0, 0, 255, 0, 0, 255, 
		4, 0, 255, 0, 255, 0, 255, 255, 0, 
		0, 255, 0, 0, 255, 0, 0, 255, 4, 
		0, 0, 255, 0, 0, 0, 0, 162, 42, 
		0, 255, 0, 0, 0, 0, 0, 0, 0, 
		0, 0, 0, 0, 0, 255, 42, 0, 255, 
		0, 0, 0, 0, 255, 0, 42, 255, 0, 
		0, 0, 0, 0, 255, 0, 0, 0, 0, 
		255, 255, 0, 0, 255, 255, 0, 255, 255, 
		4, 255, 0, 255, 0, 0, 0, 0, 0, 
		0, 0, 0, 0, 0, 0, 0, 0, 0, 
		0, 255, 0, 0, 0, 0, 0, 0, 255, 
		0, 0, 0, 0, 0, 0, 0, 0, 255, 
		0, 0, 0, 0, 0, 0, 0, 0, 0, 
		0, 0, 0, 0, 0, 0, 0, 0, 0, 
		0, 0, 0, 255, 0, 0, 0, 4, 255, 
		0, 255, 0, 255, 4, 0, 0, 0, 0, 
		255, 0, 0, 0, 0, 255, 0, 255, 0, 
		0, 0, 255, 0, 255, 0, 255, 0, 0, 
		42, 255, 42, 42, 255, 44, 255, 0, 255, 
		0, 0, 255, 0, 0, 0, 0, 0, 0, 
		0, 0, 0, 0, 0, 0, 0, 0, 0, 
		0, 255, 4, 0, 0, 0, 42, 255, 255, 
		42, 0, 255, 255, 255, 255, 255, 255, 255, 
		255, 42, 0, 0, 255, 0, 255, 255, 255, 
		42, 42, 255, 255, 42, 0, 255, 0, 0, 
		42, 255, 255, 42, 42, 255, 255, 42, 0, 
		0, 0, 0, 0, 0, 0, 0, 0, 0, 
		0, 0, 0, 255, 0, 0, 255, 0, 42, 
		255, 255, 255, 0, 255, 255, 0, 0, 255, 
		255, 255, 255, 42, 42, 255, 255, 255, 255, 
		255, 255, 42, 255, 255, 255, 255, 255, 0, 
		0, 0, 42, 255, 255, 255, 255, 0, 0, 
		255, 255, 255, 255, 42, 255, 0, 0, 255, 
		255, 255, 255, 255, 0, 0, 0, 255, 255, 
		0, 0, 0, 255, 42, 255, 255, 42, 255, 
		0, 0, 0, 42, 255, 255, 42, 255, 0, 
		0, 255, 255, 255, 255, 42, 0, 0, 255, 
		0, 0, 42, 255, 255, 42, 0, 0, 255, 
		4, 0, 42, 255, 44, 255, 42, 255, 0, 
		0, 255, 0, 0, 255, 0, 0, 255, 255, 
		255, 255, 255, 0, 0, 0, 0, 0, 255, 
		0, 255, 0, 0, 0, 0, 0, 0, 0, 
		0, 0, 0, 0, 0, 255, 162, 255, 42, 
		0, 0, 0, 0, 42, 255, 162, 255, 0, 
		0, 0, 0, 0, 255, 0, 42, 255, 255, 
		42, 255, 0, 0, 255, 255, 0, 255, 255, 
		0, 4, 255, 255, 0, 0, 0, 0, 0, 
		0, 0, 0, 0, 0, 0, 0, 0, 0, 
		0, 162, 0, 0, 0, 0, 0, 0, 162, 
		0, 0, 0, 0, 0, 0, 0, 0, 162, 
		255, 0, 0, 0, 0, 0, 0, 0, 0, 
		0, 0, 0, 0, 0, 0, 0, 0, 0, 
		42, 255, 255, 42, 0, 0, 0, 0, 255, 
		0, 255, 0, 255, 0, 0, 0, 0, 0, 
		0, 0, 0, 0, 0, 0, 0, 0, 0, 
		255, 255, 163, 255, 42, 0, 0, 0, 0, 
		0, 0, 0, 0, 0, 0, 0, 0, 255, 
		0, 0, 255, 0, 0, 0, 0, 0, 0, 
		0, 0, 0, 0, 0, 0, 0, 0, 0, 
		0, 0, 0, 0, 0, 0, 0, 0, 0, 
		0, 0, 0, 0, 0, 0, 0, 0, 0, 
		0, 0, 0, 0, 0, 0, 0, 0, 0, 
		0, 0, 0, 0, 0, 0, 0, 0, 0, 
		0, 0, 0, 0, 0, 0, 0, 0, 0, 
		0, 0, 0, 0, 0, 0, 0, 0, 0, 
		0, 0, 0, 0, 0, 0, 42, 255, 0, 
		0, 0, 42, 255, 42, 0, 0, 0, 0, 
		0, 0, 0, 0, 0, 0, 0, 0, 0, 
		0, 0, 0, 0, 0, 0, 0, 0, 0, 
		0, 0, 0, 0, 0, 0, 0, 0, 0, 
		0, 0, 0, 0, 0, 0, 0, 0, 0, 
		0, 0, 0, 0, 0, 0, 0, 0, 0, 
		0, 0, 0, 0, 0, 0, 0, 0, 0, 
		0, 0, 0, 0, 0, 42, 255, 0, 0, 
		0, 0, 0, 0, 0, 0, 0, 0, 0, 
		0, 0, 0, 0, 0, 0, 0, 0, 0, 
		0, 0, 0, 0, 0, 0, 0, 0, 0, 
		0, 0, 0, 0, 0, 0, 0, 0, 0, 
		0, 0, 255, 0, 0, 0, 0, 0, 0, 
		0, 255, 0, 0, 0, 0, 0, 0, 0, 
		0, 0, 0, 0, 0, 0, 0, 0, 0, 
		0, 0, 0, 0, 0, 0, 0, 0, 0, 
		0, 0, 0, 0, 0, 0, 0, 0, 0, 
		0, 0, 0, 0, 0, 0, 0, 255, 0, 
		0, 0, 0, 0, 0, 0, 0, 0, 0, 
		0, 0, 0, 0, 0, 0, 0, 0, 0, 
		0, 0, 0, 0, 0, 0, 0, 0, 0, 
		0, 0, 0, 0, 0, 0, 0, 0, 0, 
		0, 0, 0, 0, 0, 0, 0, 0, 0, 
		0, 0, 0, 0, 0, 0, 0, 0, 0, 
		0, 0, 0, 0, 0, 0, 0, 0, 255, 
		0, 255, 0, 255, 0, 0, 0, 0, 0, 
		0, 0, 0, 0, 0, 0, 0, 0, 0, 
		4, 4, 255, 4, 0, 0, 0, 0, 0, 
		0, 0, 0, 0, 0, 0, 0, 0, 42, 
		255, 255, 42, 0, 0, 0, 0, 0, 0, 
		0, 0, 0, 0, 0, 0, 0, 0, 0, 
		0, 0, 0, 0, 0, 0, 0, 0, 0, 
		0, 0, 0, 0, 0, 0, 0, 0, 0, 
		0, 0, 0, 0, 0, 0, 0, 0, 0, 
		0, 0, 0, 0, 0, 0, 0, 0, 0, 
		0, 0, 0, 0, 0, 0, 0, 0, 0, 
		0, 0, 0, 0, 0, 0, 0, 0, 0, 
		0, 0, 0, 0, 0, 0, 0, 42, 255, 
		255, 255, 0, 0, 0, 0, 0, 0, 0, 
		0, 0, 0, 0, 0, 0, 0, 0, 0, 
		0, 0, 0, 0, 0, 0, 0, 0, 0, 
		0, 0, 0, 0, 0, 0, 0, 0, 0, 
		0, 0, 0, 0, 0, 0, 0, 0, 0, 
		0, 0, 0, 0, 0, 0, 0, 0, 0, 
		0, 0, 0, 0, 0, 0, 0, 0, 0, 
		0, 0, 0, 0, 0, 0, 0, 0, 0, 
		0, 0, 0, 0, 0, 0, 0, 0, 0, 
		0, 0, 0, 0, 0, 0, 0, 0, 0, 
		0, 0, 0, 0, 0, 0, 0, 0, 0, 
		0, 0, 0, 0, 0, 0, 0, 0, 0, 
		0, 0, 255, 255, 0, 0, 0, 0, 0, 
		255, 255, 0, 0, 0, 0, 0, 0, 0, 
		0, 0, 0, 0, 0, 0, 0, 0, 0, 
		0, 0, 0, 0, 0, 0, 0, 0, 0, 
		0, 0, 0, 0, 0, 0, 0, 0, 0, 
		0, 0, 0, 0, 0, 0, 255, 42, 0, 
		0, 0, 0, 0, 0, 0, 0, 0, 0, 
		0, 0, 0, 0, 0, 0, 0, 0, 0, 
		0, 0, 0, 0, 0, 0, 0, 0, 0, 
		0, 0, 0, 0, 0, 0, 0, 0, 0, 
		0, 0, 0, 0, 0, 0, 0, 0, 0, 
		0, 0, 0, 0, 0, 0, 0, 0, 0, 
		0, 0, 0, 0, 0, 0, 0, 0, 42, 
		255, 255, 255, 42, 0, 0, 0, 0, 0
	};

	Reference<Bitmap> bitmap = new Bitmap(width, height,PixelFormat::MONO);
	std::copy(std::begin(data), std::end(data), bitmap->data());

	return std::make_pair(std::move(bitmap), fontInfo);
}

}
}
