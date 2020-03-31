/*
	This file is part of the E_MinSG library extension SkeletalAnimation.
	Copyright (C) 2011-2012 Lukas Kopecki
	
	This library is subject to the terms of the Mozilla Public License, v. 2.0.
	You should have received a copy of the MPL along with this library; see the 
	file LICENSE. If not, you can obtain one at http://mozilla.org/MPL/2.0/.
*/

#ifdef MINSG_EXT_SKELETAL_ANIMATION

#include "E_SkeletalHardwareRendererState.h"

#include "../../Core/Behaviours/E_AbstractBehaviour.h"
#include "../../ELibMinSG.h"
#include "E_SkeletalNode.h"

#include <EScript/EScript.h>

using namespace EScript;
using namespace MinSG;

namespace E_MinSG {

    EScript::Type * E_SkeletalHardwareRendererState::getTypeObject() {
        // E_SkeletalNode ---|> E_ListNode ---|> E_GroupNode ---|> E_Node ---|> Object
        static EScript::ERef<EScript::Type> typeObject = new EScript::Type(E_ShaderState::getTypeObject());
        return typeObject.get();
    }


    void E_SkeletalHardwareRendererState::init(EScript::Namespace & lib) {
        // MinSG.SkeletalHardwareRendererState ---|> MinSG.ShaderState ---|> MinSG.State ---|> Object
        EScript::Type * typeObject = getTypeObject();
        declareConstant(&lib,getClassName(),typeObject);
        addFactory<MinSG::SkeletalHardwareRendererState,E_SkeletalHardwareRendererState>();
        
        ES_MFUN(typeObject, SkeletalHardwareRendererState, "setDebugJointId", 1, 1, (thisObj->setDebugJointId(parameter[0].to<uint32_t>(rt)), thisEObj));

        ES_MFUN(typeObject, SkeletalHardwareRendererState, "getDebugJointId", 0, 0, (thisObj->getDebugJointId(), thisEObj));
        
        ES_MFUN(typeObject, SkeletalHardwareRendererState, "clone", 0, 0, (thisObj->clone(), thisEObj));

    }
    // ------------------------------------------------------------

    //! (ctor)	

    E_SkeletalHardwareRendererState::E_SkeletalHardwareRendererState(SkeletalHardwareRendererState * c,Type * type):E_ShaderState(c,type?type:getTypeObject()) {
    }

    //! (dtor)	
    E_SkeletalHardwareRendererState::~E_SkeletalHardwareRendererState(){
    }

}

#endif
