
/*!
 *  @file       game.cpp
 *  @brief      ゲーム管理
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
 *  コンストラクタ
 */
CGame::
CGame( aqua::IGameObject* parent )
    : aqua::IGameObject( parent, "Game" )
{
}

/*
 *  初期化
 */
void
CGame::
Initialize(void)
{
    // 最初に作るオブジェクト群
    CGameSoundManager::GetInstance().Initialize();

    aqua::CreateGameObject<CSceneManager>(this);

    IGameObject::Initialize();

}

//更新
void 
CGame::
Update(void)
{

    IGameObject::Update();
}

/*
 *  描画
 */
void
CGame::
Draw(void)
{
    // 画面のクリア
    aqua::Clear(m_clear_color);

    // 描画したいオブジェクト群

    IGameObject::Draw();
}

//解放
void 
CGame::
Finalize(void)
{
    CGameSoundManager::GetInstance().Finalize();

    IGameObject::Finalize();
}