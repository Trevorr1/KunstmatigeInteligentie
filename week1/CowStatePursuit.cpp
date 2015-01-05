#include "CowStatePursuit.h"
#include <iostream>

using namespace Tmpl8;

CowStatePursuit::CowStatePursuit()
{
	std::cout << "The Cow says: Swiggity swooty I'm coming for that booty! I mean, Mooooo!\n\n";
}


CowStatePursuit::~CowStatePursuit()
{
}

void CowStatePursuit::Run(IGameEntity* entity, IGameEntity* other)
{
	vector3 newHeading = (other->getPosition() - entity->getPosition());

	newHeading.Normalize();
	entity->setSpeed(PURSUITSPEED);
	entity->setHeading(newHeading);
	entity->Move(0.0f);

}