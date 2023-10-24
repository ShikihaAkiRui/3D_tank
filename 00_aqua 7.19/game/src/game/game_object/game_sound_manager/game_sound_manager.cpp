#include "game_sound_manager.h"

const std::string CGameSoundManager::m_sound_file_names[] =
{
    "data/sound/chiisanaannaisya.mp3",
    "data/sound/goshin.mp3",

    "data/sound/put.mp3",
    "data/sound/explosion.mp3",
    "data/sound/bomb.mp3",
    "data/sound/small_explosion3.mp3",
    "data/sound/gun-fire02.mp3",
    "data/sound/coin03.mp3",
    "data/sound/trampet.mp3"
};
const int CGameSoundManager::m_sound_volume[] =
{
    100,100,130,100,80,110,100,100,150
};

//インスタンスを取得
CGameSoundManager& CGameSoundManager::GetInstance(void)
{
    static CGameSoundManager instance;
    return instance;
}

//初期化
void CGameSoundManager::Initialize(void)
{
    if (!m_SoundPlayer) m_SoundPlayer = AQUA_NEW aqua::CSoundPlayer[(int)SOUND_ID::MAX];

    //ループ再生設定
    for (int i = (int)SOUND_ID::TITLE_BGM; i < (int)SOUND_ID::DECISION; ++i)
        m_SoundPlayer[i].Create(m_sound_file_names[i], true);

    // SEは単発
    for (int i = (int)SOUND_ID::DECISION; i < (int)SOUND_ID::MAX; ++i)
        m_SoundPlayer[i].Create(m_sound_file_names[i], false, 100);
    
    //ボリューム調整
    for (int bo = 0; bo < (int)SOUND_ID::MAX; ++bo)
        m_SoundPlayer[bo].SetVolume(m_sound_volume[bo]);
}

//解放
void CGameSoundManager::Finalize(void)
{
    for (int i = 0; i < (int)SOUND_ID::MAX; ++i)
        m_SoundPlayer[i].Delete();

    AQUA_SAFE_DELETE_ARRAY(m_SoundPlayer);
}

//サウンド再生
void CGameSoundManager::Play(SOUND_ID id)
{
    if (!m_SoundPlayer) return;

    m_SoundPlayer[(int)id].Play();
}

//サウンド停止
void CGameSoundManager::Stop(SOUND_ID id)
{
    if (!m_SoundPlayer)return;

    m_SoundPlayer[(int)id].Stop();
}

//コンストラクタ
CGameSoundManager::CGameSoundManager(void)
    :m_SoundPlayer(nullptr)
{
}

//コピーコンストラクタ
CGameSoundManager::CGameSoundManager(const CGameSoundManager& rhs)
{
    (void)rhs;
}

//代入演算子
CGameSoundManager& CGameSoundManager::operator=(const CGameSoundManager& rhs)
{
    (void)rhs;

    return *this;
}
