#pragma once
#include "CowState.h"

#define PURSUITSPEED 0.3f

namespace Tmpl8{
	class CowStatePursuit :
		public CowState
	{
	public:
		CowStatePursuit();
		virtual ~CowStatePursuit();

		void Run(IGameEntity* entity, IGameEntity* other);
	};
}

