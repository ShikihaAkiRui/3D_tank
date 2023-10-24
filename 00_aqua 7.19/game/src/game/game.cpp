
/*!
 *  @file       game.cpp
 *  @brief      �Q�[���Ǘ�
 *  @author     Kazuya Maruyama
 *  @date       2021/02/06
 *  @version    1.0
 *
 *  Copyright (c) 2013-2021, Kazuya Maruyama. All rights reserved.
 */

#include "game.h"
#include"game_object/scene_manager/scene_manager.h"
#include"game_object/game_sound_manager/game_sound_manager.h"

const unsigned int CGame::m_clear_color = 0xff7f7f7f;

/*
 *  �R���X�g���N�^
 */
CGame::
CGame( aqua::IGameObject* parent )
    : aqua::IGameObject( parent, "Game" )
{
}

/*
 *  ������
 */
void
CGame::
Initialize(void)
{
    // �ŏ��ɍ��I�u�W�F�N�g�Q
    CGameSoundManager::GetInstance().Initialize();

    aqua::CreateGameObject<CSceneManager>(this);

    IGameObject::Initialize();

}

//�X�V
void 
CGame::
Update(void)
{

    IGameObject::Update();
}

/*
 *  �`��
 */
void
CGame::
Draw(void)
{
    // ��ʂ̃N���A
    aqua::Clear(m_clear_color);

    // �`�悵�����I�u�W�F�N�g�Q

    IGameObject::Draw();
}

//���
void 
CGame::
Finalize(void)
{
    CGameSoundManager::GetInstance().Finalize();

    IGameObject::Finalize();
}