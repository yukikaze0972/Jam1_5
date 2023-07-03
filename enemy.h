#pragma once
#include "en.h"
const int EnemyNum = 300;//“G‚Ì”
extern En enemy[EnemyNum];//“G
extern En enemy2[EnemyNum];//“G
extern int enemy1img;
extern int enemy2img;
extern int kisidaimg;
extern int kisidahp;
void initEnemy();//“G‚Ì‰Šú‰»
void updateEnemy();//“G‚ÌXV
void updatesecondEnemy();
void secondupdateEnemy();
void drawEnemy();//“G‚Ì•`‰æ
void drawsecondEnemy();//“G‚Ì•`‰æ
void seconddrawEnemy();
bool canEnemyShot(En enemy);//’e‚ªŒ‚‚Ä‚é‚©Šm”F
void straightShot(int rad, En ene);//^‚Á‚·‚®Œ‚‚Â
void aimShot(En ene);//‘_‚Á‚ÄŒ‚‚Â
void tripleShot(int rad, En ene);
void twinShot(int rad, int shifty, En ene);
void closerangeShot();
void explosion(En ene);//”š”j”­¶ŠÖ”