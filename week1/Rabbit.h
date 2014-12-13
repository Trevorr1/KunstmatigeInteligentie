#pragma once

#include "template.h"
#include "IGameEntity.h"

namespace Tmpl8
{
	class Graph;
	class Surface;
	class Sprite;
	class Rabbit : public IGameEntity
	{
	public:
		Rabbit(Graph* graph);
		virtual ~Rabbit();

		void Update();

		void setRoute(eGameEntity source, eGameEntity target);

		void entityMovedNotification(eGameEntity entity);

	private:
		Sprite* m_Sprite;
		Graph* m_Graph;
	};
} //tmpl8


