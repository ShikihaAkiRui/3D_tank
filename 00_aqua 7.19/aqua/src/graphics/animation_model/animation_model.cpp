#include "animation_model.h"

/*
	�R���X�g���N�^
*/
aqua::
CAnimationModel::
CAnimationModel(void)
{
}

/*
	�t���[���̍��W�ϊ��s���ݒ�
*/
void 
aqua::CAnimationModel::
SetFrameUserLocalMatrix(aqua::CModel* model, int frame_index, const aqua::CMatrix& matrix)
{
	MV1SetFrameUserLocalMatrix(model->GetResourceHandle(), frame_index, matrix);
}
