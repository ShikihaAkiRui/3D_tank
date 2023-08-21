#pragma once

#include"aqua.h"

//�T�E���hID
enum class SOUND_ID
{
	TITLEBGM,

	DECISION,

	MAX
};

//�T�E���h�}�l�[�W���[
class CGameSoundManager
{
public:
	//�C���X�^���X���擾
	static CGameSoundManager& GetInstance(void);

	void Initialize(void);
	void Finalize(void);

	//�T�E���h�Đ�
	void Play(SOUND_ID id);
	//�T�E���h��~
	void Stop(SOUND_ID id);

private:
	CGameSoundManager(void);
	CGameSoundManager(const CGameSoundManager& rhs);
	~CGameSoundManager(void) = default;
	CGameSoundManager& operator=(const CGameSoundManager& rhs);


	static const std::string	m_sound_file_names[];	//�T�E���h�t�@�C���p�X
	aqua::CSoundPlayer* m_SoundPlayer;				//�T�E���h�v���C���[

};