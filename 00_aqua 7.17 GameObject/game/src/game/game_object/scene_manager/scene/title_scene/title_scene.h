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
	static const aqua::CVector2 m_message_position;	//メッセージ位置
	static const std::string m_message;				//メッセージ文字
	static const std::string m_object_name;			//オブジェクトの名前
	aqua::CLabel m_Label;	//デバック用
};