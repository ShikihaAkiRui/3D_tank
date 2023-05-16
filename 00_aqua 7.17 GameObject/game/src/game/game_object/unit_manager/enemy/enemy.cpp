#include "enemy.h"
#include"../../bullet_manager/bullet_manager.h"
#include"../../bullet_manager/bullet/bullet.h"

//コンストラクタ
CEnemy::CEnemy(aqua::IGameObject* parent)
	:IUnit(parent,"Enemy")
{
}

//初期化
void CEnemy::Initialize(void)
{
	IUnit::Initialize("data/boxt.mv1");

	m_Model->position = aqua::CVector3(30.0f, 0.0f, 30.0f);

}

//更新
void CEnemy::Update(void)
{
	IUnit::Update();

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
