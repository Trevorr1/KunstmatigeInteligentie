#pragma once

namespace Tmpl8
{
	class Vertex;
	class Edge
	{
	public:
		Edge(Vertex* aSource, Vertex* aDestination, int sId, int dId, unsigned int aDistance);
		Edge(Vertex* source, Vertex* destination, int distance);
		virtual ~Edge();

		Vertex* getSource() const;
		Vertex* getDestination() const;
		unsigned int getDistance() const;

	private:
		Vertex* m_Source;
		Vertex* m_Destination;
		unsigned int m_Distance;
		int m_SourceId;
		int m_DestinationId;
	};
}


