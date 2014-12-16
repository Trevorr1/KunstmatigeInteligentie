#include "CowStateFactory.h"

using namespace Tmpl8;

CowStateFactory::~CowStateFactory()
{
}

CowStateFactory& CowStateFactory::getInstance()
{
	static CowStateFactory _instance;
	return _instance;
}
