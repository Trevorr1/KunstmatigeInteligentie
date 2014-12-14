#include "Vertex.h"
#include "Edge.h"
#include "template.h"

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
	//m_Target->Bar(m_Vertices->at(i)->getPosition().x, m_Vertices->at(i)->getPosition().y,
	//	//			m_Vertices->at(i)->getPosition().x + 25, m_Vertices->at(i)->getPosition().y + 25, 0xff0000);
	//	//
	//	//		char buffer[32];
	//	//		char* c = itoa(m_Vertices->at(i)->getId(), buffer, 10);
	//	//		m_Target->Print(c, m_Vertices->at(i)->getPosition().x, m_Vertices->at(i)->getPosition().y, 0xffffff);

	////Draw images next to eachother:
	//int entityCount = m_GameEntities->size();
	//int imageWidth = 32;
	//int totalSize = entityCount * imageWidth;
	//int currentCount = 0;
	//for (IGameEntity* entity : *m_GameEntities)
	//{
	//	int addToXPosition = (entityCount > 1) ? (currentCount * imageWidth) - (totalSize / 2) + (imageWidth / 2) : 0;
	//	entity->SetOffset(this->mX + addToXPosition, this->mY);
	//	entity->
	//	entity->Draw();
	//	currentCount++;
	//}

	//mApplication->SetColor(Color(0, 0, 0, 255));
	//for (Edge* edge : *m_Edges){
	//	Vertex* target = edge->getDestination();
	//	mApplication->DrawLine(mX, mY, target->mX, target->mY);
	//	int x = mX / 2 + target->mX / 2;
	//	int y = mY / 2 + target->mY / 2;
	//	mApplication->DrawText(std::to_string(edge->getDistance()), x, y);
	//}
	//mApplication->SetColor(Color(255, 255, 255, 255));
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