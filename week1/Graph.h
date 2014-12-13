#pragma once
#include <vector>
#include <map>
#include <list>
#include <set>
#include <queue>

namespace Tmpl8
{
	template <typename T1, typename T2>
	struct pair_first_less
	{
		bool operator()(std::pair<T1, T2> p1, std::pair<T1, T2> p2)
		{
			return p1.first < p2.first;
		}
	};

	class Neighbour
	{
	public:
		Neighbour(int target, int weight) : m_Target(target), m_Weight(weight) {}
		int m_Target;
		int m_Weight;
	private:
	};

	class Surface;
	class Vertex;
	class Edge;
	class Cow;
	class Rabbit;
	class Graph
	{
	public:
		Graph(Surface* aTarget);
		virtual ~Graph();

		void init();
		void Draw();

		//dijkstra stuff
		void ComputePath(int source, std::map<int, std::list<Neighbour>>& adjacencyMap, std::map<int, int>& minDistance, std::map<int, int>& previous);
		std::list<int> GetShortestPathTo(int source, int target, std::map<int, int>& previous);

		//A* stuff
		std::list<Vertex*> ComputeAStarPath(Vertex* source, Vertex* target);

		std::vector<Vertex*>* getVertices();
		std::vector<Edge*>* getEdges();

		Surface* getSurface();

	private:
		void addEdge(short sourceLocNo, short destLocNo, int duration);

		Surface* m_Target;

		std::vector<Vertex*>* m_Vertices;
		std::vector<Edge*>* m_Edges;

		Cow* m_Cow;
		Rabbit* m_Rabbit;

		//dijkstra stuff
		std::map<int, std::list<Neighbour>> m_AdjacencyMap;
		std::map<int, int> m_MinimumDistance;
		std::map<int, int> m_Previous;

		//A* stuff
		std::vector<Vertex*>* m_OpenList;
		std::vector<Vertex*>* m_ClosedList;
	};
}

