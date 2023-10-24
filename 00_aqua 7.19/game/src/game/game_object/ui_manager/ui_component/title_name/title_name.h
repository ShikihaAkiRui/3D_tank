#pragma once

#include"../ui_component.h"

//�^�C�g�����O
class CTitleName : public IUIComponent
{
public:
	//�R���X�g���N�^
	CTitleName(aqua::IGameObject* parent);
	//�f�X�g���N�^
	~CTitleName() = default;

	//������
	//�ʒu
	void Initialize(const aqua::CVector2& position);
	//�`��
	void Draw(void)override;
	//���
	void Finalize(void)override;

private:
	aqua::CLabel m_Label;	//�^�C�g�����O

	static const int m_label_size;			//���x���傫��
	static const int m_edge_bold;			//�[�̑���
	static const aqua::CColor m_label_color;//���x���F
};