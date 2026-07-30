#include"Sowrd.h"
#include"Wizzard.h"
#include"Summoner.h"
#include"Character.h"


// コンストラクタ
Sowrd::Sowrd()
{
	// 剣士の攻撃力設定
	attack = 45;
}
// デストラクタ
Sowrd::~Sowrd()
{
	
}
// 攻撃処理
int Sowrd::Attack(Character *enemy)
{
	// 攻撃先が召喚士の場合
	if (dynamic_cast<Summoner*>(enemy))
	{
		return attack * 2;
	}
	// 攻撃先が魔法使いの場合
	if (dynamic_cast<Wizzard*>(enemy))
	{
		// 自分が食らうから-
		return -(attack * 2);
	}
	return attack;
}
// 防御処理
int Sowrd::Defense(Character* enemy)
{
	// 魔法使いが攻撃してきたた場合
	if (dynamic_cast<Summoner*>(enemy))
	{
		return enemy->GetAttack() * 2;
	}
	// 召喚士が攻撃してきた場合
	if (dynamic_cast<Wizzard*>(enemy))
	{
		return -(enemy->GetAttack() * 2);
	}
	return 0;
}
