#include "CowStateInvulnerable.h"
#include <iostream>

using namespace Tmpl8;

CowStateInvulnerable::CowStateInvulnerable()
{
	m_eState = INVULNERABLE;
	std::cout << "Cow says: I HAVE THE POWER.\n";
}


CowStateInvulnerable::~CowStateInvulnerable()
{
}
