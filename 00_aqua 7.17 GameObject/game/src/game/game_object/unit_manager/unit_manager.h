#pragma once

#include"../unit/unit.h"
#include"unit_id.h"
//#include<map>

//���j�b�g�}�l�[�W���[
class CUnitManager : public aqua::IGameObject
{
public:
	CUnitManager(aqua::IGameObject* parent);
	~CUnitManager() = default;

	//����
	IUnit* Create(UNIT_ID id);

	//�G����
	void CreateEnemy(UNIT_ID id, const aqua::CVector3& position);

	//���j�b�g�̓����蔻��
	bool CheckHitUnit(const std::string& object_name,const aqua::CVector3& start_position,const aqua::CVector3& end_position);

	//�Ə��ƓG�̔���
	aqua::CVector3 CheckHitAim(const aqua::CVector3& start_position, const aqua::CVector3& end_position);

	//�v���C���[�ƓG�̋����擾
	int GetEnemyData(aqua::CVector2* vectors,int max_enemy);

private:
	static const std::string m_enemy_name;	//������Ώۂ̖��O

};