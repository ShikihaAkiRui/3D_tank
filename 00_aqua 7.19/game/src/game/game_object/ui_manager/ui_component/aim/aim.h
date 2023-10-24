#pragma once

#include"../ui_component.h"

//�Ə�
class CAim : public IUIComponent
{
public:
	//�R���X�g���N�^
	CAim(aqua::IGameObject* parent);
	//�f�X�g���N�^
	~CAim() = default;

	//������
	void Initialize(void)override;
	//�X�V
	void Update(void)override;
	//�`��
	void Draw(void)override;
	//���
	void Finalize(void)override;

	//�_���Ă���������擾
	aqua::CVector3 GetAimAngle(void);

private:
	//�J��������̃��C�̌v�Z
	void SetAimRay(void);

	//���C�����������ʒu���擾
	aqua::CVector3 CheckHitRay(void);

	//�e���΂��p�x
	//��΂��ʒu
	void GetBulletAngle(const aqua::CVector3& position);

	//�ː���̂Ƃ��F��ς���
	void ChangeColor(void);


	aqua::CSprite m_Sprite;		//�Ə�
	aqua::CVector2 m_Position;	//�ʒu
	aqua::CVector3 m_DirectionAngle;	//�e���o������
	aqua::CVector3 m_StartRayPosition;	//���C�̏o�n�߈ʒu
	aqua::CVector3 m_EndRayPosition;	//���C�̏I���ʒu
	bool m_HitEnemyFlag;				//���C���G�Ɠ����������̃t���O

	static const aqua::CVector2 m_aim_position;		//�ʒu
	static const aqua::CColor m_aim_default_color;	//�f�t�H���g�̐F
	static const aqua::CColor m_aim_target_color;	//�_���Ă���̐F
	static const float m_ray_length;				//���C�̒���
	static const std::string m_hit_object_name;		//�����蔻�������I�u�W�F�N�g�̖��O
	static const int m_frame_index;					//�t���[���̔ԍ�
};