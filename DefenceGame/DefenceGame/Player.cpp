#include "Player.h"
#include"SceneManager.h"
Player* Player::m_pInst = nullptr;

void Player::modifyHP(int value)
{
	_hp += value;
	if (_hp <= 0)
	{
		GET_SINGLETON(SceneManager)->loadScene("EndScene");
	}
}

void Player::modifyGold(int value)
{
	if (value > 0)
		_totalGold += value;
	_gold += value;
}
