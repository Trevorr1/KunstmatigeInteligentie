#pragma once
#include "WeaponState.h"

namespace Tmpl8{

	class WeaponStateIdle :
		public WeaponState
	{
	public:
		WeaponStateIdle();
		virtual ~WeaponStateIdle();

		void Run(IGameEntity* self, IGameEntity* other, IGameEntity* ally, IGameEntity* neutral){}
	};
}

