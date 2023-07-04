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

	//�G�l�~�[�̐���ݒ�
	void SetCountEnemy(int count);

	//�G�l�~�[�̍ő吔�擾
	int GetMaxCountEnemy(void);

private:
	aqua::CTimer m_AppearTimer;		//�o���̎���
	int m_CountEnemy;				//�G�l�~�[�̏o�Ă��鐔

	static const float m_max_ray_height;	//���C�̍ő卂��
	static const float m_min_ray_height;	//���C�̍ŏ�����
	static const float m_appear_time;		//�o���Ԋu
	static const float m_appear_height;		//�o������
	static const int m_max_enemy;			//�G�l�~�[�̍ő吔
};