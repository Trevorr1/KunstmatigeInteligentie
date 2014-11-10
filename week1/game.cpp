#include <string>
#include "string.h"
#include "surface.h"
#include "stdlib.h"
#include "template.h"
#include "game.h"

using namespace Tmpl8;

#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>

Game::~Game()
{
	_CrtDumpMemoryLeaks();
}

void Game::Init()
{	
}

void Game::Tick( float a_DT )
{
	m_Screen->Clear(0x000000);
}

void Game::KeyDown(unsigned int code)
{
	
	
}