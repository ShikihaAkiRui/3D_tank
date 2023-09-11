#pragma once
#include"aqua.h"
#include"../../unit_manager/unit_id.h"

//�e�N���X
class IBullet : public aqua::IGameObject
{
public:
	//�R���X�g���N�^
	IBullet(aqua::IGameObject* parent,const std::string& object_name);
	//�f�X�g���N�^
	~IBullet() = default;

	//������
	//�t�@�C����
	virtual void Initialize(const std::string& file_name);
	//�X�V
	virtual void Update(void)override;
	//�`��
	virtual void Draw(void)override;
	//���
	virtual void Finalize(void)override;

	//�L�����N�^�[�ɓ�������
	virtual void HitCharacter(void);

	//���S�ʒu�擾
	aqua::CVector3 GetCenterPosition(void);
	//���a�擾
	float GetRadius(void);
	//�J�e�S���[�擾
	UNIT_CATEGORY GetCategory(void);

protected:
	aqua::CModel m_Model;			//���f��
	aqua::CVector3 m_Position;		//�ʒu
	aqua::CVector3 m_Velocity;		//���x
	float m_Radius;					//���a
	UNIT_CATEGORY  m_UnitCategory;	//�o�������j�b�g�̃J�e�S���[

private:
	//���̓����蔻��
	void CheckGraund(void);

	//�\���͈͂̔���
	void CheckRange(void);

	static const aqua::CVector3 m_default_direction;//��������
	static const aqua::CVector3 m_min_range;		//�ŏ��͈�
	static const aqua::CVector3 m_max_range;		//�ő�͈�

};