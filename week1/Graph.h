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
	class Cow;
	class Rabbit;
	class Graph
	{
	public:
		Graph(Surface* aTarget);
		virtual ~Graph();

		void init();
		void Draw();

		//A* stuff
		std::list<Vertex*> ComputeAStarPath(Vertex* source, Vertex* target);

		std::vector<Vertex*>* getVertices();
		std::vector<Edge*>* getEdges();

		Surface* getSurface();

		std::map<eGameEntity, Vertex*> m_LookUpBook;

	private:
		void addEdge(short sourceLocNo, short destLocNo, int duration);

		Surface* m_Target;

		std::vector<Vertex*>* m_Vertices;
		std::vector<Edge*>* m_Edges;

		Cow* m_Cow;
		Rabbit* m_Rabbit;

		//A* stuff
		std::vector<Vertex*>* m_OpenList;
		std::vector<Vertex*>* m_ClosedList;
	};
}

