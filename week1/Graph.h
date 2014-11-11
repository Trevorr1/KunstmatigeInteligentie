#pragma once
#include <vector>

namespace Tmpl8
{
	class Vertex;
	class Edge;
	class Graph
	{
	public:
		Graph();
		virtual ~Graph();

		void init();

		std::vector<Vertex*>* getVertices();
		std::vector<Edge*>* getEdges();

	private:
		void addEdge(int sourceLocNo, int destLocNo, int duration, std::string laneId);

		std::vector<Vertex*>* m_Vertices;
		std::vector<Edge*>* m_Edges;
	};
}

