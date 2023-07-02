#include "en.h"
#include "DxLib.h"
#include "enemyshot.h"
#include "player.h"
#include "game.h"
#include "shot.h"


int AttackCoolTime;
En enemyshot[EnemyShotNum];//弾
//弾の初期化
void initEnemyShot()
{
	for (int i = 0; i < EnemyShotNum; i++) {
		enemyshot[i].r = 2;
		enemyshot[i].color = GetColor(0,255, 0);
		enemyshot[i].fill = true;
		enemyshot[i].enable = false;
	}
	
}


//弾の更新
void updateEnemyShot()
{
	//弾が有効なときに弾を動かす
	for (int i = 0; i < EnemyShotNum; i++)
	{
		if (enemyshot[i].enable == true) {
			enemyshot[i].x = enemyshot[i].x + enemyshot[i].vx;
			enemyshot[i].y = enemyshot[i].y + enemyshot[i].vy;
			if (enemyshot[i].x >= 800 ||
				enemyshot[i].x < 0 ||
				enemyshot[i].y >= 600 ||
				enemyshot[i].y < 0) 
			{
				enemyshot[i].enable = false;
			}
		}
		if (isHit(player, enemyshot[i]) && BlackHole.enable == false)
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
	}

}
//弾の描画
void drawEnemyShot()
{
	for (int i = 0; i < EnemyShotNum; i++) {
		if (enemyshot[i].enable == true)
		{
			SetDrawBlendMode(DX_BLENDMODE_ALPHA, 127);
			DrawCircle(enemyshot[i].x, enemyshot[i].y, enemyshot[i].r*5, enemyshot[i].color, enemyshot[i].fill);
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
			DrawCircle(enemyshot[i].x, enemyshot[i].y, enemyshot[i].r, enemyshot[i].color, enemyshot[i].fill);
			
		}
	}
}