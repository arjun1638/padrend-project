/*
	This file is part of the E_MinSG library.
	Copyright (C) 2007-2012 Benjamin Eikel <benjamin@eikel.org>
	Copyright (C) 2007-2012 Claudius Jähn <claudius@uni-paderborn.de>
	Copyright (C) 2007-2012 Ralf Petring <ralf@petring.net>
	
	This library is subject to the terms of the Mozilla Public License, v. 2.0.
	You should have received a copy of the MPL along with this library; see the 
	file LICENSE. If not, you can obtain one at http://mozilla.org/MPL/2.0/.
*/
#ifndef __E_StrangeExampleRenderer_H
#define __E_StrangeExampleRenderer_H

#include "../../Core/States/E_State.h"
#include <MinSG/Ext/States/StrangeExampleRenderer.h>

namespace E_MinSG {
/***
 **   E_StrangeExampleRenderer ---|> E_State ---|> Object
 **/
class E_StrangeExampleRenderer : public E_State{
		ES_PROVIDES_TYPE_NAME(StrangeExampleRenderer)
	public:
		template<class, class, class> friend class Util::PolymorphicWrapperCreator;

		static EScript::Type* typeObject;
		static void init(EScript::Namespace & lib);

		virtual ~E_StrangeExampleRenderer();

		const MinSG::StrangeExampleRenderer * operator*()const	{	return static_cast<const MinSG::StrangeExampleRenderer*>(ref().get());	}
		MinSG::StrangeExampleRenderer * operator*()				{	return static_cast<MinSG::StrangeExampleRenderer*>(ref().get());	}

	protected:
		E_StrangeExampleRenderer(MinSG::StrangeExampleRenderer * obj, EScript::Type * type=nullptr);
};
}

ES_CONV_EOBJ_TO_OBJ(E_MinSG::E_StrangeExampleRenderer, MinSG::StrangeExampleRenderer *, **eObj)

#endif // __E_StrangeExampleRenderer_H
