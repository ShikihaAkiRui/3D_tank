#pragma once

#include"../scene.h"

//�Q�[�����C���V�[��
class CGameMainScene : public IScene
{
public:
	CGameMainScene(aqua::IGameObject* parent);
	~CGameMainScene() = default;

	void Initialize(void)override;
	void Update(void)override;
	void Draw(void)override;
	void Finalize(void)override;

private:
	aqua::CModel m_Model;

	static const std::string m_object_name;	//�I�u�W�F�N�g�̖��O
	aqua::CLabel m_Label;	//�f�o�b�N�p
};