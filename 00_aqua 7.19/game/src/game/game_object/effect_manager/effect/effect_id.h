#pragma once

//エフェクトID
enum class EFFECT_ID
{
	EXPLOSION,			//爆発
	GRAUND_HIT_BULLET,	//地面に着弾
	HITPLAYER,			//弾が当たった
	NOT_HIT,			//弾が当たらなかった

	MAX					//エフェクト数
};