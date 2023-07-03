#include "en.h"
#include "DxLib.h"
#include "shot.h"
#include "player.h"
#include "game.h"

En player;//プレイヤー
int shotse;
int daison;
int masupa;
int playerHp;
bool LightRaysTrigger;
//プレイヤーの初期化
void initPlayer()
{
	player.x = 100;
	player.y = 200;
	player.r = 10;
	player.color = GetColor(255, 255, 255);
	player.fill = true;
	player.cooltime = 0;
	shotse = LoadSoundMem("maou_se_battle07.mp3");
	daison = LoadSoundMem("daison.mp3");
	masupa = LoadSoundMem("masupa.mp3");
	playerimg= LoadGraph("UFO.png");

	playerHp = 100;
	LightRaysTrigger = false;
	playerBar.x1 = 550;
	playerBar.x2 = 750;
	playerBar.y1 = 20;
	playerBar.y2 = 50;
	playerBar.color = GetColor(255, 255, 255);
	playerBar.fill = true;

}

//プレイヤーの更新
void updatePlayer()
{
	//プレイヤーを動かす
	if (CheckHitKey(KEY_INPUT_D) == 1)
	{
		player.x = player.x + 2.0;
	}
	if (CheckHitKey(KEY_INPUT_A) == 1)
	{
		player.x = player.x - 2.0;
	}
	if (CheckHitKey(KEY_INPUT_W) == 1)
	{
		player.y = player.y - 2.0;
	}
	if (CheckHitKey(KEY_INPUT_S) == 1)
	{
		player.y = player.y + 2.0;
	}
	if (player.x < 0) {
		//もし左端に出たら
		player.x = 0;
	}
	if (player.x >= 800) {
		//もし右端に出たら
		player.x = 800;
	}
	if (player.y < 0) {
		//もし左端に出たら
		player.y = 0;
	}
	if (player.y >= 600) {
		//もし右端に出たら
		player.y = 600;
	}

	//弾を撃つ処理
	if (CheckHitKey(KEY_INPUT_SPACE) == 1 &&
		player.cooltime <= 0 && selectbomb == 0)
	{
		//弾が無効なときのみ初期値をセットし有効にする
		for (int i = 0; i < ShotNum; i++)
		{
			//撃てる弾をみつける
			if (shot[i].enable == false) {
				//弾を撃つ
				shot[i].x = player.x;
				shot[i].y = player.y;
				shot[i].enable = true;
				player.cooltime = 30;//連射速度　小さいほど連射できる
				PlaySoundMem(shotse, DX_PLAYTYPE_BACK);
				break;
			}
		}
	}

	if (CheckHitKey(KEY_INPUT_SPACE) == 1 && selectbomb == 1 && BlackHole.enable == false)
	{
		BlackHole.x = player.x;
		BlackHole.y = player.y;
		BlackHoleDuration = 1000;
		BlackHole.enable = true;
		PlaySoundMem(daison, DX_PLAYTYPE_BACK);
	}

	if (CheckHitKey(KEY_INPUT_SPACE) == 1 && selectbomb == 2 && LightRaysTrigger == false)
	{
		LightRaysDuration = 300;
		LightRaysTrigger = true;
		PlaySoundMem(masupa, DX_PLAYTYPE_BACK);
	}
	//銃を冷やす処理
	if (player.cooltime > 0) {
		player.cooltime--;
	}
}

//プレイヤーの描画
void drawPlayer()
{
	DrawGraph(player.x-40, player.y-30, playerimg,true);

}