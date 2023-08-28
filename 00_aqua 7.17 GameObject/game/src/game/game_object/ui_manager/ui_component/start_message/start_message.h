#pragma once

#include"../ui_component.h"

//�J�n���b�Z�[�W
class CStartMessage : public IUIComponent
{
public:
	CStartMessage(aqua::IGameObject* parent);
	~CStartMessage() = default;

	void Initialize(void)override;
	void Update(void)override;
	void Draw(void)override;
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
	static const float m_max_scale;				//�ő�g�嗦
};