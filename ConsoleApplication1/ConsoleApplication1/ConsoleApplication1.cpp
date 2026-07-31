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
            // Teamからmember[0]のポインタをコピー
            character = me.member[0];
            std::cout << "剣士を選びました" << std::endl;
        }
        else if (Choose == 1)
        {
            // Teamからmember[1]のポインタをコピー
            character = me.member[1];
            std::cout << "魔法使いを選びました" << std::endl;
        }
        else if (Choose == 2)
        {
            // Teamからmember[2]のポインタをコピー
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

        // 敵ランダム選択
        Character* Enemy = enemy.Random();

        int EnemyAction = 0;
        EnemyAction = rand() % 2;

        // 敵キャラ名の表示
        if (dynamic_cast<Sowrd*>(Enemy))
        {
            std::cout << "敵は剣士を選んだ" << std::endl;
        }
        else if (dynamic_cast<Wizzard*>(Enemy))
        {
            std::cout << "敵は魔法使いを選んだ！" << std::endl;
        }
        else if (dynamic_cast<Summoner*>(Enemy))
        {
            std::cout << "敵は召喚士を選んだ！" << std::endl;
        }

        // 敵の行動の表示
        if (EnemyAction == 0)
        {
            std::cout << "敵は攻撃を選んだ！" << std::endl;
        }
        else
        {
            std::cout << "敵は防御を選んだ！" << std::endl;
        }
  // 行動の組み合わせ判定

// 両者攻撃
        if (ActionChoose == 0 && EnemyAction == 0)
        {
            // 
            int MAtk = character->Attack(Enemy); 
            int enemyAtk = Enemy->Attack(character); 
            // ダメージ比較
            if (MAtk > enemyAtk)
            {
                enemy.Damage(MAtk);
                std::cout << "私の攻撃力の方が上なので敵に "<< MAtk << " ダメージ"<<std::endl;
            }
            else if (enemyAtk > MAtk)
            {
                me.Damage(enemyAtk);
                std::cout << "敵の攻撃力の方が上なのであなたに "<< enemyAtk << " ダメージ" << std::endl;
            }
            else
            {
                std::cout << "ドロー"<<std::endl;
            }

        }

        // 自分が攻撃で敵防御
        if (ActionChoose == 0 && EnemyAction == 1)
        {
            // 敵の防御処理
            int dmg = Enemy->Defense(character);

            // 敵がダメージ
            if (dmg >= 0)
            {
                enemy.Damage(dmg);  
                std::cout << "敵に " << dmg << " ダメージ"<< std::endl;
            }
            else
            {
                me.Damage(-dmg);
                std::cout << "カウンターくらった " << -dmg << " ダメージ" << std::endl;
            }
        }

        // 自分が防御で敵攻撃
        if (ActionChoose == 1 && EnemyAction == 0)
        {
            // 自分の防御処理
            int dmg = character->Defense(Enemy);  

            if (dmg >= 0)
            {
                // 自分がダメージ
                me.Damage(dmg); 
                std::cout << "自分に" << dmg << " ダメージ"<< std::endl;
            }
            // カウンター処理
            else
            {
                enemy.Damage(-dmg);  
                std::cout << "カウンターで敵に " << -dmg << " ダメージ"<<std::endl;
            }
        }
        // ターン終了時点の残り戦力の表示
        std::cout << "自陣の残り戦力: " << me.GetHP() << std::endl;
        std::cout << "敵陣の残り戦力: " << enemy.GetHP() << std::endl;
    }

    // 勝った場合
    if (me.GetHP() <= 0)
    {
        std::cout << "私たちの負けです"<<std::endl;
    }
    // 負けた場合
    else
    {
        std::cout << "勝ちました" << std::endl;
    }
    std::cout << "ゲーム終了までのターン" << TurnCount << std::endl;
    return 0;
}