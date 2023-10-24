#pragma once

#include"aqua.h"
#include"../unit/unit.h"
#include"unit_id.h"
#include"player/player.h"


//���j�b�g�}�l�[�W���[
class CUnitManager
{
public:
	//�C���X�^���X���擾
	static CUnitManager& GetInstance(void);

	//������
	void Initialzie(void);
	//�X�V
	void Update(void);
	//�`��
	void Draw(void);
	//���
	void Finalize(void);

	//����
	//���j�b�gID
	IUnit* Create(UNIT_ID id);

	//�G����
	//���j�b�g,	�ʒu
	void CreateEnemy(UNIT_ID id, const aqua::CVector3& position);

	//���j�b�g�̓����蔻��
	//�I�u�W�F�N�g�̖��O,	���̏��߂̈ʒu,	���̏I���̈ʒu
	bool CheckHitUnit(const std::string& object_name, const aqua::CVector3& start_position, const aqua::CVector3& end_position);

	//�Ə��ƓG�̔���
	//���̏��߂̈ʒu,	���̏I���̈ʒu
	aqua::CVector3 CheckHitAim(const aqua::CVector3& start_position, const aqua::CVector3& end_position);

	//�v���C���[�ƓG�̋����擾
	//�����擾����z��,	�G�̍ő�o����
	int GetEnemyData(aqua::CVector2* vectors, int max_enemy);

	//�S���j�b�g�̏�ԕύX
	//�ύX������
	void SetGameState(aqua::GAME_OBJECT_STATE state);

	//�v���C���[���擾
	CPlayer* GetPlayer(void);

private:
	//�R���X�g���N�^
	CUnitManager() = default;
	//�R�s�[�R���X�g���N�^
	CUnitManager(const CUnitManager & rhs);
	//�f�X�g���N�^
	~CUnitManager() = default;
	//������Z�q
	CUnitManager& operator=(const CUnitManager & rhs);

	aqua::IGameObject m_GameObject;	//�Q�[���I�u�W�F�N�g

	aqua::CModel* m_LoadModel;		//���炩���ߓǂݍ��ރ��f��

	static const std::string m_enemy_name;	//������Ώۂ̖��O
	static const std::string m_player_name;	//�v���C���[�̖��O
	static const int m_load_model_count;	//�ǂݍ��ރ��f���̐�
};
