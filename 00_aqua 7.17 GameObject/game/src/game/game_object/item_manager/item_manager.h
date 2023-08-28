#pragma once

#include"aqua.h"
#include"../unit_manager/unit_manager.h"

//アイテムマネージャー
class CItemManager
{
public:
	//インスタンスを取得
	static CItemManager& GetInstance(void);

	void Initialize(void);
	void Update(void);
	void Draw(void);
	void Finalize(void);

	//生成
	//位置
	void Create(aqua::CVector3& position);

	//アイテムとキャラクターの当たり判定
	//コリジョン,	ユニットのカテゴリー
	bool CheckHitCharacter(ICollision* collision, UNIT_CATEGORY unit_category);

private:
	//コンストラクタ
	CItemManager() = default;
	//コピーコンストラクタ
	CItemManager(const CItemManager & rhs);
	//デストラクタ
	~CItemManager() = default;
	//代入演算子
	CItemManager& operator=(const CItemManager & rhs);

	aqua::IGameObject m_GameObject;	//ゲームオブジェクト

};