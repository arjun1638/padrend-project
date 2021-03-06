/*
 * This file is part of the open source part of the
 * Platform for Algorithm Development and Rendering (PADrend).
 * Web page: http://www.padrend.de/
 * Copyright (C) 2009-2012 Benjamin Eikel <benjamin@eikel.org>
 * Copyright (C) 2009-2014 Claudius Jähn <claudius@uni-paderborn.de>
 * Copyright (C) 2010 Jan Krems
 * Copyright (C) 2010-2013 Ralf Petring <ralf@petring.net>
 * 
 * PADrend consists of an open source part and a proprietary part.
 * The open source part of PADrend is subject to the terms of the Mozilla
 * Public License, v. 2.0. You should have received a copy of the MPL along
 * with this library; see the file LICENSE. If not, you can obtain one at
 * http://mozilla.org/MPL/2.0/.
 */

var PPEffect = new Type;
PPEffect._printableName @(override) ::= $PPEffect;
//! ---o
PPEffect.begin ::= fn(){};
//! ---o
PPEffect.end ::= fn(){};
//! ---o
PPEffect.beginPass ::= fn(PADrend.RenderingPass pass){};
//! ---o
PPEffect.endPass ::= fn(PADrend.RenderingPass pass){};
//! ---o
PPEffect.getOptionPanel ::= fn(){
    return gui.createLabel("Effect");
};
PPEffect.getShaderFolder ::= fn(){	return __DIR__+"/resources/PP_Effects/";	};

return PPEffect;
