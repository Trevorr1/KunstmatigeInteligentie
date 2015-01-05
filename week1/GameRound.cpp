#include "GameRound.h"
#include "Rabbit.h"
#include "Pill.h"
#include "Weapon.h"


using namespace Tmpl8;

GameRound::GameRound(vector3 cSpawn, vector3 rSpawn)
{
	srand(time(NULL));

	m_iRScore = 0;
	m_iCScore = 0;

	m_vCowSpawn = cSpawn;
	m_vRabbitSpawn = rSpawn;

	m_Cow = new Cow(WANDER);
	m_Rabbit = new Rabbit(PURSUIT);
	m_Pill = new Pill(IDLE);
	m_Weapon = new Weapon(IDLE);

	SpawnCow();
	SpawnRabbit();
	SpawnGun();
	SpawnPill();

	m_Odds = std::vector<int>();
}

GameRound::~GameRound()
{
	delete m_Cow;
	delete m_Rabbit;
	delete m_Pill;
	delete m_Weapon;
}


void GameRound::setOdds(int flee, int pill, int gun, int hide)
{
	m_Odds.push_back(flee);
	m_Odds.push_back(pill);
	m_Odds.push_back(gun);
	m_Odds.push_back(hide);

	m_Cow->CurrentState()->AddOption(flee);
	m_Cow->CurrentState()->AddOption(pill);
	m_Cow->CurrentState()->AddOption(gun);
	m_Cow->CurrentState()->AddOption(hide);
	m_Cow->CurrentState()->NormalizeOptionsTo(100);
}

void GameRound::PushOdds()
{
	if (m_Odds.size() > 0)
	{
		m_Cow->CurrentState()->AddOption(m_Odds.at(0));
		m_Cow->CurrentState()->AddOption(m_Odds.at(1));
		m_Cow->CurrentState()->AddOption(m_Odds.at(2));
		m_Cow->CurrentState()->AddOption(m_Odds.at(3));
	}
	else
	{
		int foo = 0;
	}
}

void GameRound::Tick(float dt)
{
	m_Cow->Run(dt, m_Rabbit, m_Pill, m_Weapon);
	m_Rabbit->Run(dt, m_Cow, m_Pill, m_Weapon);
	m_Weapon->Run(dt, m_Pill, m_Cow, m_Rabbit);
	m_Pill->Run(dt, m_Weapon, m_Cow, m_Rabbit);
	ResolveCollision();// here the scoring is done
}

void GameRound::SpawnRabbit()
{
	m_Rabbit->setPosition(m_vRabbitSpawn);
}

void GameRound::SpawnCow()
{
	if (m_Cow->getState() != INVULNERABLE)
	{
		delete m_Cow;
		m_Cow = new Cow(WANDER);
		PushOdds();
	}
	m_Cow->setPosition(m_vCowSpawn);
}

void GameRound::SpawnPill()
{
	m_Pill->setPosition(RandomPos());
}

void GameRound::SpawnGun()
{
	m_Weapon->setPosition(RandomPos());
}

vector3 GameRound::RandomPos()
{
	int x = (rand() % SCRWIDTH) + 1;
	int y = (rand() % (SCRHEIGHT - 32)) + 1;

	return vector3(x, y, 0);
}

void GameRound::ResolveCollision()
{
	float cow_to_rabbit = (m_Rabbit->getCenter() - m_Cow->getCenter()).Length();

	if (cow_to_rabbit < 32)
	{
		switch (m_Cow->getState())
		{
		case IDLE:
			SpawnRabbit();
			SpawnCow();
			break;
		case HIDE:
			SpawnRabbit();
			SpawnCow();
			break;
		case INVULNERABLE:
			m_iCScore += 1;
			SpawnRabbit();
			SpawnCow();
			break;
		default:
			m_iRScore += 10;
			SpawnRabbit();
			SpawnCow();
			break;
		}
	}

	float cow_to_pill = (m_Pill->getCenter() - m_Cow->getCenter()).Length();
	if (cow_to_pill < 32)
	{
		if (m_Cow->getState() == INVULNERABLE)
		{
			SpawnPill();
		}
	}

	float cow_to_weapon = (m_Weapon->getCenter() - m_Cow->getCenter()).Length();
	if (cow_to_weapon < 32 && m_Cow->getState() == IDLE)
	{
		SpawnGun();
	}
}