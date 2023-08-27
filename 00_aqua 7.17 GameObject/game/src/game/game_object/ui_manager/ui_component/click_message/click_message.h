#pragma once

#include"../ui_component.h"

//クリックメッセージフラグ
class CClickMessage : public IUIComponent
{
public:
	CClickMessage(aqua::IGameObject* parent);
	~CClickMessage() = default;

	void Initialize(const aqua::CVector2& position, const std::string word);
	void Update(void)override;
	void Draw(void)override;
	void Finalize(void)override;

private:
	aqua::CLabel m_Label;   //メッセージ
	float m_AlphaAngle;			//アルファ値アングル

	static const float m_label_angle_speed;	//アルファ値の速度
	static const float m_max_alpha;			//アルファ値最大
	static const int m_size;				//大きさ

};