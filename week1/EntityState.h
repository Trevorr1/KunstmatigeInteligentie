#pragma once
#include "eEntityState.h"
#include <vector>
#include <time.h>

#define FLEESPEED 2.0f
#define WANDERSPEED 0.1f
#define PURSUITSPEED 0.3f

#define RDANGERRANGE 60
#define CDANGERRANGE 300

namespace Tmpl8 {

	class IGameEntity;
	class EntityState
	{
	public:
		EntityState() : m_eState{ NONE } {	m_Options = std::vector<int>();	srand(time(NULL)); }
		virtual ~EntityState();

		void AddOption(int probability) { m_Options.push_back(probability); }
		void PushOptions(std::vector<int> odds) { m_Options = odds; }
		void NormalizeOptionsTo(int value);

		std::vector<int> GetOptions() { return m_Options; }
		eState getState() { return m_eState; }


		virtual void Run(IGameEntity* self, IGameEntity* other, IGameEntity* ally, IGameEntity* neutral) = 0;
	protected:
		void ToriodLogic(IGameEntity* self);
		int OptionSum();
		int RandomOption();

		eState m_eState;
		std::vector<int> m_Options;
	};
}//namespace Tmpl8

