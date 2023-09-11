#pragma once

#include"../ui_component.h"

//�I�����b�Z�[�W
class CEndMessage : public IUIComponent
{
public:
	//�R���X�g���N�^
	CEndMessage(aqua::IGameObject* parent);
	//�f�X�g���N�^
	~CEndMessage() = default;

	//������
	void Initialize(void)override;
	//�X�V
	void Update(void)override;
	//�`��
	void Draw(void)override;
	//���
	void Finalize(void)override;

	//�o���Ă��邩���擾
	bool GetAppearFlag(void);

private:
	//�X�^�[�g���b�Z�[�W�̏��
	enum class STATE
	{
		START_IN,	//������
		WAIT,		//�o���I���
	};

	aqua::CSprite m_Sprite;			//�X�v���C�g
	aqua::CTimer  m_DisplayTimer;	//��Ԃ̕ύX����
	STATE m_State;					//�I�����b�Z�[�W�̏��
	bool m_AppearFlag;				//�o���Ă��邩�̃t���O
	
	static const float m_display_time;		//��Ԃ̕ύX����
	static const float m_position_height;	//�X�v���C�g����
	static const aqua::CVector2 m_default_scale;//�����̊g�嗦
	static const aqua::CVector2 m_max_scale;	//�ő�g�嗦
};
