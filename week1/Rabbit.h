#pragma once

#include "template.h"

namespace Tmpl8
{
	class Graph;
	class Surface;
	class Sprite;
	class Rabbit
	{
	public:
		Rabbit(Graph* graph);
		virtual ~Rabbit();

		void update();

	private:
		Sprite* m_Sprite;
		Graph* m_Graph;
	};
} //tmpl8


