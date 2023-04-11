#pragma once

#include"aqua.h"

//�G�l�~�[�[�N���X
class IEnemy : public aqua::IGameObject
{
public:
	IEnemy(aqua::IGameObject* parent, const std::string& object_name);
	~IEnemy() = default;

	virtual void Initialize(std::string file_name);
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

};