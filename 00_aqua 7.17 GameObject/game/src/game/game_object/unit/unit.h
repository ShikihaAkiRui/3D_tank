#pragma once

#include"aqua.h"

//���j�b�g�N���X
class IUnit : public ICollision ,public aqua::IGameObject
{
public:
	IUnit(aqua::IGameObject* parent, const std::string& object_name);
	virtual ~IUnit() = default;

	//������
	virtual void Initialize(void) = 0;
	virtual void Initialize(const std::string& file_name);

	//�X�V
	virtual void Update(void);

	//�`��
	virtual void Draw(void);

	//���
	virtual void Finalize(void);

	//���C���o���Ĕ���
	bool CollCheckRay(const aqua::CVector3& start_position,const aqua::CVector3& end_position);

	aqua::CModel* GetModel(void);

protected:
	aqua::CModel* m_Model;	//���f��
	
	static const int m_frame_index;			//�t���[���ԍ�
	static const aqua::CVector3 m_divnum;	//������
};