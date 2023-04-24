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
	aqua::CModel m_Model;

	static const std::string m_object_name;	//オブジェクトの名前
	aqua::CLabel m_Label;	//デバック用
};