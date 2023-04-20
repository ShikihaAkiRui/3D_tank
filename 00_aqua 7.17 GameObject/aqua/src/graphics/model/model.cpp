/*
	@file	model.cpp

	@brief	3D���f���N���X
*/

#include<windows.h>
#include"model.h"
#include"model_manager/model_manager.h"

/*
	�R���X�g���N�^
*/
aqua::CModel::
CModel(void)
	:m_ModelResource(nullptr)
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
