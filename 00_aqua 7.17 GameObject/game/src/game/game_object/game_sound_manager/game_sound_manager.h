#pragma once

#include"aqua.h"

//サウンドID
enum class SOUND_ID
{
	TITLEBGM,

	DECISION,

	MAX
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
	aqua::CSoundPlayer* m_SoundPlayer;				//サウンドプレイヤー

};