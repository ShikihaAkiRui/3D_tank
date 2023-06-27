#pragma once

#include"../ui_component.h"

//�X�R�A
class CScore : public IUIComponent
{
public:
	CScore(aqua::IGameObject* parent);
	~CScore() = default;

	void Initialize(const aqua::CVector2& position)override;

	void Draw(void)override;
	void Finalize(void)override;

	//�X�R�A�����Z
	void Add(int score);

private:
	aqua::CSprite* m_Sprites;	//�摜
	int m_Score;				//�X�R�A

	static const int m_max_score;		//�ő�X�R�A
	static const int m_min_score;		//�ŏ��X�R�A
	static const int m_max_dight;		//�ő包��
	static const int m_digit_width;		//�ꌅ�̕�
	static const int m_digit_height;	//�ꌅ�̍���
};