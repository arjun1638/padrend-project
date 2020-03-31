/*
	This file is part of the E_MinSG library extension SVS.
	Copyright (C) 2012-2013 Benjamin Eikel <benjamin@eikel.org>
	
	This library is subject to the terms of the Mozilla Public License, v. 2.0.
	You should have received a copy of the MPL along with this library; see the 
	file LICENSE. If not, you can obtain one at http://mozilla.org/MPL/2.0/.
*/
#ifdef MINSG_EXT_SVS

#ifndef E_MINSG_SVS_E_SPHEREVISUALIZATIONRENDERER_H
#define E_MINSG_SVS_E_SPHEREVISUALIZATIONRENDERER_H

#include "../../Core/States/E_NodeRendererState.h"
#include <string>

namespace EScript {
class Namespace;
class Runtime;
class Type;
}
namespace MinSG {
namespace SVS {
class SphereVisualizationRenderer;
}
}
namespace E_MinSG {
namespace SVS {

//!	EScript wrapper class for MinSG::SVS::SphereVisualizationRenderer
class E_SphereVisualizationRenderer : public E_NodeRendererState {
	protected:
		E_SphereVisualizationRenderer(MinSG::SVS::SphereVisualizationRenderer * renderer);
	public:
		template<class, class, class> friend class Util::PolymorphicWrapperCreator;

		static EScript::Type * getTypeObject();
		static void init(EScript::Namespace & lib);

		virtual ~E_SphereVisualizationRenderer();

		const MinSG::SVS::SphereVisualizationRenderer * operator*() const;
		MinSG::SVS::SphereVisualizationRenderer * operator*();
};

}
}

#endif /* E_MINSG_SVS_E_SPHEREVISUALIZATIONRENDERER_H */

#endif /* MINSG_EXT_SVS */
