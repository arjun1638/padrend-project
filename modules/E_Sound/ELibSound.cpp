/*
	This file is part of the E_Sound library.
	Copyright (C) 2008-2012 Benjamin Eikel <benjamin@eikel.org>
	Copyright (C) 2008-2012 Claudius Jähn <claudius@uni-paderborn.de>
	
	This library is subject to the terms of the Mozilla Public License, v. 2.0.
	You should have received a copy of the MPL along with this library; see the 
	file LICENSE. If not, you can obtain one at http://mozilla.org/MPL/2.0/.
*/
#include "ELibSound.h"
#include "E_Buffer.h"
#include "E_Listener.h"
#include "E_Source.h"

#include <Sound/Sound.h>

using namespace EScript;

namespace E_Sound {

void init(EScript::Namespace * globals) {
	Namespace * lib = new Namespace();
	declareConstant(globals, "Sound", lib);

	//! [ESF] bool Sound.checkErrorStatus([message])
	ES_FUN(lib, "checkErrorStatus", 0, 1, Bool::create(Sound::checkErrorStatus(rt.getCurrentFile().c_str(), rt.getCurrentLine(), parameter[0].toString())))

	//! [ESF] Buffer Sound.createRectangleSound(unsigned int width, unsigned int freq,unsigned int size)
	ES_FUN(lib, "createRectangleSound", 3, 3, E_Buffer::create(Sound::createRectangleSound(parameter[0].to<uint32_t>(rt), parameter[1].to<uint32_t>(rt), parameter[2].to<uint32_t>(rt))))

	//! [ESF] Buffer Sound.createNoise(unsigned int freq,unsigned int size)
	ES_FUN(lib, "createNoise", 2, 2, E_Buffer::create(Sound::createNoise(parameter[0].to<uint32_t>(rt), parameter[1].to<uint32_t>(rt))))

	//! [ESF] Buffer Sound.createSilence(unsigned int freq,unsigned int size)
	ES_FUN(lib, "createSilence", 2, 2, E_Buffer::create(Sound::createSilence(parameter[0].to<uint32_t>(rt), parameter[1].to<uint32_t>(rt))))

	//! [ESF] Source Sound.createSource( )
	ES_FUN(lib, "createSource", 0, 0, E_Source::create())

	//! [ESF] Listener Sound.getListener( )
	ES_FUN(lib, "getListener", 0, 0, new E_Listener(Sound::getListener()))

	//! [ESF] Sound.initSoundSystem()
	ES_FUN(lib, "initSoundSystem", 0, 0, (Sound::initSoundSystem(), EScript::create(nullptr)))

	//! [ESF] Buffer Sound.loadWAV(String filename)
	ES_FUN(lib, "loadWAV", 1, 1, E_Buffer::create(Sound::loadWAV(parameter[0].toString())))

	//! [ESF] Sound.shutDownSoundSystem()
	ES_FUN(lib, "shutDownSoundSystem", 0, 0, (Sound::shutDownSoundSystem(), EScript::create(nullptr)))

	E_Buffer::init(*lib);
	E_Listener::init(*lib);
	E_Source::init(*lib);
}

}
