#pragma once

#include"../../unit/unit.h"

//�A�C�e��
class CItem : public IUnit
{
public:
	CItem(aqua::IGameObject* parent);
	~CItem() = default;

	void Initialize(void)override {};
	void Initialize(const aqua::CVector3& position);

	void Update(void)override;

	//���S�ʒu�擾
	aqua::CVector3 GetCenterPosition(void);

	//���a�擾
	float GetRadius(void);

private:
	//�d��
	void Gravity(void);

	aqua::CVector3 m_Position;	//�ʒu
	
	static const aqua::CVector3 m_graund_ray;	//���̔���̃��C�̑傫��
	static const float m_radius;				//���a
};