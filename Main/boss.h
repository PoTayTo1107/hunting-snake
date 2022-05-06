#pragma once
#include "mylib.h"
#include "snake.h"
#pragma comment(lib, "winmm.lib")
struct SNAKE
{
	int x;
	int y;
	//int col; // 1 -> 10
	int goleft;
	int goright;
};


struct BULLET
{
	int x;
	int y;
	int appearance;
};

struct FIREBALL
{
	int x, y;
	int appearance;
};

struct DRAGON
{
	int x;
	int y;
	int goright, goleft;
	int countdown;
	int life;
};



void BOSSMap(char* ten_nguoi_choi, int x, int y, int vung_ran_di_chuyen_dai, int bang_diem_dai, int rong, int& man, int& diem, int soundOn);
void DrawSnake(SNAKE& snake);
void DeleteTheOldSnake(int oldx, int oldy);
void Move(SNAKE& snake);
void FlyingBullet(BULLET& bullet);
void FlyingFireball(FIREBALL& fireball);
void DragonStart(DRAGON& dragon);
void DrawDragon(DRAGON dragon);
// delete the previous dragon
void DeleteTheOldDragon(int oldx, int oldy);
// Move
void DragonMoving(DRAGON& dragon);
int DEAD(FIREBALL fireball, SNAKE snake);
int DragonDead(DRAGON& dragon, BULLET bullet, int soundOn);
void DragonHP(int x, int y, int HP);
