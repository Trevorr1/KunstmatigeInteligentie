#pragma once
#include "CowState.h"

namespace Tmpl8 {

	class CowStateFlee :
		public CowState
	{
	public:
		CowStateFlee();
		virtual ~CowStateFlee();


		void Run(IGameEntity* self, IGameEntity* other, IGameEntity* ally, IGameEntity* neutral);
	};
}//namespace Tmpl8

