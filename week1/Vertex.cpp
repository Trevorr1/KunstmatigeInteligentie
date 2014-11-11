#include "Vertex.h"

using namespace Tmpl8;
using namespace std;

Vertex::Vertex()
{
}

Vertex::Vertex(string aName, string aDescription, unsigned int aID)
{
	m_Name = aName;
	m_Description = aDescription;
	m_ID = aID;
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

void Vertex::setDescription(string aDescription)
{
	m_Description = aDescription;
}

unsigned int Vertex::getID()
{
	return m_ID;
}


