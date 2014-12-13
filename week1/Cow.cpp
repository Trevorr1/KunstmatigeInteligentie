#include "Cow.h"
#include "Graph.h"
#include "surface.h"

using namespace Tmpl8;

Cow::Cow(Graph* graph)
{
	m_Graph = graph;
	m_Sprite = new Sprite(new Surface("assets/cow-2.png"), 1);
}

Cow::~Cow()
{
	delete m_Sprite;
}

void Cow::update()
{
	m_Sprite->Draw(50, 100, m_Graph->getSurface());
}
