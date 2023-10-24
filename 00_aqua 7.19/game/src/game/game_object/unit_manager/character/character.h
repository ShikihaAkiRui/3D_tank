#pragma once

#include"../../unit/unit.h"
#include"../unit_id.h"

//�L�����N�^�[�N���X
class ICharacter : public IUnit
{
public:
	//�R���X�g���N�^
	ICharacter(aqua::IGameObject* parent,const std::string& object_name);
	//�f�X�g���N�^
	virtual ~ICharacter() = default;

	//������
	//���f���̃p�X
	virtual void Initialize(const std::string& file_name)override;
	//�X�V
	virtual void Update(void)override;

	//���j�b�g�̃J�e�S���[���擾
	UNIT_CATEGORY GetUnitCategory(void);

protected:
	aqua::CVector3 m_Position;			//�ʒu	
	aqua::CVector3 m_GraundRayLength;	//���ւ̃��C����
	aqua::CVector3 m_Velocity;			//���x
	aqua::CVector3 m_Rotation;			//��]
	UNIT_CATEGORY m_UnitCategory;		//���j�b�g�̃J�e�S���[
	int m_Life;							//�̗�
	bool m_GraundFlag;					//���ɂ��Ă��邩


	//�ړ�
	virtual void Move(void);

	//�U������������
	virtual void HitAttack(void);

	//�|���ꂽ
	virtual void Dead(void);

	//�A�C�e������������
	virtual void HitItem(void);

	//�^�C���̉�]
	//��]���x
	virtual void WheelRotation(float rotation_speed);

	//���̔���
	void CheckGround(void);

	//�ǂ̔���
	void CheckWall(void);

	//�e�̔���
	bool CheckHitBullet(void);

	//�A�C�e���̔���
	bool CheckHitItem(void);

	static const int m_default_damage;							//�f�t�H���g�̃_���[�W��

private:

	float m_WheelAngle;			//�^�C���̊p�x

	static const aqua::CVector3 m_default_position;				//�f�t�H���g�̈ʒu
	static const aqua::CVector3 m_default_graund_ray_length;	//�f�t�H���g�̏��ւ̃��C�̒���
	static const aqua::CVector3 m_model_right_vector;			//�E�����̃x�N�g��
	static const aqua::CVector3 m_tank_wheel_position[];		//�^�C���̃��[�J�����W�z��
	static const int m_wheel_first_frame;						//��ڂ̃^�C���̃t���[���ԍ�
	static const int m_max_wheel;								//�^�C���̐�
};