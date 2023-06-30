#pragma once

#include"../ui_component.h"

//�Ə�
class CAim : public IUIComponent
{
public:
	CAim(aqua::IGameObject* parent);
	~CAim() = default;

	void Initialize(void)override;
	void Update(void)override;
	void Draw(void)override;
	void Finalize(void)override;

	//�_���Ă���������擾
	aqua::CVector3 GetAimAngle(void);

private:
	//�J��������̃��C�̌v�Z
	void SetAimRay(void);

	//�ʏ펞�̒e�̊p�x
	void GetNormalBulletAngle(void);
	//���C�ɓ����������̒e�̊p�x
	void GetRayHitBulletAngle(void);

	aqua::CSprite m_Sprite;		//�Ə�
	aqua::CVector2 m_Position;	//�ʒu
	aqua::CVector3 m_DirectionAngle;	//�e���o������
	aqua::CVector3 m_StartRayPosition;	//���C�̏o�n�߈ʒu
	aqua::CVector3 m_EndRayPosition;	//���C�̏I���ʒu

	static const float m_ray_length;	//���C�̒���

};