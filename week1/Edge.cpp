#include "Edge.h"

using namespace Tmpl8;
using namespace std;

Edge::Edge()
{
}

Edge::Edge(Vertex* aSource, Vertex* aDestination, unsigned int aWeight, string aID)
{
	m_Source = aSource;
	m_Destination = aDestination;
	m_Weight = aWeight;
	m_ID = aID;
}


Edge::~Edge()
{
}

Vertex* Edge::getSource()
{
	return m_Source;
}

Vertex* Edge::getDestination()
{
	return m_Destination;
}

unsigned int Edge::getWeight()
{
	return m_Weight;
}

string Edge::getID()
{
	return m_ID;
}