#pragma once
#include "EntityState.h"

namespace Tmpl8{
	class CowState :
		public EntityState
	{
	public:
		CowState();
		virtual ~CowState();

		void Run(IGameEntity* entity, IGameEntity* other){}
	};
}//namespace Tmpl8

