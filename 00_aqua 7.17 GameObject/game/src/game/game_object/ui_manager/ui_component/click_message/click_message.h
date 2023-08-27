#pragma once

#include"../ui_component.h"

//�N���b�N���b�Z�[�W�t���O
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
	aqua::CLabel m_Label;   //���b�Z�[�W
	float m_AlphaAngle;			//�A���t�@�l�A���O��

	static const float m_label_angle_speed;	//�A���t�@�l�̑��x
	static const float m_max_alpha;			//�A���t�@�l�ő�
	static const int m_size;				//�傫��

};