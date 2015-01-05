#pragma once
#include "CowState.h"

namespace Tmpl8 {
	class CowStateHide :
		public CowState
	{
	public:
		CowStateHide();
		virtual ~CowStateHide();

		void Run(IGameEntity* self, IGameEntity* other, IGameEntity* ally, IGameEntity* neutral){}
	};
}//namespace Tmpl8

