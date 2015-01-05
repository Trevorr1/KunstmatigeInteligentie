#pragma once
#include "CowState.h"

namespace Tmpl8{
	class CowStateFleePill :
		public CowState
	{
	public:
		CowStateFleePill();
		virtual ~CowStateFleePill();


		void Run(IGameEntity* self, IGameEntity* other, IGameEntity* ally, IGameEntity* neutral);
	};
}//namespace Tmpl8

