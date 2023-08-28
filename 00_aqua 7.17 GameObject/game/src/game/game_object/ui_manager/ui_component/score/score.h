#pragma once

#include"../ui_component.h"

//�X�R�A
class CScore : public IUIComponent
{
public:
	CScore(aqua::IGameObject* parent);
	~CScore() = default;

	//������
	//�ʒu
	void Initialize(const aqua::CVector2& position)override;
	void Draw(void)override;
	void Finalize(void)override;

	//�X�R�A�����Z
	void Add(int score);

	//�X�R�A�擾
	int GetScore(void);

	//���l��ύX���邩��ݒ�
	void SetCountFlag(bool flag);

private:
	aqua::CSprite* m_Sprites;	//�摜
	int m_Score;				//�X�R�A
	bool m_CountFlag;			//���l�𑝉������邩�̃t���O

	static const int m_max_score;		//�ő�X�R�A
	static const int m_min_score;		//�ŏ��X�R�A
	static const int m_max_digit;		//�ő包��
	static const int m_digit_width;		//�ꌅ�̕�
	static const int m_digit_height;	//�ꌅ�̍���
	static const aqua::CVector2 m_scale;//�g�嗦
};