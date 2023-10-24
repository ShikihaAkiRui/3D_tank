#pragma once

#include"../scene.h"

//�Q�[�����C���V�[��
class CGameMainScene : public IScene
{
public:
	//�R���X�g���N�^
	CGameMainScene(aqua::IGameObject* parent);
	//�f�X�g���N�^
	~CGameMainScene() = default;

	//������
	void Initialize(void)override;
	//�X�V
	void Update(void)override;
	//�`��
	void Draw(void)override;
	//���
	void Finalize(void)override;

private:
	//�Q�[���I������
	bool CheckGameFinish(void);
	
	//�Q�[���̏��
	enum class GAME_STATE
	{
		START,
		MAIN,
		END
	};

	aqua::CCamera m_Camera;					//�J����
	aqua::CLight m_Light;					//���C�g
	GAME_STATE m_GameState;					//�Q�[���̏��

	static const std::string m_object_name;	//�I�u�W�F�N�g�̖��O
	static const aqua::CVector2 m_radar_position;	//���[�_�[�ʒu
	static const aqua::CVector2 m_life_position;	//�̗͈ʒu
	static const aqua::CVector2 m_score_position;	//�X�R�A�ʒu
	static const aqua::CVector2 m_show_score_position;	//�\���X�R�A�̈ʒu
	static const float m_show_score_scale;				//�\���X�R�A�̊g�嗦
	static const aqua::CColor m_show_score_color;		//�\���X�R�A�̐F


	aqua::CLabel m_Label;	//�f�o�b�N�p
};