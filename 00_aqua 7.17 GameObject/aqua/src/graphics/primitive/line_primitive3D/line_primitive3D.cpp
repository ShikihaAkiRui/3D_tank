
/*!
 *  @file       line_primitive3D.cpp
 *  @brief      線分描画クラス
 *  @author     
 *  @date       2021/03/10
 *  @version    7.17
 *
 *  Copyright (c) 2013-2021, . All rights reserved.
 */

#include "line_primitive3D.h"
#include "..\..\..\debug\debug.h"

/*
 *  コンストラクタ
 */
aqua::CLinePrimitive3D::
CLinePrimitive3D( void )
    : pointA( CVector3::ZERO )
    , pointB( CVector3::ZERO )
    , color( aqua::CColor::WHITE )
    , thickness( 1.0f )
    , blend_mode( aqua::ALPHABLEND::ALPHA )
{
}

/*
 *  初期化
 */
void
aqua::CLinePrimitive3D::
Setup(const aqua::CVector3& pointA_, const aqua::CVector3& pointB_, const aqua::CColor& color_ , aqua::ALPHABLEND blend_mode_ )
{
    pointA      = pointA_;
    pointB      = pointB_;
    color       = color_;
    blend_mode  = blend_mode_;
}

/*
 *  描画
 */
void
aqua::CLinePrimitive3D::
Draw( void )
{
    // 非表示の時は描画しない
    if( !visible ) return;

    // アルファブレンド設定
    SetDrawBlendMode((int)blend_mode, color.alpha );

    // 描画
    DrawLine3D( pointA, pointB, color.GetColor());

    // アルファブレンドモードをデフォルトに戻す
    SetDrawBlendMode((int)aqua::ALPHABLEND::ALPHA, aqua::CColor::MAX_COLOR );
}
