/*
	This file is part of the E_Sound library.
	Copyright (C) 2008-2012 Benjamin Eikel <benjamin@eikel.org>
	Copyright (C) 2008-2012 Claudius Jähn <claudius@uni-paderborn.de>
	
	This library is subject to the terms of the Mozilla Public License, v. 2.0.
	You should have received a copy of the MPL along with this library; see the 
	file LICENSE. If not, you can obtain one at http://mozilla.org/MPL/2.0/.
*/
#ifndef __E_Listener_H
#define __E_Listener_H

#include <EScript/Objects/ReferenceObject.h>
#include <Sound/Listener.h>
#include <Util/References.h>

namespace E_Sound {

/***
 ** E_Listener ---|> ReferenceObject<Util::WeakPointer<Sound::Listener> >
 **/
class E_Listener : public EScript::ReferenceObject<Util::WeakPointer<Sound::Listener> > {
	ES_PROVIDES_TYPE_NAME(Listener)
	public:
		static EScript::Type * getTypeObject();
		static void init(EScript::Namespace & lib);

		E_Listener(Sound::Listener * listener, EScript::Type * type=nullptr) : ReferenceObject_t(listener,type?type:getTypeObject()) {}
		virtual ~E_Listener() {}
};

}

#endif // __E_Listener_H
