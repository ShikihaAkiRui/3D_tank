#pragma once

#include"aqua.h"
#include"../unit/unit.h"

//�J��������N���X
class CControlCamera : public aqua::IGameObject
{
public:
	CControlCamera(aqua::IGameObject* parent);
	~CControlCamera() = default;
	
	//������
	//�J����,	�J�������ǂ����j�b�g
	void Initialize(aqua::CCamera* camera,IUnit* unit);
	void Update(void)override;

	//�J�����̒����_�ʒu�擾
	aqua::CVector3 GetTargetPosition(void);
	//�����Ă���p�x���擾
	aqua::CVector3 GetAngle(void);
private:

	aqua::CCamera* m_Camera;	//�J�����̃|�C���^
	IUnit* m_Unit;				//�����_�̃��j�b�g�̃|�C���^
	aqua::CVector3 m_Angle;		//�J�����p�x


	static const aqua::CVector3 m_camera_length;		//�ΏۂƂ̋���
	static const aqua::CVector2 m_angle_variation;		//�p�x�̕ω���
	static const float m_max_y_angle;					//y���p�x�ő�l
	static const float m_min_y_angle;					//y���p�x�ŏ��l
	static const float m_max_x_angle;					//X���p�x�ő�l
	static const float m_min_x_angle;					//X���p�x�ŏ��l
	static const aqua::CVector3 m_target_position;		//�^�[�Q�b�g�̍���
};