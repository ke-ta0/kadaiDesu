#pragma once
#include"Character.h"

class Summoner : public Character
{
public:
	// 召喚士のコンストラクタとデストラクタ
	Summoner();
	~Summoner();

	// 純粋仮想関数再定義
	int Attack() override;
	int Defense() override;
};