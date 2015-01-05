#pragma once
#include "CowState.h"
namespace Tmpl8
{
	class CowStateWander :
		public CowState
	{
	public:
		CowStateWander();
		virtual ~CowStateWander();

		void Run(IGameEntity* self, IGameEntity* other, IGameEntity* ally, IGameEntity* neutral);

	};
}//namespace Tmpl8

