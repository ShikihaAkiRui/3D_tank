#pragma once

#include"aqua.h"
#include"../unit/unit.h"

//ライト操作クラス
class CControlLight : public aqua::IGameObject
{
public:
	//コンストラクタ
	CControlLight(aqua::IGameObject* parent);
	//デストラクタ
	~CControlLight() = default;

	//初期化
	//ライトのポインタ
	void Initialize(aqua::CLight* light);
	//更新
	void Update(void);

private:
	aqua::CLight* m_Light;	//ライトのポインタ

	static const aqua::CVector3 m_position;				//ライトの場所
	static const float m_range;							//ライトの有効範囲
	static const float m_attenuation;					//距離減衰
	static const float m_attenuation_proportion;		//距離減衰(比例)
	static const float m_attenuation_squaring;			//距離減衰(二乗)
};