#pragma once
#include "IGameEntity.h"

namespace Tmpl8{

	class Weapon :
		public IGameEntity
	{
	public:
		Weapon();
		Weapon(eState state);
		virtual ~Weapon();

		void Update(float dt){}
		void setRoute(eGameEntity source, eGameEntity target){}
	};
}//namespace Tmpl8

