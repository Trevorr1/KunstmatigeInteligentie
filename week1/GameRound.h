#pragma once

#include <vector>
#include "template.h"
#include "eEntityState.h"
#include "Cow.h"

namespace Tmpl8
{
	class Rabbit;
	class Pill;
	class Weapon;
	class GameRound
	{
	public:
		GameRound(vector3 cSpawn, vector3 rSpawn);
		virtual ~GameRound();

		void setOdds(int flee, int pill, int gun, int hide);
		void PushOdds();
		std::vector<int> GetOptions() { return m_Odds; }

		void SpawnRabbit();
		void SpawnCow();
		void SpawnGun();
		void SpawnPill();

		void ResolveCollision();
		void Tick(float dt);

		vector3 RandomPos();

		int GetRabbitScore() { return m_iRScore; }
		int GetCowScore() { return m_iCScore; }
	private:
		Cow* m_Cow;
		Rabbit* m_Rabbit;
		Pill* m_Pill;
		Weapon* m_Weapon;

		int m_iRScore;
		int m_iCScore;

		vector3 m_vCowSpawn;
		vector3 m_vRabbitSpawn;

		std::vector<int> m_Odds;

	};
}//namespace Tmpl8

