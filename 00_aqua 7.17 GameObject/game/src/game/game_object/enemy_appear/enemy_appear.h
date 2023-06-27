#pragma once

#include"aqua.h"

//�G�l�~�[�̏o���Ǘ��N���X
class CEnemyAppear : public aqua::IGameObject
{
public:
	CEnemyAppear(aqua::IGameObject* parent);
	~CEnemyAppear() = default;

	void Initialize(void)override;
	void Update(void)override;

private:
	aqua::CTimer m_AppearTimer;		//�o���̎���

	static const float m_max_ray_height;	//���C�̍ő卂��
	static const float m_min_ray_height;	//���C�̍ŏ�����
	static const float m_appear_time;		//�o���Ԋu
};