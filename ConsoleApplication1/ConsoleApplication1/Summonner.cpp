#include "Wizzard.h"
#include "Sowrd.h"
#include "Summoner.h"
#include"Character.h"
Summoner::Summoner()
{
	// ¢Š«m‚ÌUŒ‚—Íİ’è
	attack = 25;
}

Summoner::~Summoner()
{

}

int Summoner::Attack(Character* enemy)
{
	return attack;
}

int Summoner::Defense(Character* enemy)
{
	// Œ•m‚ªUŒ‚‚µ‚Ä‚«‚½ê‡
	if (dynamic_cast<Sowrd*>(enemy))
	{
		return -(enemy->GetAttack() * 2);
	}
	// –‚–@g‚¢‚ªUŒ‚‚µ‚Ä‚«‚½ê‡
	else if (dynamic_cast<Wizzard*>(enemy))
	{
		return enemy->GetAttack() * 2;
	}
	// ¢Š«m“¯m‚Ìê‡
	else
	{
		return 0;
	}
	 
}