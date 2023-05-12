#include "enemy.h"
#include"../../bullet_manager/bullet_manager.h"
#include"../../bullet_manager/bullet/bullet.h"

//�R���X�g���N�^
CEnemy::CEnemy(aqua::IGameObject* parent)
	:IUnit(parent,"Enemy")
{
}

//������
void CEnemy::Initialize(void)
{
	IUnit::Initialize("data/boxt.mv1");

	m_Model->position = aqua::CVector3(30.0f, 0.0f, 30.0f);

}

//�X�V
void CEnemy::Update(void)
{
	IUnit::Update();

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

		hit_flag = CollCheckSphere(-1, bullet->GetCenterPosition(), bullet->GetRadius());

		//����������true
		if (hit_flag)
			return hit_flag;

		++it;
	}

	//�������ĂȂ��Ȃ�false
	return hit_flag;
}
