#pragma once
#include <ctime>

namespace Tmpl8
{
	class IGameLoop
	{
	public:
		IGameLoop(){};
		virtual ~IGameLoop(){};
		
		virtual void Tick(float dt) = 0;
	protected:
		std::clock_t m_TimerStart;
	};
}//namespace Tmpl8