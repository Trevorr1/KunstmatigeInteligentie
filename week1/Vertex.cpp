#include "Vertex.h"
#include "Edge.h"
#include "template.h"
#include "DrawManager.h"

using namespace Tmpl8;
using namespace std;

Vertex::Vertex(string aName, int aId, vector3 aPosition)
{
	m_Name = aName;
	m_Id = aId;
	m_Position = aPosition;

	m_Edges = new vector<Edge*>();
	m_GameEntities = new vector<IGameEntity*>();
	m_MinDistance = 0;
	m_GuessedTotalDistance = 0;
}

Vertex::~Vertex()
{
	for (IGameEntity* ent : *m_GameEntities)
	{
		delete ent;
	}

	delete m_GameEntities;
}

void Vertex::Draw()
{
	//get target surface from passed param or singleton
	Surface* surface = DrawManager::getInstance().getScreen();

	surface->Bar(m_Position.x, m_Position.y, m_Position.x + 25, m_Position.y + 25, 0xff0000);

	char buffer[32];
	char* c = itoa(m_Id, buffer, 10);
	surface->Print(c, m_Position.x, m_Position.y, 0xffffff);

	////Draw images next to eachother:
	int entityCount = m_GameEntities->size();
	int imageWidth = 32;
	int totalSize = entityCount * imageWidth;
	int currentCount = 0;
	for (IGameEntity* entity : *m_GameEntities)
	{
		int addToXPosition = (entityCount > 1) ? (currentCount * imageWidth) - (totalSize / 2) + (imageWidth / 2) : 0;
		entity->setPosition(m_Position.x + 10 + addToXPosition, m_Position.y);
		//entity->setPosition(50, 250);
		entity->Draw();
		currentCount++;
	}

	for (Edge* edge : *m_Edges)
	{
		Vertex* target = edge->getDestination();
		surface->Line(m_Position.x + imageWidth / 2, m_Position.y + imageWidth / 2, target->getPosition().x + imageWidth / 2, target->getPosition().y + imageWidth / 2, 0x0000ff);
		int x = m_Position.x / 2 + target->getPosition().x / 2;
		int y = m_Position.y / 2 + target->getPosition().y / 2;
		char* c = itoa(edge->getDistance(), buffer, 10);
		surface->Print(c, x, y, 0xffffff);
	}
}

void Vertex::Update(float dt)
{

}

void Vertex::addGameObject(IGameEntity* gameObject)
{
	m_GameEntities->push_back(gameObject);
}

IGameEntity* Vertex::getGameObject(eGameEntity entityEnum)
{
	IGameEntity* result = nullptr;

	for (IGameEntity* entity : *m_GameEntities)
	{
		if (entity->getEnum() == entityEnum)
		{
			result = entity;
			break;
		}
	}

	return result;
}

IGameEntity* Vertex::takeGameObject(eGameEntity entityEnum)
{
	IGameEntity* result = nullptr;

	for (IGameEntity* entity : *m_GameEntities)
	{
		if (entity->getEnum() == entityEnum)
		{
			result = entity;
			break;
		}
	}
	
	if (result != nullptr)
		//delete from list

	return result;
}

string Vertex::getName()
{
	return m_Name;
}

vector3 Vertex::getPosition()
{
	return m_Position;
}

short Vertex::getId()
{
	return m_Id;
}

vector<Edge*>* Vertex::getEgdes()
{
	return m_Edges;
}