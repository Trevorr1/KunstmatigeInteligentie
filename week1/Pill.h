#pragma once
#include "IGameEntity.h"

namespace Tmpl8{
	class Pill :
		public IGameEntity
	{
	public:
		Pill();
		Pill(eState state);
		virtual ~Pill();

		void Update(float dt){}
		void setRoute(eGameEntity source, eGameEntity target){}
	};
}//namespace Tmpl8

