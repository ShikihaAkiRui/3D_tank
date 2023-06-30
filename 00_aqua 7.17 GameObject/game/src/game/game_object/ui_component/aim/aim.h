#pragma once

#include"../ui_component.h"

//照準
class CAim : public IUIComponent
{
public:
	CAim(aqua::IGameObject* parent);
	~CAim() = default;

	void Initialize(void)override;
	void Update(void)override;
	void Draw(void)override;
	void Finalize(void)override;

	//狙っている方向を取得
	aqua::CVector3 GetAimAngle(void);

private:
	//カメラからのレイの計算
	void SetAimRay(void);

	//通常時の弾の角度
	void GetNormalBulletAngle(void);
	//レイに当たった時の弾の角度
	void GetRayHitBulletAngle(void);

	aqua::CSprite m_Sprite;		//照準
	aqua::CVector2 m_Position;	//位置
	aqua::CVector3 m_DirectionAngle;	//弾を出す向き
	aqua::CVector3 m_StartRayPosition;	//レイの出始め位置
	aqua::CVector3 m_EndRayPosition;	//レイの終わる位置

	static const float m_ray_length;	//レイの長さ

};