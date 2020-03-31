/*
	This file is part of the E_Sound library.
	Copyright (C) 2008-2012 Benjamin Eikel <benjamin@eikel.org>
	Copyright (C) 2008-2012 Claudius Jähn <claudius@uni-paderborn.de>
	
	This library is subject to the terms of the Mozilla Public License, v. 2.0.
	You should have received a copy of the MPL along with this library; see the 
	file LICENSE. If not, you can obtain one at http://mozilla.org/MPL/2.0/.
*/
#ifndef __E_Source_H
#define __E_Source_H

#include <EScript/Objects/ReferenceObject.h>
#include <Sound/Source.h>
#include <Util/References.h>

namespace E_Sound {


/***
 ** E_Source ---|> ReferenceObject<Util::Reference<Sound::Source> >
 **/
class E_Source : public EScript::ReferenceObject<Util::Reference<Sound::Source> > {
	ES_PROVIDES_TYPE_NAME(Source)
	public:
		static EScript::Type * getTypeObject();
		static void init(EScript::Namespace & lib);

		static E_Source * create();
		static E_Source * create(Sound::Source * source);

		virtual ~E_Source() {}

	private:
		E_Source(Sound::Source * source, EScript::Type * type=nullptr) : ReferenceObject_t(source,type?type:getTypeObject()){}
};

}

#endif // __E_Source_H
