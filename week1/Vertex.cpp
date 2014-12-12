#include "Vertex.h"
#include "template.h"

using namespace Tmpl8;
using namespace std;

Vertex::Vertex(string aName, int aId, vector3 aPosition)
{
	m_Name = aName;
	m_Id = aId;
	m_Position = aPosition;
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