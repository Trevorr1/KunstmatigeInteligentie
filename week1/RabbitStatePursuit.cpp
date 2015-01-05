#include "RabbitStatePursuit.h"
#include "IGameEntity.h"
#include "template.h"

using namespace Tmpl8;

RabbitStatePursuit::RabbitStatePursuit()
{
	m_eState = PURSUIT;
}


RabbitStatePursuit::~RabbitStatePursuit()
{
}

void RabbitStatePursuit::Run(IGameEntity* self, IGameEntity* other, IGameEntity* ally, IGameEntity* neutral)
{
	vector3 newHeading = (other->getCenter() - self->getCenter());

	newHeading.Normalize();
	self->setSpeed(PURSUITSPEED);
	self->setHeading(newHeading);
	self->Move(0.0f);
}
