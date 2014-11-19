#include <string>
#include "string.h"
#include "surface.h"
#include "stdlib.h"
#include "template.h"
#include "game.h"

#include "Graph.h"
#include "DijkstraSearch.h"
#include <vector>

using namespace Tmpl8;

#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>

Game::~Game()
{
	delete m_Graph;
	delete m_DS;
	//surface memory leaks in template
	_CrtDumpMemoryLeaks();
}

void Game::Init()
{
	m_Graph = new Graph();
	m_Graph->init();

	m_DS = new DijkstraSearch(m_Graph);
	m_DS->Execute(m_Graph->getVertices()->at(0));
	std::vector<Vertex*>* path = m_DS->GetPath(m_Graph->getVertices()->at(10));

	int wait = 0;

}

void Game::Tick( float a_DT )
{
	m_Screen->Clear(0x000000);
}