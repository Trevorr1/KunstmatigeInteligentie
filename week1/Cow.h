#pragma once

#include "template.h"
#include "IGameEntity.h"

namespace Tmpl8
{
	class Graph;
	class Surface;
	class Sprite;
	class Cow : public IGameEntity
	{
	public:
		Cow();
		Cow(eState state);
		Cow(Graph* graph);
		virtual ~Cow();

		void Update(float dt);
		void chase(IGameEntity* entity, float dt);
		void setRoute(eGameEntity source, eGameEntity target);
		void entityMovedNotification(eGameEntity entity);

	private:
		
	};
} //tmpl8



