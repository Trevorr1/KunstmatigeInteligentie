#pragma once

#include "template.h"

namespace Tmpl8
{
	class Graph;
	class Surface;
	class Sprite;
	class Cow
	{
	public:
		Cow(Graph* graph);
		virtual ~Cow();

		void update();

	private:
		Sprite* m_Sprite;
		Graph* m_Graph;
	};
} //tmpl8



