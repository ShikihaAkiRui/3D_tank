#pragma once

#include"aqua.h"

//ステージクラス
class CStage : public aqua::IGameObject
{
public:
	CStage(aqua::IGameObject* parent);
	~CStage() = default;

	void Initialize(void)override;
	void Update(void)override;
	void Draw(void)override;
	void Finalize(void)override;

private:

	aqua::CSprite m_BackSprite;		//背景

	static const std::string m_object_name;		//オブジェクトの名前
};