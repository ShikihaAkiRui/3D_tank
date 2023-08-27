#pragma once

#include"../ui_component.h"

//�\���p�X�R�A�N���X
class CShowScore : public IUIComponent
{
public:
	CShowScore(aqua::IGameObject* parent);
	~CShowScore() = default;

	void Initialize(const aqua::CVector2 position,int score,float scale,unsigned char color);
	void Draw(void)override;
	void Finalize(void)override;

private:
	aqua::CSprite* m_Sprites;	//�摜
	int m_Score;				//�X�R�A
	int m_MaxDigit;				//�ő包��
	unsigned char m_Color;		//�F
	aqua::CVector2 m_Scale;		//�g�嗦

	static const int m_min_score;		//�ŏ��X�R�A
	static const int m_digit_width;		//�ꌅ�̕�
	static const int m_digit_height;	//�ꌅ�̍���
};