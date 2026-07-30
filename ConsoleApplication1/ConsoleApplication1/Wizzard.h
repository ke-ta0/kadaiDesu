#pragma once
#include"Character.h"

class Wizzard : public Character
{
public:
	// 魔法使いのコンストラクタとデストラクタ
	Wizzard();
	~Wizzard();

	// 純粋仮想関数再定義
	int Attack(Character* enemy) override;
	int Defense(Character* enemy) override;
};