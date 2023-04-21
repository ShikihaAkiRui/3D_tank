/*
	@file	model_resource.cpp

	@brief	3D���f�����\�[�X
*/
#include<DxLib.h>
#include<ctime>
#include "model_resource.h"
#include"../../../debug/debug.h"
#include"../../../utility/memory/memory.h"
#include"../model_manager/model_manager.h"

/*
	�R���X�g���N�^
*/
aqua::core::
CModelResource::
CModelResource(void)
	:IResourceObject(aqua::core::RESOURCE_TYPE::LOAD_MODEL)
{
}

/*
	���f���ǂݍ���
*/
void
aqua::core::CModelResource::
Load(const std::string& file_name)
{
	if (m_Enabel) return;

	//���f���̓ǂݍ���
	m_ResourceHandle = MV1LoadModel(file_name.c_str());

	AQUA_DX_ASSERT(m_ResourceHandle, file_name + "�̓ǂݍ��݂Ɏ��s���܂����B");

	// �t�@�C���p�X��ۑ�
	m_ResourceName = file_name;

	// �ǂݍ��ݍς�
	m_Enabel = true;

}

/*
	���f��������ꍇ�̓ǂݍ���
*/
void 
aqua::core::CModelResource::
Duplicate(const aqua::core::CModelResource* model)
{
	if (m_Enabel) return;

	//���f���̕���
	m_ResourceHandle = MV1DuplicateModel(model->GetResourceHandle());

	AQUA_DX_ASSERT(m_ResourceHandle, model->GetResourceName() + "�̓ǂݍ��݂Ɏ��s���܂����B");

	// �t�@�C���p�X��ۑ�
	m_ResourceName = model->GetResourceName();
	
	//���O�̓����������
	m_ResourceName += std::to_string(model->m_ReferenceCount);

	// �ǂݍ��ݍς�
	m_Enabel = true;
}

/*
	���f�����
*/
void
aqua::core::CModelResource::
Unload(void)
{
	MV1DeleteModel(m_ResourceHandle);

	m_ResourceHandle = AQUA_UNUSED_HANDLE;

	m_ResourceName.clear();

	m_ReferenceCount = 0;

	m_ResourceType = RESOURCE_TYPE::DUMMY;

	m_Enabel = true;

}
