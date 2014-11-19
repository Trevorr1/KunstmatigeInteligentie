#include "Edge.h"
#include "Vertex.h"

using namespace Tmpl8;
using namespace std;

Edge::Edge(Vertex* aSource, Vertex* aDestination, unsigned int aWeight)
{
	m_Source = aSource;
	m_Destination = aDestination;
	m_Weight = aWeight;
}


Edge::~Edge()
{
	delete m_Source;
	delete m_Destination;
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