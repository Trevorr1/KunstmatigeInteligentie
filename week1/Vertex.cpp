#include "Vertex.h"

using namespace Tmpl8;
using namespace std;

Vertex::Vertex()
{
}

Vertex::Vertex(string aName, string aDescription)
{
	m_Name = aName;
	m_Description = aDescription;
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
