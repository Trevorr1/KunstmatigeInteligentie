#pragma once

#include "template.h"
#include <string>
#include <vector>
#include "IGameEntity.h"

namespace Tmpl8
{
	class Edge;
	class Vertex : public IGameEntity
	{
	public:
		Vertex(std::string aName, int aId, vector3 aPosition);
		virtual ~Vertex();

		//inherited
		void Draw();
		void Update(float dt);
		void addGameObject(IGameEntity* obj);
		void setRoute(eGameEntity source, eGameEntity target) {}
		//end

		IGameEntity* getGameObject(eGameEntity entity);
		IGameEntity* takeGameObject(eGameEntity entity);

		std::string getName();
		vector3 getPosition();
		short getId();

		std::vector<Edge*>* getEgdes();

		Vertex* m_VisitedBy = nullptr;
		int m_MinDistance;
		int m_GuessedTotalDistance;

	private:
		std::string m_Name;
		vector3 m_Position;
		int m_Id;
		std::vector<Edge*>* m_Edges;
		std::vector<IGameEntity*>* m_GameEntities;
		bool m_Found;
	};
}

