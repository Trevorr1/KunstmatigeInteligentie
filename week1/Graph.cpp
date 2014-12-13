#include "Graph.h"
#include "Vertex.h"
#include "Edge.h"
#include "Cow.h"
#include "Rabbit.h"
#include "surface.h"
#include "template.h"

#include <queue>
#include <iostream>
#include <limits>

using namespace Tmpl8;
using namespace std;

bool sortByGuessedTotalDistance(Vertex *lhs, Vertex *rhs) 
{ //todo: give this method a proper position in the code
	return lhs->m_GuessedTotalDistance < rhs->m_GuessedTotalDistance;
}

Graph::Graph(Surface* aTarget)
{
	m_Vertices = new vector<Vertex*>();
	m_Edges = new vector<Edge*>();
	m_Target = aTarget;
}

Graph::~Graph()
{	
	m_Edges->erase(m_Edges->begin(), m_Edges->end());

	delete m_Edges;

	m_Vertices->erase(m_Vertices->begin(), m_Vertices->end());

	delete m_Vertices;

	m_OpenList->erase(m_OpenList->begin(), m_OpenList->end());
	delete m_OpenList;

	m_ClosedList->erase(m_ClosedList->begin(), m_ClosedList->end());
	delete m_ClosedList;

	delete m_Cow;
	delete m_Rabbit;
}

void Graph::init()
{
	m_Cow = new Cow(this);
	m_Rabbit = new Rabbit(this);

	Vertex* location[9] = { nullptr };

	location[0] = new Vertex("V0", 0, vector3(50.0f, 240.0f, 0.0f));
	location[1] = new Vertex("V1", 1, vector3(100.0f, 140.0f, 0.0f));
	location[2] = new Vertex("V2", 2, vector3(110.0f, 340.0f, 0.0f));
	location[3] = new Vertex("V3", 3, vector3(200.0f, 240.0f, 0.0f));
	location[4] = new Vertex("V4", 4, vector3(300.0f, 340.0f, 0.0f));
	location[5] = new Vertex("V5", 5, vector3(350.0f, 140.0f, 0.0f));
	location[6] = new Vertex("V6", 6, vector3(350.0f, 240.0f, 0.0f));
	location[7] = new Vertex("V7", 7, vector3(450.0f, 330.0f, 0.0f));
	location[8] = new Vertex("V8", 8, vector3(500.0f, 220.0f, 0.0f));

	for (int i = 0; i < 9; i++)
	{
		m_Vertices->push_back(location[i]);
	}

	addEdge(0, 1, 85);
	addEdge(0, 2, 217);
	addEdge(1, 3, 173);
	addEdge(1, 5, 186);
	addEdge(2, 3, 103);
	addEdge(2, 4, 183);
	addEdge(3, 6, 250);
	addEdge(4, 6, 150);
	addEdge(4, 7, 100);
	addEdge(5, 6, 84);
	addEdge(5, 8, 502);
	addEdge(6, 7, 224);
	addEdge(7, 8, 167);

	m_OpenList = new vector<Vertex*>();
	m_ClosedList = new vector<Vertex*>();

	list<Vertex*> path = ComputeAStarPath(m_Vertices->at(0), m_Vertices->at(6));

	for (Vertex* v : path)
	{
		printf("Path %d ", v->getId());
	}
}

