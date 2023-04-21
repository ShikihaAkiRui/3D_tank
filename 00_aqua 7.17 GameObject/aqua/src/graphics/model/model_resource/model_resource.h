/*!
    @file   model_resource.h
    @brief  ���f�����\�[�X
 */

#pragma once

#include"../../../resources/resources.h"

/*
    aqua���O���
*/
namespace aqua
{
    /*
        aqua::core���O���
    */
    namespace core
    {
        /*
            @class  CModelResource

            @brief  ���f�����\�[�X�N���X
        */
        class CModelResource : public IResourceObject
        {
            /*
                @brief  �R���X�g���N�^
            */
            CModelResource(void);

            /*
                @brief  �f�X�g���N�^
            */
            ~CModelResource(void) = default;

            /*
                @brief  ���f���̓ǂݍ���

                @param[in]  file_name    �t�@�C����
            */
            void   Load(const std::string& file_name);

            /*
                @brief  ���f��������ꍇ�̓ǂݍ���

                @param[in]  model  ���f�����\�[�X�N���X
            */
            void    Duplicate(const CModelResource* model);

            /*
                @brief  ���f���̉��
            */
            void    Unload(void);         


        private:
            /*
                brief   �N���X���t�����h�o�^
            */
            friend class CModel;
            friend class CModelManager;


        };
    }
}
