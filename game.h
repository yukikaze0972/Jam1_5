#pragma once
#include "en.h"

enum GameScene
{
	Title,
	Game,
	stand,
	second,
	gameover,
	cria
};
extern Box playerBar;
extern Box playerBarBox;
extern int score;//点数
extern int b;
extern int p;
extern int t;
extern int selectbomb;
extern bool gameOverFlag;//ゲームオーバー判定
extern GameScene scene;
void initGame();
void updateGame();//ゲーム内容の更新
void drawGame();//ゲーム関連の描画
void secondUpdate();
void SelectBomb();