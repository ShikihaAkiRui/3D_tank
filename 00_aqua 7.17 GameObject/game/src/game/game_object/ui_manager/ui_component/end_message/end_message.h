#pragma once

#include"../ui_component.h"

//�I�����b�Z�[�W
class CEndMessage : public IUIComponent
{
public:
	CEndMessage(aqua::IGameObject* parent);
	~CEndMessage() = default;

	void Initialize(void)override;
	void Update(void)override;
	void Draw(void)override;
	void Finalize(void)override;

	//�o���Ă��邩���擾
	bool GetAppearFlag(void);

private:
	//�X�^�[�g���b�Z�[�W�̏��
	enum class STATE
	{
		START_IN,
		WAIT,
	};

	aqua::CSprite m_Sprite;			//�X�v���C�g
	aqua::CTimer  m_DisplayTimer;	//��Ԃ̕ύX����
	STATE m_State;					//�I�����b�Z�[�W�̏��
	bool m_AppearFlag;				//�o���Ă��邩�̃t���O

	static const float m_display_time;	//��Ԃ̕ύX����
	static const float m_position_height;	//�X�v���C�g����
	static const float m_max_scale;		//�ő�g�嗦
};
