#pragma once

#include"aqua.h"
#include"../unit/unit.h"
#include"unit_id.h"
#include"player/player.h"


//���j�b�g�}�l�[�W���[
class CUnitManager
{
public:
	static CUnitManager& GetInstance(void);

	void Initialzie(void);
	void Update(void);
	void Draw(void);
	void Finalize(void);

	//����
	IUnit* Create(UNIT_ID id);

	//�G����
	void CreateEnemy(UNIT_ID id, const aqua::CVector3& position);

	//���j�b�g�̓����蔻��
	bool CheckHitUnit(const std::string& object_name, const aqua::CVector3& start_position, const aqua::CVector3& end_position);

	//�Ə��ƓG�̔���
	aqua::CVector3 CheckHitAim(const aqua::CVector3& start_position, const aqua::CVector3& end_position);

	//�v���C���[�ƓG�̋����擾
	int GetEnemyData(aqua::CVector2* vectors, int max_enemy);

	//�S���j�b�g�̏�ԕύX
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

	static const std::string m_enemy_name;	//������Ώۂ̖��O
	static const std::string m_player_name;	//�v���C���[�̖��O
};
