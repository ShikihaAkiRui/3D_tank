/*
	@file       animation_model.h
    @brief      �A�j���[�V�������f��
 */

#pragma once

#include<DxLib.h>
#include"../model/model.h"

 /*
	 aqua���O���
 */
namespace aqua
{
	/*
	   @class      CAnimationModel

	   @brief      �A�j���[�V�������f���N���X
	*/
	class CAnimationModel
	{
	public:
		/*
			�R���X�g���N�^
		*/
		CAnimationModel(void);

		/*
			�f�X�g���N�^
		*/
		~CAnimationModel(void) = default;

		/*
			@brief	�t���[���̍��W�ϊ��s���ݒ�

			@param[in]	model	���f���̃|�C���^
			@param[in]	frame_index	�t���[���ԍ�
			@param[in]	matrix	�t���[���ɐݒ肷��ϊ��s��
		*/
		static void SetFrameUserLocalMatrix(aqua::CModel* model, int frame_index, const aqua::CMatrix& matrix);
	};
}