#pragma once

#include"../../unit/unit.h"
#include"../../unit_manager/unit_id.h"

//�e�N���X
class CBullet : public IUnit
{
public:
	CBullet(aqua::IGameObject* parent);
	~CBullet() = default;

	void Initialize(void)override {};
	void Initialize(UNIT_CATEGORY unit_category, const aqua::CVector3& position, const aqua::CVector3& rotation);
	void Update(void)override;

	//���S�ʒu�擾
	aqua::CVector3 GetCenterPosition(void);
	//���a�擾
	float GetRadius(void);
	//�J�e�S���[�擾
	UNIT_CATEGORY GetCategory(void);

private:
	//�G�̓����蔻��
	void CheckCharacter(void);

	//���̓����蔻��
	void CheckGraund(void);
	
	aqua::CVector3 m_Position;		//�ʒu
	aqua::CVector3 m_Velocity;		//���x
	UNIT_CATEGORY  m_UnitCategory;	//�o�������j�b�g�̃J�e�S���[

	static const aqua::CVector3 m_direction;	//��������
	static const float m_move_speed;			//�ړ����x
	static const float m_radius;				//���a
};