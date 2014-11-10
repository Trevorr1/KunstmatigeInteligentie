#pragma once

#include <string>

class Vertex;
class Edge
{
public:
	Edge();
	Edge(Vertex* aSource, Vertex* aDestination, unsigned int aWeight, unsigned int aID);
	virtual ~Edge();

	Vertex* getSource();
	Vertex* getDestination();
	unsigned int getWeight();
	unsigned int getID();

private:
	Vertex* m_Source;
	Vertex* m_Destination;
	unsigned int m_Weight;
	unsigned int m_ID;
};

