#pragma once
#include <vector>
#include "template.h"
#include "IGameLoop.h"

#define ROUNDLENGTH 30000
#define ROUNDS 5

namespace Tmpl8
{
	class GameRound;
	class GameLoopWFive :
		public IGameLoop
	{
	public:
		GameLoopWFive();
		virtual ~GameLoopWFive();

		void ReInitInstances();
		void ReInitRed();
		void ReInitBlue();
		void ReInitGreen();
		void ReInitYellow();

		int RandomNr(int range) { return (rand() % range) + 1; }

		void Tick(float dt);
		int RunRound(float dt);

	private:
		GameRound* m_RInstance;
		GameRound* m_BInstance;
		GameRound* m_GInstance;
		GameRound* m_YInstance;

		int m_iCounter;

		//spawn the cows and breed them
		// also randomize mutations
		
		
	};
}//namespace Tmpl8

