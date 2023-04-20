/*
	@file	model.h
	@brief	3D���f���N���X
*/

#pragma once

#include"model_resource/model_resource.h"

/*
	@brief	aqua���O���
*/
namespace aqua
{
	/*
		@class	CModel

		@brief	���f���N���X
	*/
	class CModel
	{
	public:
		/*
			@brief	�R���X�g���N�^
		*/
		CModel(void);

		/*
			@brief	�R�s�[�R���X�g���N�^

			@param[in]	texture	���f���N���X
		*/
		CModel(const CModel& model);

		/*
			@brief	�f�X�g���N�^
		*/
		~CModel(void) = default;

		/*
			@brief	���f���̓ǂݍ���

			@param[in]	file_name �t�@�C����
		*/
		void Load(const std::string& file_name);

		/*
			@brief	�e�N�X�`���̉��
		*/
		void Unload(void);

		/*
			@brief	���f���̃��\�[�X�n���h���擾

			@param[in]	���f���̃��\�[�X�n���h���擾
		*/
		int GetResourceHandle(void)const
		{
			if (!m_ModelResource) return AQUA_UNUSED_HANDLE;

			return m_ModelResource->GetResourceHandle();
		}

		/*
			@brief	���f���̓ǂݍ��݃`�F�b�N

			@retval	true	�ǂݍ��ݍς�
			@retval false	�ǂݍ��܂�Ă��Ȃ�
		*/
		bool	IsEnable(void)const
		{
			if (!m_ModelResource)return false;

			return m_ModelResource->IsEnable();
		}

		/*
			@brief	������Z�q�̃I�[�o�[���[�h

			@param[in]	model	���f���N���X
		*/
		CModel& operator=(const CModel& model);

	private:
		// ���f�����\�[�X�N���X
		core::CModelResource* m_ModelResource;

	};
	
}
