/*
	This file is part of the MinSG library extension BlueSurfels.
	Copyright (C) 2017-2018 Sascha Brandt <sascha@brandt.graphics>
	
	This library is subject to the terms of the Mozilla Public License, v. 2.0.
	You should have received a copy of the MPL along with this library; see the 
	file LICENSE. If not, you can obtain one at http://mozilla.org/MPL/2.0/.
*/
#ifdef MINSG_EXT_BLUE_SURFELS

#ifndef E_BLUE_SURFELS_STRATEGIES_AdaptiveStrategy_H_
#define E_BLUE_SURFELS_STRATEGIES_AdaptiveStrategy_H_

#include "E_AbstractSurfelStrategy.h"
#include <MinSG/Ext/BlueSurfels/Strategies/AdaptiveStrategy.h>

#include <Util/Timer.h>

namespace E_MinSG {
namespace BlueSurfels {

class E_AdaptiveStrategy : public E_AbstractSurfelStrategy {
  ES_PROVIDES_TYPE_NAME(AdaptiveStrategy)
	public:
		template<class, class, class> friend class Util::PolymorphicWrapperCreator;
		
	  static EScript::Type * getTypeObject();
	  static void init(EScript::Namespace & lib);

	  E_AdaptiveStrategy(MinSG::BlueSurfels::AdaptiveStrategy* obj, EScript::Type* type=nullptr) : E_AbstractSurfelStrategy(obj, type ? type : getTypeObject()) {}
	  virtual ~E_AdaptiveStrategy() = default;
	
		const MinSG::BlueSurfels::AdaptiveStrategy * operator*() const { return static_cast<const MinSG::BlueSurfels::AdaptiveStrategy*>(ref().get()); }
		MinSG::BlueSurfels::AdaptiveStrategy * operator*() { return static_cast<MinSG::BlueSurfels::AdaptiveStrategy*>(ref().get()); }
};
  
} /* BlueSurfels */
} /* E_MinSG */

ES_CONV_EOBJ_TO_OBJ(E_MinSG::BlueSurfels::E_AdaptiveStrategy, MinSG::BlueSurfels::AdaptiveStrategy*, **eObj)

#endif /* end of include guard: E_BLUE_SURFELS_STRATEGIES_AdaptiveStrategy_H_ */
#endif // MINSG_EXT_BLUE_SURFELS