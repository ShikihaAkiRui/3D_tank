#pragma once

#include"../scene.h"

//タイトルシーン
class CTitleScene : public IScene
{
public:
	CTitleScene(aqua::IGameObject* parent);
	~CTitleScene() = default;

	void Initialize(void)override;
	void Update(void)override;
	void Draw(void)override;
	void Finalize(void)override;

private:
	static const std::string m_object_name;	//オブジェクトの名前
	aqua::CLabel m_Label;	//デバック用
};