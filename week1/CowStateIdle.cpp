#include "CowStateIdle.h"
#include <iostream>

using namespace Tmpl8;

CowStateIdle::CowStateIdle()
{
	m_eState = IDLE;
	std::cout << "Cow says: EAT LEAD!\n";
}


CowStateIdle::~CowStateIdle()
{
}
