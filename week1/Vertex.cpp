#include "Vertex.h"
#include "template.h"

using namespace Tmpl8;
using namespace std;

Vertex::Vertex(string aName, int aId, vector3 aPosition)
{
	m_Name = aName;
	m_Id = aId;
	m_Position = aPosition;

	m_Edges = new vector<Edge*>();
	m_MinDistance = 0;
	m_GuessedTotalDistance = 0;
}

Vertex::~Vertex()
{
}

string Vertex::getName()
{
	return m_Name;
}

vector3 Vertex::getPosition()
{
	return m_Position;
}

short Vertex::getId()
{
	return m_Id;
}

vector<Edge*>* Vertex::getEgdes()
{
	return m_Edges;
}