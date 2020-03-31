/*
	This file is part of the E_Sound library.
	Copyright (C) 2008-2012 Benjamin Eikel <benjamin@eikel.org>
	Copyright (C) 2008-2012 Claudius Jähn <claudius@uni-paderborn.de>
	
	This library is subject to the terms of the Mozilla Public License, v. 2.0.
	You should have received a copy of the MPL along with this library; see the 
	file LICENSE. If not, you can obtain one at http://mozilla.org/MPL/2.0/.
*/
#include "E_Listener.h"

#include <EScript/EScript.h>

namespace E_Sound{

using namespace EScript;
using namespace Sound;

//! [static]
Type * E_Listener::getTypeObject(){
	// [Buffer] ---|> [Object]
	static EScript::Type * typeObject = new EScript::Type(Object::getTypeObject());
	return typeObject;
}

//! initMembers
void E_Listener::init(EScript::Namespace & lib) {

	EScript::Type * typeObject = getTypeObject();
	declareConstant(&lib,getClassName(),typeObject);

	//! [ESMF] Number Listener.getDistanceModel()
	ES_MFUN(typeObject,E_Listener,"getDistanceModel",0,0,Number::create((**thisObj)->getDistanceModel()))

	//! [ESMF] Number Listener.getDopplerFactor()
	ES_MFUN(typeObject,E_Listener,"getDopplerFactor",0,0,Number::create((**thisObj)->getDopplerFactor()))

	//! [ESMF] Number Listener.getGain()
	ES_MFUN(typeObject,E_Listener,"getGain",0,0,Number::create((**thisObj)->getGain()))

	//! [ESMF] [atX,atY,atZ,dirX,dirY,dirZ] Listener.getOrientation()
	ES_MFUNCTION(typeObject,E_Listener,"getOrientation",0,0,{
		float f[6];
		(**thisObj)->getOrientation(f[0],f[1],f[2],f[3],f[4],f[5]);
		Array * a = Array::create();
		a->pushBack(Number::create(f[0]));
		a->pushBack(Number::create(f[1]));
		a->pushBack(Number::create(f[2]));
		a->pushBack(Number::create(f[3]));
		a->pushBack(Number::create(f[4]));
		a->pushBack(Number::create(f[5]));
		return a;
	})

	//! [ESMF] [x,y,z] Listener.getPosition()
	ES_MFUNCTION(typeObject,E_Listener,"getPosition",0,0,{
		float f[3];
		(**thisObj)->getPosition(f[0],f[1],f[2]);
		Array * a = Array::create();
		a->pushBack(Number::create(f[0]));
		a->pushBack(Number::create(f[1]));
		a->pushBack(Number::create(f[2]));
		return a;
	})

	//! [ESMF] Number Listener.getSpeedOfSound()
	ES_MFUN(typeObject,E_Listener,"getSpeedOfSound",0,0,Number::create((**thisObj)->getSpeedOfSound()))

	//! [ESMF] [x,y,z] Listener.getVelocity()
	ES_MFUNCTION(typeObject,E_Listener,"getVelocity",0,0,{
		float f[3];
		(**thisObj)->getVelocity(f[0],f[1],f[2]);
		Array * a = Array::create();
		a->pushBack(Number::create(f[0]));
		a->pushBack(Number::create(f[1]));
		a->pushBack(Number::create(f[2]));
		return a;
	})

	//! [ESMF] thisObj Listener.setDistanceModel( int )
	ES_MFUN(typeObject,E_Listener,"setDistanceModel",1,1,((**thisObj)->setDistanceModel(parameter[0].toInt()),thisEObj))

	//! [ESMF] thisObj Listener.setDopplerFactor( float )
	ES_MFUN(typeObject,E_Listener,"setDopplerFactor",1,1,((**thisObj)->setDopplerFactor(parameter[0].toFloat()),thisEObj))

	//! [ESMF] thisObj Listener.setGain( float )
	ES_MFUN(typeObject,E_Listener,"setGain",1,1,((**thisObj)->setGain(parameter[0].toFloat()),thisEObj))

	//! [ESMF] thisObj Listener.setOrientation( float atX,float atY, float atZ, float dirX, float dirY, float dirZ )
	ES_MFUN(typeObject,E_Listener,"setOrientation",6,6,((**thisObj)->setOrientation(
			parameter[0].toFloat(),parameter[1].toFloat(),parameter[2].toFloat(),
			parameter[3].toFloat(),parameter[4].toFloat(),parameter[5].toFloat()),thisEObj))

	//! [ESMF] thisObj Listener.setPosition( float x,float y, float z )
	ES_MFUN(typeObject,E_Listener,"setPosition",3,3,((**thisObj)->setPosition(
			parameter[0].toFloat(),parameter[1].toFloat(),parameter[2].toFloat()),thisEObj))

	//! [ESMF] thisObj Listener.setSpeedOfSound( float )
	ES_MFUN(typeObject,E_Listener,"setSpeedOfSound",1,1,((**thisObj)->setSpeedOfSound(parameter[0].toFloat()),thisEObj))

	//! [ESMF] thisObj Listener.setVelocity( float x,float y, float z )
	ES_MFUN(typeObject,E_Listener,"setVelocity",3,3,((**thisObj)->setVelocity(
			parameter[0].toFloat(),parameter[1].toFloat(),parameter[2].toFloat()),thisEObj))

}

}
