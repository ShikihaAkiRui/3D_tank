#include "scene_manager.h"
#include"scene/title_scene/title_scene.h"
#include"scene/gamemain_scene/gamemain_scene.h"

const float CSceneManager::m_fade_speed = 255.0f;

//�R���X�g���N�^
CSceneManager::CSceneManager(aqua::IGameObject* parent)
	:aqua::IGameObject(parent,"SceneManager")
	,m_CurrentSceneID(SCENE_ID::DUMMY)
	,m_NextSceneID(SCENE_ID::DUMMY)
	,m_PushSceneID(SCENE_ID::DUMMY)
	,m_State(STATE::SCENE_IN)
	,m_PushFlag(false)
{
}

//������
void CSceneManager::Initialize(void)
{
	//�t�F�[�h�p�p�l���ݒ�
	m_FadePlane.Setup(aqua::CVector2::ZERO, (float)aqua::GetWindowWidth(), (float)aqua::GetWindowHeight(), aqua::CColor::BLACK);

	//�^�C�g���V�[���𐶐�
	Create(SCENE_ID::TITLE);

	//�V�[���C���̏�Ԃɐݒ�
	m_State = STATE::SCENE_IN;

	//Push�t���O��OFF
	m_PushFlag = false;

}

//�X�V
void CSceneManager::Update(void)
{
	switch (m_State)
	{
	case STATE::SCENE_IN:		SceneIn();		break;
	case STATE::SCENE_UPDATE:	SceneUpdate();	break;
	case STATE::SCENE_OUT:		SceneOut();		break;
	case STATE::SCENE_CHANGE:	SceneChange();	break;
	default:	break;
	}

}

//�`��
void CSceneManager::Draw(void)
{
	IGameObject::Draw();

	if (m_State != STATE::SCENE_UPDATE)
		m_FadePlane.Draw();
}

//�V�[����ύX
void CSceneManager::Change(SCENE_ID id)
{
	//���̃V�[��ID
	m_NextSceneID = id;
}

//�V�[�����X�^�b�N
void CSceneManager::Push(SCENE_ID id)
{
	//�����t���[�����ɂ��łɃv�b�V������Ă�
	if (m_PushFlag || m_PushSceneID != SCENE_ID::DUMMY)
		return;

	//�v�b�V���t���O��ON
	m_PushFlag = true;

	//�X�^�b�N����V�[��ID��ۑ�
	m_PushSceneID = id;
}

//�X�^�b�N�����V�[�������o��
void CSceneManager::Pop(void)
{
	//���̃V�[������̏ꍇ�̓|�b�v�ł��Ȃ�
	if (m_ChildObjectList.size() <= 1)
		return;
	//�����̃V�[���̃C�e���[�^���擾
	aqua::GAME_OBJECT_LIST::reverse_iterator it = m_ChildObjectList.rbegin();

	//�V�[���N���X�ɃL���X�g����
	IScene* scene = (IScene*)(*it);

	//�����̃V�[�����폜�Ώۂɐݒ�
	scene->DeleteObject();

	//�ЂƂO�̃V�[�����擾
	scene = (IScene*)(*(++it));

	//�ЂƂO�̃V�[�����A�N�e�B�u��ԂɕύX
	scene->SetGameObjectState(aqua::GAME_OBJECT_STATE::ACTIVE);
}

//���݂̃V�[�������Z�b�g
void CSceneManager::Reset(void)
{
	m_NextSceneID = m_CurrentSceneID;

	m_CurrentSceneID = SCENE_ID::DUMMY;
}

//���݂̃V�[��ID
SCENE_ID CSceneManager::GetSceneID(void) const
{
	return m_CurrentSceneID;
}

//�V�[���𐶐�
void CSceneManager::Create(SCENE_ID id)
{
	IScene* scene = nullptr;

	//ID���ƂɐV�����V�[���𐶐�
	switch (id)
	{
	case SCENE_ID::TITLE:	scene = aqua::CreateGameObject<CTitleScene>(this);			break;
	case SCENE_ID::GAMEMAIN:	scene = aqua::CreateGameObject<CGameMainScene>(this);	break;
	default:	break;
	}

	AQUA_ASSERT(scene, "�V�[���������ł��܂���ł���");

	//�V�[���̏�����
	scene->Initialize();
}

//�V�[���̍폜
void CSceneManager::Delete(void)
{
	IGameObject::Finalize();
}

//�V�[�����o�J�n
void CSceneManager::SceneIn(void)
{
	float alpha = (float)m_FadePlane.color.alpha;

	alpha -= m_fade_speed * aqua::GetDeltaTime();

	if (alpha < 0.0f)
	{
		alpha = 0.0f;

		m_State = STATE::SCENE_UPDATE;
	}

	m_FadePlane.color.alpha = (unsigned char)alpha;
}

//�V�[�����X�V
void CSceneManager::SceneUpdate(void)
{
	//�v�b�V���������s��ꂽ�ꍇ
	if (m_PushFlag)
	{
		//�����̃V�[���̃C�e���[�^���擾
		aqua::GAME_OBJECT_LIST::reverse_iterator it = m_ChildObjectList.rbegin();

		//�V�[���N���X�ɃL���X�g
		IScene* scene = (IScene*)(*it);

		//���݂̃V�[�����A�N�e�B�u�ɕύX
		scene->SetGameObjectState(aqua::GAME_OBJECT_STATE::WAIT);

		//�V�����V�[���𐶐����ăX�^�b�N
		Create(m_PushSceneID);

		//���g�p���̓_�~�[ID�����Ă���
		m_PushSceneID = SCENE_ID::DUMMY;

		//�V�[���̃v�b�V�����I��
		m_PushFlag = false;
	}

	IGameObject::Update();

	//�V�[���̕ύX�����m
	if (m_CurrentSceneID != m_NextSceneID)
		m_State = STATE::SCENE_OUT;
}

//�V�[���̏I�����o
void CSceneManager::SceneOut(void)
{
	float alpha = (float)m_FadePlane.color.alpha;

	alpha += m_fade_speed * aqua::GetDeltaTime();

	if (alpha > (float)aqua::CColor::MAX_COLOR)
	{
		alpha = (float)aqua::CColor::MAX_COLOR;

		m_State = STATE::SCENE_CHANGE;
	}

	m_FadePlane.color.alpha = (unsigned char)alpha;
}

//�V�[����ύX
void CSceneManager::SceneChange(void)
{
	//���݂̃V�[�����폜
	Delete();

	//���̃V�[���𐶐�
	Create(m_NextSceneID);

	//�V�[��ID��ۑ�
	m_CurrentSceneID = m_NextSceneID;

	//��Ԃ��ڍs
	m_State = STATE::SCENE_IN;
}

//�V�[���}�l�[�W���[���擾
CSceneManager* GetSceneManager(void)
{
	return (CSceneManager*)aqua::FindGameObject("SceneManager");
}
