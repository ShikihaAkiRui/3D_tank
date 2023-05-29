#pragma once

#include"../../unit/unit.h"

//�L�����N�^�[�N���X
class ICharacter : public IUnit
{
public:
	ICharacter(aqua::IGameObject* parent,const std::string& object_name);
	virtual ~ICharacter() = default;

	virtual void Initialize(const std::string& file_name)override;

	virtual void Update(void)override;

protected:
	aqua::CVector3 m_Position;			//�ʒu	
	aqua::CVector3 m_GraundRayLength;	//���ւ̃��C����
	aqua::CVector3 m_Velocity;			//���x
	aqua::CVector3 m_Rotation;			//��]

	//�ړ�
	virtual void Move(void);

private:
	//���̔���
	void CheckGround(void);


	static const aqua::CVector3 m_default_position;				//�f�t�H���g�̈ʒu
	static const aqua::CVector3 m_default_graund_ray_length;	//�f�t�H���g�̏��ւ̃��C�̒���
	static const aqua::CVector3 m_model_right_vector;			//�E�����̃x�N�g��
};