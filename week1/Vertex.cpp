#include "Vertex.h"
#include "template.h"

using namespace Tmpl8;
using namespace std;

Vertex::Vertex(string aName, string aDescription, vector3 aPosition)
{
	m_Name = aName;
	m_Description = aDescription;
	m_Position = aPosition;
}


Vertex::~Vertex()
{
}

string Vertex::getName()
{
	return m_Name;
}

string Vertex::getDescription()
{
	return m_Description;
}

vector3 Vertex::getPosition()
{
	return m_Position;
}
