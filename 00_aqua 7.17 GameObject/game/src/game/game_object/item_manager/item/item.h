#pragma once

#include"aqua.h"

//�A�C�e��
class CItem : public aqua::IGameObject
{
public:
	//�R���X�g���N�^
	CItem(aqua::IGameObject* parent);
	//�f�X�g���N�^
	~CItem() = default;

	//������
	//�ʒu
	void Initialize(const aqua::CVector3& position);
	//�X�V
	void Update(void)override;
	//�`��
	void Draw(void)override;
	//���
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
	
	static const std::string m_item_file_names[];	//�A�C�e���̃t�@�C����
	static const int m_max_file;				//�t�@�C����
	static const aqua::CVector3 m_graund_ray;	//���̔���̃��C�̑傫��
	static const float m_radius;				//���a
};