void Graph::Draw()
{
	for (int i = 0; i < m_Vertices->size(); i++)
	{
		m_Target->Bar(m_Vertices->at(i)->getPosition().x, m_Vertices->at(i)->getPosition().y,
			m_Vertices->at(i)->getPosition().x + 25, m_Vertices->at(i)->getPosition().y + 25, 0xff0000);

		char buffer[32];
		char* c = itoa(m_Vertices->at(i)->getId(), buffer, 10);
		m_Target->Print(c, m_Vertices->at(i)->getPosition().x, m_Vertices->at(i)->getPosition().y, 0xffffff);
	}

	for (int i = 0; i < m_Edges->size(); i++)
	{
		m_Target->Line(m_Edges->at(i)->getSource()->getPosition().x + 12, m_Edges->at(i)->getSource()->getPosition().y + 12,
			m_Edges->at(i)->getDestination()->getPosition().x + 12, m_Edges->at(i)->getDestination()->getPosition().y + 12, 0x0000ff);

		char buffer[32];
		char* c = itoa(m_Edges->at(i)->getDistance(), buffer, 10);

		//vector3 vsource = m_Edges->at(i)->getSource()->getPosition();
		//vector3 vdest = m_Edges->at(i)->getDestination()->getPosition();
		//vector3 line = vsource - vdest;
		//int mx = max(vsource.x, vdest.x);
		//int my = max(vsource.y, vdest.y);
		//int nx = min(vsource.x, vdest.x);
		//int ny = min(vsource.y, vdest.y);

		////int x = vsource.x + abs(line.x);
		////int y = vsource.y + abs(line.y);

		//int x = mx - nx;
		//int y = my - ny;

		//m_Target->Print(c, x/2, y/2, 0xffff00);
	}

	m_Cow->update();
	m_Rabbit->update();
}

list<Vertex*> Graph::ComputeAStarPath(Vertex* source, Vertex* target)
{
	if (source == target)
		throw std::invalid_argument("Source cannot be the same as target!");

	list<Vertex*> path;

	for (Vertex* v : *m_Vertices)
	{
		v->m_VisitedBy = nullptr;
		v->m_MinDistance = 2147483647;
		v->m_GuessedTotalDistance = 0;
	}

	source->m_MinDistance = 0;
	m_OpenList->push_back(source);

	//good stuff incoming
	while (!m_OpenList->empty())
	{
		Vertex* vertex = m_OpenList->front();
		m_OpenList->erase(m_OpenList->begin());

		//calculate guessed distance
		float guessedDistance;

		if (vertex == target)
			guessedDistance = 0.0f;
		else
		{
			int sourceX = (int)vertex->getPosition().x;
			int sourceY = (int)vertex->getPosition().y;
			int targetX = (int)target->getPosition().x;
			int targetY = (int)target->getPosition().y;

			if (sourceY == targetY)
				guessedDistance = abs(sourceX - targetX);
			else if (sourceX == targetX)
				guessedDistance = abs(sourceY - targetY);
			else
			{
				int a = pow((float)(sourceX - targetX), 2);
				int b = pow((float)(sourceY - targetY), 2);
				guessedDistance = abs(sqrt(a + b));
			}
		}

		for (Edge* edge : *vertex->getEgdes())
		{
			Vertex* target = edge->getDestination();


			if (std::find(m_ClosedList->begin(), m_ClosedList->end(), target) == m_ClosedList->end())
			{
				int distance = edge->getDistance();

				int totalDistance = vertex->m_MinDistance + distance;
				if ((totalDistance) < target->m_MinDistance)
				{
					target->m_MinDistance = totalDistance;
					target->m_GuessedTotalDistance = totalDistance + guessedDistance;
					target->m_VisitedBy = vertex;
					m_OpenList->push_back(target);
				}
			}
		}

		m_ClosedList->push_back(vertex);

		std::sort(m_OpenList->begin(), m_OpenList->end(), sortByGuessedTotalDistance);
	}

	Vertex* current = target;

	while (current != nullptr && current != source)
	{
		path.push_front(current);
		current = current->m_VisitedBy;
	}

	m_ClosedList->clear();

	return path;
}

void Graph::addEdge(short sourceLocNo, short destLocNo, int duration) 
{
	Edge* edge = new Edge(m_Vertices->at(sourceLocNo), m_Vertices->at(destLocNo), sourceLocNo, destLocNo, duration);
	m_Edges->push_back(edge);

	m_Vertices->at(sourceLocNo)->getEgdes()->push_back(edge);

	edge = nullptr;
}

vector<Vertex*>* Graph::getVertices()
{
	return m_Vertices;
}

vector <Edge*>* Graph::getEdges()
{
	return m_Edges;
}

Surface* Graph::getSurface()
{
	return m_Target;
}
