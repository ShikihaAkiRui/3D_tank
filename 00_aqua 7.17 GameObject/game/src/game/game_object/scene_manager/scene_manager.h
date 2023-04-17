#pragma once

#include"aqua.h"
#include"scene/scene_id.h"

//�V�[���}�l�[�W���[
class CSceneManager : public aqua::IGameObject
{
public:
	CSceneManager(aqua::IGameObject* parent);
	~CSceneManager() = default;

	void Initialize(void)override;
	void Update(void)override;
	void Draw(void)override;

	//�V�[����ύX
	void Change(SCENE_ID id);
	//�V�[�����X�^�b�N
	void Push(SCENE_ID id);
	//�X�^�b�N�����V�[�������o��
	void Pop(void);
	//�V�[�������Z�b�g
	void Reset(void);

	//���݂̃V�[��ID
	SCENE_ID GetSceneID(void)const;

private:
	//���
	enum class STATE
	{
		SCENE_IN,		//�J�n
		SCENE_UPDATE,	//�X�V
		SCENE_OUT,		//�I��
		SCENE_CHANGE	//�ύX
	};

	//�V�[���𐶐�
	void Create(SCENE_ID id);
	//���݂̃V�[�����폜
	void Delete(void);
	//�V�[���̊J�n���o
	void SceneIn(void);
	//�V�[�����X�V
	void SceneUpdate(void);
	//�V�[���̏I�����o
	void SceneOut(void);
	//�V�[����ύX
	void SceneChange(void);

	static const float m_fade_speed;	//�t�F�[�h���x
	SCENE_ID m_CurrentSceneID;			//���݂̃V�[��ID
	SCENE_ID m_NextSceneID;				//���̃V�[��ID
	SCENE_ID m_PushSceneID;				//�v�b�V������V�[��ID
	STATE m_State;						//���ID
	bool m_PushFlag;					//�V�[���̃v�b�V�����s��ꂽ
	aqua::CBoxPrimitive m_FadePlane;	//�t�F�[�h�p�̍�����

	aqua::CCamera m_Camera;
};

//�V�[���}�l�[�W���[�̎擾
CSceneManager* GetSceneManager(void);