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
	m_Path = list<Vertex*>();
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

	//m_Path->erase(m_Path->begin(), m_Path->end());
	//delete m_Path;

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

	location[0]->addGameObject(m_Cow);
	m_LookUpBook.insert({ eCow, location[0] });
	m_LookUpBook.insert({ eRabbit, location[6] });
	location[6]->addGameObject(m_Rabbit);

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

	m_Path = getPath(eCow, eRabbit);
}

void Graph::Draw(Surface* target)
{
	for (auto* v : *m_Vertices)
	{
		v->Draw();
	}
}

void Graph::Update(float dt)
{
	m_LookUpBook.at(eCow)->getGameObject(eCow)->setRoute(eCow, eRabbit);

	m_LookUpBook.at(eCow)->getGameObject(eCow)->Update(dt);

	for (auto& keyvalue : m_LookUpBook)
	{
		if (keyvalue.first != eCow)
		{
			IGameEntity* ent = keyvalue.second->getGameObject(keyvalue.first);
			ent->Update(dt);
		}
	}
}

list<Vertex*> Graph::ComputeAStarPath(Vertex* source, Vertex* target)
{
	if (source == target)
		throw std::invalid_argument("Vertex source cannot be the same as  vertex target!");

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

list<Vertex*> Graph::getPath(eGameEntity source, eGameEntity target)
{
	Vertex* vsrc = m_LookUpBook.at(source);
	Vertex* vtrgt = m_LookUpBook.at(target);

	return ComputeAStarPath(vsrc, vtrgt);
}

void Graph::ShuffleAllExcept(eGameEntity exception)
{
	Vertex* exceptionVertex = m_LookUpBook.at(exception);

	std::map<eGameEntity, Vertex*>::iterator it = m_LookUpBook.begin();

	for (; it != m_LookUpBook.end(); it++)
	{
		if (it->first == exception)
			continue;

		Vertex* newVertex;
		do
		{
			int result = rand() % (m_Vertices->size());
			newVertex = m_Vertices->at(result);
		} while (newVertex == exceptionVertex);

		m_LookUpBook[it->first] = newVertex;

		moveGameObject(newVertex, it->first);
	}
}

void Graph::moveGameObject(Vertex* target, eGameEntity entity)
{
	IGameEntity* target_entity = m_LookUpBook.at(entity)->takeGameObject(entity);
	target->addGameObject(target_entity);
	m_LookUpBook[entity] = target;

	// notify entities
	for (auto &vertex : m_LookUpBook)
	{
		if (vertex.first != entity) 
			vertex.second->getGameObject(vertex.first)->entityMovedNotification(entity);
	}
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
