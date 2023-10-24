#pragma once

#include"../character/character.h"

//エネミー
class IEnemy : public ICharacter
{
public:
	//コンストラクタ
	IEnemy(aqua::IGameObject* parent,const std::string& object_name);
	//デストラクタ
	virtual ~IEnemy() = default;

	//初期化
	void Initialize(void)override {};
	//位置
	virtual void Initialize(const aqua::CVector3& position) {};
	//モデルのパス,	位置,	床までの高さ,	体力
	virtual void Initialize(const std::string& file_name,const aqua::CVector3& position ,float graund_ray_langeth,int life);

protected:

	//倒された
	virtual void Dead(void)override;

};