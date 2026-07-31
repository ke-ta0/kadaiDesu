#include "Wizzard.h"
#include "Sowrd.h"
#include "Summoner.h"
#include"Character.h"
Wizzard::Wizzard()
{
	// –‚–@g‚¢‚ÌUŒ‚—Íİ’è
	attack = 30;
}

Wizzard::~Wizzard()
{

}

int Wizzard::Attack(Character* enemy)
{
	return attack;
}

int Wizzard::Defense(Character* enemy)
{
	// Œ•m‚ªUŒ‚‚µ‚Ä‚«‚½ê‡
	if (dynamic_cast<Sowrd*>(enemy))
	{
		// Œ•m‚ÌUŒ‚—Í‚ğ•Ô‚·
		return -(attack* 2);
	}
	// ¢Š«m‚ªUŒ‚‚µ‚Ä‚«‚½ê‡
	else if (dynamic_cast<Summoner*>(enemy))
	{
		// ¢Š«m‚Ì“ñ”{‚ÌUŒ‚—Í‚ğ•Ô‚·
		return enemy->GetAttack() * 2;
	}
	// –‚–@g‚¢“¯m‚Ìê‡
	else
	{
		// ‰½‚à‹N‚±‚ç‚È‚¢
		return 0;
	}
	
}