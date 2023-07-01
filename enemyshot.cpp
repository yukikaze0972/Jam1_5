#include "en.h"
#include "DxLib.h"
#include "enemyshot.h"
#include "player.h"
#include "game.h"



En enemyshot[EnemyShotNum];//’e
//’e‚Ì‰Šú‰»
void initEnemyShot()
{
	for (int i = 0; i < EnemyShotNum; i++) {
		enemyshot[i].r = 2;
		enemyshot[i].color = GetColor(0,255, 0);
		enemyshot[i].fill = true;
		enemyshot[i].enable = false;
	}
	
}


//’e‚ÌXV
void updateEnemyShot()
{
	//’e‚ª—LŒø‚È‚Æ‚«‚É’e‚ğ“®‚©‚·
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
		if (isHit(player, enemyshot[i]))
		{
			//“–‚½‚Á‚Ä‚¢‚é
			player.color = enemyshot[i].color;
			gameOverFlag = true;//ƒQ[ƒ€ƒI[ƒo[ƒtƒ‰ƒO‚ğ—§‚Ä‚é
		}
	}

}
//’e‚Ì•`‰æ
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