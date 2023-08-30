#pragma once

#include"aqua.h"

//サウンドID
enum class SOUND_ID
{
	TITLE_BGM,		//タイトルBGM
	GAMEMAIN_BGM,	//ゲームメイン

	DECISION,		//決定
	EXPLOSION,		//爆発
	DAMAGE,			//ダメージを受ける
	IMPACT,			//着弾
	SHOT,			//発射
	GET_ITEM,		//アイテム取得
	HORN,			//角笛

	MAX				//サウンド数
};

//サウンドマネージャー
class CGameSoundManager
{
public:
	//インスタンスを取得
	static CGameSoundManager& GetInstance(void);

	void Initialize(void);
	void Finalize(void);

	//サウンド再生
	void Play(SOUND_ID id);
	//サウンド停止
	void Stop(SOUND_ID id);

private:
	CGameSoundManager(void);
	CGameSoundManager(const CGameSoundManager& rhs);
	~CGameSoundManager(void) = default;
	CGameSoundManager& operator=(const CGameSoundManager& rhs);


	static const std::string	m_sound_file_names[];	//サウンドファイルパス
	static const int m_sound_volume[];					//サウンドの大きさ
	aqua::CSoundPlayer* m_SoundPlayer;					//サウンドプレイヤー

};