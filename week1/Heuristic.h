#pragma once
class Heuristic
{
public:
	Heuristic();

	//calculate the heuristic for the use by the search algorithm
	template<class graph_type>
	static double Calculate(const graph_type& G, int nd1, int nd2) = 0;
	virtual ~Heuristic();
};

