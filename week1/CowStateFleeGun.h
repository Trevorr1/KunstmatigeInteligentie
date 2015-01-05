#pragma once
#include "CowState.h"
namespace Tmpl8 {
	class CowStateFleeGun :
		public CowState
	{
	public:
		CowStateFleeGun();
		virtual ~CowStateFleeGun();

		void Run(IGameEntity* self, IGameEntity* other, IGameEntity* ally, IGameEntity* neutral);
	};
}

