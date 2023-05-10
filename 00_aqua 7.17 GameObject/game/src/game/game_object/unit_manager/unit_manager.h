#pragma once

#include"../unit/unit.h"
#include"unit_id.h"

//���j�b�g�}�l�[�W���[
class CUnitManager : public aqua::IGameObject
{
public:
	CUnitManager(aqua::IGameObject* parent);
	~CUnitManager() = default;

	//����
	void Create(UNIT_ID id);

	//���j�b�g�̓����蔻��
	bool HitUnitFlag(const std::string& object_name,aqua::CVector3 start_position,aqua::CVector3 end_position);

};