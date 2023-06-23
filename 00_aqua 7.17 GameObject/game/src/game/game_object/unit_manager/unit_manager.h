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

	//���j�b�g�̓����蔻��
	bool CheckHitUnit(const std::string& object_name,const aqua::CVector3& start_position,const aqua::CVector3& end_position);

	//�e�̓����蔻��
	bool CheckHitBullet(UNIT_CATEGORY unit_category,const aqua::CVector3& center_position, float radius);

	//�A�C�e���̓����蔻��
	bool CheckHitItem(const aqua::CVector3& center_position,float radius);

private:
	static const int m_frame_index;		//�t���[���ԍ�

};