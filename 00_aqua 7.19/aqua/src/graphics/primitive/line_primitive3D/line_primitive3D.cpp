
/*!
 *  @file       line_primitive3D.cpp
 *  @brief      �����`��N���X
 *  @author     
 *  @date       2021/03/10
 *  @version    7.17
 *
 *  Copyright (c) 2013-2021, . All rights reserved.
 */

#include "line_primitive3D.h"
#include "..\..\..\debug\debug.h"

/*
 *  �R���X�g���N�^
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
 *  ������
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
 *  �`��
 */
void
aqua::CLinePrimitive3D::
Draw( void )
{
    // ��\���̎��͕`�悵�Ȃ�
    if( !visible ) return;

    // �A���t�@�u�����h�ݒ�
    SetDrawBlendMode((int)blend_mode, color.alpha );

    // �`��
    DrawLine3D( pointA, pointB, color.GetColor());

    // �A���t�@�u�����h���[�h���f�t�H���g�ɖ߂�
    SetDrawBlendMode((int)aqua::ALPHABLEND::ALPHA, aqua::CColor::MAX_COLOR );
}
