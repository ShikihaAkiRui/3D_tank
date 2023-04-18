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

const unsigned int aqua::core::CModelResource::m_transparent_color = 0xffff00ff;

/*
	�R���X�g���N�^
*/
aqua::core::
CModelResource::
CModelResource(void)
	:IResourceObject(aqua::core::RESOURCE_TYPE::LOAD_MODEL)
	,m_Width(0)
	,m_Height(0)
	,m_Depth(0)
{
}

/*
	�e�N�X�`���ǂݍ���
*/
void
aqua::core::CModelResource::
Load(const std::string& file_name)
{
	if (m_Enabel) return;

	// ���ߐF�w��
	SetTransColor((m_transparent_color >> 16) & 0xff, (m_transparent_color >> 8) & 0xff, m_transparent_color & 0xff);

	//�e�N�X�`���ǂݍ���
	m_ResourceHandle = MV1LoadModel(file_name.c_str());

	AQUA_DX_ASSERT(m_ResourceHandle, file_name + "�̓ǂݍ��݂Ɏ��s���܂����B");

	// �O���t�B�b�N�T�C�Y�擾
	

	// �t�@�C���p�X��ۑ�
	m_ResourceName = file_name;

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
}

/*
	���f������
*/
void
aqua::core::CModelResource::
Create(int width, int height, int depth, bool alpha_channel)
{

}

/*
	���f�����
*/
void
aqua::core::CModelResource::
Delete(void)
{
}
