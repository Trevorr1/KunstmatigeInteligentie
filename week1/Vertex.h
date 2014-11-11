#pragma once

#include <string>

namespace Tmpl8
{
	class Vertex
	{
	public:
		Vertex();
		Vertex(std::string aName, std::string aDirection, unsigned int aID);
		virtual ~Vertex();

		std::string getName();
		std::string getDescription();
		void setDescription(std::string aDescription);
		unsigned int getID();
	private:
		std::string m_Name;
		std::string m_Description;
		unsigned int m_ID;
	};
}

