#pragma once

#include"../ui_component.h"

//�J�n���b�Z�[�W
class CStartMessage : public IUIComponent
{
public:
	//�R���X�g���N�^
	CStartMessage(aqua::IGameObject* parent);
	//�f�X�g���N�^
	~CStartMessage() = default;

	//������
	void Initialize(void)override;
	//�X�V
	void Update(void)override;
	//�`��
	void Draw(void)override;
	//���
	void Finalize(void)override;

private:
	//���b�Z�[�W�̏��
	enum class STATE
	{
		START_IN,	//������
		WAIT,		//�o���I���
	};

	aqua::CSprite m_StartSprite;		//�J�n�̃X�v���C�g
	aqua::CTimer  m_StartDisplayTimer;	//��Ԃ̕ύX����
	STATE m_State;						//�J�n���b�Z�[�W�̏��

	static const float m_start_display_time;	//��Ԃ̕ύX����
	static const aqua::CVector2 m_default_scale;//�����̊g�嗦
	static const aqua::CVector2 m_max_scale;	//�ő�g�嗦
	static const float m_max_alpha;				//�A���t�@�l�ő�
	static const float m_min_alpha;				//�A���t�@�l�ŏ�
};