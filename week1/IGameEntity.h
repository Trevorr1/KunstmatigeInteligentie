#pragma once

#include "template.h"
#include "eGameEntity.h"
#include "surface.h"
#include "DrawManager.h"
#include <iomanip> 
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
		void setState(EntityState* state) { delete m_State; m_State = state; }

		void setHeading(vector3 heading) { m_Heading.Set(heading.x, heading.y, heading.z); }
		vector3 getHeading() { return m_Heading; }

		void setSpeed(float speed) { m_Speed = speed; }
		float getSpeed() { return m_Speed; }

		void Move(float dt) { m_Position += m_Heading * m_Speed; }

		virtual void entityMovedNotification(eGameEntity entity) {};
	protected:
		eGameEntity m_Enum;
		std::list<Vertex*> m_Path;
		Graph* m_Graph;
		Sprite* m_Sprite;
		Surface* m_Surface;
		vector3 m_Position;
		vector3 m_Heading;
		float m_Speed;
		EntityState* m_State;
	};
}

