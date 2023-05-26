#include "enemy.h"
#include"../../bullet_manager/bullet_manager.h"
#include"../../bullet_manager/bullet/bullet.h"

const aqua::CVector3 CEnemy::m_graund_ray_langth = aqua::CVector3(0.0f, -10.0f, 0.0f);

//コンストラクタ
CEnemy::CEnemy(aqua::IGameObject* parent)
	:ICharacter(parent,"Enemy")
{
}

//初期化
void CEnemy::Initialize(void)
{
	ICharacter::Initialize("data/boxt.mv1");

	m_GraundRayLength = m_graund_ray_langth;
	m_Position = aqua::CVector3(-1200.0f, 100.0f, -600.0f);

	m_Model->position = m_Position;
}

//更新
void CEnemy::Update(void)
{
	ICharacter::Update();

	if (CheckHitBullet())
		DeleteObject();
}

//弾の当たり判定
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

		//当たったらtrue
		if (hit_flag)
			return hit_flag;

		++it;
	}

	//当たってないならfalse
	return hit_flag;
}
