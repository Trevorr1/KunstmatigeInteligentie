#include <string>
#include "string.h"
#include "surface.h"
#include "stdlib.h"
#include "template.h"
#include "game.h"
#include "DrawManager.h"
#include "Graph.h"
#include "GameLoopWFour.h"
#include <vector>

using namespace Tmpl8;

#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>

Game::~Game()
{
	//delete m_Graph;
	//surface memory leaks in template
	//_CrtDumpMemoryLeaks();
}

void Game::Init()
{
	DrawManager::getInstance().setTargetSurface(m_Screen);
	m_GLF = new GameLoopWFour();
	//m_Graph = new Graph(m_Screen);
	//m_Graph->init();
}

void Game::Tick( float a_DT )
{
	m_Screen->Clear(0xffffff);
	m_GLF->Tick(a_DT);
}

void Game::KeyDown(unsigned int code)
{
	if (code == 44) //space bar
		//step graph and astar
		m_Graph->Update(0.0f);
}