#include "DxLib.h"
#include "bgsprite.h"
int bgimg0;//背景画像1
int bgimg1;//背景画像2
int bgimg2;//背景画像3
double scrollX1 = 0.0;//スクロールの関数
double scrollX2 = 800.0;//スクロールの関数
double scrollX3 = 0.0;//スクロールの関数
double scrollX4 = 800.0;//スクロールの関数
//背景スプライトの初期化
void initBg()
{
	bgimg0 = LoadGraph("IMG_6884 (1).jpg");//背景画像1
	bgimg1 = LoadGraph("IMG_6884 (1).jpg");//背景画像2
	bgimg2 = LoadGraph("IMG_6884 (1).jpg");//背景画像3

}
//背景移動の処理
double scroll(double x, double speed)//スクロールの位置とスピードの関数
{
	x = x - speed;//背景の進むスピード
	if (x <= -800.0)//画像1枚分左にズレたら
	{

		x = x + 1600.0;//画像2枚分右に戻す
	}
	return x;
}
//背景スプライトの更新
void updateBg()
{
	//スクロール
	scrollX1 = scroll(scrollX1, 1.0);//スクロールの関数
	scrollX2 = scroll(scrollX2, 1.0);//スクロールの関数

	scrollX3 = scroll(scrollX3, 1.0);//スクロールの関数
	scrollX4 = scroll(scrollX4, 1.0);//スクロールの関数
}
//背景の描画
void drawBg()
{
	DrawGraph(scrollX1, 0, bgimg0, true);//背景画像1のスクロール
	DrawGraph(scrollX2, 0, bgimg1, true);//背景画像2のスクロール
	DrawGraph(scrollX3, 0, bgimg2, true);//背景画像3のスクロール
}