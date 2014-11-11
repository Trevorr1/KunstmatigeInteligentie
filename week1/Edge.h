#pragma once

#include <string>

namespace Tmpl8
{
	class Vertex;
	class Edge
	{
	public:
		Edge();
		Edge(Vertex* aSource, Vertex* aDestination, unsigned int aWeight, std::string aID);
		virtual ~Edge();

		Vertex* getSource();
		Vertex* getDestination();
		unsigned int getWeight();
		std::string getID();

	private:
		Vertex* m_Source;
		Vertex* m_Destination;
		unsigned int m_Weight;
		std::string m_ID;
	};
}


