#pragma once

#include"aqua.h"

//���j�b�g�N���X
class IUnit : public ICollision ,public aqua::IGameObject
{
public:
	//�R���X�g���N�^
	IUnit(aqua::IGameObject* parent, const std::string& object_name);
	//�f�X�g���N�^
	virtual ~IUnit() = default;

	//������
	virtual void Initialize(void) = 0;
	//���f���̃p�X
	virtual void Initialize(const std::string& file_name);
	//�X�V
	virtual void Update(void);
	//�`��
	virtual void Draw(void);
	//���
	virtual void Finalize(void);

	//���f���擾
	aqua::CModel* GetModel(void);

protected:
	aqua::CModel* m_Model;	//���f��
	
	static const aqua::CVector3 m_divnum;	//������
};