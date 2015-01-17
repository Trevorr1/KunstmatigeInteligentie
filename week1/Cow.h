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
		Cow(Graph* graph);
		virtual ~Cow();

		void Draw();
		void Update(float dt);
		void setRoute(eGameEntity source, eGameEntity target);
		void entityMovedNotification(eGameEntity entity);

		void ResetState();

	private:
	};
} //tmpl8



