#include "Edge.h"
#include "Vertex.h"

using namespace Tmpl8;
using namespace std;

Edge::Edge(Vertex* aSource, Vertex* aDestination, int sId, int dId, unsigned int aDistance)
{
	m_Source = aSource;
	m_Destination = aDestination;
	m_Distance = aDistance;
	m_SourceId = sId;
	m_DestinationId = dId;
}

Edge::Edge(Vertex* source, Vertex* destination, int distance)
{
	m_Source = source;
	m_Destination = destination;
	m_Distance = distance;
}

Edge::~Edge()
{
	delete m_Source;
	delete m_Destination;
}

Vertex* Edge::getSource() const
{
	return m_Source;
}

Vertex* Edge::getDestination() const
{
	return m_Destination;
}

unsigned int Edge::getDistance() const
{
	return m_Distance;
}