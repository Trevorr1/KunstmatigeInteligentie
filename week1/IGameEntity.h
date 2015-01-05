#pragma once

#include "template.h"
#include "eGameEntity.h"
#include "surface.h"
#include <list>

namespace Tmpl8
{
	class Graph;
	class Vertex;
	class Surface;
	class EntityState;
	class IGameEntity
	{
	public:
		IGameEntity() {};
		eGameEntity getEnum() { return m_Enum; };
		virtual void Draw() = 0;
		virtual void Update(float dt) = 0;
		virtual void setRoute(eGameEntity source, eGameEntity target) = 0;
		virtual ~IGameEntity() {};

		Graph* getGraph() { return m_Graph; }
		vector3 getPosition() { return m_Position; }
		void setPosition(int x, int y){ m_Position.x = x, m_Position.y = y; }
		void setPosition(vector3 vec){ m_Position = vec; }
		void setState(EntityState* state) { m_State = state; }

		virtual void entityMovedNotification(eGameEntity entity) {};
	protected:
		eGameEntity m_Enum;
		std::list<Vertex*> m_Path;
		Graph* m_Graph;
		Sprite* m_Sprite;
		vector3 m_Position;
		vector3 m_Heading;
		float m_Speed;
		EntityState* m_State;
	};
}

