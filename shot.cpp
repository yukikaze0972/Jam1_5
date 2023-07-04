#include "en.h"
#include "DxLib.h"
#include <math.h>
#include "shot.h"
#include "enemyshot.h"
#include "enemy.h"
#include "player.h"
#include "game.h"
#include "effect.h"


En shot[ShotNum];//弾
En BlackHole;
En LightRays[LightRaysShotNum];
int BlackHoleimg;
int BlackHoleDuration;
double BlackHoleGravity;
double playerYC;
int LightRaysDuration;
//弾の初期化
void initShot()
{
	BlackHoleDuration = 0;

	for (int i = 0; i < ShotNum; i++) {
		shot[i].r = 5;
		shot[i].color = GetColor(255, 255, 0);
		shot[i].fill = true;
		shot[i].vx = 1.0;
		shot[i].vy = 0.0;
		shot[i].enable = false;
	}

	BlackHoleimg = LoadGraph("BlackHole.png");
	BlackHole.r = 50;
	BlackHole.color = GetColor(100, 0, 100);
	BlackHole.fill = true;
	BlackHole.vx = 1.0;
	BlackHole.vy = 5.0;
	BlackHole.enable = false;
	BlackHoleGravity = 0.1;

	for (int i = 0; i < LightRaysShotNum; i++) {
		LightRays[i].r = 5;
		LightRays[i].color = GetColor(255, 255, 0);
		LightRays[i].fill = true;
		LightRays[i].enable = false;
		LightRays[i].cooltime = 0;
	}
	LightRaysDuration = 0;
}

void LightRaysShot_moto(int rad, En play)
{
	//弾が無効なときのみ初期値をセットし有効にする
	for (int j = 0; j < LightRaysShotNum; j++)
	{
		if (LightRays[j].enable == false)
		{
			//弾を撃つ
			LightRays[j].x = play.x;
			LightRays[j].y = play.y;
			double PI = 3.14159265358979323846264338;
			double minrad = PI / 180.0;//1度のラジアン
			double speed = 10;//速度
			LightRays[j].vx = speed * cos(minrad * rad);
			LightRays[j].vy = speed * sin(minrad * rad);
			LightRays[j].enable = true;
			break;
		}
	}
}


//弾の更新
void updateShot()
{
	//弾が有効なときに弾を動かす
	for (int i = 0; i < ShotNum; i++)
	{
		if (shot[i].enable == true) {
			shot[i].x = shot[i].x + shot[i].vx;
			shot[i].y = shot[i].y + shot[i].vy;
			if (shot[i].x >= 800) {
				shot[i].enable = false;
			}
		}
	}
}

void BlackHoleShot()
{
	if (BlackHole.enable == false)
	{
		playerYC = player.y;
		BlackHole.vy = 3.0;
		BlackHole.vx = 5.0;
	}
	if (BlackHole.enable == true)
	{
		BlackHole.x += BlackHole.vx;
		BlackHole.y -= BlackHole.vy;
		BlackHole.vy -= BlackHoleGravity;
		if (BlackHole.y > playerYC)
		{
			BlackHole.vx = 0;
			BlackHole.vy = 0;
		}
		if (BlackHoleDuration == 0)
		{
			BlackHole.enable = false;
			enemy2[0].vx = -2.0;
			enemy2[0].vy = 2.0;
		}
	}

	if (BlackHoleDuration > 0)
	{
		BlackHoleDuration--;
	}

	for (int i = 0; i < EnemyNum; i++)
	{
		if (enemy[i].x <= 800 &&
			enemy[i].x > 0 &&
			enemy[i].y <= 600 &&
			enemy[i].y > 0 && BlackHole.enable == true)
		{
			if (isRight(enemy[i], BlackHole))
			{
				RotVec(enemy[i], 0.9);
			}
			else {
				RotVec(enemy[i], -0.9);
			}
			if (enemy[i].enable == true) {
				if (isHit(BlackHole, enemy[i]))
				{
					enemy[i].enable = false;//敵を無効
					p++;
				}
			}
		}
	}
	if (enemy2[0].x <= 800 &&
		enemy2[0].x > 0 &&
		enemy2[0].y <= 600 &&
		enemy2[0].y > 0 && BlackHole.enable == true)
	{
		if (isRight(enemy2[0], BlackHole))
		{
			RotVec(enemy2[0], 0.9);
		}
		else {
			RotVec(enemy2[0], -0.9);
		}
		if (enemy2[0].enable == true) {
			if (isHit(BlackHole, enemy2[0]))
			{
				enemy2[0].enable = false;//敵を無効
				kisidahp = 0;
				p++;
			}
		}
	}
	if (BlackHole.enable == true)
	{
		for (int j = 0; j < EnemyShotNum; j++)
		{
			if (isRight(enemyshot[j], BlackHole))
			{
				RotVec(enemyshot[j], 0.9);
			}
			else {
				RotVec(enemyshot[j], -0.9);
			}
			if (isHit(BlackHole, enemyshot[j]))
			{
				enemyshot[j].enable = false;
			}
		}
	}
}


