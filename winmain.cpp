#include "DxLib.h"
#include "player.h"
#include "shot.h"
#include "enemyshot.h"
#include "enemy.h"
#include "en.h"
#include "game.h"
#include "effect.h"
#include "bgsprite.h"

void init();//初期化関数のプロトタイプ宣言
void explanationUpdate();//タイトル後の説明画面
void titleUpdate();//タイトルシーンの更新関数
void criaUpdate();//クリア画面
void update();//更新関数のプロトタイプ宣言
void draw();//描画処理
void roundUpdate();//1ndと2ndの間のシーン
void Updatesecond();//2ndステージ
void gameoverUpdate();//ゲームオーバー画面

//シーンのenumを定義

GameScene scene = Title; //シーン変数
int TitleLogo; //タイトルロゴ
int press;//プッシュロゴS
int next;//ネクストステージロゴ
int space;//プッシュスペースのロゴ
int end;//エンドエンターロゴ
int bg0;
int bg1;
int bg2;
int gameover2;
int explanationbg;
int RO;
int rond;


// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	//DXライブラリの初期化処理 ここから
	ChangeWindowMode(TRUE);	//ウィンドウモードにする
	SetGraphMode(800, 600, 32);	//ウィンドウサイズを設定する
	if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
	{
		return -1;			// エラーが起きたら直ちに終了
	}
	SetDrawScreen(DX_SCREEN_BACK);	//裏画面を描画対象へ
	//DXライブラリの初期化処理 ここまで

	init();//初期化処理の呼び出し　起動時一度だけ呼び出す

	//メインループ処理
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0) {
		if (scene == Title) {
			titleUpdate();//タイトル更新処理
		}
		else if (scene == explanation) {
			explanationUpdate();//ゲーム更新処理の呼び出し
		}
		else if (scene == Game) {
			update();//ゲーム更新処理の呼び出し
		}
		else if (scene == stand) {
			roundUpdate();//1ndと2ndの間のシーン
		}
		else if (scene == second) {
			Updatesecond();//2ndのゲーム更新処理
		}
		else if (scene == cria) {
			criaUpdate();//クリア画面の更新処理
		}
		else if (scene == gameover) {
			gameoverUpdate();//ゲームオーバーの更新処理
		}

		

		ScreenFlip();		//裏画面と表画面の入替
		ClearDrawScreen();	//裏画面の描画を全て消去
	}
	//メインループ処理ここまで

	DxLib_End();			// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}
//初期化関数　引数、戻り値なし
void init()
{
	initGame();
	TitleLogo = LoadGraph("cooltext437633513189197.png");//タイトルロゴの画像
	press= LoadGraph("cooltext437636616251046.png");//プッシュロゴの画像
	next= LoadGraph("Cool Text - next stage 438643731255705.png");//ネクストステージロゴの画像
    end= LoadGraph("Cool Text - end enter 438643686421366.png");//エンドエンターのロゴ画像
	space = LoadGraph("Cool Text - push space 438650699222967.png");//プッシュスペースのロゴ画像
	bg0=LoadGraph("titler image .png");
	bg1 = LoadGraph("gameover2.png");
	bg2 = LoadGraph("niko5.jpg");
	gameover2 = LoadGraph("cooltext438730459234063.png");
	explanationbg= LoadGraph("image (9).png");
	RO= LoadGraph("cooltext438733569129930.png");
	rond = LoadGraph("cooltext438730777439596.png");
	
	initPlayer();//プレイヤーの初期化
	
	initShot();//弾の初期化

	initEnemyShot();//敵の弾の初期化

	
	initEnemy();//敵の初期化処理

	initEffect();//エフェクトの初期化

	initBg();//背景スプライトの初期化
	
	//PlayMusic("maou_bgm_8bit26.mp3", DX_PLAYTYPE_LOOP);//BGM
		PlayMusic("taitoru.mp3", DX_PLAYTYPE_LOOP);//BGM
}
//タイトルの更新関数
void titleUpdate()
{
	if (CheckHitKey(KEY_INPUT_RETURN) == 1)
	{
		//タイトル画像の描画
		scene = explanation;//Gameシーンへの切り替え
		//PlayMusic("sentou.mp3", DX_PLAYTYPE_LOOP);
		//PlayMusic("DEEP IN THE HEATWAVE  SOUND HOLIC　Vo 小寺可南子(THE ARCADE EDIT).mp3", DX_PLAYTYPE_LOOP);
		PlayMusic("maou_se_8bit24.mp3", DX_PLAYTYPE_BACK);
		//PlayMusic("DEEP IN THE HEATWAVE  SOUND HOLIC　Vo 小寺可南子(THE ARCADE EDIT).mp3", DX_PLAYTYPE_LOOP);
		//PlayMusic("sentou.mp3", DX_PLAYTYPE_LOOP); 
	}
	DrawGraph(0, 0, bg0, true);
	DrawGraph(280, 350, press, true);//プッシュロゴの表示設定
	DrawGraph(100, 250, TitleLogo, true);//タイトルロゴの表示設定

}

