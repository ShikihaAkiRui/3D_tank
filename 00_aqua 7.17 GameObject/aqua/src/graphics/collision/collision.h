/*
	@file	collision.h

	@brief	�R���W����
*/

#pragma once
#include"../model/model.h"

/*
	@class ICollision
	
	@brief	�R���W�����N���X
*/
class ICollision
{
public:
	/*
		@brief	�R���X�g���N�^
	*/
	ICollision(void);

	/*
		@brief	�f�X�g���N�^
	*/
	~ICollision(void) = default;

	/*
		@brief	�R���W���������\�z

		@param[in]	handle	�n���h�����
		@param[in]	frame_index	�R���W�����̏����\�z����t���[���̔ԍ�
		@param[in]	x_divnum	�R���W��������x�������̋�ԕ�����
		@param[in]	y_divnum	�R���W��������y�������̋�ԕ�����
		@param[in]	z_divnum	�R���W��������z�������̋�ԕ�����
	*/
	void SetupCollision(aqua::CModel* handle,int frame_index,int x_divnum,int y_divnum,int z_divnum);

	/*
		@brief	�R���W�������̌�n��

		@param[in]	handle	���f���̃n���h��
		@param[in]	frame_index	�R���W�����̏�����n�����s���t���[���ԍ�
	*/
	void TerminateCollision(aqua::CModel* handle, int frame_index);

	/*
		@brief	�R���W�������̍X�V

		@param[in]	handle	���f���̃n���h��
		@param[in]	frame_index	�R���W�����̏����X�V����t���[���̔ԍ�
	*/
	void RefreshCollision(aqua::CModel* handle, int frame_index);

	/*
		@brief	�����ƃ��f���̓����蔻��

		@param[in]	handle	���f���̃n���h��
		@param[in]	frame_index	�R���W�����̏����X�V����t���[���̔ԍ�
		@param[in]	pos_start	�����蔻��Ŏg�p��������̎n�_
		@param[in]	pos_end		�����蔻��Ŏg�p��������̏I�_

		@return �����蔻�茋�ʍ\����
	*/
	MV1_COLL_RESULT_POLY CollCheckLine(aqua::CModel* handle, int frame_index, VECTOR pos_start, VECTOR pos_end);
	
	/*
		@brief �ʂƃ��f���̓����蔻��

		@param[in]	handle	���f���n���h��
		@param[in]	frame_index	�R���W�����̏����X�V����t���[���̔ԍ�
		@param[in]	center_pos	�����蔻��Ɏg�p���鋅�̒��S���W
		@param[in]	radius	�����蔻��Ŏg�p���鋅�̔��a
		
		@return	�����蔻�茋�ʃ|���S���z��\����
	*/
	MV1_COLL_RESULT_POLY_DIM CollCheckSphere(aqua::CModel* handle, int frame_index, VECTOR center_pos, float radius);
};