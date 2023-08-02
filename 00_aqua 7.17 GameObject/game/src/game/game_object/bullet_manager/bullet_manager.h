#pragma once

#include"aqua.h"
#include"../unit_manager/unit_id.h"
#include"bullet/bullet_id.h"

//弾のマネージャー
class CBulletManager
{
public:
	//インスタンスの取得
	static CBulletManager& GetInstance(void);

	void Initialize(void);
	void Update(void);
	void Draw(void);
	void Finalize(void);

	//生成
	void Create(BULLET_ID id,UNIT_CATEGORY unit_category, const aqua::CVector3& position, const aqua::CVector3& rotation);

	//弾とキャラクターの当たり判定
	bool CheckHitCharacter(ICollision* collision, UNIT_CATEGORY unit_category);

private:
	//コンストラクタ
	CBulletManager() = default;
	//コピーコンストラクタ
	CBulletManager(const CBulletManager& rhs);
	//デストラクタ
	~CBulletManager() = default;
	//代入演算子
	CBulletManager& operator=(const CBulletManager& rhs);

	aqua::IGameObject m_GameObject;	//ゲームオブジェクト
};
