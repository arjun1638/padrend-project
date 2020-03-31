/*
	This file is part of the E_MinSG library.
	Copyright (C) 2007-2012 Benjamin Eikel <benjamin@eikel.org>
	Copyright (C) 2007-2012 Claudius Jähn <claudius@uni-paderborn.de>
	Copyright (C) 2007-2012 Ralf Petring <ralf@petring.net>
	
	This library is subject to the terms of the Mozilla Public License, v. 2.0.
	You should have received a copy of the MPL along with this library; see the 
	file LICENSE. If not, you can obtain one at http://mozilla.org/MPL/2.0/.
*/
#ifndef E_GroupState_H
#define E_GroupState_H

#include "E_State.h"
#include <MinSG/Core/States/GroupState.h>

namespace E_MinSG{

/**
 *  [E_GroupState] ---|> [E_State]
 */
class E_GroupState : public E_State{
	ES_PROVIDES_TYPE_NAME(GroupState)

	public:
		template<class, class, class> friend class Util::PolymorphicWrapperCreator;

		static EScript::Type * getTypeObject();
		static void init(EScript::Namespace & lib);

		virtual ~E_GroupState()	{}
	
		const MinSG::GroupState * operator*()const	{	return static_cast<const MinSG::GroupState*>(ref().get());	}
		MinSG::GroupState * operator*()				{	return static_cast<MinSG::GroupState*>(ref().get());	}

	protected:
		E_GroupState(MinSG::GroupState * c,EScript::Type * type=nullptr) : E_State(c, type ? type : getTypeObject()) {}
};
}

ES_CONV_EOBJ_TO_OBJ(E_MinSG::E_GroupState,		MinSG::GroupState*,		**eObj)	

#endif // E_GroupState_H
