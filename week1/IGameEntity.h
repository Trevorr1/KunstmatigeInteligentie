#pragma once

#include "template.h"
#include "eGameEntity.h"
#include "surface.h"
#include "DrawManager.h"
#include "eEntityState.h"
#include "EntityState.h"
#include <iomanip> 
#include <list>

namespace Tmpl8
{
	class Graph;
	class Vertex;
	class Surface;
	//class EntityState;
	class IGameEntity
	{
	public:
		IGameEntity() {};
		eGameEntity getEnum() { return m_Enum; };
		virtual void Update(float dt) = 0;
		virtual void setRoute(eGameEntity source, eGameEntity target) = 0;
		virtual ~IGameEntity() {};

		void Draw(){ m_Sprite->Draw(m_Position.x, m_Position.y, m_Surface); }
		void Run(float dt, IGameEntity* other, IGameEntity* ally, IGameEntity* neutral){ m_State->Run(this, other, ally, neutral); Draw(); }

		Graph* getGraph() { return m_Graph; }
		vector3 getPosition() { return m_Position; }
		void setPosition(int x, int y){ m_Position.x = (float)x; m_Position.y = (float)y; InitCenter(); }
		void setPosition(vector3 vec){ m_Position = vec; InitCenter(); }
		void setState(EntityState* state) { delete m_State; m_State = state; }
		EntityState* CurrentState() { return m_State; }
		eState getState() { return m_State->getState(); }

		void setHeading(vector3 heading) { m_Heading.Set(heading.x, heading.y, heading.z); }
		vector3 getHeading() { return m_Heading; }

		void setSpeed(float speed) { m_Speed = speed; }
		float getSpeed() { return m_Speed; }

		void Move(float dt) { m_Position += m_Heading * m_Speed; InitCenter(); }
		void InitCenter() { m_Center = vector3(m_Position.x + 16, m_Position.y + 16, 0); }// needs to be more dynamic
		vector3 getCenter() { return m_Center; }

		virtual void entityMovedNotification(eGameEntity entity) {};
	protected:
		eGameEntity m_Enum;
		std::list<Vertex*> m_Path;
		Graph* m_Graph;
		Sprite* m_Sprite;
		Surface* m_Surface;
		vector3 m_Position;
		vector3 m_Center;
		vector3 m_Heading;
		float m_Speed;
		EntityState* m_State;
	};
}

