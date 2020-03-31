#version 130

/*
 * This file is part of the open source part of the
 * Platform for Algorithm Development and Rendering (PADrend).
 * Web page: http://www.padrend.de/
 * Copyright (C) 2012 Claudius Jähn <claudius@uni-paderborn.de>
 * Copyright (C) 2011-2012 Ralf Petring <ralf@petring.net>
 * 
 * PADrend consists of an open source part and a proprietary part.
 * The open source part of PADrend is subject to the terms of the Mozilla
 * Public License, v. 2.0. You should have received a copy of the MPL along
 * with this library; see the file LICENSE. If not, you can obtain one at
 * http://mozilla.org/MPL/2.0/.
 */

uniform sampler2D color;
uniform float border = 1.0;
uniform int[4] sg_viewport;
out vec4 fragColor;

const vec4 Sepia1 = vec4( 0.2, 0.05, 0.0, 1.0 );
const vec4 Sepia2 = vec4( 1.0, 0.9, 0.5, 1.0 );

vec4 getColor(in sampler2D tex, in ivec2 pos){
	return texelFetch(tex, pos, 0);
}

vec4 addEffect(in ivec2 pos){

	vec4 c = getColor(color, pos);
	float SepiaMix = dot(vec3(0.3, 0.59, 0.11), vec3(c));
	c = mix(c, vec4(SepiaMix), vec4(0.5));
	vec4 Sepia = mix(Sepia1, Sepia2, SepiaMix);
	return mix(c, Sepia, 1.0);
}

void main(void){

	ivec2 pos = ivec2(gl_FragCoord.xy)-ivec2(sg_viewport[0],sg_viewport[1]);

	int b = int(float(sg_viewport[2]) * border);

	if(pos.x < b)
		fragColor = addEffect(pos);
	else if(pos.x == b)
		fragColor = vec4(1,0,0,1);
	else
		fragColor = getColor(color, pos);
}