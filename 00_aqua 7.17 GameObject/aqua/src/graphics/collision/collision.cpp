#include "collision.h"

/*
	�R���X�g���N�^
*/
ICollision::
ICollision(void)
{
}

/*
	�R���W���������\�z
*/
void
ICollision::
SetupCollInfo(aqua::CModel* model, int frame_index, int x_divnum, int y_divnum, int z_divnum)
{
	m_Model = model;

	MV1SetupCollInfo(m_Model->GetResourceHandle(), frame_index, x_divnum, y_divnum, z_divnum);
}

/*
	�R���W�������̌�n��
*/
void 
ICollision::
TerminateCollInfo(int frame_index)
{
	MV1TerminateCollInfo(m_Model->GetResourceHandle(), frame_index);
}

/*
	�R���W�������̍X�V
*/
void
ICollision::
RefreshCollInfo(int frame_index)
{
	MV1RefreshCollInfo(m_Model->GetResourceHandle(), frame_index);
}

/*
	�����ƃ��f���̓����蔻��
*/
bool 
ICollision::
CollCheckLine(int frame_index, aqua::CVector3 pos_start, aqua::CVector3 pos_end)
{
	MV1_COLL_RESULT_POLY result = MV1CollCheck_Line(m_Model->GetResourceHandle(), frame_index, pos_start, pos_end);

	return result.HitFlag;
}

/*
	 �ʂƃ��f���̓����蔻��
*/
bool
ICollision::
CollCheckSphere(int frame_index, aqua::CVector3 center_pos, float radius)
{
	MV1_COLL_RESULT_POLY_DIM result = MV1CollCheck_Sphere(m_Model->GetResourceHandle(), frame_index, center_pos, radius);

	//0�Ȃ瓖�����ĂȂ�
	bool hit_flag = result.HitNum <= 0 ? false : true;

	//�����蔻�茋�ʃ|���S���z��̌�n��
	CollResultPolyDimTerminate(result);

	return hit_flag;
}

/*
	�J�v�Z���ƃ��f���̓����蔻��
*/
bool
ICollision::
CollCheckCapsule(int frame_index, aqua::CVector3 pos1, aqua::CVector3 pos2, float radius)
{
	MV1_COLL_RESULT_POLY_DIM result = MV1CollCheck_Capsule(m_Model->GetResourceHandle(), frame_index, pos1, pos2, radius);

	//0�Ȃ瓖�����ĂȂ�
	bool hit_flag = result.HitNum <= 0 ? false : true;

	//�����蔻�茋�ʃ|���S���z��̌�n��
	CollResultPolyDimTerminate(result);

	return hit_flag;
}

/*
	�����蔻�茋�ʃ|���S���z�񂩂�w��Ԃ̃|���S�������擾
*/
MV1_COLL_RESULT_POLY 
ICollision::
CollCheckGetResultPoly(MV1_COLL_RESULT_POLY_DIM result_poly_dim, int poly_no)
{
	return MV1CollCheck_GetResultPoly(result_poly_dim,poly_no);
}

/*
	�����蔻�茋�ʃ|���S���z��̌�n��
*/
void
ICollision::
CollResultPolyDimTerminate(MV1_COLL_RESULT_POLY_DIM result_poly_dim)
{
	MV1CollResultPolyDimTerminate(result_poly_dim);
}