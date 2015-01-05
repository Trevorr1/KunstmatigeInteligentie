#pragma once
#include "CowState.h"



namespace Tmpl8{
	class CowStatePursuit :
		public CowState
	{
	public:
		CowStatePursuit();
		virtual ~CowStatePursuit();

		void Run(IGameEntity* self, IGameEntity* other, IGameEntity* ally, IGameEntity* neutral);
	};
}

