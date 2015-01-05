#include "EntityState.h"
#include "IGameEntity.h"
#include "template.h"

using namespace Tmpl8;


EntityState::~EntityState()
{
}

void EntityState::ToriodLogic(IGameEntity* self)
{
	vector3 currentPos = self->getPosition();
	if (self->getPosition().y > SCRHEIGHT)
	{
		self->setPosition(currentPos.x, -31);
	}
	if (self->getPosition().y < -31)
	{
		self->setPosition(currentPos.x, SCRHEIGHT);
	}
	if (self->getPosition().x > SCRWIDTH)
	{
		self->setPosition(-31, currentPos.y);
	}
	if (self->getPosition().x < -31)
	{
		self->setPosition(SCRWIDTH , currentPos.y);
	}
}

int EntityState::OptionSum()
{
	float sum = 0;
	for (auto v : m_Options)
	{
		sum += v;
	}
	return sum;
}

void EntityState::NormalizeOptionsTo(int value)
{
	float sum = OptionSum();
	for (auto option : m_Options)
	{
		option *= value / sum;
	}
}

int EntityState::RandomOption()
{
	int p = (rand() % 100) + 1;
	int cumulativeProbability = 0;
	for (int i = 0; i < m_Options.size(); i++)
	{
		cumulativeProbability += m_Options.at(i);
		if (p <= cumulativeProbability && m_Options.at(i) != 0)
		{
			return i;
		}
	}
}