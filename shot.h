#pragma once
#include "en.h"

const int ShotNum = 100;
const int LightRaysShotNum = 1800;
extern En shot[ShotNum];//’e
extern En BlackHole;
extern En LightRays[LightRaysShotNum];
extern int BlackHoleDuration;
extern int LightRaysDuration;
extern bool LightRaysTrigger;
bool canLightRaysShot(En player);

void initShot();//’e‚Ì‰Šú‰»
void updateShot();//’e‚ÌXV
void BlackHoleShot();
void LightRaysShot();
void LightRaysShot_moto();
void drawShot();