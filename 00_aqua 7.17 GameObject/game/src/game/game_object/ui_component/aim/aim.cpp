#include "aim.h"
#include"../../control_camera/control_camera.h"
#include"../../unit_manager/unit_manager.h"
#include"../../unit_manager/player/player.h"

const aqua::CVector2 CAim::m_aim_position = aqua::CVector2(aqua::GetWindowWidth() / 2.0f, aqua::GetWindowHeight() / 2.0f);
const float CAim::m_ray_length = 500.0f;
const std::string CAim::m_hit_object_name = "Enemy";
const int CAim::m_frame_index = -1;

//�R���X�g���N�^
CAim::CAim(aqua::IGameObject* parent)
	:IUIComponent(parent,"Aim")
	,m_Position(aqua::CVector2::ZERO)
	,m_DirectionAngle(aqua::CVector3::ZERO)
	,m_StartRayPosition(aqua::CVector3::ZERO)
	,m_EndRayPosition(aqua::CVector3::ZERO)
{
}

//������
void CAim::Initialize(void)
{
	/*
	m_Sprite.Create("data/abe.png");
	m_Sprite.position.x = m_aim_position.x - m_Sprite.GetTextureWidth() / 2.0f;
	m_Sprite.position.y = m_aim_position.y - m_Sprite.GetTextureHeight() / 2.0f;
	*/
}

//�X�V
void CAim::Update(void)
{
	//�J��������̃��C�̈ʒu��ݒ�
	SetAimRay();

	//�e����������ݒ�
	GetBulletAngle(CheckHitRay());
}

//�`��
void CAim::Draw(void)
{
	//m_Sprite.Draw();
}

//���
void CAim::Finalize(void)
{
//	m_Sprite.Delete();
}

//�_���Ă���������擾
aqua::CVector3 CAim::GetAimAngle(void)
{
	return m_DirectionAngle;
}

//�J��������̃��C�̈ʒu
void CAim::SetAimRay(void)
{
	CControlCamera* camera = (CControlCamera*)aqua::FindGameObject("ControlCamera");
	if (!camera)return;

	m_StartRayPosition = camera->GetPosition();

	//�����Ă�������̃x�N�g���擾
	aqua::CVector3 vector = aqua::CVector3(0.0f, 0.0f, 1.0f);
	aqua::CMatrix matrix = aqua::CMatrix::Ident();

	matrix.RotX(aqua::DegToRad(camera->GetAngle().x));
	matrix.RotY(aqua::DegToRad(camera->GetAngle().y));
	vector.Transform(matrix);

	m_EndRayPosition = camera->GetPosition() + (vector * m_ray_length);

}

//���C�����������ʒu���擾
aqua::CVector3 CAim::CheckHitRay(void)
{
	CPlayer* player = (CPlayer*)aqua::FindGameObject("Player");
	if (!player)
		return m_EndRayPosition;

	CUnitManager* unit_manager = (CUnitManager*)aqua::FindGameObject("UnitManager");
	if (!unit_manager || unit_manager->GetChildList()->empty())
		return m_EndRayPosition;

	aqua::CVector3 hit_position = aqua::CVector3::ZERO;
	bool hit_flag = false;
	float more_near = 0.0f;

	auto it = unit_manager->GetChildList()->begin();

	while (it != unit_manager->GetChildList()->end())
	{
		IUnit* unit = (IUnit*)(*it);
		
		//�G�������画�肷��
		if (unit->GetGameObjectName().find(m_hit_object_name) != std::string::npos)
		{
			//����������ʒu�擾
			if (unit->CollCheckLine(m_frame_index, m_StartRayPosition, m_EndRayPosition))
			{
				//���߂ē�������
				if (!hit_flag)
				{
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

		++it;
	}

	//�������Ă����瓖�������ʒu��Ԃ�
	if (hit_flag)
	{
		return hit_position;
	}
	//������Ȃ������烌�C�̏I���̈ʒu��Ԃ�
	else
	{
		return m_EndRayPosition;
	}
}

//�e�����p�x
void CAim::GetBulletAngle(const aqua::CVector3& position)
{
	CPlayer* player = (CPlayer*)aqua::FindGameObject("Player");
	if (!player)return;

	aqua::CVector3 distance = position - player->GetModel()->position;
	m_DirectionAngle.y = aqua::RadToDeg(atan2(distance.x, distance.z));

	aqua::CVector3 floor = distance;
	floor.y = 0.0f;
	float x_angle = 0.0f;
	x_angle = acos(aqua::CVector3::Dot(floor.Normalize(), distance.Normalize()));

	x_angle *= distance.y < 0 ? 1.0f : -1.0f;
	m_DirectionAngle.x = aqua::RadToDeg(x_angle);

}
