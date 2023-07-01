#pragma once
enum GameScene
{
	Title,
	Game,
	stand,
	second,
	gameover,
	cria
};
extern int score;//点数
extern int b;
extern int p;
extern int t;
extern bool gameOverFlag;//ゲームオーバー判定
extern GameScene scene;
void updateGame();//ゲーム内容の更新
void drawGame();//ゲーム関連の描画
void secondUpdate();
