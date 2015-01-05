#include "GameLoopWFive.h"
#include "GameRound.h"
#include <iostream>

using namespace Tmpl8;

GameLoopWFive::GameLoopWFive()
{
	srand(time(NULL));
	m_TimerStart = NULL;

	// set startpositions cuz they need to be at specific distances
	m_RInstance = new GameRound(vector3(200, 100, 0), vector3(600, 100, 0));
	m_BInstance = new GameRound(vector3(200, 200, 0), vector3(600, 200, 0));
	m_GInstance = new GameRound(vector3(200, 300, 0), vector3(600, 300, 0));
	m_YInstance = new GameRound(vector3(200, 400, 0), vector3(600, 400, 0));

	//set odds
	m_RInstance->setOdds(RandomNr(100), RandomNr(100), RandomNr(100), RandomNr(100));
	m_BInstance->setOdds(RandomNr(100), RandomNr(100), RandomNr(100), RandomNr(100));
	m_GInstance->setOdds(RandomNr(100), RandomNr(100), RandomNr(100), RandomNr(100));
	m_YInstance->setOdds(RandomNr(100), RandomNr(100), RandomNr(100), RandomNr(100));

	// init round counter
	m_iCounter = 0;
}

void GameLoopWFive::ReInitInstances()
{
	ReInitRed();
	ReInitBlue();
	ReInitGreen();
	ReInitYellow();
}

void GameLoopWFive::ReInitRed()

{
	// red instance
	std::vector<int> odds = m_RInstance->GetOptions();
	odds.at(1) = odds.at(1) += m_RInstance->GetCowScore();//add changing percentage to pill

	delete m_RInstance;
	m_RInstance = new GameRound(vector3(200, 100, 0), vector3(600, 100, 0));
	m_RInstance->setOdds(odds[0], odds[1], odds[2], odds[3]);
}

void GameLoopWFive::ReInitBlue()
{
	//blue instance
	std::vector<int> odds = m_BInstance->GetOptions();
	odds.at(1) = odds.at(1) += m_BInstance->GetCowScore();
	//cout << blue odds at end of round << roundcntr << 
	delete m_BInstance;
	m_BInstance = new GameRound(vector3(200, 200, 0), vector3(600, 200, 0));
	m_BInstance->setOdds(odds[0], odds[1], odds[2], odds[3]);
}

void GameLoopWFive::ReInitGreen()
{
	//green instance
	std::vector<int>odds = m_GInstance->GetOptions();
	odds.at(1) = odds.at(1) += m_GInstance->GetCowScore();

	delete m_GInstance;
	m_GInstance = new GameRound(vector3(200, 300, 0), vector3(600, 300, 0));
	m_GInstance->setOdds(odds[0], odds[1], odds[2], odds[3]);
}

void GameLoopWFive::ReInitYellow()
{
	//yellow instance
	std::vector<int>odds = m_YInstance->GetOptions();
	odds.at(1) = odds.at(1) += m_YInstance->GetCowScore();

	delete m_YInstance;
	m_YInstance = new GameRound(vector3(200, 400, 0), vector3(600, 400, 0));
	m_YInstance->setOdds(odds[0], odds[1], odds[2], odds[3]);
}

GameLoopWFive::~GameLoopWFive()
{
	delete m_RInstance;
	delete m_BInstance;
	delete m_GInstance;
	delete m_YInstance;
}


int GameLoopWFive::RunRound(float dt)
{
	if (m_TimerStart == NULL){
		m_TimerStart = std::clock();
	}


	int timer_end = (int)((std::clock() - m_TimerStart) / (double)(CLOCKS_PER_SEC / 1000));
	int round_lenght_ms = ROUNDLENGTH;


	// drug timer checker
	if (timer_end < round_lenght_ms)
	{
		//std::cout << "Counter: " << timer_end << "\n";
		// run the game rounds here
		m_RInstance->Tick(dt);
		return 0;
	}
	else
	{
		m_TimerStart = NULL;
		// reload the game rounds here

		//ReInitInstances();
		ReInitRed();
		std::cout << "Start again!\n";
		return 1;
	}
}

void GameLoopWFive::Tick(float dt)
{
	if (m_iCounter < ROUNDS)
	{
		m_iCounter += RunRound(dt);
	}
	else
	{
		int foo = 0;
	}
}