#pragma once
#include "EntityState.h"

namespace Tmpl8{

	class WeaponState :
		public EntityState
	{
	public:
		WeaponState();
		virtual ~WeaponState();

		void Run(IGameEntity* self, IGameEntity* other, IGameEntity* ally, IGameEntity* neutral){}
	};
}//namespace Tmpl8

