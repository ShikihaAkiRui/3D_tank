#pragma once

#include"../character/character.h"

//�G�l�~�[
class IEnemy : public ICharacter
{
public:
	IEnemy(aqua::IGameObject* parent,const std::string& object_name);
	virtual ~IEnemy() = default;

	void Initialize(void)override {};
	virtual void Initialize(const aqua::CVector3& position) {};
	virtual void Initialize(const std::string& file_name,const aqua::CVector3& position ,float graund_ray_langeth,int life);

	virtual void Update(void)override;

protected:

	//�|���ꂽ
	virtual void Dead(void)override;

};