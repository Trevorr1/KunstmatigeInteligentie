#pragma once
#include <vector>

class Vertex;
class Edge;
class Graph
{
public:
	Graph(std::vector<Vertex*>* vertices, std::vector<Edge*>* edges);
	virtual ~Graph();

	std::vector<Vertex*>* getVertices();
	std::vector<Edge*>* getEdges();

private:
	std::vector<Vertex*>* m_Vertices;
	std::vector<Edge*>* m_Edges;
};

