#include "RabbitStateFactory.h"

using namespace Tmpl8;


RabbitStateFactory::~RabbitStateFactory()
{
}

RabbitStateFactory& RabbitStateFactory::getInstance()
{
	static RabbitStateFactory _instance;
	return _instance;
}