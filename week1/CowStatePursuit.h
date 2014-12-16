#pragma once
#include "CowState.h"

namespace Tmpl8{
	class CowStatePursuit :
		public CowState
	{
	public:
		CowStatePursuit();
		virtual ~CowStatePursuit();

		void Run(IGameEntity* entity, IGameEntity* other){}
	};
}

