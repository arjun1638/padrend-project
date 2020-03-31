/*
	This file is part of the E_MinSG library extension SVS.
	Copyright (C) 2012 Benjamin Eikel <benjamin@eikel.org>
	
	This library is subject to the terms of the Mozilla Public License, v. 2.0.
	You should have received a copy of the MPL along with this library; see the 
	file LICENSE. If not, you can obtain one at http://mozilla.org/MPL/2.0/.
*/
#ifdef MINSG_EXT_SVS

#ifndef E_MINSG_SVS_E_HELPER_H_
#define E_MINSG_SVS_E_HELPER_H_

namespace EScript {
class Namespace;
}
namespace E_MinSG {
namespace SVS {

//!	EScript wrapper class for MinSG::SVS helper functions
namespace E_Helper {
void init(EScript::Namespace & lib);
}

}
}

#endif /* E_MINSG_SVS_E_HELPER_H_ */

#endif /* MINSG_EXT_SVS */
