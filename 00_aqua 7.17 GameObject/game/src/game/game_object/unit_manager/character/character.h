#pragma once

#include"../../unit/unit.h"
#include"../unit_id.h"

//�L�����N�^�[�N���X
class ICharacter : public IUnit
{
public:
	ICharacter(aqua::IGameObject* parent,const std::string& object_name);
	virtual ~ICharacter() = default;

	virtual void Initialize(const std::string& file_name)override;

	virtual void Update(void)override;

	virtual void Draw(void) override;

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

private:
	//���̔���
	void CheckGround(void);

	//�e�̔���
	bool CheckHitBullet(void);

	//�A�C�e���̔���
	bool CheckHitItem(void);

	static const aqua::CVector3 m_default_position;				//�f�t�H���g�̈ʒu
	static const aqua::CVector3 m_default_graund_ray_length;	//�f�t�H���g�̏��ւ̃��C�̒���
	static const aqua::CVector3 m_model_right_vector;			//�E�����̃x�N�g��
	static const int m_default_damage;							//�f�t�H���g�̃_���[�W��
};