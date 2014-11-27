#pragma once

#include <string>
#include "template.h"

namespace Tmpl8
{
	class vector3;
	class Vertex
	{
	public:
		Vertex(std::string aName, int aId, vector3 aPosition);
		virtual ~Vertex();

		std::string getName();
		vector3 getPosition();
		short getId();
	private:
		std::string m_Name;
		vector3 m_Position;
		int m_Id;
	};
}

