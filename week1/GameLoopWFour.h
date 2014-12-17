#pragma once
#include "Cow.h"
#include "Rabbit.h"
namespace Tmpl8 {
	class GameLoopWFour
	{
	public:
		GameLoopWFour();
		virtual ~GameLoopWFour();

		void Tick(float dt);

	private:
		Cow* m_Cow;
		Rabbit* m_Rabbit;
		
	};
}//namespace Tmpl8

