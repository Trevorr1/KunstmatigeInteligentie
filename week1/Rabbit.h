#pragma once

#include "template.h"
#include "IGameEntity.h"

namespace Tmpl8
{
	class Graph;
	class Surface;
	class Sprite;
	class Cow;
	class RabbitState;
	class Rabbit : public IGameEntity
	{
	public:
		Rabbit();
		Rabbit(Graph* graph);
		virtual ~Rabbit();

		void Draw();
		void Update(float dt);
		void Lookout(Cow* cow, float dt);
		void setRoute(eGameEntity source, eGameEntity target);
		void entityMovedNotification(eGameEntity entity);

	private:
	};
} //tmpl8


