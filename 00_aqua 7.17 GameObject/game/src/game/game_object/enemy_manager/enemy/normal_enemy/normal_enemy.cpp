#include "normal_enemy.h"

//�R���X�g���N�^
CNormalEnemy::CNormalEnemy(aqua::IGameObject* parent)
	:IEnemy(parent,"NormalEnemy")
{
}

//������
void CNormalEnemy::Initialize(void)
{
	m_Position = aqua::CVector2::ZERO;
	m_Velocity = aqua::CVector2::ZERO;
	m_Life = 0;
}