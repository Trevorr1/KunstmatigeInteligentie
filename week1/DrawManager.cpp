#include "DrawManager.h"

using namespace Tmpl8;

DrawManager& DrawManager::getInstance()
{
	static DrawManager _instance;
	return _instance;
}


DrawManager::~DrawManager()
{
}
