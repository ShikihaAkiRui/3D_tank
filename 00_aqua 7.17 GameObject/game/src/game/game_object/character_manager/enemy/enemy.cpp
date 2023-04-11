#include "enemy.h"

//�R���X�g���N�^
IEnemy::IEnemy(aqua::IGameObject* parent, const std::string& object_name)
	:aqua::IGameObject(parent,object_name,"Enemy")
	,m_Position(aqua::CVector2::ZERO)
	,m_Velocity(aqua::CVector2::ZERO)
{
}

//������
void IEnemy::Initialize(std::string file_name)
{
	m_EnemySprite.Create(file_name);
	m_EnemySprite.position = m_Position;
}

//�X�V
void IEnemy::Update(void)
{
	switch (m_State)
	{
	case STATE::WAIT:
		break;
	case STATE::MOVE:
		Move();
		break;
	case STATE::DEAD:
		Dead();
		break;
	default:	break;
	}
}

//�`��
void IEnemy::Draw(void)
{
	m_EnemySprite.Draw();
}

//���
void IEnemy::Finalize(void)
{
	m_EnemySprite.Delete();
}

//�ړ�
void IEnemy::Move(void)
{
	m_Position += m_Velocity;

	m_EnemySprite.position = m_Position;

}

//�_���[�W���󂯂�
void IEnemy::Damage(void)
{

}

//������
void IEnemy::Dead(void)
{
}

//�U��
void IEnemy::Attack(void)
{
}