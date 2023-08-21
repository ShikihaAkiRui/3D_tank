#pragma once

#include"aqua.h"
#include"ui_component/ui_id.h"
#include"ui_component/aim/aim.h"
#include"ui_component/life/life.h"
#include"ui_component/score/score.h"

//UIマネージャー
class CUIManager
{
public:
	//インスタンスを取得
	static CUIManager& GetInstance(void);

	void Initialize(void);
	void Update(void);
	void Draw(void);
	void Finalize(void);

	//生成
	void Create(UI_ID id);
	void Create(UI_ID id, const aqua::CVector2& position);

	//照準UI取得
	CAim* GetAim(void);
	//体力UI取得
	CLife* GetLife(void);
	//スコアUI取得
	CScore* GetScore(void);

private:

	//コンストラクタ
	CUIManager() = default;
	//コピーコンストラクタ
	CUIManager(const CUIManager & rhs);
	//デストラクタ
	~CUIManager() = default;
	//代入演算子
	CUIManager& operator=(const CUIManager & rhs);

	aqua::IGameObject m_GameObject;	//ゲームオブジェクト

	static const std::string m_aim_name;	//照準の名前
	static const std::string m_life_name;	//体力の名前
	static const std::string m_score_name;	//スコアの名前
};