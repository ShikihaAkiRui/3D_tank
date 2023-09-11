#pragma once

#include"../character/character.h"

//�G�l�~�[
class IEnemy : public ICharacter
{
public:
	//�R���X�g���N�^
	IEnemy(aqua::IGameObject* parent,const std::string& object_name);
	//�f�X�g���N�^
	virtual ~IEnemy() = default;

	//������
	void Initialize(void)override {};
	//�ʒu
	virtual void Initialize(const aqua::CVector3& position) {};
	//���f���̃p�X,	�ʒu,	���܂ł̍���,	�̗�
	virtual void Initialize(const std::string& file_name,const aqua::CVector3& position ,float graund_ray_langeth,int life);

protected:

	//�|���ꂽ
	virtual void Dead(void)override;

};