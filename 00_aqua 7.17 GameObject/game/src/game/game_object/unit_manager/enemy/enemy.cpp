#include "enemy.h"
#include"../../bullet_manager/bullet_manager.h"
#include"../../bullet_manager/bullet/bullet.h"

const aqua::CVector3 CEnemy::m_graund_ray_langth = aqua::CVector3(0.0f, -10.0f, 0.0f);

//�R���X�g���N�^
CEnemy::CEnemy(aqua::IGameObject* parent)
	:ICharacter(parent,"Enemy")
{
}

//������
void CEnemy::Initialize(void)
{
	ICharacter::Initialize("data/boxt.mv1");

	m_GraundRayLength = m_graund_ray_langth;
	m_Position = aqua::CVector3(-1200.0f, 100.0f, -600.0f);

	m_Model->position = m_Position;
}

//�X�V
void CEnemy::Update(void)
{
	ICharacter::Update();

	if (CheckHitBullet())
		DeleteObject();
}

//�e�̓����蔻��
bool CEnemy::CheckHitBullet(void)
{
	CBulletManager* bullet_manager = (CBulletManager*)aqua::FindGameObject("BulletManager");
	if (!bullet_manager || bullet_manager->GetChildList()->empty())
		return false;

	auto it = bullet_manager->GetChildList()->begin();

	bool hit_flag = false;

	while(it != bullet_manager->GetChildList()->end())
	{
		CBullet* bullet = (CBullet*)(*it);

		hit_flag = CollCheckSphere(m_frame_index, bullet->GetCenterPosition(), bullet->GetRadius());

		//����������true
		if (hit_flag)
			return hit_flag;

		++it;
	}

	//�������ĂȂ��Ȃ�false
	return hit_flag;
}
