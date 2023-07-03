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

	//レイが当たった位置を取得
	aqua::CVector3 CheckHitRay(void);

	//弾を飛ばす角度
	void GetBulletAngle(const aqua::CVector3& position);


	aqua::CSprite m_Sprite;		//照準
	aqua::CVector2 m_Position;	//位置
	aqua::CVector3 m_DirectionAngle;	//弾を出す向き
	aqua::CVector3 m_StartRayPosition;	//レイの出始め位置
	aqua::CVector3 m_EndRayPosition;	//レイの終わる位置

	static const aqua::CVector2 m_aim_position;		//位置
	static const float m_ray_length;				//レイの長さ
	static const std::string m_hit_object_name;		//当たり判定を見るオブジェクトの名前
	static const int m_frame_index;					//フレームの番号

};