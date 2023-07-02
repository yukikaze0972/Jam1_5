#pragma once
#include "en.h"

const int EnemyShotNum = 1100;
extern En enemyshot[EnemyShotNum];//’e
extern int AttackCoolTime;

void initEnemyShot();//’e‚Ì‰Šú‰»
void updateEnemyShot();//’e‚ÌXV
void drawEnemyShot();