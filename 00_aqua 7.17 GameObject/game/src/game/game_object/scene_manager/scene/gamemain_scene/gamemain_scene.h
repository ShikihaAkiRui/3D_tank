#pragma once

#include"../scene.h"

//ゲームメインシーン
class CGameMainScene : public IScene
{
public:
	//コンストラクタ
	CGameMainScene(aqua::IGameObject* parent);
	//デストラクタ
	~CGameMainScene() = default;

	//初期化
	void Initialize(void)override;
	//更新
	void Update(void)override;
	//描画
	void Draw(void)override;
	//解放
	void Finalize(void)override;

private:
	//ゲーム終了判定
	bool CheckGameFinish(void);
	
	//ゲームの状態
	enum class GAME_STATE
	{
		START,
		MAIN,
		END
	};

	aqua::CCamera m_Camera;					//カメラ
	aqua::CLight m_Light;					//ライト
	GAME_STATE m_GameState;					//ゲームの状態

	static const std::string m_object_name;	//オブジェクトの名前
	static const aqua::CVector2 m_radar_position;	//レーダー位置
	static const aqua::CVector2 m_life_position;	//体力位置
	static const aqua::CVector2 m_score_position;	//スコア位置
	static const aqua::CVector2 m_show_score_position;	//表示スコアの位置
	static const float m_show_score_scale;				//表示スコアの拡大率
	static const aqua::CColor m_show_score_color;		//表示スコアの色


	aqua::CLabel m_Label;	//デバック用
};