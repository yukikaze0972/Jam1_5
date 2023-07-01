#include "DxLib.h"
#include "game.h"
#include"en.h"
#include "player.h"
#include "effect.h"

//ゲーム関連の情報
int score = 0;//点数
int t = 0;
int p = 0;
int b = 0;
bool gameOverFlag = false;//ゲームオーバー判定

//ゲーム内容の更新
void updateGame()
{
	if (gameOverFlag == false) {
		score++;//１フレームごとに１点加算
	}
	if (score == 100) {
		t = t + 1;
		score = 0;
	}
	if (t >= 10) {
		scene = stand;
		
	}
	if (p >= 2) {
		scene = stand;
		
	}
	
}
void secondUpdate()
{
	if (gameOverFlag == false) {
		score++;//１フレームごとに１点加算
	}
	if (score == 100) {
		t = t + 1;
		score = 0;
	}
	if (t >=20)
	{
		scene = cria;
	}
	if (p >= 4)
	{
		scene = cria;
	}
}

//ゲーム情報の描画
void drawGame()
{

	DrawFormatString(0, 0, GetColor(255, 255, 0), "タイム %d 点", t);
	DrawFormatString(0, 20, GetColor(255, 255, 0), "スコア %d 点", p);
	if (gameOverFlag == true) {
		scene = gameover;
		
		//DrawFormatString(350, 300, GetColor(255, 0, 0), "ゲームオーバー");
	}
	
}