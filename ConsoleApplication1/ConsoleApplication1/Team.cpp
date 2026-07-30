#include "Team.h"
#include "Sowrd.h"
#include "Wizzard.h"
#include "Summoner.h"
#include <cstdlib>

// コンストラクタ
Team::Team()
{
    HP = 300;

    // キャラ3体を生成
    member[0] = new Sowrd();
    member[1] = new Wizzard();
    member[2] = new Summoner();
}

// デストラクタ
Team::~Team()
{
    for (int i = 0; i < 3; i++)
    {
        delete member[i];
    }
}

// ランダムにキャラを返す
Character* Team::Random()
{
    int r = rand() % 3;
    return member[r];
}

// ダメージを戦力に反映
void Team::Damage(int damage)
{
    HP -= damage;

    if (HP < 0)
       HP = 0;
}
