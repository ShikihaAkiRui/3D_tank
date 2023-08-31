#pragma once

//ユニットID
enum class UNIT_ID
{
	PLAYER,			//プレイヤー
	ENEMY_NORMAL,	//敵（普通の弾）
	ENEMY_PARABOLA	//敵（放物線の弾）
};

//ユニットのカテゴリー
enum class UNIT_CATEGORY
{
	DUMMY,	//ダミー
	PLAYER,	//プレイヤー
	ENMEY	//敵
};