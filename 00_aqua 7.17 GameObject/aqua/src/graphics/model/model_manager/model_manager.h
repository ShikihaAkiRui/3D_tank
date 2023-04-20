/*
	@file	model_manager.h
	@brief	���f���Ǘ��N���X
*/

#pragma once

#include<list>
#include<string>

/*
	@brief	aqua���O���
*/
namespace aqua
{
	/*
		@brief	aqua::core���O���
	*/
	namespace core
	{
		class CModelResource;

		/*
			@class	CModelManager

			@brief	���f���Ǘ��N���X
		*/
		class CModelManager
		{
		public:
			/*
				@brief	�C���X�^���X�̎擾

				@return	�C���X�^���X�ւ̎Q��
			*/
			static CModelManager& GetInstance(void);

			/*
				@brief	���f���̓ǂݍ���

				@param[in]	file_name

				@return	���f�����\�[�X�N���X
			*/
			CModelResource* Load(const std::string& file_name);

			/*
				@brief	���f���̉��

				@param[in]	model	���f�����\�[�X�N���X
			*/
			void	UnLoad(CModelResource* model);

			/*
				@brief	���f���̌���

				@param[in]	file_name	�t�@�C����

				@return	���f�����\�[�X�N���X
			*/
			CModelResource* Find(const std::string& file_name);

			/*
				@brief	���f���N���A
			*/
			void Clear(void);

		private:

			/*
				@brief �R���X�g���N�^
			*/
			CModelManager(void);

			/*
				@brief	�R�s�[�R���X�g���N�^

				@param[in] rhs	�R�s�[�I�u�W�F�N�g
			*/
			CModelManager(const CModelManager& rhs);

			/*
				@brief �f�X�g���N�^
			*/
			~CModelManager(void) = default;

			/*
				@brief	������Z�q

				@param[in]	rhs ����I�u�W�F�N�g

				@return		���g�̃I�u�W�F�N�g
			*/
			CModelManager& operator=(const CModelManager& rhs);

			/*
				@brief	���f�����\�[�X���X�g
			*/
			typedef std::list<CModelResource*> MODEL_LIST;

			//!���f�����\�[�X���X�g
			MODEL_LIST	m_ModelList;
		};
	}

}