#include "en.h"
#include "DxLib.h"
#include <math.h>
#include "shot.h"
#include "enemyshot.h"
#include "enemy.h"
#include "player.h"
#include "game.h"
#include "effect.h"
extern bool gameOverFlag;//ゲームオーバー判定
En enemy[EnemyNum];//1ndの敵の関数
En enemy2[EnemyNum];//2ndの敵の関数
int explodese;//爆破エフェクトの関数
int enemyimg;//爆破エフェクトの画像
int enemy2img;
int kisidaimg;
int kisidahp;
int q = 0;
//敵の初期化
void initEnemy()
{
	//爆破エフェクト
	explodese = LoadSoundMem("maou_se_battle_explosion05.mp3");
	//敵の画像
	enemyimg = LoadGraph("enemy1.png");
	enemy2img = LoadGraph("enemy2.png");
	kisidaimg = LoadGraph("kisida.png");
	//1ステージ目の敵
	//1体目の敵
	enemy[0].x = 900;//敵のX座標
	enemy[0].y = 200;//敵のY座標
	enemy[0].r = 30;//敵の大きさ
	enemy[0].color = GetColor(255, 0, 0);//敵の色
	enemy[0].fill = true;//塗りつぶすか否か
	enemy[0].enable = true;//生きているか死んでいるか
	enemy[0].vx = -2.0;//X方向のスピード
	enemy[0].vy = 0.0;//Y方向のスピード
	enemy[0].type = ENEMY2;//弾の種類
	//2体目の敵
	enemy[1].x = 1500;//敵のX座標
	enemy[1].y = 300;//敵のY座標
	enemy[1].r = 30;//敵の大きさ
	enemy[1].color = GetColor(255, 0, 0);//敵の色
	enemy[1].fill = true;//塗りつぶすか否か
	enemy[1].enable = true;//生きているか死んでいるか
	enemy[1].vx = -2.0;//X方向のスピード
	enemy[1].vy = 0.0;//Y方向のスピード
	enemy[1].type = ENEMY2;//弾の種類
	//3体目の敵
	enemy[2].x = 1500;//敵のX座標
	enemy[2].y = 200;//敵のY座標
	enemy[2].r = 30;//敵の大きさ
	enemy[2].color = GetColor(255, 0, 0);//敵の色
	enemy[2].fill = true;//塗りつぶすか否か
	enemy[2].enable = true;//生きているか死んでいるか
	enemy[2].vx = -2.0;//X方向のスピード
	enemy[2].vy = 0.0;//Y方向のスピード
	enemy[2].type = ENEMY3;//弾の種類
	//4体目の敵
	enemy[3].x = 1550;
	enemy[3].y = 50;
	enemy[3].r = 30;
	enemy[3].color = GetColor(255, 0, 0);
	enemy[3].fill = true;
	enemy[3].enable = true;
	enemy[3].vx = -2.0;
	enemy[3].vy = 0.0;
	enemy[3].type = ENEMY3;
	//5体目の敵
	enemy[4].x = 1600;
	enemy[4].y = 400;
	enemy[4].r = 30;
	enemy[4].color = GetColor(255, 0, 0);
	enemy[4].fill = true;
	enemy[4].enable = true;
	enemy[4].vx = -2.0;
	enemy[4].vy = 0.0;
	enemy[4].type = ENEMY3;
	//6体目の敵
	enemy[6].x = 1600;
	enemy[6].y = 100;
	enemy[6].r = 30;
	enemy[6].color = GetColor(255, 0, 0);
	enemy[6].fill = true;
	enemy[6].enable = true;
	enemy[6].vx = -2.0;
	enemy[6].vy = 0.0;
	enemy[6].type = ENEMY3;

	enemy[7].x = 1700;
	enemy[7].y = 200;
	enemy[7].r = 30;
	enemy[7].color = GetColor(255, 0, 0);
	enemy[7].fill = true;
	enemy[7].enable = true;
	enemy[7].vx = -2.0;
	enemy[7].vy = 0.0;
	enemy[7].type = ENEMY3;

	enemy[8].x = 1700;
	enemy[8].y = 400;
	enemy[8].r = 30;
	enemy[8].color = GetColor(255, 0, 0);
	enemy[8].fill = true;
	enemy[8].enable = true;
	enemy[8].vx = -2.0;
	enemy[8].vy = 0.0;
	enemy[8].type = ENEMY3;

	enemy[9].x = 1700;
	enemy[9].y = 500;
	enemy[9].r = 30;
	enemy[9].color = GetColor(255, 0, 0);
	enemy[9].fill = true;
	enemy[9].enable = true;
	enemy[9].vx = -2.0;
	enemy[9].vy = 0.0;
	enemy[9].type = ENEMY3;

	enemy[10].x = 1750;
	enemy[10].y = 200;
	enemy[10].r = 30;
	enemy[10].color = GetColor(255, 0, 0);
	enemy[10].fill = true;
	enemy[10].enable = true;
	enemy[10].vx = -2.0;
	enemy[10].vy = 0.0;
	enemy[10].type = ENEMY3;

	enemy[11].x = 1800;
	enemy[11].y = 500;
	enemy[11].r = 30;
	enemy[11].color = GetColor(255, 0, 0);
	enemy[11].fill = true;
	enemy[11].enable = true;
	enemy[11].vx = -2.0;
	enemy[11].vy = 0.0;
	enemy[11].type = ENEMY3;

	enemy[12].x = 1800;
	enemy[12].y = 100;
	enemy[12].r = 30;
	enemy[12].color = GetColor(255, 0, 0);
	enemy[12].fill = true;
	enemy[12].enable = true;
	enemy[12].vx = -2.0;
	enemy[12].vy = 0.0;
	enemy[12].type = ENEMY3;

	enemy[13].x = 1800;
	enemy[13].y = 300;
	enemy[13].r = 30;
	enemy[13].color = GetColor(255, 0, 0);
	enemy[13].fill = true;
	enemy[13].enable = true;
	enemy[13].vx = -2.0;
	enemy[13].vy = 0.0;
	enemy[13].type = ENEMY3;

	int a = 20;
	for (int i = 14; i < 20; i++)
	{
		enemy[i].x = 1900;
		enemy[i].y = a + a;
		enemy[i].r = 30;
		enemy[i].color = GetColor(255, 0, 0);
		enemy[i].fill = true;
		enemy[i].enable = true;
		enemy[i].vx = -2.0;
		enemy[i].vy = 0.0;
		enemy[i].type = ENEMY3;

		a += 100;
	}

	a = 10;
	for (int i = 20; i < 25; i++)
	{
		enemy[i].x = 2000;
		enemy[i].y = a + a;
		enemy[i].r = 30;
		enemy[i].color = GetColor(255, 0, 0);
		enemy[i].fill = true;
		enemy[i].enable = true;
		enemy[i].vx = -2.0;
		enemy[i].vy = 0.0;
		enemy[i].type = ENEMY3;

		a += 125;
	}


	a = 30;
	for (int i = 25; i < 30; i++)
	{
		enemy[i].x = 2200;
		enemy[i].y = a + a;
		enemy[i].r = 30;
		enemy[i].color = GetColor(255, 0, 0);
		enemy[i].fill = true;
		enemy[i].enable = true;
		enemy[i].vx = -2.0;
		enemy[i].vy = 0.0;
		enemy[i].type = ENEMY3;

		a += 100;
	}

	a = 10;
	for (int i = 30; i < 35; i++)
	{
		enemy[i].x = 2500;
		enemy[i].y = a + a;
		enemy[i].r = 30;
		enemy[i].color = GetColor(255, 0, 0);
		enemy[i].fill = true;
		enemy[i].enable = true;
		enemy[i].vx = -2.0;
		enemy[i].vy = 0.0;
		enemy[i].type = ENEMY3;

		a += 125;
	}

	a = 25;
	for (int i = 35; i < 40; i++)
	{
		enemy[i].x = 2700;
		enemy[i].y = a + a;
		enemy[i].r = 30;
		enemy[i].color = GetColor(255, 0, 0);
		enemy[i].fill = true;
		enemy[i].enable = true;
		enemy[i].vx = -2.0;
		enemy[i].vy = 0.0;
		enemy[i].type = ENEMY3;

		a += 100;
	}


	a = 25;
	for (int i = 40; i < 45; i++)
	{
		enemy[i].x = 2800;
		enemy[i].y = a + a;
		enemy[i].r = 30;
		enemy[i].color = GetColor(255, 0, 0);
		enemy[i].fill = true;
		enemy[i].enable = true;
		enemy[i].vx = -2.0;
		enemy[i].vy = 0.0;
		enemy[i].type = ENEMY3;

		a += 110;
	}

	a = 10;
	for (int i = 45; i < 50; i++)
	{
		enemy[i].x = 2900;
		enemy[i].y = a + a;
		enemy[i].r = 30;
		enemy[i].color = GetColor(255, 0, 0);
		enemy[i].fill = true;
		enemy[i].enable = true;
		enemy[i].vx = -2.0;
		enemy[i].vy = 0.0;
		enemy[i].type = ENEMY3;

		a += 130;
	}

	a = 50;
	for (int i = 50; i < 55; i++)
	{
		enemy[i].x = 3000;
		enemy[i].y = a + a;
		enemy[i].r = 30;
		enemy[i].color = GetColor(255, 0, 0);
		enemy[i].fill = true;
		enemy[i].enable = true;
		enemy[i].vx = -2.0;
		enemy[i].vy = 0.0;
		enemy[i].type = ENEMY3;

		a += 100;
	}

	a = 5;
	for (int i = 55; i < 60; i++)
	{
		enemy[i].x = 3100;
		enemy[i].y = a + a;
		enemy[i].r = 30;
		enemy[i].color = GetColor(255, 0, 0);
		enemy[i].fill = true;
		enemy[i].enable = true;
		enemy[i].vx = -2.0;
		enemy[i].vy = 0.0;
		enemy[i].type = ENEMY3;

		a += 125;
	}

	a = 10;
	for (int i = 60; i < 65; i++)
	{
		enemy[i].x = 3200;
		enemy[i].y = a + a;
		enemy[i].r = 30;
		enemy[i].color = GetColor(255, 0, 0);
		enemy[i].fill = true;
		enemy[i].enable = true;
		enemy[i].vx = -2.0;
		enemy[i].vy = 0.0;
		enemy[i].type = ENEMY3;

		a += 110;
	}

	a = 40;
	for (int i = 65; i < 70; i++)
	{
		enemy[i].x = 3200;
		enemy[i].y = a + a;
		enemy[i].r = 30;
		enemy[i].color = GetColor(255, 0, 0);
		enemy[i].fill = true;
		enemy[i].enable = true;
		enemy[i].vx = -2.0;
		enemy[i].vy = 0.0;
		enemy[i].type = ENEMY3;

		a += 110;
	}

	a = 20;
	for (int i = 70; i < 75; i++)
	{
		enemy[i].x = 3300;
		enemy[i].y = a + a;
		enemy[i].r = 30;
		enemy[i].color = GetColor(255, 0, 0);
		enemy[i].fill = true;
		enemy[i].enable = true;
		enemy[i].vx = -2.0;
		enemy[i].vy = 0.0;
		enemy[i].type = ENEMY3;

		a += 130;
	}

	a = 10;
	for (int i = 75; i < 80; i++)
	{
		enemy[i].x = 3400;
		enemy[i].y = a + a;
		enemy[i].r = 30;
		enemy[i].color = GetColor(255, 0, 0);
		enemy[i].fill = true;
		enemy[i].enable = true;
		enemy[i].vx = -2.0;
		enemy[i].vy = 0.0;
		enemy[i].type = ENEMY3;

		a += 100;
	}

	a = 8;
	for (int i = 80; i < 85; i++)
	{
		enemy[i].x = 3400;
		enemy[i].y = a + a;
		enemy[i].r = 30;
		enemy[i].color = GetColor(255, 0, 0);
		enemy[i].fill = true;
		enemy[i].enable = true;
		enemy[i].vx = -2.0;
		enemy[i].vy = 0.0;
		enemy[i].type = ENEMY3;

		a += 100;
	}

	a = 15;
	for (int i = 85; i < 90; i++)
	{
		enemy[i].x = 3500;
		enemy[i].y = a + a;
		enemy[i].r = 30;
		enemy[i].color = GetColor(255, 0, 0);
		enemy[i].fill = true;
		enemy[i].enable = true;
		enemy[i].vx = -2.0;
		enemy[i].vy = 0.0;
		enemy[i].type = ENEMY3;

		a += 120;
	}

	a = 20;
	for (int i = 90; i < 95; i++)
	{
		enemy[i].x = 3600;
		enemy[i].y = a + a;
		enemy[i].r = 30;
		enemy[i].color = GetColor(255, 0, 0);
		enemy[i].fill = true;
		enemy[i].enable = true;
		enemy[i].vx = -2.0;
		enemy[i].vy = 0.0;
		enemy[i].type = ENEMY3;

		a += 120;
	}

	a = 15;
	for (int i = 95; i < 100; i++)
	{
		enemy[i].x = 3700;
		enemy[i].y = a + a;
		enemy[i].r = 30;
		enemy[i].color = GetColor(255, 0, 0);
		enemy[i].fill = true;
		enemy[i].enable = true;
		enemy[i].vx = -2.0;
		enemy[i].vy = 0.0;
		enemy[i].type = ENEMY3;

		a += 110;
	}


	a = 30;
	for (int i = 100; i < 105; i++)
	{
		enemy[i].x = 3700;
		enemy[i].y = a + a;
		enemy[i].r = 30;
		enemy[i].color = GetColor(255, 0, 0);
		enemy[i].fill = true;
		enemy[i].enable = true;
		enemy[i].vx = -2.0;
		enemy[i].vy = 0.0;
		enemy[i].type = ENEMY3;

		a += 100;
	}

	a = 15;
	for (int i = 105; i < 110; i++)
	{
		enemy[i].x = 3800;
		enemy[i].y = a + a;
		enemy[i].r = 30;
		enemy[i].color = GetColor(255, 0, 0);
		enemy[i].fill = true;
		enemy[i].enable = true;
		enemy[i].vx = -2.0;
		enemy[i].vy = 0.0;
		enemy[i].type = ENEMY3;

		a += 130;
	}

	a = 20;
	for (int i = 110; i < 115; i++)
	{
		enemy[i].x = 3900;
		enemy[i].y = a + a;
		enemy[i].r = 30;
		enemy[i].color = GetColor(255, 0, 0);
		enemy[i].fill = true;
		enemy[i].enable = true;
		enemy[i].vx = -2.0;
		enemy[i].vy = 0.0;
		enemy[i].type = ENEMY3;

		a += 110;
	}


	a = 10;
	for (int i = 115; i < 120; i++)
	{
		enemy[i].x = 4000;
		enemy[i].y = a + a;
		enemy[i].r = 30;
		enemy[i].color = GetColor(255, 0, 0);
		enemy[i].fill = true;
		enemy[i].enable = true;
		enemy[i].vx = -2.0;
		enemy[i].vy = 0.0;
		enemy[i].type = ENEMY3;

		a += 100;
	}


	a = 8;
	for (int i = 120; i < 125; i++)
	{
		enemy[i].x = 4100;
		enemy[i].y = a + a;
		enemy[i].r = 30;
		enemy[i].color = GetColor(255, 0, 0);
		enemy[i].fill = true;
		enemy[i].enable = true;
		enemy[i].vx = -2.0;
		enemy[i].vy = 0.0;
		enemy[i].type = ENEMY3;

		a += 120;
	}

	a = 10;
	for (int i = 125; i < 130; i++)
	{
		enemy[i].x = 4200;
		enemy[i].y = a + a;
		enemy[i].r = 30;
		enemy[i].color = GetColor(255, 0, 0);
		enemy[i].fill = true;
		enemy[i].enable = true;
		enemy[i].vx = -2.0;
		enemy[i].vy = 0.0;
		enemy[i].type = ENEMY3;

		a += 100;
	}


	a = 20;
	for (int i = 130; i < 135; i++)
	{
		enemy[i].x = 4300;
		enemy[i].y = a + a;
		enemy[i].r = 30;
		enemy[i].color = GetColor(255, 0, 0);
		enemy[i].fill = true;
		enemy[i].enable = true;
		enemy[i].vx = -2.0;
		enemy[i].vy = 0.0;
		enemy[i].type = ENEMY3;

		a += 80;
	}

	a = 6;
	for (int i = 140; i < 145; i++)
	{
		enemy[i].x = 4400;
		enemy[i].y = a + a;
		enemy[i].r = 30;
		enemy[i].color = GetColor(255, 0, 0);
		enemy[i].fill = true;
		enemy[i].enable = true;
		enemy[i].vx = -2.0;
		enemy[i].vy = 0.0;
		enemy[i].type = ENEMY3;

		a += 50;
	}

	a = 10;
	for (int i = 145; i < 150; i++)
	{
		enemy[i].x = 4500;
		enemy[i].y = a + a;
		enemy[i].r = 30;
		enemy[i].color = GetColor(255, 0, 0);
		enemy[i].fill = true;
		enemy[i].enable = true;
		enemy[i].vx = -2.0;
		enemy[i].vy = 0.0;
		enemy[i].type = ENEMY3;

		a += 50;
	}

	a = 20;
	for (int i = 150; i < 155; i++)
	{
		enemy[i].x = 4600;
		enemy[i].y = a + a;
		enemy[i].r = 30;
		enemy[i].color = GetColor(255, 0, 0);
		enemy[i].fill = true;
		enemy[i].enable = true;
		enemy[i].vx = -2.0;
		enemy[i].vy = 0.0;
		enemy[i].type = ENEMY3;

		a += 100;
	}

	a = 50;
	for (int i = 150; i < 155; i++)
	{
		enemy[i].x = 4700;
		enemy[i].y = a + a;
		enemy[i].r = 30;
		enemy[i].color = GetColor(255, 0, 0);
		enemy[i].fill = true;
		enemy[i].enable = true;
		enemy[i].vx = -2.0;
		enemy[i].vy = 0.0;
		enemy[i].type = ENEMY3;

		a += 120;
	}


	a = 10;
	for (int i = 155; i < 165; i++)
	{
		enemy[i].x = 4800;
		enemy[i].y = a + a;
		enemy[i].r = 30;
		enemy[i].color = GetColor(255, 0, 0);
		enemy[i].fill = true;
		enemy[i].enable = true;
		enemy[i].vx = -2.0;
		enemy[i].vy = 0.0;
		enemy[i].type = ENEMY3;

		a += 50;
	}

	//2ステージ目の敵
	//1体目の敵
	enemy2[0].x = 900;
	enemy2[0].y = 300;
	enemy2[0].r = 50;
	enemy2[0].color = GetColor(255, 0, 0);
	enemy2[0].fill = true;
	enemy2[0].enable = true;
	enemy2[0].vx = -2.0;
	enemy2[0].vy = 2.0;
	enemy2[0].type = ENEMY4;
	kisidahp = 100;
}
//真っすぐ弾を撃つ
void straightShot(int rad, En ene)
{
	//弾が無効なときのみ初期値をセットし有効にする
	for (int j = 0; j < EnemyShotNum; j++)
	{
		//撃てる弾をみつける
		if (enemyshot[j].enable == false) {
			//弾を撃つ
			enemyshot[j].x = ene.x;
			enemyshot[j].y = ene.y;
			double PI = 3.14159265358979323846264338;//円周率
			double minrad = PI / 180.0;//1度のラジアン
			double speed = 3.0;//速度
			enemyshot[j].vx = speed * cos(minrad * rad);//横の移動量
			enemyshot[j].vy = speed * sin(minrad * rad);//縦の移動量
			enemyshot[j].enable = true;//有効フラグ
			enemyshot[j].type = ene.type;//弾の種類
			break;
		}
	}
}
void tripleShot(int rad, En ene)
{
	for (int j = 0; j < EnemyShotNum; j++)
	{
		//撃てる弾をみつける
		if (enemyshot[j].enable == false) {
			//弾を撃つ
			enemyshot[j].x = ene.x;
			enemyshot[j].y = ene.y;
			double PI = 3.14159265358979323846264338;
			double minrad = PI / 180.0;//1度のラジアン
			double speed = 3.0;//速度
			enemyshot[j].vx = speed * cos(minrad * rad);
			enemyshot[j].vy = speed * sin(minrad * rad);
			enemyshot[j].enable = true;
			break;
		}
	}
}
void twinShot(int rad, int shifty, En ene)
{
	for (int j = 0; j < EnemyShotNum; j++)
	{
		//撃てる弾をみつける
		if (enemyshot[j].enable == false) {
			//弾を撃つ
			enemyshot[j].x = ene.x;
			enemyshot[j].y = ene.y + shifty;
			double PI = 3.14159265358979323846264338;
			double minrad = PI / 180.0;//1度のラジアン
			double speed = 4.0;//速度
			enemyshot[j].vx = speed * cos(minrad * rad);
			enemyshot[j].vy = speed * sin(minrad * rad);
			enemyshot[j].enable = true;
			break;
			break;
		}
	}
}
void closerangeShot(En ene) {
	for (int j = 0; j < EnemyShotNum; j++)
	{
		//撃てる弾をみつける
		if (enemyshot[j].enable == false) {
			//弾を撃つ
			enemyshot[j].x = ene.x;
			enemyshot[j].y = ene.y;
			double speed = 3.0;//速度
			double dx = player.x - ene.x;//プレイヤーと敵のx方向の距離
			double dy = player.y - ene.y;//プレイヤーと敵のy方向の距離
			double d = sqrt(dx * dx + dy * dy);//敵とプレイヤーとの距離
			if (d <= 300) {
				enemyshot[j].vx = speed * (dx / d);//xの移動量
				enemyshot[j].vy = speed * (dy / d);//yの移動量
			}
			else if (d >= 300) {
				enemyshot[j].vx = speed;
				enemyshot[j].vy = speed;
			}
			enemyshot[j].enable = true;
			break;
		}
	}
}
//狙って撃つ
void aimShot(En ene)
{
	//弾を撃てる状態
//弾が無効なときのみ初期値をセットし有効にする
	for (int j = 0; j < EnemyShotNum; j++)
	{
		//撃てる弾をみつける
		if (enemyshot[j].enable == false) {
			//弾を撃つ
			enemyshot[j].x = ene.x;
			enemyshot[j].y = ene.y;
			double speed = 3.0;//速度
			double dx = player.x - ene.x;//プレイヤーと敵のx方向の距離
			double dy = player.y - ene.y;//プレイヤーと敵のy方向の距離
			double d = sqrt(dx * dx + dy * dy);//敵とプレイヤーとの距離
			enemyshot[j].vx = speed * (dx / d);//xの移動量
			enemyshot[j].vy = speed * (dy / d);//yの移動量
			enemyshot[j].enable = true;//判定が有効か否か
			break;
		}
	}
}
//爆発発生関数
void explosion(En ene)
{
	for (int i = 0; i < EffectNum; i++)
	{
		if (effe[i].enable == false)
		{
			effe[i].enable = true;
			effe[i].x = ene.x - 60;
			effe[i].y = ene.y - 60;
			effe[i].animeNo = 0;
			break;
		}
	}
}

