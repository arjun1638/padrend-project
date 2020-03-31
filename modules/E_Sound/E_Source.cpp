/*
	This file is part of the E_Sound library.
	Copyright (C) 2008-2012 Benjamin Eikel <benjamin@eikel.org>
	Copyright (C) 2008-2012 Claudius Jähn <claudius@uni-paderborn.de>
	
	This library is subject to the terms of the Mozilla Public License, v. 2.0.
	You should have received a copy of the MPL along with this library; see the 
	file LICENSE. If not, you can obtain one at http://mozilla.org/MPL/2.0/.
*/
#include "E_Source.h"
#include "E_Buffer.h"

#include <EScript/EScript.h>

namespace E_Sound{

using namespace EScript;
using namespace Sound;

//! [static]
Type * E_Source::getTypeObject(){
	// [Buffer] ---|> [Object]
	static EScript::Type * typeObject = new EScript::Type(Object::getTypeObject());
	return typeObject;
}

//! initMembers
void E_Source::init(EScript::Namespace & lib) {

	 EScript::Type * typeObject = getTypeObject();
	declareConstant(&lib,getClassName(),typeObject);

	//! [ESMF] thisObj Source.dequeueBuffers( number )
	ES_MFUN(typeObject,E_Source,"dequeueBuffers",1,1,((**thisObj)->dequeueBuffers(parameter[0].toInt()),thisEObj))

	//! [ESMF] thisObj Source.enqueueBuffer(Buffer)
	ES_MFUN(typeObject,E_Source,"enqueueBuffer",1,1,((**thisObj)->enqueueBuffer(EScript::assertType<E_Buffer>(rt,parameter[0])->ref().get()),thisEObj))

	//! [ESMF] [x,y,z] Source.getDirection()
	ES_MFUNCTION(typeObject,E_Source,"getDirection",0,0,{
		float f[3];
		(**thisObj)->getDirection(f[0],f[1],f[2]);
		Array * a = Array::create();
		a->pushBack(Number::create(f[0]));
		a->pushBack(Number::create(f[1]));
		a->pushBack(Number::create(f[2]));
		return a;
	})

	//! [ESMF] Number Source.getNumBuffersProcessed()
	ES_MFUN(typeObject,E_Source,"getNumBuffersProcessed",0,0,Number::create((**thisObj)->getNumBuffersProcessed()))

	//! [ESMF] Number Source.getNumBuffersQueued()
	ES_MFUN(typeObject,E_Source,"getNumBuffersQueued",0,0,Number::create((**thisObj)->getNumBuffersQueued()))

	//! [ESMF] [x,y,z] Source.getPosition()
	ES_MFUNCTION(typeObject,E_Source,"getPosition",0,0,{
		float f[3];
		(**thisObj)->getPosition(f[0],f[1],f[2]);
		Array * a = Array::create();
		a->pushBack(Number::create(f[0]));
		a->pushBack(Number::create(f[1]));
		a->pushBack(Number::create(f[2]));
		return a;
	})

	//! [ESMF] [x,y,z] Source.getVelocity()
	ES_MFUNCTION(typeObject,E_Source,"getVelocity",0,0,{
		float f[3];
		(**thisObj)->getVelocity(f[0],f[1],f[2]);
		Array * a = Array::create();
		a->pushBack(Number::create(f[0]));
		a->pushBack(Number::create(f[1]));
		a->pushBack(Number::create(f[2]));
		return a;
	})

	//! [ESMF] Bool Source.isLooping()
	ES_MFUN(typeObject,E_Source,"isLooping",0,0,Bool::create((**thisObj)->isLooping()))

	//! [ESMF] Bool Source.isPlaying()
	ES_MFUN(typeObject,E_Source,"isPlaying",0,0,Bool::create((**thisObj)->isPlaying()))

	//! [ESMF] Bool Source.isSourceRelative()
	ES_MFUN(typeObject,E_Source,"isSourceRelative",0,0,Bool::create((**thisObj)->isSourceRelative()))

	//! [ESMF] thisObj Source.pause( )
	ES_MFUN(typeObject,E_Source,"pause",0,0,((**thisObj)->pause(),thisEObj))

	//! [ESMF] thisObj Source.play( )
	ES_MFUN(typeObject,E_Source,"play",0,0,((**thisObj)->play(),thisEObj))

	//! [ESMF] thisObj Source.rewind( )
	ES_MFUN(typeObject,E_Source,"rewind",0,0,((**thisObj)->rewind(),thisEObj))

	//! [ESMF] thisObj Source.setConeInnerAngle( float )
	ES_MFUN(typeObject,E_Source,"setConeInnerAngle",1,1,((**thisObj)->setConeInnerAngle(parameter[0].toFloat()),thisEObj))

	//! [ESMF] thisObj Source.setConeOuterAngle( float )
	ES_MFUN(typeObject,E_Source,"setConeOuterAngle",1,1,((**thisObj)->setConeOuterAngle(parameter[0].toFloat()),thisEObj))

	//! [ESMF] thisObj Source.setConeOuterGain( float )
	ES_MFUN(typeObject,E_Source,"setConeOuterGain",1,1,((**thisObj)->setConeOuterGain(parameter[0].toFloat()),thisEObj))

	//! [ESMF] thisObj Source.setDirection( float x,float y, float z )
	ES_MFUN(typeObject,E_Source,"setDirection",3,3,((**thisObj)->setDirection(
			parameter[0].toFloat(),parameter[1].toFloat(),parameter[2].toFloat()),thisEObj))

	//! [ESMF] thisObj Source.setGain( float )
	ES_MFUN(typeObject,E_Source,"setGain",1,1,((**thisObj)->setGain(parameter[0].toFloat()),thisEObj))

	//! [ESMF] thisObj Source.setLooping( bool )
	ES_MFUN(typeObject,E_Source,"setLooping",1,1,((**thisObj)->setLooping(parameter[0].toBool()),thisEObj))

	//! [ESMF] thisObj Source.setMaxGain( float )
	ES_MFUN(typeObject,E_Source,"setMaxGain",1,1,((**thisObj)->setMaxGain(parameter[0].toFloat()),thisEObj))

	//! [ESMF] thisObj Source.setMinGain( float )
	ES_MFUN(typeObject,E_Source,"setMinGain",1,1,((**thisObj)->setMinGain(parameter[0].toFloat()),thisEObj))

	//! [ESMF] thisObj Source.setPitch( float )
	ES_MFUN(typeObject,E_Source,"setPitch",1,1,((**thisObj)->setPitch(parameter[0].toFloat()),thisEObj))

	//! [ESMF] thisObj Source.setPosition( float x,float y, float z )
	ES_MFUN(typeObject,E_Source,"setPosition",3,3,((**thisObj)->setPosition(
			parameter[0].toFloat(),parameter[1].toFloat(),parameter[2].toFloat()),thisEObj))

	//! [ESMF] thisObj Source.setRolloffFactor( float )
	ES_MFUN(typeObject,E_Source,"setRolloffFactor",1,1,((**thisObj)->setRolloffFactor(parameter[0].toFloat()),thisEObj))

	//! [ESMF] thisObj Source.setSourceIsRelative( bool )
	ES_MFUN(typeObject,E_Source,"setSourceIsRelative",1,1,((**thisObj)->setSourceIsRelative(parameter[0].toBool()),thisEObj))

	//! [ESMF] thisObj Source.setReferenceDistance( float )
	ES_MFUN(typeObject,E_Source,"setReferenceDistance",1,1,((**thisObj)->setReferenceDistance(parameter[0].toFloat()),thisEObj))

	//! [ESMF] thisObj Source.setVelocity( float x,float y, float z )
	ES_MFUN(typeObject,E_Source,"setVelocity",3,3,((**thisObj)->setVelocity(
			parameter[0].toFloat(),parameter[1].toFloat(),parameter[2].toFloat()),thisEObj))

	//! [ESMF] thisObj Source.stop( )
	ES_MFUN(typeObject,E_Source,"stop",0,0,((**thisObj)->stop(),thisEObj))

}

//---
//! [static] factory
E_Source * E_Source::create(){
	return create(Source::create());
}

//! [static] factory
E_Source * E_Source::create(Source * source){
	if(source==nullptr){
		return nullptr;
	}
	return new E_Source(source);
}

}
