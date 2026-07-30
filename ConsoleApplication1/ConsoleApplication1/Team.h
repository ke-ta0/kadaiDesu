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

	Character* Random();

private:
	int HP;
	Character* member[3];
};

