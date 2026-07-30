#include "Character.h"
#include<iostream>
Character::Character()
{
	std::cout << "Characterのコンストラクタ" << std::endl;
}
Character::~Character()
{
	std::cout << "Characterのデストラクタ" << std::endl;
}

int Character::GetAttack()const
{
	return attack;
}
