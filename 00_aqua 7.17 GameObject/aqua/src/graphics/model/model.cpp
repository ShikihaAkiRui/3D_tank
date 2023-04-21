/*
	@file	model.cpp

	@brief	3D���f���N���X
*/

#include<windows.h>
#include"model.h"
#include"model_manager/model_manager.h"
#include"../../debug/debug.h"

/*
	�R���X�g���N�^
*/
aqua::CModel::
CModel(void)
	:m_ModelResource(nullptr)
	,position(aqua::CVector3::ZERO)
	,scale(aqua::CVector3::ONE)
	,rotation(aqua::CVector3::ZERO)
{
}

/*
	�R�s�[�R���X�g���N�^
*/
aqua::CModel::
CModel(const aqua::CModel& model)
{
	if (m_ModelResource)
		m_ModelResource->RemoveReference();

	m_ModelResource = model.m_ModelResource;

	//�Q�ƃJ�E���^���Z
	m_ModelResource->AddReference();
}

/*
	���f���ǂݍ���
*/
void 
aqua::CModel::
Load(const std::string& file_name)
{
	//���f�����\�[�X�ޔ�
	core::CModelResource* model = m_ModelResource;

	//���f���}�l�[�W���[���烂�f�����擾
	m_ModelResource = core::CModelManager::GetInstance().Load(file_name);

	if (model)
	{
		int count = model->RemoveReference();

		//�O�̃��f���̎Q�Ƃ��Ȃ��Ȃ�������
		if (count <= 0)
			core::CModelManager::GetInstance().UnLoad(model);
	}
}

/*
	���f���J��
*/
void
aqua::CModel::
Unload(void)
{
	//���f�����
	if (m_ModelResource)
		core::CModelManager::GetInstance().UnLoad(m_ModelResource);

	m_ModelResource = nullptr;
}

/*
	�`��
*/
void 
aqua::CModel::
Draw(void)
{
	//���f�����ǂݍ��܂�Ă��Ȃ���Ε`�悵�Ȃ�
	if (!m_ModelResource->IsEnable()) return;	

	//���f�����\�[�X�n���h�����擾
	int handle = m_ModelResource->GetResourceHandle();

	//�ʒu�ݒ�
	MV1SetPosition(handle,position);
	//�g�嗦�ݒ�
	MV1SetScale(handle, scale);
	//��]�l�ݒ�
	MV1SetRotationXYZ(handle,aqua::CVector3(aqua::DegToRad(rotation.x), aqua::DegToRad(rotation.y), aqua::DegToRad(rotation.z)));

	//�`��
	MV1DrawModel(handle);
}

/*
	������Z�q�̃I�[�o�[���[�h
*/
aqua::CModel&
aqua::CModel::
operator=(const aqua::CModel& model)
{
	//���f���������Ă�����Q�Ƃ����Z
	if (m_ModelResource)
		m_ModelResource->RemoveReference();

	m_ModelResource = model.m_ModelResource;

	//�Q�ƃJ�E���^�̉��Z
	m_ModelResource->AddReference();

	return *this;
}
