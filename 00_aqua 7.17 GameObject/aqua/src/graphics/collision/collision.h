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

		@param[in]	model	���f�����
		@param[in]	frame_index	�R���W�����̏����\�z����t���[���̔ԍ�
		@param[in]	x_divnum	�R���W��������x�������̋�ԕ�����
		@param[in]	y_divnum	�R���W��������y�������̋�ԕ�����
		@param[in]	z_divnum	�R���W��������z�������̋�ԕ�����
	*/
	void	SetupCollInfo(aqua::CModel* model,int frame_index,int x_divnum,int y_divnum,int z_divnum);

	/*
		@brief	�R���W�������̌�n��

		@param[in]	frame_index	�R���W�����̏�����n�����s���t���[���ԍ�
	*/
	void	TerminateCollInfo(int frame_index);

	/*
		@brief	�R���W�������̍X�V

		@param[in]	frame_index	�R���W�����̏����X�V����t���[���̔ԍ�
	*/
	void	RefreshCollInfo(int frame_index);

	/*
		@brief	�����ƃ��f���̓����蔻��

		@param[in]	frame_index	�R���W�����̏����X�V����t���[���̔ԍ�
		@param[in]	pos_start	�����蔻��Ŏg�p��������̎n�_
		@param[in]	pos_end		�����蔻��Ŏg�p��������̏I�_

		@return ���������ǂ���
	*/
	bool	CollCheckLine(int frame_index, const aqua::CVector3& pos_start, const aqua::CVector3& pos_end);
	
	/*
		@brief �����ƃ��f���̓����������̃t���O

		@return ���������ǂ���
	*/
	bool	GetCollCheckLineHitFlag(void);

	/*
		@brief �����ƃ��f���̓��������ʒu

		@return ���������ʒu
	*/
	aqua::CVector3	GetCollCheckLineHitPosition(void);

	/*
		@brief	�����ƃ��f���̓��������|���S���̖@��

		@return ���������|���S���̖@��
	*/
	aqua::CVector3	GetCollCheckLineNormal(void);

	/*
		@brief �ʂƃ��f���̓����蔻��

		@param[in]	frame_index	�R���W�����̏����X�V����t���[���̔ԍ�
		@param[in]	center_pos	�����蔻��Ɏg�p���鋅�̒��S���W
		@param[in]	radius	�����蔻��Ŏg�p���鋅�̔��a
		
		@return	���������ǂ���
	*/
	bool	CollCheckSphere( int frame_index,const aqua::CVector3& center_pos, float radius);

	/*
		@brief	�J�v�Z���ƃ��f���̓����蔻��

		@param[in]	frame_index �R���W���������X�V����t���[���̔ԍ�
		@param[in]	pos1	�J�v�Z���𐶐�����2�_���̂P�_�̍��W
		@param[in]	pos2	�J�v�Z���𐶐�����2�_���̂P�_�̍��W
		@param[in]	radius	�J�v�Z���̔��a

		@return ���������ǂ���
	*/
	bool	CollCheckCapsule(int frame_index,const aqua::CVector3& pos1,const aqua::CVector3& pos2, float radius);

	/*
		@brief	�����蔻�茋�ʃ|���S���z�񂩂�w��Ԃ̃|���S�������擾

		@param[in]	result_poly_dim	�����蔻�茋�ʃ|���S���z��\����
		@param[in]	poly_no	�擾�������|���S���̔ԍ�

		@return �����蔻�茋�ʃ|���S��
	*/
	MV1_COLL_RESULT_POLY	CollCheckGetResultPoly(const MV1_COLL_RESULT_POLY_DIM& result_poly_dim, int poly_no);

	/*
		@brief	�����蔻�茋�ʃ|���S���z��̌�n��

		@param[in]	result_poly_dim	�����蔻�茋�ʃ|���S���z��\����
	*/
	void	CollResultPolyDimTerminate(const MV1_COLL_RESULT_POLY_DIM& result_poly_dim);

	//!���f���̃|�C���^
	aqua::CModel* m_Model;
	
	//���������������̃f�[�^
	MV1_COLL_RESULT_POLY m_HitLineResult;
};