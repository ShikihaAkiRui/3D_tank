#pragma once

#include"../unit/unit.h"
#include"unit_id.h"
#include<map>

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

private:
	static const int m_frame_index;		//�t���[���ԍ�

};