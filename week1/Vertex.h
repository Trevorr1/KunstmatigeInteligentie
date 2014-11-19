#pragma once

#include <string>
#include "template.h"

namespace Tmpl8
{
	class vector3;
	class Vertex
	{
	public:
		Vertex(std::string aName, std::string aDescription, vector3 aPosition);
		virtual ~Vertex();

		std::string getName();
		std::string getDescription();
		vector3 getPosition();
	private:
		std::string m_Name;
		std::string m_Description;
		vector3 m_Position;
	};
}

