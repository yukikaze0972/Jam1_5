#pragma once
#include <map>

enum EnemyType
{
	ENEMY1,//敵タイプ１
	ENEMY2,//敵タイプ２
	ENEMY3,//敵タイプ３
	ENEMY4,//敵タイプ４
	ENEMY5, //敵タイプ５
	ENEMY6,//敵タイプ6
	ENEMY7//敵タイプ7
};
struct MovePattern
{
	double vx;
	double vy;
};
//円の構造体
struct En
{
	EnemyType type;//敵の種類
	double x;//X座標
	double y;//Y座標
	double r;//半径
	int color;//円の色
	bool fill;//塗りつぶすか否か
	double vx;//横の移動量
	double vy;//縦の移動量
	double vvx;//横の移動量の増量
	double vvy;//縦の移動量の増量
	bool enable;//有効フラグ（生きてるか、死んでるか）
	int cooltime;//連射できないようにするタイマー
	int counter;
	int spawnTiming;//出現タイミング
	std::map<int,MovePattern> pattern;

};

bool isHit(En en1, En en2);//当たり判定関数

bool isRight(En shot, En target);//進行方向の右にいるか
void RotVec(En& shot, double r);