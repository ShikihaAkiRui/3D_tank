#pragma once

#include"aqua.h"

//�A�C�e��
class CItem : public aqua::IGameObject
{
public:
	CItem(aqua::IGameObject* parent);
	~CItem() = default;

	void Initialize(const aqua::CVector3& position);
	void Update(void)override;
	void Draw(void)override;
	void Finalize(void)override;

	//�L�����N�^�[�ɓ�������
	void HitCharacter(void);

	//���S�ʒu�擾
	aqua::CVector3 GetCenterPosition(void);

	//���a�擾
	float GetRadius(void);

private:
	//�d��
	void Gravity(void);

	aqua::CModel m_Model;		//���f��
	aqua::CVector3 m_Position;	//�ʒu
	bool m_GraundFlag;			//�n�ʂɂ��Ă��邩
	
	static const aqua::CVector3 m_graund_ray;	//���̔���̃��C�̑傫��
	static const float m_radius;				//���a
};