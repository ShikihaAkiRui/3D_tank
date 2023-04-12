#pragma once

#include"aqua.h"

//�G�l�~�[�[�N���X
class IEnemy : public aqua::IGameObject
{
public:
	IEnemy(aqua::IGameObject* parent, const std::string& object_name);
	~IEnemy() = default;

	virtual void Initialize(const std::string& file_name,const aqua::CVector2& position,const aqua::CVector2 velocity,int& life);
	virtual void Update(void)override;
	virtual void Draw(void)override;
	virtual void Finalize(void)override;

protected:
	aqua::CVector2 m_Position;	//�ʒu
	aqua::CVector2 m_Velocity;	//���x
	int m_Life;					//�̗�

private:
	//���
	enum class STATE
	{
		WAIT,		//�ҋ@
		MOVE,		//�ړ�
		DEAD		//������
	};

	//�ړ�
	virtual void Move(void);

	//�_���[�W���󂯂�
	void Damage(void);

	//������
	void Dead(void);

	//�U��
	virtual void Attack(void);

	STATE m_State;					//���
	aqua::CSprite m_EnemySprite;	//�G�l�~�[�̃X�v���C�g
	aqua::CTimer m_DeleteTimer;		//�����܂ł̎���

	static const float m_delete_time;	//�����܂ł̎���

};