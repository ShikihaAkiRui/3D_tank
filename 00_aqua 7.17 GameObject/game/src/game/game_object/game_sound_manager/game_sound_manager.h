#pragma once

#include"aqua.h"

//�T�E���hID
enum class SOUND_ID
{
	TITLE_BGM,		//�^�C�g��BGM
	GAMEMAIN_BGM,	//�Q�[�����C��

	DECISION,		//����
	EXPLOSION,		//����
	DAMAGE,			//�_���[�W���󂯂�
	IMPACT,			//���e
	SHOT,			//����
	GET_ITEM,		//�A�C�e���擾
	HORN,			//�p�J

	MAX				//�T�E���h��
};

//�T�E���h�}�l�[�W���[
class CGameSoundManager
{
public:
	//�C���X�^���X���擾
	static CGameSoundManager& GetInstance(void);

	//������
	void Initialize(void);
	//�X�V
	void Finalize(void);

	//�T�E���h�Đ�
	//�T�E���hID
	void Play(SOUND_ID id);
	//�T�E���h��~
	//�T�E���hID
	void Stop(SOUND_ID id);

private:
	//�R���X�g���N�^
	CGameSoundManager(void);
	//�R�s�[�R���X�g���N�^
	CGameSoundManager(const CGameSoundManager& rhs);
	//�f�X�g���N�^
	~CGameSoundManager(void) = default;
	//������Z�q
	CGameSoundManager& operator=(const CGameSoundManager& rhs);

	static const std::string	m_sound_file_names[];	//�T�E���h�t�@�C���p�X
	static const int m_sound_volume[];					//�T�E���h�̑傫��
	aqua::CSoundPlayer* m_SoundPlayer;					//�T�E���h�v���C���[

};