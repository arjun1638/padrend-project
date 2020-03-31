/*
	This file is part of the E_Sound library.
	Copyright (C) 2008-2012 Benjamin Eikel <benjamin@eikel.org>
	Copyright (C) 2008-2012 Claudius Jähn <claudius@uni-paderborn.de>
	
	This library is subject to the terms of the Mozilla Public License, v. 2.0.
	You should have received a copy of the MPL along with this library; see the 
	file LICENSE. If not, you can obtain one at http://mozilla.org/MPL/2.0/.
*/
#include "E_Buffer.h"

#include <EScript/EScript.h>

using namespace EScript;

namespace E_Sound {

//! [static]
Type * E_Buffer::getTypeObject(){
	// [Buffer] ---|> [Object]
	static EScript::Type * typeObject = new EScript::Type(Object::getTypeObject());
	return typeObject;
}

//!	[static] initMembers
void E_Buffer::init(EScript::Namespace & lib) {

	EScript::Type * typeObject = getTypeObject();
	declareConstant(&lib,getClassName(),typeObject);

	//! [ESMF] Number Buffer.getFrequency()
	ES_MFUN(typeObject,E_Buffer,"getFrequency",0,0,Number::create((**thisObj)->getFrequency()))

	//! [ESMF] Number Buffer.getBits()
	ES_MFUN(typeObject,E_Buffer,"getBits",0,0,Number::create((**thisObj)->getBits()))

	//! [ESMF] Number Buffer.getChannels()
	ES_MFUN(typeObject,E_Buffer,"getChannels",0,0,Number::create((**thisObj)->getChannels()))

	//! [ESMF] Number Buffer.getDataSize()
	ES_MFUN(typeObject,E_Buffer,"getDataSize",0,0,Number::create((**thisObj)->getDataSize()))
}

//---
//! [static] factory
E_Buffer * E_Buffer::create(Sound::Buffer * b){
	return b == nullptr ? nullptr : new E_Buffer(b);
}

}
