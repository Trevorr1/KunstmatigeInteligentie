#pragma once

#include <string>
#include <vector>
#include "Edge.h"
#include "template.h"

namespace Tmpl8
{
	class vector3;
	class Vertex
	{
	public:
		Vertex(std::string aName, int aId, vector3 aPosition);
		virtual ~Vertex();

		//void addGameObject()

		std::string getName();
		vector3 getPosition();
		short getId();

		std::vector<Edge*>* getEgdes();

		Vertex* m_VisitedBy = nullptr;
		int m_MinDistance;
		int m_GuessedTotalDistance;

	private:
		std::string m_Name;
		vector3 m_Position;
		int m_Id;
		std::vector<Edge*>* m_Edges;
	};
}

