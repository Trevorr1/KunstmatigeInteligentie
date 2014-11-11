#include <string>
#include "string.h"
#include "surface.h"
#include "stdlib.h"
#include "template.h"
#include "game.h"

#include "Graph.h"

using namespace Tmpl8;

#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>

Game::~Game()
{
	delete m_Graph;
	_CrtDumpMemoryLeaks();
}

void Game::Init()
{
	m_Graph = new Graph();
	m_Graph->init();
}

void Game::Tick( float a_DT )
{
	m_Screen->Clear(0x000000);
}