#pragma once
#include <vector>

namespace Tmpl8
{
	class Surface;
	class Vertex;
	class Edge;
	class Graph
	{
	public:
		Graph(Surface* aTarget);
		virtual ~Graph();

		void init();
		void Draw();

		std::vector<Vertex*>* getVertices();
		std::vector<Edge*>* getEdges();

	private:
		Surface* m_Target;
		void addEdge(int sourceLocNo, int destLocNo, int duration);

		std::vector<Vertex*>* m_Vertices;
		std::vector<Edge*>* m_Edges;
	};
}

