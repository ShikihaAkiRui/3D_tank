#include "unit_manager.h"
#include"../unit/unit.h"
#include"player/player.h"
#include"enemy/enemy.h"

const int CUnitManager::m_frame_index = -1;

CUnitManager::CUnitManager(aqua::IGameObject* parent)
	:aqua::IGameObject(parent,"UnitManager")
{
}

//����
void CUnitManager::Create(UNIT_ID id)
{
	aqua::IGameObject* unit = nullptr;

	switch (id)
	{
	case UNIT_ID::PLAYER:	unit = aqua::CreateGameObject<CPlayer>(this); break;
	case UNIT_ID::ENEMY:	unit = aqua::CreateGameObject<CEnemy>(this); break;
	default:	break;
	}

	if (!unit)return;

	unit->Initialize();

}

//���j�b�g�̓����蔻��
bool CUnitManager::CheckHitUnit(const std::string& object_name, aqua::CVector3 start_position, aqua::CVector3 end_position)
{
	if (m_ChildObjectList.empty())
		return false;

	auto it = m_ChildObjectList.begin();

	bool hit_flag = false;

	while (it != m_ChildObjectList.end())
	{
		IUnit* unit = (IUnit*)(*it);

		//�w�肵���I�u�W�F�N�g����������
		if (unit->GetGameObjectName().find(object_name) != std::string::npos)
		{
			hit_flag = unit->CollCheckRay(start_position,end_position);

			//������������true
			if (hit_flag)
				return hit_flag;
		}

		it++;
	}

	//�������ĂȂ��Ȃ�false
	return hit_flag;
}

//�G�l�~�[�ƒe�̓����蔻��
bool CUnitManager::EnemyCheckHitBullet(aqua::CVector3 center_position, float radius)
{
	if (m_ChildObjectList.empty())
		return false;

	auto it = m_ChildObjectList.begin();

	bool hit_flag = false;

	while (it != m_ChildObjectList.end())
	{
		IUnit* unit = (IUnit*)(*it);

		//�w�肵���I�u�W�F�N�g����������
		if (unit->GetGameObjectName().find("Enemy") != std::string::npos)
		{
			hit_flag = unit->CollCheckSphere(m_frame_index, center_position, radius);
			
			//������������true
			if (hit_flag)
				return hit_flag;
		}

		it++;
	}

	//�������ĂȂ��Ȃ�false
	return hit_flag;
}