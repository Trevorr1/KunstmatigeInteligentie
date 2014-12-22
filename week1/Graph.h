#pragma once
#include <vector>
#include <map>
#include <list>
#include "eGameEntity.h"

namespace Tmpl8
{
	class Surface;
	class Vertex;
	class Edge;
	class IGameEntity;
	class Cow;
	class Rabbit;
	class Graph
	{
	public:
		Graph(Surface* aTarget);
		virtual ~Graph();

		void init();
		void Update(float dt);
		void Draw(Surface* target);

		//A* stuff
		std::list<Vertex*> ComputeAStarPath(Vertex* source, Vertex* target);
		std::list<Vertex*> getPath(eGameEntity source, eGameEntity target);
		void ShuffleHare();
		void moveGameObject(Vertex* target, eGameEntity entity);

		std::vector<Vertex*>* getVertices();
		std::vector<Edge*>* getEdges();

		Surface* getSurface();

		std::map<eGameEntity, Vertex*> m_LookUpBook;

	private:
		void addEdge(short sourceLocNo, short destLocNo, int duration);

		Surface* m_Target;

		std::vector<Vertex*>* m_Vertices;
		std::vector<Edge*>* m_Edges;

		IGameEntity* m_Cow;
		IGameEntity* m_Rabbit;

		//A* stuff
		std::vector<Vertex*>* m_OpenList;
		std::vector<Vertex*>* m_ClosedList;
	};
}

