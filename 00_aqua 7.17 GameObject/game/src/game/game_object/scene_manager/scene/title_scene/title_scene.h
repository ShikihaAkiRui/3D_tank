#pragma once

#include"../scene.h"

//�^�C�g���V�[��
class CTitleScene : public IScene
{
public:
	CTitleScene(aqua::IGameObject* parent);
	~CTitleScene() = default;

	void Initialize(void)override;
	void Update(void)override;
	void Draw(void)override;
	void Finalize(void)override;

private:
	static const std::string m_object_name;	//�I�u�W�F�N�g�̖��O
	aqua::CLabel m_Label;	//�f�o�b�N�p
};