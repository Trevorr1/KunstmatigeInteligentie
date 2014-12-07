#pragma once
#include "Heuristic.h"
#include "template.h"
class Heuristic_Euclid :
	public Heuristic
{
public:
	Heuristic_Euclid();

	template<class graph_type>

	//calculate the straight -line distance from node nd1 to node nd2
	static double Calculate(const graph_type& G, int nd1, int nd2)
	{
		return (double)Lenght(G.GetNode(nd1).Position, G.GetNode(nd2).Position);
	}

	virtual ~Heuristic_Euclid();
};

