#include "animation_model.h"

/*
	コンストラクタ
*/
aqua::
CAnimationModel::
CAnimationModel(void)
{
}

/*
	フレームの座標変換行列を設定
*/
void 
aqua::CAnimationModel::
SetFrameUserLocalMatrix(aqua::CModel* model, int frame_index, const aqua::CMatrix& matrix)
{
	MV1SetFrameUserLocalMatrix(model->GetResourceHandle(), frame_index, matrix);
}
