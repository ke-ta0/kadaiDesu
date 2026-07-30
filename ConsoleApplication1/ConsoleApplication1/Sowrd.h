#pragma once
#include"Character.h"
class Sowrd :public Character
{
public:
	// 剣士のコンストラクタとデストラクタ
	Sowrd();
	~Sowrd();

	// 純粋仮想関数再定義
	int Attack(Character* enemy) override;
	int Defense(Character* enemy) override;
};