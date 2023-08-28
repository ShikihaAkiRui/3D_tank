#pragma once

#include"aqua.h"
#include"../unit_manager/unit_id.h"

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
	//�o�����@�P
	void FirstAppear(void);
	//�o�����@�Q
	void SecondAppear(void);

	//�o���̏��
	enum class APPEAR_STATE
	{
		FIRST,
		SECOND
	};

	aqua::CTimer m_AppearTimer;		//�o���̎���
	float m_AppearTime;				//���݂̏o������
	int m_CountEnemy;				//�G�l�~�[�̏o�Ă��鐔
	int m_TotalCountEnemy;			//�S�̂̃G�l�~�[�o����
	APPEAR_STATE m_AppearState;		//�o�����
	UNIT_ID m_UnitID;				//�����������j�b�g��ID
	bool m_FirstAppearFlag;			//�ŏ��̏o���t���O


	static const float m_max_ray_height;	//���C�̍ő卂��
	static const float m_min_ray_height;	//���C�̍ŏ�����
	static const float m_appear_height;		//�o������
	static const int m_max_enemy;			//�G�l�~�[�̍ő吔
	static const aqua::CVector2 m_min_appear_area;	//�ŏ��o���͈�
	static const aqua::CVector2 m_max_appear_area;	//�ő�o���͈�
	static const float m_first_appear_time;			//�ŏ��̏o������
	static const float m_default_appear_time;		//�����̏o������
	static const float m_max_appear_time;			//�ő��̏o������
	static const float m_acceleration;				//������
	static const int m_second_change_count;			//�o�����@��؂�ւ���^�C�~���O
};