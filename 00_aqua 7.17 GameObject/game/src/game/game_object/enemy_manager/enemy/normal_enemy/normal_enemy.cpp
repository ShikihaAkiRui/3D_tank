#include "normal_enemy.h"

const std::string CNormalEnemy::m_object_name = "NormalEnemy";

//�R���X�g���N�^
CNormalEnemy::CNormalEnemy(aqua::IGameObject* parent)
	:IEnemy(parent,m_object_name)
{
}

//������
void CNormalEnemy::Initialize(void)
{
	m_Position = aqua::CVector2::ZERO;
	m_Velocity = aqua::CVector2::ZERO;
	m_Life = 0;
}