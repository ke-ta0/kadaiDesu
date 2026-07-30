#include "Team.h"
#include"Character.h"
#include"Wizzard.h"
#include"Sowrd.h"
#include"Summoner.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
// ループ処理作る
int main()
{
    // ターン数
    int TurnCount= 0;

    // 選択するときに使う
    int Choose;
    int ActionChoose;

    // 自分チームのインスタンス
    Team me;

    // 敵チームのインスタンス
    Team enemy;

    std::cout << "ゲーム開始" << std::endl;

    while (me.GetHP() > 0 && enemy.GetHP() > 0)
    {
        TurnCount++;
        std::cout << TurnCount << " ターン目" << std::endl;
        // キャラクター選択
        std::cout << "使う役職を選択(0:剣士、1:魔法使い、2:召喚士)" << std::endl;
        std::cin >> Choose;

        Character* character;
        // それぞれの処理
        if (Choose == 0)
        {
            character = me.member[0];
            std::cout << "剣士を選びました" << std::endl;
        }
        else if (Choose == 1)
        {
            character = me.member[1];
            std::cout << "魔法使いを選びました" << std::endl;
        }
        else if (Choose == 2)
        {
            character = me.member[2];
            std::cout << "召喚士を選びました" << std::endl;
        }
        else
        {
            std::cout << "0から2を選んでください" << std::endl;
            return 0;
        }

        // 行動選択
        std::cout << "行動を選択(0:攻撃、1:防御)" << std::endl;
        std::cin >> ActionChoose;

        // それぞれの処理
        if (ActionChoose == 0)
        {
            std::cout << "攻撃を選びました" << std::endl;
        }
        else if (ActionChoose == 1)
        {
            std::cout << "防御を選びました" << std::endl;
        }
        else
        {
                std::cout << "0か1を選んでください" << std::endl;
                return 0;
        }

        int EnemyChoose = 0;
        EnemyChoose = rand() % 3;
        Character* Enemy = enemy.member[EnemyChoose];

        int EnemyAction = 0;
        EnemyAction = rand() % 2;

        std::cout << "自陣の残り戦力: " << me.GetHP() << std::endl;
        std::cout << "敵陣の残り戦力: " << enemy.GetHP() << std::endl;
    }
    // 買った場合
    if (me.GetHP() <= 0)
    {
        std::cout << "私たちの負けです"<<std::endl;
    }
    // 負けた場合
    else
    {
        std::cout << "勝ちました!" << std::endl;
    }

    return 0;
}