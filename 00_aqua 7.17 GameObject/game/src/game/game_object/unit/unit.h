#pragma once

#include"aqua.h"

//���j�b�g�N���X
class IUnit : public ICollision ,public aqua::IGameObject
{
public:
	IUnit(aqua::IGameObject* parent,const std::string& object_name);
	virtual ~IUnit() = default;

	//������
	virtual void Initialize(const std::string& file_name);

	//�X�V
	virtual void Update(void);

	//�`��
	virtual void Draw(void);

	//���
	virtual void Finalize(void);

protected:
	aqua::CModel* m_Model;	//���f��
};