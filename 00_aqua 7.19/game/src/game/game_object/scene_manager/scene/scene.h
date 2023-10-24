#pragma once

#include"aqua.h"
#include"scene_id.h"

//�V�[��
class IScene : public aqua::IGameObject
{
public:
	//�R���X�g���N�^
	IScene(aqua::IGameObject* parent,const std::string& object_name);
	//�f�X�g���N�^
	~IScene() = default;

	//�V�[����ύX
	void ChangeScene(SCENE_ID id);
	//�V�[�����X�^�b�N
	void PushScene(SCENE_ID id);
	//�X�^�b�N�����V�[�������o��
	void PopScene(void);
	//�V�[�������Z�b�g
	void ResetScene(void);

private:
	static const std::string m_scene_category;	//�V�[���̃J�e�S���[
};