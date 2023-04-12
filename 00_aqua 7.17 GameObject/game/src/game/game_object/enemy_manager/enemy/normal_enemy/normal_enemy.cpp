#include "normal_enemy.h"

//コンストラクタ
CNormalEnemy::CNormalEnemy(aqua::IGameObject* parent)
	:IEnemy(parent,"NormalEnemy")
{
}

//初期化
void CNormalEnemy::Initialize(void)
{
	m_Position = aqua::CVector2::ZERO;
	m_Velocity = aqua::CVector2::ZERO;
	m_Life = 0;
}