void explanationUpdate()
{
	if (CheckHitKey(KEY_INPUT_SPACE) == 1)
	{
		scene = Game;//Gameシーンへの切り替え
		//PlayMusic("DEEP IN THE HEATWAVE  SOUND HOLIC　Vo 小寺可南子(THE ARCADE EDIT).mp3", DX_PLAYTYPE_LOOP);
		PlayMusic("sentou.mp3", DX_PLAYTYPE_LOOP);
		PlayMusic("sentou.mp3", DX_PLAYTYPE_LOOP);
	}
	DrawGraph(0, 0, explanationbg, true);
	DrawGraph(270, 250,RO , true);
	DrawGraph(280, 360, space, true);
}


//ゲームオーバーの更新関数
void gameoverUpdate()
{
	if (CheckHitKey(KEY_INPUT_SPACE) == 1)
	{
		scene = Title;

		gameOverFlag = false;//ゲームオーバーの無効

		t = 0;//タイムの初期化

		p = 0;//ポイントの初期化

		initPlayer();//プレイヤーの初期化

		initShot();//弾の初期化

		initEnemyShot();//敵の弾の初期化


		initEnemy();//敵の初期化処理

		initEffect();//エフェクトの初期化

		initBg();//背景スプライトの初期化
	}
	DrawFormatString(310, 250, GetColor(255, 0, 0), "ゆーあーでっと");//ゲームオーバー時の文字の表示
	DrawFormatString(320, 275, GetColor(255, 255, 0), "タイム %d 点", t);//タイムの表示設定
	DrawFormatString(320, 300, GetColor(255, 255, 0), "スコア %d 点", p);//スコアの表示設定
	DrawGraph(0, 0, bg1, true);
	DrawGraph(200, 190, gameover2, true);
	DrawGraph(260, 350, space, true);
	PlayMusic("maou_bgm_healing16.mp3", DX_PLAYTYPE_LOOP);//ゲームオーバー時に流す予定のBGMですが、現在機能していません
}
//1ndと2ndの間のシーンの更新関数
void roundUpdate()
{
	if (CheckHitKey(KEY_INPUT_RETURN) == 1)
	{
		scene = second;
		for (int i = 0; i < EnemyShotNum; i++)
		{
			enemyshot[i].enable = false;//1nd目の敵の弾を消す処理
		}
		for (int i = 0; i < ShotNum; i++)
		{
			shot[i].enable = false;//1nd目の自機の弾を消す処理
		}
		for (int i = 0; i < EffectNum; i++)
		{
			effe[i].enable = false;//1ndのエフェクトを消す処理
		}
		for (int i = 0; i < EnemyNum; i++)
		{
			enemy[i].enable = false;
		}
		BlackHole.enable = false;
		LightRaysTrigger = false;
		LightRaysDuration = 0;
		for (int i = 0; i < LightRaysShotNum; i++)
		{
			LightRays[i].enable = false;
		}
	}
	DrawGraph(0, 0, bg2, true);
	DrawGraph(200, 190,rond , true);
	DrawFormatString(320, 275, GetColor(255, 255, 0), "タイム %d 点", t);
	DrawFormatString(320, 300, GetColor(255, 255, 0), "スコア %d 点", p);
	DrawGraph(200, 350, next, true);
}
//クリア画面の更新関数
void criaUpdate()
{

	if (CheckHitKey(KEY_INPUT_SPACE) == 1)
	{
		scene = Title;

		gameOverFlag = false;//ゲームオーバーの無効

		t = 0;//タイムの初期化

		p = 0;//ポイントの初期化

		initPlayer();//プレイヤーの初期化

		initShot();//弾の初期化

		initEnemyShot();//敵の弾の初期化


		initEnemy();//敵の初期化処理

		initEffect();//エフェクトの初期化

		initBg();//背景スプライトの初期化
	}
	PlayMusic("maou_bgm_healing16.mp3", DX_PLAYTYPE_LOOP);//クリア時のBGM予定でしたが現在機能していません
	DrawFormatString(310, 250, GetColor(255, 0, 0), "ゲームクリア");//ゲームクリア時の文字の表示
	DrawFormatString(320, 275, GetColor(255, 255, 0), "タイム %d 点", t);//タイムの表示
	DrawFormatString(320, 300, GetColor(255, 255, 0), "スコア %d 点", p);//スコアの表示
	DrawGraph(200, 190, next, true);
	DrawGraph(260, 350, space, true);
}
//更新関数
	void update()
{
	
	updateGame();//ゲーム(審判)の更新

	
	updatePlayer();//プレイヤーの更新
	
	updateShot();//弾の更新
	BlackHoleShot();
	LightRaysShot();

	updateEnemyShot();//敵の弾の更新

	updateEnemy();//敵の更新

	updateEffect();//エフェクトの更新
	
	updateBg();//背景スプライトの描画

	draw();//描画処理

	
	
}
//2ndの更新関数
void Updatesecond()
{
	secondUpdate();//2nd目のゲームの更新

	updatePlayer();//プレイヤーの更新

	updateShot();//弾の更新
	BlackHoleShot();
	LightRaysShot();

	updateEnemyShot();//敵の弾の更新

	updatesecondEnemy();//2nd目の敵の更新

	updateEffect();//エフェクトの更新

	updateBg();//背景スプライトの描画

	draw();//描画処理
}
//描画処理
void draw()
{

	drawBg();//背景の描画
	
	drawEnemy();//敵の描画

	drawsecondEnemy();//敵の描画
	
	drawPlayer();//プレイヤーの描画
	
	drawShot();//弾の描画

	drawEnemyShot();//敵の弾の描画

	drawEffect();//エフェクトの描画

	drawGame();//ゲーム関連の描画
}
