#pragma once

#include "surface.h"

namespace Tmpl8
{
	class DrawManager
	{
	public:
		virtual ~DrawManager();
		static DrawManager& getInstance();
		void setTargetSurface(Surface* surface) { m_Surface = surface; }
		Surface* getScreen() { return m_Surface; }

	private:
		DrawManager() {}
		Surface* m_Surface;
	};
}



