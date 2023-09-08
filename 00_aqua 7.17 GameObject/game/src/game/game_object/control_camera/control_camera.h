#pragma once

#include"aqua.h"
#include"../unit/unit.h"

//カメラ操作クラス
class CControlCamera : public aqua::IGameObject
{
public:
	CControlCamera(aqua::IGameObject* parent);
	~CControlCamera() = default;
	
	//初期化
	//カメラ,	カメラが追うユニット
	void Initialize(aqua::CCamera* camera,IUnit* unit);
	void Update(void)override;

	//カメラの注視点位置取得
	aqua::CVector3 GetTargetPosition(void);
	//向いている角度を取得
	aqua::CVector3 GetAngle(void);
private:

	aqua::CCamera* m_Camera;	//カメラのポインタ
	IUnit* m_Unit;				//注視点のユニットのポインタ
	aqua::CVector3 m_Angle;		//カメラ角度


	static const aqua::CVector3 m_camera_length;		//対象との距離
	static const aqua::CVector2 m_angle_variation;		//角度の変化量
	static const float m_max_y_angle;					//y軸角度最大値
	static const float m_min_y_angle;					//y軸角度最小値
	static const float m_max_x_angle;					//X軸角度最大値
	static const float m_min_x_angle;					//X軸角度最小値
	static const aqua::CVector3 m_target_position;		//ターゲットの高さ
};