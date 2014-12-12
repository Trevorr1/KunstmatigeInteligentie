#pragma once
#include "stdafx.h"
class GraphEdge
{
protected:
	// An edge connects two nodes.Valid node indices are always positive.
	int m_iFrom;
	int m_iTo;

	// The cost of traversing the edge
	double m_dCost; // I guess it can be a float but for the sake of unknown future implementation double ok for now
public:
	//ctors
	GraphEdge(int from, int to, double cost) : m_dCost{ cost }, 
												m_iFrom{ from }, 
												m_iTo{ to }
	{}

	GraphEdge(int from, int to) : m_dCost{ 1.0 },
									m_iFrom{ from },
									m_iTo{ to }
	{}

	GraphEdge() : m_dCost{ 1.0 },
					m_iFrom{ invalid_node_index },
					m_iTo{ invalid_node_index }
	{}

	virtual ~GraphEdge();

	int From() const { return m_iFrom; }
	void SetFrom(int NewIndex) { m_iFrom = NewIndex; }

	int To() const { return m_iTo; }
	void SetTo(int NewIndex) { m_iTo = NewIndex; }

	double Cost()const { return m_dCost; }
	void SetCost(double NewCost) { m_dCost = NewCost; }

	void Remove() 
	{ 
		m_iFrom = invalid_node_index;
		m_iTo = invalid_node_index;
	}
};

