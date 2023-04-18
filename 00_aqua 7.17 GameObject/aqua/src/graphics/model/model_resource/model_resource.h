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
                @brief  ���f���̉��
            */
            void    Unload(void);

            /*
                @brief  ���f���̉����擾

                @return ���f���̉���
            */
            int    GetWidth(void) {return m_Width; }
           
            /*
                @brief  ���f���̏c���擾

                @return ���f���̏c��
            */
            int     GetHeight(void) { return m_Height; }

            /*
                @brief  ���f���̉��s�擾

                @return ���f���̉��s
            */
            int     GetDepth(void) { return m_Depth; }

        private:
            /*
                brief   �N���X���t�����h�o�^
            */
            friend class CModel;
            friend class CModelManager;

            /*
                @brief  ���f���̐���

                @param[in]  width       ����
                @param[in]  height      �c��
                @param[in]  depth       ���s
                @param[in]  alpha_channel   �A���t�@�`�����l��
            */
            void    Create(int width, int height, int depth, bool alpha_channel);

            /*
                @brief  ���f���̉��
            */
            void    Delete(void);

            //!���ߐF�i�}�[���^0xff00ff)
            static const unsigned int m_transparent_color;
            //!���f���̕�
            int m_Width;
            //!���f���̍���
            int m_Height;
            //!���f���̉��s
            int m_Depth;
        };
    }
}
