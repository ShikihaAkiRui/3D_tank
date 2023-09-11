#pragma once

#include"../ui_component.h"

//�̗�
class CLife : public IUIComponent
{
public:
	//�R���X�g���N�^
	CLife(aqua::IGameObject* parent);
	//�f�X�g���N�^
	~CLife() = default;

	//������
	//�ʒu
	void Initialize(const aqua::CVector2& position);
	//�X�V
	void Update(void)override;
	//�`��
	void Draw(void)override;
	//���
	void Finalize(void)override;

	//�̗͂����炷
	//���炷��
	void Reduce(int life);

	//���݂̗̑͂��擾
	int GetLife(void);

private:
	aqua::CSprite* m_Sprites;	//�摜
	int m_Life;					//�̗͂��擾
	int m_ShowLife;				//�\������̗�
	aqua::CTimer m_DisappearTimer;//��������
	bool m_DisappearFlag;		//�����t���O

	static const int m_default_life;//�����̗�
	static const int m_min_life;	//�̗͍ŏ��l
	static const int m_life_width;	//���C�t�ЂƂ̕�
	static const float m_disappear_time;	//��������
	static const float m_max_alpha;	//�A���t�@�l�ő�
};