void LightRaysShot()
{
	if (LightRaysTrigger == true)
	{
		if (canLightRaysShot(player))
		{
			LightRaysShot_moto(0, player);
			LightRaysShot_moto(-20, player);
			LightRaysShot_moto(-40, player);
			LightRaysShot_moto(-60, player);
			LightRaysShot_moto(20, player);
			LightRaysShot_moto(40, player);
			LightRaysShot_moto(60, player);
			player.cooltime = 0;

			for (int i = 0; i < LightRaysShotNum; i++)
			{
				LightRays[i].x = LightRays[i].x + LightRays[i].vx;
				LightRays[i].y = LightRays[i].y + LightRays[i].vy;
				if (LightRays[i].y < 0)
				{
					LightRays[i].vy *= -1;
				}
				if (LightRays[i].y > 600)
				{
					LightRays[i].vy *= -1;
				}
				if (LightRaysDuration == 0)
				{
					LightRays[i].enable = false;
				}
			}
		}
	}
	if (LightRaysDuration == 0)
	{
		LightRaysTrigger = false;
	}

	if (player.cooltime > 0)
	{
		player.cooltime--;
	}
	if (LightRaysDuration > 0)
	{
		LightRaysDuration--;
	}

	if (LightRaysDuration == 250 || LightRaysDuration == 200 || LightRaysDuration == 150 || LightRaysDuration == 100 || LightRaysDuration == 50)
	{
		for (int i = 0; i < EnemyNum; i++) {
			if (enemy[i].x <= 800 &&
				enemy[i].x > 0 &&
				enemy[i].y <= 600 &&
				enemy[i].y > 0 && enemy[i].enable == true) {
				enemy[i].enable = false;
				PlaySoundMem(explodese, DX_PLAYTYPE_BACK);//爆破エフェクトの呼び出し
				explosion(enemy[i]);//爆発
				p++;
			}
			if (enemy2[i].x <= 800 &&
				enemy2[i].x > 0 &&
				enemy2[i].y <= 600 &&
				enemy2[i].y > 0 && enemy2[i].enable == true) {
				kisidahp -= 2;
				p++;

				if (kisidahp <= 0)
				{
					enemy2[i].enable = false;
					PlaySoundMem(explodese, DX_PLAYTYPE_BACK);//爆破エフェクトの呼び出し
					explosion(enemy2[i]);//爆発
				}
			}
		}
	}
}

//弾の描画
void drawShot()
{
	for (int i = 0; i < ShotNum; i++) {
		if (shot[i].enable == true)
		{
			SetDrawBlendMode(DX_BLENDMODE_ALPHA, 127);
			DrawCircle(shot[i].x, shot[i].y, shot[i].r * 5, shot[i].color, shot[i].fill);
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
			DrawCircle(shot[i].x, shot[i].y, shot[i].r, shot[i].color, shot[i].fill);
		}
	}

	if (BlackHole.enable == true)
	{
		//SetDrawBlendMode(DX_BLENDMODE_ALPHA, 127);
		//DrawCircle(BlackHole.x, BlackHole.y, BlackHole.r, BlackHole.color, BlackHole.fill);
		//SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
		//DrawCircle(BlackHole.x, BlackHole.y, BlackHole.r, BlackHole.color, BlackHole.fill);
		DrawGraph(BlackHole.x - 100, BlackHole.y - 100, BlackHoleimg, true);
	}

	for (int i = 0; i < LightRaysShotNum; i++) {
		if (LightRays[i].enable == true)
		{
			SetDrawBlendMode(DX_BLENDMODE_ADD, 255);//半透明
			DrawCircle(LightRays[i].x, LightRays[i].y, LightRays[i].r, LightRays[i].color, LightRays[i].fill);
			DrawCircle(LightRays[i].x - 9, LightRays[i].y, LightRays[i].r, LightRays[i].color, LightRays[i].fill);
			DrawCircle(LightRays[i].x - 8, LightRays[i].y, LightRays[i].r, LightRays[i].color, LightRays[i].fill);
			DrawCircle(LightRays[i].x - 7, LightRays[i].y, LightRays[i].r, LightRays[i].color, LightRays[i].fill);
			DrawCircle(LightRays[i].x - 6, LightRays[i].y, LightRays[i].r, LightRays[i].color, LightRays[i].fill);
			DrawCircle(LightRays[i].x - 5, LightRays[i].y, LightRays[i].r, LightRays[i].color, LightRays[i].fill);
			DrawCircle(LightRays[i].x - 4, LightRays[i].y, LightRays[i].r, LightRays[i].color, LightRays[i].fill);
			DrawCircle(LightRays[i].x - 3, LightRays[i].y, LightRays[i].r, LightRays[i].color, LightRays[i].fill);
			DrawCircle(LightRays[i].x - 2, LightRays[i].y, LightRays[i].r, LightRays[i].color, LightRays[i].fill);
			DrawCircle(LightRays[i].x - 1, LightRays[i].y, LightRays[i].r, LightRays[i].color, LightRays[i].fill);
			DrawCircle(LightRays[i].x, LightRays[i].y, LightRays[i].r * 0.8, LightRays[i].color, LightRays[i].fill);
			DrawCircle(LightRays[i].x, LightRays[i].y, LightRays[i].r * 0.6, LightRays[i].color, LightRays[i].fill);
			DrawCircle(LightRays[i].x, LightRays[i].y, LightRays[i].r * 0.4, LightRays[i].color, LightRays[i].fill);
			DrawCircle(LightRays[i].x, LightRays[i].y, LightRays[i].r * 0.2, LightRays[i].color, LightRays[i].fill);
			DrawCircle(LightRays[i].x, LightRays[i].y, LightRays[i].r * 0.1, LightRays[i].color, LightRays[i].fill);
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);//不透明
		}
	}
}


//弾が撃てるか確認する関数
bool canLightRaysShot(En player)
{
	//銃が冷えている
	if (player.cooltime <= 0) {
		if (player.x >= 0 &&
			player.x < 800 &&
			player.y>0 &&
			player.y < 600)
		{
			//画面の中にいる
			return true;
		}
	}

	return false;
}