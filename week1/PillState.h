#pragma once
#include "EntityState.h"

namespace Tmpl8{

	class PillState :
		public EntityState
	{
	public:
		PillState();
		virtual ~PillState();

		void Run(IGameEntity* self, IGameEntity* other, IGameEntity* ally, IGameEntity* neutral){}
	};
}//namespace Tmpl8

