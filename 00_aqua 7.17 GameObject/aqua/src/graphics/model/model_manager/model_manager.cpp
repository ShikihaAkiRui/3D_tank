/*
	@file model_manager.cpp
	@brief	3D���f���Ǘ��N���X
*/

#include "model_manager.h"
#include"../model_resource/model_resource.h"
#include"../../../debug/debug.h"
#include"../../../utility/memory/memory.h"

/*
	�C���X�^���X�̎擾
*/
aqua::core::CModelManager& 
aqua::core::CModelManager::
GetInstance(void)
{
	static CModelManager instance;

	return instance;
}

/*
	���f���N���X�̓ǂݍ���
*/
aqua::core::CModelResource* 
aqua::core::CModelManager::
Load(const std::string& file_name)
{
	//���f���̌���
	CModelResource* model = Find(file_name);

	//���f����������Ȃ�����
	if (!model)
	{
		//�V�������f���𐶐�
		model = AQUA_NEW CModelResource();

		//�ǂݍ���
		model->Load(file_name);

		//���f�����X�g�ɒǉ�
		m_ModelList.push_back(model);
	}
	//���f������������
	else
	{
		//�f�[�^��ޔ�
		CModelResource* src_model = model;
		//�Q�ƃ|�C���^�����Z
		src_model->AddReference();

		//�V�������f���𐶐�
		model = AQUA_NEW CModelResource();

		//���f���𕡐�
		model->Duplicate(src_model);

		//���f�����X�g�ɒǉ�
		m_ModelList.push_back(model);
	}

	//�Q�ƃ|�C���^���Z
	model->AddReference();

	return model;
}

/*
	���f���̉��
*/
void 
aqua::core::CModelManager::
UnLoad(aqua::core::CModelResource* model)
{
	if (!model)return;

	if (m_ModelList.empty())return;

	//�Q�ƃ|�C���^���Z
	//�Q�Ƃ��Ȃ��Ȃ�������
//	if (model->RemoveReference() > 0) return;

	MODEL_LIST::iterator it = m_ModelList.begin();
	MODEL_LIST::iterator end = m_ModelList.end();


	while (it != end)
	{
		if ((*it)->GetResourceName() == model->GetResourceName())
		{
			(*it)->Unload();

			AQUA_SAFE_DELETE((*it));

			m_ModelList.erase(it);

			break;
		}

		++it;
	}
}

/*
	���f���̌���
*/
aqua::core::CModelResource* 
aqua::core::CModelManager::
Find(const std::string& file_name)
{
	if (m_ModelList.empty())return NULL;

	MODEL_LIST::iterator it = m_ModelList.begin();
	MODEL_LIST::iterator end = m_ModelList.end();

	//�t�@�C��������v�����e�N�X�`���N���X��Ԃ�
	while (it != end)
	{
		if ((*it)->GetResourceName() == file_name)
			return (*it);

		++it;
	}

	return NULL;
}

/*
	���f�����X�g�̃N���A
*/
void
aqua::core::CModelManager::
Clear(void)
{
	if (m_ModelList.empty())return;

	MODEL_LIST::iterator it = m_ModelList.begin();
	MODEL_LIST::iterator end = m_ModelList.end();

	while (it != end)
	{
		if ((*it))
		{
			//���f���̉��
			(*it)->Unload();

			AQUA_SAFE_DELETE((*it));
		}

		++it;
	}

	//���f�����X�g���
	m_ModelList.clear();
}

/*
	�R���X�g���N�^
*/
aqua::core::CModelManager::
CModelManager(void)
{
	m_ModelList.clear();
}

/*
	�R�s�[�R���X�g���N�^
*/
aqua::core::CModelManager::
CModelManager(const aqua::core::CModelManager& rhs)
{
	(void)rhs;

}

/*
	������Z�q
*/
aqua::core::CModelManager& 
aqua::core::CModelManager::
operator=(const aqua::core::CModelManager& rhs)
{
	(void)rhs;

	return *this;
}
