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
		//�V�������f���𐶐�
		CModelResource* model = AQUA_NEW CModelResource();

		//���f���𕡐�
	//	model->Duplicate();

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
UnLoad(CModelResource* model)
{
	if (!model)return;

	if (m_ModelList.empty())return;

	//�Q�ƃ|�C���^���Z
	//�Q�Ƃ��Ȃ��Ȃ�������
	if (model->RemoveReference() > 0) return;

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



	return NULL;
}

void aqua::core::CModelManager::Clear(void)
{
}

aqua::core::CModelManager::CModelManager(void)
{
}

aqua::core::CModelManager::CModelManager(const CModelManager& rhs)
{
}

aqua::core::CModelManager& aqua::core::CModelManager::operator=(const CModelManager& rhs)
{
	// TODO: return �X�e�[�g�����g�������ɑ}�����܂�
}
