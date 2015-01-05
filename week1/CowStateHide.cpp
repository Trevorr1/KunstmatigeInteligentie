#include "CowStateHide.h"
#include <iostream>

using namespace Tmpl8;

CowStateHide::CowStateHide()
{
	m_eState = HIDE;
	std::cout << "The cow says: Hehe he'll never find me here >:D\n";
}


CowStateHide::~CowStateHide()
{
}