//敵の更新
void updateEnemy()
{
	for (int i = 0; i < EnemyNum; i++) {
		if (enemy[i].enable == true) {
			//弾の種類に応じて
			if (enemyshot[i].type == ENEMY1)
			{
				enemy[i].vx = enemy[i].vx * 1, 02;
				enemy[i].vy = enemy[i].vy * 1, 02;
			}
			//敵を自動で動かす
			enemy[i].x = enemy[i].x + enemy[i].vx;
			enemy[i].y = enemy[i].y + enemy[i].vy;
			//弾を発射する
			if (canEnemyShot(enemy[i]))
			{
				if (enemy[i].type == ENEMY1) {
					straightShot(180, enemy[i]);//真っすぐ弾が飛ぶ
				}
				if (enemy[i].type == ENEMY2) {
					straightShot(200, enemy[i]);//左上に弾が飛ぶ
				}
				if (enemy[i].type == ENEMY3) {
					aimShot(enemy[i]);//プレイヤーを狙って弾が飛んでくる
				}
				if (enemy[i].type == ENEMY4) {
					tripleShot(160, enemy[i]);//3方向に弾が飛ぶ
					tripleShot(180, enemy[i]);
					tripleShot(200, enemy[i]);
				}
				if (enemy[i].type == ENEMY5) {
					twinShot(180, -5, enemy[i]);//真っすぐ2列で弾が飛んでくる
					twinShot(180, 5, enemy[i]);
				}
				if (enemy[i].type == ENEMY6) {
					straightShot(0, enemy[i]);//弾が敵を中心に放出される。
					straightShot(20, enemy[i]);
					straightShot(40, enemy[i]);
					straightShot(60, enemy[i]);
					straightShot(80, enemy[i]);
					straightShot(100, enemy[i]);
					straightShot(120, enemy[i]);
					straightShot(140, enemy[i]);
					straightShot(160, enemy[i]);
					straightShot(180, enemy[i]);
					straightShot(200, enemy[i]);
					straightShot(220, enemy[i]);
					straightShot(240, enemy[i]);
					straightShot(260, enemy[i]);
					straightShot(280, enemy[i]);
					straightShot(300, enemy[i]);
					straightShot(320, enemy[i]);
					straightShot(340, enemy[i]);
					straightShot(360, enemy[i]);
				}
				if (enemy[i].type == ENEMY7) {
					closerangeShot(enemy[i]);//プレイヤーに近いと、プレイヤーを狙って弾を打つ
				}
				enemy[i].cooltime = 100;//弾のクールタイム
			}
			if (isHit(player, enemy[i]) && BlackHole.enable == false)
			{
				if (AttackCoolTime == 0)
				{
					playerHp--;//プレイヤーのHPを減らす
					AttackCoolTime = 30;//アタッククールタイムを作る
					playerBar.x2--;
				}
				if (playerHp == 0)
				{
					gameOverFlag = true;//ゲームオーバーフラグを立てる
				}
			}
			if (AttackCoolTime > 0)
			{
				AttackCoolTime--;
			}
			for (int j = 0; j < ShotNum; j++) {
				//敵と弾との当たり判定
				if (shot[j].enable == true) {
					if (isHit(shot[j], enemy[i]))
					{
						//当たっている
						enemy[i].enable = false;//敵を無効
						shot[j].enable = false;//弾を無効
						PlaySoundMem(explodese, DX_PLAYTYPE_BACK);//爆破エフェクトの呼び出し
						p = p + 1;//ポイント+1
						explosion(enemy[i]);//爆発
						break;
					}
				}
			}
			//銃を冷やす処理
			if (enemy[i].cooltime > 0) {
				enemy[i].cooltime--;//クールタイムの処理
			}
		}
	}
}
//2ndの敵の更新
void updatesecondEnemy()
{
	if (enemy2[0].enable == false) {
		q++;//１フレームごとに１点加算
		if (q == 500) {
			scene = cria;
		}
	}
	for (int i = 0; i < EnemyNum; i++) {
		if (enemy2[i].enable == true) {
			//敵を自動で動かす
			if (enemy2[i].x >= 650) {
				enemy2[i].x = enemy2[i].x + enemy2[i].vx;
			}
			if (enemy2[i].x == 648) {
				enemy2[i].y = enemy2[i].y + enemy2[i].vy;
			}
			if (enemy2[i].y >= 600) {
				enemy2[i].vy = -2;
			}
			if (enemy2[i].y <= 0) {
				enemy2[i].vy = 2;
			}
			//弾を発射する
			if (canEnemyShot(enemy2[i]))
			{
				if (enemy2[i].type == ENEMY1) {
					straightShot(180, enemy2[i]);//
				}
				if (enemy2[i].type == ENEMY2) {
					straightShot(200, enemy2[i]);//
				}
				if (enemy2[i].type == ENEMY3) {
					aimShot(enemy2[i]);//
				}
				if (enemy2[i].type == ENEMY4) {
					tripleShot(160, enemy2[i]);//
					tripleShot(180, enemy2[i]);
					tripleShot(200, enemy2[i]);
				}
				if (enemy2[i].type == ENEMY5) {
					tripleShot(160, enemy2[i]);//
					tripleShot(180, enemy2[i]);
					tripleShot(200, enemy2[i]);
					twinShot(180, -5, enemy2[i]);//
					twinShot(180, 5, enemy2[i]);
				}
				if (enemy2[i].type == ENEMY6) {
					tripleShot(160, enemy2[i]);//
					tripleShot(180, enemy2[i]);
					tripleShot(200, enemy2[i]);
					twinShot(180, -5, enemy2[i]);//
					twinShot(180, 5, enemy2[i]);
					straightShot(0, enemy2[i]);//
					straightShot(20, enemy2[i]);
					straightShot(40, enemy2[i]);
					straightShot(60, enemy2[i]);
					straightShot(80, enemy2[i]);
					straightShot(100, enemy2[i]);
					straightShot(120, enemy2[i]);
					straightShot(140, enemy2[i]);
					straightShot(160, enemy2[i]);
					straightShot(180, enemy2[i]);
					straightShot(200, enemy2[i]);
					straightShot(220, enemy2[i]);
					straightShot(240, enemy2[i]);
					straightShot(260, enemy2[i]);
					straightShot(280, enemy2[i]);
					straightShot(300, enemy2[i]);
					straightShot(320, enemy2[i]);
					straightShot(340, enemy2[i]);
					straightShot(360, enemy2[i]);
				}
				if (enemy2[i].type == ENEMY7) {
					tripleShot(160, enemy2[i]);//
					tripleShot(180, enemy2[i]);
					tripleShot(200, enemy2[i]);
					twinShot(180, -5, enemy2[i]);//
					twinShot(180, 5, enemy2[i]);
					straightShot(0, enemy2[i]);//
					straightShot(20, enemy2[i]);
					straightShot(40, enemy2[i]);
					straightShot(60, enemy2[i]);
					straightShot(80, enemy2[i]);
					straightShot(100, enemy2[i]);
					straightShot(120, enemy2[i]);
					straightShot(140, enemy2[i]);
					straightShot(160, enemy2[i]);
					straightShot(180, enemy2[i]);
					straightShot(200, enemy2[i]);
					straightShot(220, enemy2[i]);
					straightShot(240, enemy2[i]);
					straightShot(260, enemy2[i]);
					straightShot(280, enemy2[i]);
					straightShot(300, enemy2[i]);
					straightShot(320, enemy2[i]);
					straightShot(340, enemy2[i]);
					straightShot(360, enemy2[i]);
					closerangeShot(enemy2[i]);//
				}if (enemy2[i].type == ENEMY8) {
				}
				enemy2[i].cooltime = 100;//
			}
			if (isHit(player, enemy2[i]) && BlackHole.enable == false)
			{
				if (AttackCoolTime == 0)
				{
					playerHp--;//プレイヤーのHPを減らす
					AttackCoolTime = 30;//アタッククールタイムを作る
					playerBar.x2--;
				}
				if (playerHp == 0)
				{
					gameOverFlag = true;//ゲームオーバーフラグを立てる
				}
			}
			if (AttackCoolTime > 0)
			{
				AttackCoolTime--;
			}
			for (int j = 0; j < ShotNum; j++) {
				//敵と弾との当たり判定
				if (shot[j].enable == true) {
					if (isHit(shot[j], enemy2[i]))
					{
						kisidahp--;
						shot[j].enable = false;//弾を無効
						//当たっている
						if (kisidahp == 0) {
							enemy2[i].enable = false;//敵を無効
							PlaySoundMem(explodese, DX_PLAYTYPE_BACK);//爆破エフェクトの呼び出し
							explosion(enemy2[i]);//爆発
							break;
						}
						break;
					}
				}
			}
			//銃を冷やす処理
			if (enemy2[i].cooltime > 0) {
				enemy2[i].cooltime--;//クールタイムの処理
			}
		}
	}
}
//1ndの敵の描画
void drawEnemy()
{
	for (int i = 0; i < EnemyNum; i++) {
		if (enemy[i].enable == true) {
			DrawGraph(enemy[i].x - 10, enemy[i].y - 30, enemyimg, true);//敵の描画
		}
	}
}
//2ndの敵の描画
void drawsecondEnemy()
{
	SetFontSize(20);
	for (int i = 0; i < EnemyNum; i++) {
		if (1 <= kisidahp && kisidahp <= 100 && scene == second) {
			DrawFormatString(320, 20, GetColor(25, 200, 0), "vs岸田：HP%d", kisidahp);
		}
		if (enemy2[i].enable == true) {
			DrawGraph(enemy2[i].x - 10, enemy2[i].y - 40, kisidaimg, true);
		}
		if (scene == second && 75 <= kisidahp && kisidahp <= 100) {
			DrawFormatString(100, 550, GetColor(255, 0, 0), "所詮下級戦士如きがこの第１００代内閣総理大臣\n岸田文雄を倒せるとでも思っているのか");
		}
		if (scene == second && 50 <= kisidahp && kisidahp <= 74) {
			DrawFormatString(100, 550, GetColor(255, 0, 0), "どうだ怖気着いたか？ならばくらえ！！HigherTax!!");
			//HigherTax 訳　増税
			enemy2[0].type = ENEMY5;
		}
		if (scene == second && 30 <= kisidahp && kisidahp <= 49) {
			DrawFormatString(100, 550, GetColor(255, 0, 0), "ふん　どうやら雑魚では無いらしいな");
			enemy2[0].type = ENEMY6;
		}if (scene == second && 1 <= kisidahp && kisidahp <= 29) {
			DrawFormatString(100, 550, GetColor(255, 0, 0), "この死に損ないが！４ね！");
			enemy2[0].type = ENEMY7;
		}if (scene == second && kisidahp <= 0) {
			DrawFormatString(100, 500, GetColor(255, 0, 0), "何ィ！？\nこの第１００代内閣総理大臣岸田文雄が負けるとはああああああああああああああああああああああああああああああああ");
			enemy2[0].type = ENEMY8;
		}if (scene == second && kisidahp <= 0 && q >= 100) {
			DrawFormatString(130, 20, GetColor(255, 0, 0), "安倍さん聞こえますか？");
		}if (scene == second && kisidahp <= 0 && q >= 200) {
			DrawFormatString(150, 50, GetColor(255, 0, 0), "オレ達から貴方への");
		}if (scene == second && kisidahp <= 0 && q >= 300) {
			DrawFormatString(150, 80, GetColor(255, 0, 0), "鎮魂曲<レクイエム>です");
		}
	}
}
//弾が撃てるか確認する関数
bool canEnemyShot(En enemy)
{
	//銃が冷えている
	if (enemy.cooltime <= 0) {
		if (enemy.x >= 0 &&
			enemy.x < 800 &&
			enemy.y>0 &&
			enemy.y < 600)
		{
			//画面の中にいる
			return true;
		}
	}
	//画面内にいない
	return false;
}