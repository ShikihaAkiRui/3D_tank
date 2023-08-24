#pragma once

#include"../scene.h"

//ゲームメインシーン
class CGameMainScene : public IScene
{
public:
	CGameMainScene(aqua::IGameObject* parent);
	~CGameMainScene() = default;

	void Initialize(void)override;
	void Update(void)override;
	void Draw(void)override;
	void Finalize(void)override;

private:

	//ゲームの状態
	enum class GAME_STATE
	{
		START,
		MAIN,
		END
	};

	aqua::CCamera m_Camera;					//カメラ
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