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
	return attack;
}
// 防御処理
int Sowrd::Defense(Character* enemy)
{
	//召喚士が攻撃してきたた場合
	if (dynamic_cast<Summoner*>(enemy))
	{
		return enemy->GetAttack() * 2;
	}
	// 魔法使いが攻撃してきた場合
	if (dynamic_cast<Wizzard*>(enemy))
	{
		return -(enemy->GetAttack() * 2);
	}
	return 0;
}
