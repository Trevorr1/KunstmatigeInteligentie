#pragma once

#include <string>

class Vertex
{
public:
	Vertex();
	Vertex(std::string aName, std::string aDirection, int aID);
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

