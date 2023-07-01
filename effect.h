#pragma once

const int EffectNum = 100;
extern int img[10];//最大１０コマ　画像
struct Effect
{
	double x;
	double y;
	double animeNo=0;
	double mazAnimeNo;
	bool enable = false;

};
extern Effect effe[EffectNum];//エフェクト用の変数
void initEffect();
void updateEffect();
void drawEffect();