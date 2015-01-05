#pragma once
#include "EntityState.h"

namespace Tmpl8{
	class CowState :
		public EntityState
	{
	public:
		CowState();
		virtual ~CowState();

		void Run(IGameEntity* self, IGameEntity* other, IGameEntity* ally, IGameEntity* neutral) {}
	};
}//namespace Tmpl8

