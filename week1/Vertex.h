#pragma once

#include <string>

namespace Tmpl8
{
	class Vertex
	{
	public:
		Vertex();
		Vertex(std::string aName, std::string aDirection);
		virtual ~Vertex();

		std::string getName();
		std::string getDescription();
	private:
		std::string m_Name;
		std::string m_Description;
	};
}

