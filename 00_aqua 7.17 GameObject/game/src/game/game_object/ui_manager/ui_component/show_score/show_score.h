#pragma once

#include"../ui_component.h"

//�\���p�X�R�A
class CShowScore : public IUIComponent
{
public:
	CShowScore(aqua::IGameObject* parent);
	~CShowScore() = default;

	//������
	//�ʒu,	�X�R�A,	�g�嗦,	�F
	void Initialize(const aqua::CVector2& position, int score, float scale, aqua::CColor color);
	void Draw(void)override;
	void Finalize(void)override;

private:
	aqua::CSprite* m_Sprites;	//�X�v���C�g
	int m_Score;				//�\������X�R�A
	aqua::CVector2 m_Scale;		//�g�嗦
	aqua::CColor m_Color;		//�F
	int m_ShowDigit;			//�\������

	static const int m_min_score;	//�ŏ��X�R�A
	static const int m_max_score;	//�ő�X�R�A
	static const int m_max_digit;	//�ő包��
	static const int m_digit_width;	//�ꌅ�̕�
	static const int m_digit_height;//�ꌅ�̍���

};