#include "effect.h"
#include "DxLib.h"
Effect effe[EffectNum];//エフェクト用の変数
int img[10];//最大１０コマ　画像
//エフェクトの初期化
void initEffect()
{

	LoadDivGraph("effect.png", 5, 5, 1, 120, 120, img);//画像の読み込み
}
//エフェクトの更新
void updateEffect()
{
	for (int i = 0; i < EffectNum; i++) {
		if (effe[i].enable == true)
		{
			
			effe[i].animeNo = effe[i].animeNo + 0.1;//アニメーションを進める
			
			if ((int)(effe[i].animeNo) > 5) {//６コマ目になったら終了
				effe[i].enable = false;//エフェクトを消す処理
			}
		}
	}
}
//エフェクトの描画
void drawEffect()
{
	for (int i = 0; i < EffectNum; i++) {
		if (effe[i].enable == true)
		{
			int no = effe[i].animeNo;//エフェクトのコマ数
			DrawGraph(effe[i].x, effe[i].y, img[no],true);//エフェクトの描画
		}
	}
}