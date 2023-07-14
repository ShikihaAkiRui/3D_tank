#include "unit_manager.h"
#include"../unit/unit.h"
#include"player/player.h"
#include"enemy/enemy_normal/enemy_normal.h"

const std::string CUnitManager::m_enemy_name = "Enemy";

CUnitManager::CUnitManager(aqua::IGameObject* parent)
	:aqua::IGameObject(parent,"UnitManager")
{
}

//����
IUnit* CUnitManager::Create(UNIT_ID id)
{
	IUnit* unit = nullptr;

	switch (id)
	{
	case UNIT_ID::PLAYER:	unit = aqua::CreateGameObject<CPlayer>(this); break;
	default:	break;
	}

	if (!unit)return nullptr;

	unit->Initialize();

	return unit;
}

//�G����
void CUnitManager::CreateEnemy(UNIT_ID id, const aqua::CVector3& position)
{
	IEnemy* enemy = nullptr;

	switch (id)
	{
	case UNIT_ID::ENEMY_NORMAL:	enemy = aqua::CreateGameObject<CEnemyNormal>(this);	break;
	default:	break;
	}

	if (!enemy)return;

	enemy->Initialize(position);

}

//���j�b�g�̓����蔻��
bool CUnitManager::CheckHitUnit(const std::string& object_name,const aqua::CVector3& start_position,const aqua::CVector3& end_position)
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
			hit_flag = unit->CollCheckLine(start_position,end_position);

			//������������true
			if (hit_flag)
				return hit_flag;
		}

		it++;
	}

	//�������ĂȂ��Ȃ�false
	return hit_flag;
}

//�Ə��ƓG�̓����蔻��
aqua::CVector3 CUnitManager::CheckHitAim(const aqua::CVector3& start_position, const aqua::CVector3& end_position)
{
	bool hit_flag = false;
	aqua::CVector3 hit_position = end_position;
	float more_near = 0.0f;

	auto it = GetChildList()->begin();

	while (it != GetChildList()->end())
	{
		IUnit* unit = (IUnit*)(*it);

		//�G�������画�肷��
		if (unit->GetGameObjectName().find(m_enemy_name) != std::string::npos)
		{
			//���������ʒu���擾
			if (unit->CollCheckLine(start_position, end_position))
			{
				CPlayer* player = (CPlayer*)aqua::FindGameObject("Player");
				if (!player)return end_position;

				//���߂ē�������
				if (!hit_flag)
				{
					//���������ʒu��ۑ�
					hit_position = unit->GetCollCheckLineHitPosition();

					aqua::CVector3 vector = unit->GetCollCheckLineHitPosition() - player->GetModel()->position;
					more_near = vector.Length();

				}
				else
				{
					//�L�����N�^�[�ɋ߂��ʒu���擾
					aqua::CVector3 vector = unit->GetCollCheckLineHitPosition() - player->GetModel()->position;
					float length = vector.Length();

					//�ʒu���߂��ق��ɕύX
					if (more_near > length)
					{
						hit_position = unit->GetCollCheckLineHitPosition();
					}

				}

				hit_flag = true;

			}

		}

		it++;
	}

	return hit_position;
}

//�v���C���[�ƓG�̋����擾
int CUnitManager::GetEnemyData(aqua::CVector2* vectors, int max_enemy)
{
	CPlayer* player = (CPlayer*)aqua::FindGameObject("Player");
	if (!player)return 0;

	int appear_enemy_count = 0;

	auto it = GetChildList()->begin();

	while (it != GetChildList()->end())
	{
		IUnit* unit = (IUnit*)(*it);

		//�w�肵���I�u�W�F�N�g����������
		if (unit->GetGameObjectName().find(m_enemy_name) != std::string::npos)
		{
			//�v���C���[����̃x�N�g���擾
			vectors[appear_enemy_count].x = unit->GetModel()->position.x - player->GetModel()->position.x;
			vectors[appear_enemy_count].y = -(unit->GetModel()->position.z - player->GetModel()->position.z);

			//�o�����Ă��鐔�𑝂₷
			appear_enemy_count++;

			//�o���ő吔�𖞂������ꍇ
			if (appear_enemy_count >= max_enemy)
				break;
		}

		it++;
	}

	//�G�l�~�[����Ԃ�
	return appear_enemy_count;
}
