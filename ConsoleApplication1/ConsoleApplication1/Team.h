#pragma once
#include"Character.h"
class Team
{
public:
	Team();
	~Team();

	// ターン終了時のHP残量を返す 
	int GetHP() const;

	// ダメージ計算
	void Damage(int damage);


	// キャラクターをランダムで選ぶ
	Character* Random();

	// 

	// 配列でキャラクター3人
	Character* member[3];
private:
	int HP;
};

