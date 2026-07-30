#pragma once
class Character
{
public:
	// コンストラクタとデストラクタ
	Character();
	// deleteに使う
	virtual~Character();
public:
	// 攻撃力を取得する関数
	int GetAttack();
	// 攻撃と防御の純粋仮想関数
	// 防御時のダメージ処理
	virtual int Defense(Character* enemy) = 0;
	// 攻撃時のダメージ処理
	virtual int Attack(Character* enemy) = 0;
protected:
	// 継承したクラスでも使える
	int attack;
};