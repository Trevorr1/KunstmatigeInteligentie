#pragma once

namespace Tmpl8
{
	class Vertex;
	class Edge
	{
	public:
		Edge();
		Edge(Vertex* aSource, Vertex* aDestination, unsigned int aWeight);
		virtual ~Edge();

		Vertex* getSource();
		Vertex* getDestination();
		unsigned int getWeight();

	private:
		Vertex* m_Source;
		Vertex* m_Destination;
		unsigned int m_Weight;
	};
}


