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

	GAME_STATE m_GameState;					//ゲームの状態

	static const std::string m_object_name;	//オブジェクトの名前

	aqua::CCamera m_Camera;					//カメラ

	aqua::CLabel m_Label;	//デバック用
};