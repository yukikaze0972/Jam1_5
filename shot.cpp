#include "en.h"
#include "DxLib.h"
#include "shot.h"


En shot[ShotNum];//’e
//’e‚Ì‰Šú‰»
void initShot()
{
	for (int i = 0; i < ShotNum; i++) {
		shot[i].r = 5;
		shot[i].color = GetColor(255, 255, 0);
		shot[i].fill = true;
		shot[i].vx = 1.0;
		shot[i].vy = 0.0;
		shot[i].enable = false;
	}
}
//’e‚ÌXV
void updateShot()
{
	//’e‚ª—LŒø‚È‚Æ‚«‚É’e‚ğ“®‚©‚·
	for (int i = 0; i < ShotNum; i++)
	{
		if (shot[i].enable == true) {
			shot[i].x = shot[i].x + shot[i].vx;
			shot[i].y = shot[i].y + shot[i].vy;
			if (shot[i].x >= 800) {
				shot[i].enable = false;
			}
		}
	}
}
//’e‚Ì•`‰æ
void drawShot()
{
	for (int i = 0; i < ShotNum; i++) {
		if (shot[i].enable == true)
		{
			SetDrawBlendMode(DX_BLENDMODE_ALPHA, 127);
			DrawCircle(shot[i].x, shot[i].y, shot[i].r*5, shot[i].color, shot[i].fill);
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
			DrawCircle(shot[i].x, shot[i].y, shot[i].r, shot[i].color, shot[i].fill);
		}
	}
}