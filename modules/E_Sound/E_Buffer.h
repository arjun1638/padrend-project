/*
	This file is part of the E_Sound library.
	Copyright (C) 2008-2012 Benjamin Eikel <benjamin@eikel.org>
	Copyright (C) 2008-2012 Claudius Jähn <claudius@uni-paderborn.de>
	
	This library is subject to the terms of the Mozilla Public License, v. 2.0.
	You should have received a copy of the MPL along with this library; see the 
	file LICENSE. If not, you can obtain one at http://mozilla.org/MPL/2.0/.
*/
#ifndef __E_Buffer_H
#define __E_Buffer_H

#include <EScript/Objects/ReferenceObject.h>
#include <Sound/Buffer.h>
#include <Util/References.h>

namespace E_Sound {

/***
 ** E_Buffer ---|> ReferenceObject<Util::Reference<Sound::Buffer> >
 **/
class E_Buffer : public EScript::ReferenceObject<Util::Reference<Sound::Buffer> > {
	ES_PROVIDES_TYPE_NAME(Buffer)

	public:
		static EScript::Type * getTypeObject();
		static void init(EScript::Namespace & lib);
		static E_Buffer * create(Sound::Buffer * buffer);

		virtual ~E_Buffer() {}

	private:
		E_Buffer(Sound::Buffer * buffer,EScript::Type * type=nullptr) : ReferenceObject_t(buffer,type?type:getTypeObject()) {}
};

}

#endif // __E_Buffer_H
