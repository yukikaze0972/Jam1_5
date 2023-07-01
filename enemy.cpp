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

//敵の初期化
void initEnemy()
{
	//爆破エフェクト
	explodese = LoadSoundMem("maou_se_battle_explosion05.mp3");

	//敵の画像
	enemyimg = LoadGraph("teki (1).png");

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
	enemy[2].x = 2000;//敵のX座標
	enemy[2].y = 200;//敵のY座標
	enemy[2].r = 30;//敵の大きさ
	enemy[2].color = GetColor(255, 0, 0);//敵の色
	enemy[2].fill = true;//塗りつぶすか否か
	enemy[2].enable = true;//生きているか死んでいるか
	enemy[2].vx = -2.0;//X方向のスピード
	enemy[2].vy = 0.0;//Y方向のスピード
	enemy[2].type = ENEMY3;//弾の種類


	//2ステージ目の敵
	//1体目の敵
	enemy2[0].x = 900;//敵のX座標
	enemy2[0].y = 400;//敵のY座標
	enemy2[0].r = 30;//敵の大きさ
	enemy2[0].color = GetColor(255, 0, 0);//敵の色
	enemy2[0].fill = true;//塗りつぶすか否か
	enemy2[0].enable = true;//生きているか死んでいるか
	enemy2[0].vx = -2.0;//X方向のスピード
	enemy2[0].vy = 0.0;//Y方向のスピード
	enemy2[0].type = ENEMY4;//弾の種類

	//2体目の敵
	enemy2[1].x = 1500;//敵のX座標
	enemy2[1].y = 300;//敵のY座標
	enemy2[1].r = 30;//敵の大きさ
	enemy2[1].color = GetColor(255, 0, 0);//敵の色
	enemy2[1].fill = true;//塗りつぶすか否か
	enemy2[1].enable = true;//生きているか死んでいるか
	enemy2[1].vx = -2.0;//X方向のスピード
	enemy2[1].vy = 0.0;//Y方向のスピード
	enemy2[1].type = ENEMY5;//弾の種類

	//3体目の敵
	enemy2[2].x = 2200;//敵のX座標
	enemy2[2].y = 500;//敵のY座標
	enemy2[2].r = 30;//敵の大きさ
	enemy2[2].color = GetColor(255, 0, 0);//敵の色
	enemy2[2].fill = true;//塗りつぶすか否か
	enemy2[2].enable = true;//生きているか死んでいるか
	enemy2[2].vx = -2.0;//X方向のスピード
	enemy2[2].vy = 0.0;//Y方向のスピード
	enemy2[2].type = ENEMY6;//弾の種類

	
}
//真っすぐ弾を撃つ
void straightShot(int rad,En ene)
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

void tripleShot(int rad,  En ene)
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

void twinShot( int rad, int shifty,En ene)
{
	for (int j = 0; j < EnemyShotNum; j++)
	{
		//撃てる弾をみつける
		if (enemyshot[j].enable == false) {
			//弾を撃つ
			enemyshot[j].x = ene.x;
			enemyshot[j].y = ene.y+shifty;
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
				enemy[i].vx= enemy[i].vx*1,02;
				enemy[i].vy= enemy[i].vy*1,02;
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
					twinShot(180,-5, enemy[i]);//真っすぐ2列で弾が飛んでくる
					twinShot(180,5,enemy[i]);
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
		
			if (isHit(player, enemy[i]))
			{
				player.color = enemy[i].color;//当たっている
				gameOverFlag = true;//ゲームオーバーフラグを立てる
			}
		
			for (int j = 0; j < ShotNum; j++) {
				//敵と弾との当たり判定
				if (shot[j].enable == true) {
					if (isHit(shot[j], enemy[i]))
					{
						//当たっている
						enemy[i].enable = false;//敵を無効
						shot[j].enable = false;//弾を無効
						PlaySoundMem(explodese,DX_PLAYTYPE_BACK);//爆破エフェクトの呼び出し
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
	for (int i = 0; i < EnemyNum; i++) {
		if (enemy2[i].enable == true) {
			//弾の種類に応じて
			if (enemyshot[i].type == ENEMY1)
			{
				enemy2[i].vx = enemy2[i].vx * 1, 02;
				enemy2[i].vy = enemy2[i].vy * 1, 02;
			}
			//敵を自動で動かす
			enemy2[i].x = enemy2[i].x + enemy2[i].vx;
			enemy2[i].y = enemy2[i].y + enemy2[i].vy;

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
					twinShot(180, -5, enemy2[i]);//
					twinShot(180, 5, enemy2[i]);
				}
				if (enemy2[i].type == ENEMY6) {
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
					closerangeShot(enemy2[i]);//
				}

				enemy2[i].cooltime = 100;//
			}

			if (isHit(player, enemy2[i]))
			{
				
				player.color = enemy2[i].color;//当たっている
				gameOverFlag = true;//ゲームオーバーフラグを立てる
			}

			for (int j = 0; j < ShotNum; j++) {
				//敵と弾との当たり判定
				if (shot[j].enable == true) {
					if (isHit(shot[j], enemy2[i]))
					{
						//当たっている
						enemy2[i].enable = false;//敵を無効
						shot[j].enable = false;//弾を無効
						PlaySoundMem(explodese, DX_PLAYTYPE_BACK);//爆破エフェクトの呼び出し
						p = p + 1;//ポイント+1
						explosion(enemy2[i]);//爆発
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
			DrawGraph(enemy[i].x-10, enemy[i].y-40, enemyimg,true);//敵の描画
		}
	}
}
//2ndの敵の描画
void drawsecondEnemy()
{
	for (int i = 0; i < EnemyNum; i++) {
		if (enemy2[i].enable == true) {
			DrawGraph(enemy2[i].x - 10, enemy2[i].y - 40, enemyimg, true);//敵の描画
		}
	}
}
//弾が撃てるか確認する関数
bool canEnemyShot(En enemy)
{
	//銃が冷えている
	if (enemy.cooltime <= 0) {
		if(enemy.x >=0 &&
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