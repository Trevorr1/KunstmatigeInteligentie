#pragma once
#define DANGERRANGE 30
#include "IGameEntity.h"
namespace Tmpl8 {
	class EntityState
	{
	public:
		EntityState();
		virtual ~EntityState();

		virtual void Run(IGameEntity* entity, IGameEntity* other) = 0;
	};
}//namespace Tmpl8

