#pragma once

#include"../ui_component.h"

//���[�_�[
class CRadar : public IUIComponent
{
public:
	CRadar(aqua::IGameObject* parent);
	~CRadar() = default;

	void Initialize(const aqua::CVector2& position)override;
	void Update(void)override;
	void Draw(void)override;
	void Finalize(void)override;

private:

	//�G�l�~�[�̃f�[�^�𓾂�
	void GetEnemyData(void);

	//�\���ʒu��ݒ�
	void SetEnemyPosition(void);

	aqua::CSprite m_AreaSprite;		//�摜
	aqua::CSprite m_PlayerSprite;	//�v���C���[�̉摜
	aqua::CSprite* m_EnemySprites;	//�G�̉摜
	int m_MaxEnemyCount;			//�G�l�~�[�̍ő吔
	int m_AppearEnemyCount;			//�o�Ă���G�̐�
	aqua::CVector2 m_CenterPosition;//���S�ʒu
	aqua::CVector2* m_EnemyVectors;	//�G�̃x�N�g���̔z��
	float m_ShowRadius;				//�o�����a

	static const std::string m_find_name;	//�����閼�O
	static const float m_scale_vector;		//�x�N�g�����k��
	static const aqua::CVector2 m_character_scale;	//�L�����N�^�[�̊g�嗦
};
