#include "IGameEntity.h"
#include "CowStateWander.h"
#include "CowStateFactory.h"
#include <iostream>

using namespace Tmpl8;

CowStateWander::CowStateWander()
{
	srand(time(NULL));
	m_eState = WANDER;
	std::cout << "Cow says: Just keep grazing, grazing, grazing.\n";
}


CowStateWander::~CowStateWander()
{
}

void CowStateWander::Run(IGameEntity* self, IGameEntity* other, IGameEntity* ally, IGameEntity* neutral)
{

	float distance = (other->getCenter() - self->getCenter()).Length();
	if (distance < CDANGERRANGE)
	{
		std::vector<int> odds = m_Options;
		//choosing a different probability to jump to based on probability
		switch (RandomOption())
		{
		case 0:
			self->setState(CowStateFactory::getInstance().createFleeState());
			self->CurrentState()->PushOptions(odds);
			break;
		case 1:
			self->setState(CowStateFactory::getInstance().createHideState());
			self->CurrentState()->PushOptions(odds);
			break;
		case 2:
			self->setState(CowStateFactory::getInstance().createJunkyState());
			self->CurrentState()->PushOptions(odds);
			break;
		case 3:
			self->setState(CowStateFactory::getInstance().createGunnerState());
			self->CurrentState()->PushOptions(odds);
			break;
		}
	}
	else
	{
		int iX = 13 - (rand() % 25);
		int iY = 13 - (rand() % 25);

		vector3 newHeading = vector3((float)iX + 1, (float)iY + 1, 0);

		ToriodLogic(self);

		newHeading.Normalize();

		self->setHeading(newHeading);
		self->setSpeed(WANDERSPEED);

		self->Move(0.0f);
	}

}
