#pragma once

#include"aqua.h"
#include"../unit/unit.h"

//���C�g����N���X
class CControlLight : public aqua::IGameObject
{
public:
	//�R���X�g���N�^
	CControlLight(aqua::IGameObject* parent);
	//�f�X�g���N�^
	~CControlLight() = default;

	//������
	//���C�g�̃|�C���^
	void Initialize(aqua::CLight* light);
	//�X�V
	void Update(void);

private:
	aqua::CLight* m_Light;	//���C�g�̃|�C���^

	static const aqua::CVector3 m_position;				//���C�g�̏ꏊ
	static const float m_range;							//���C�g�̗L���͈�
	static const float m_attenuation;					//��������
	static const float m_attenuation_proportion;		//��������(���)
	static const float m_attenuation_squaring;			//��������(���)
};