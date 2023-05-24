#pragma once

#include"../../unit/unit.h"

//キャラクタークラス
class ICharacter : public IUnit
{
public:
	ICharacter(aqua::IGameObject* parent,const std::string& object_name);
	virtual ~ICharacter() = default;

	virtual void Initialize(const std::string& file_name)override;

	virtual void Update(void)override;

protected:
	aqua::CVector3 m_Position;			//位置	
	aqua::CVector3 m_GraundRayLength;	//床へのレイ長さ
private:
	//床の判定
	void CheckGround(void);

	static const aqua::CVector3 m_default_position;				//デフォルトの位置
	static const aqua::CVector3 m_default_graund_ray_length;	//デフォルトの床へのレイの長さ
};