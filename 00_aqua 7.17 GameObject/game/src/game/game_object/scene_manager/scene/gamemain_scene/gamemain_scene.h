#pragma once

#include"../scene.h"

//�Q�[�����C���V�[��
class CGameMainScene : public IScene
{
public:
	CGameMainScene(aqua::IGameObject* parent);
	~CGameMainScene() = default;

	void Initialize(void)override;
	void Update(void)override;
	void Draw(void)override;
	void Finalize(void)override;

private:

	//�Q�[���̏��
	enum class GAME_STATE
	{
		START,
		MAIN,
		END
	};

	aqua::CCamera m_Camera;					//�J����
	GAME_STATE m_GameState;					//�Q�[���̏��

	static const std::string m_object_name;	//�I�u�W�F�N�g�̖��O
	static const aqua::CVector2 m_radar_position;	//���[�_�[�ʒu
	static const aqua::CVector2 m_life_position;	//�̗͈ʒu
	static const aqua::CVector2 m_score_position;	//�X�R�A�ʒu


	aqua::CLabel m_Label;	//�f�o�b�N�p
};