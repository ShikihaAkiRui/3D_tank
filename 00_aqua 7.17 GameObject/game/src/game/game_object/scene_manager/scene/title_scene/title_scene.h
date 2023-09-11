#pragma once

#include"../scene.h"

//�^�C�g���V�[��
class CTitleScene : public IScene
{
public:
	//�R���X�g���N�^
	CTitleScene(aqua::IGameObject* parent);
	//�f�X�g���N�^
	~CTitleScene() = default;

	//������
	void Initialize(void)override;
	//�X�V
	void Update(void)override;
	//�`��
	void Draw(void)override;
	//���
	void Finalize(void)override;

private:
	aqua::CSprite m_BackSprite;	//�w�i�X�v���C�g

	static const aqua::CVector2 m_back_scale;		//�w�i�g�嗦
	static const aqua::CVector2 m_title_name_position;	//�^�C�g���̈ʒu
	static const aqua::CVector2 m_message_position;	//���b�Z�[�W�ʒu
	static const std::string m_message;				//���b�Z�[�W����
	static const std::string m_object_name;			//�I�u�W�F�N�g�̖��O
	aqua::CLabel m_Label;	//�f�o�b�N�p
};