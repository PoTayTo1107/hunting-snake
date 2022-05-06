#include "boss.h"
#include "savegame.h"
#include "bangdiem.h"
#include <iostream>
using namespace std;

void BOSSMap(char* ten_nguoi_choi, int x, int y, int vung_ran_di_chuyen_dai, int bang_diem_dai, int rong, int& man, int& diem, int soundOn)
{
	resizeConsole(1600, 900);
	noCursorType();//Xóa con tr?(d?u nháy)
	//v? vùng r?n di chuy?n
	ve_vung_ran_di_chuyen(x, y, vung_ran_di_chuyen_dai, rong);
	//v? b?ng ?i?m
	ve_bang_diem(x + vung_ran_di_chuyen_dai + 1, y, bang_diem_dai, rong, man);
	ve_diem(diem, x + vung_ran_di_chuyen_dai + 2, y + 2, ten_nguoi_choi); // v? ?i?m;

	// Khai bao
	SNAKE snake;
	BULLET bullet;
	DRAGON dragon;

	// Play
	snake.goright = 0;
	snake.goleft = 0;
	snake.x = 30;
	snake.y = 31;
	DrawSnake(snake);

	bullet.appearance = 0;

	dragon.x = 65;
	dragon.y = 4;
	dragon.goright = 0;
	dragon.goleft = 0;
	dragon.countdown = 200;
	dragon.life = 50;
	DrawDragon(dragon);

	FIREBALL fireball;
	fireball.appearance = 1;
	fireball.x = dragon.x + 7;
	fireball.y = dragon.y + 7;

	// Press A or D to Start
	while (1)
	{
		if (_kbhit())
		{
			char button = _getch();
			if (button == 'a')
			{
				snake.goright = 0;
				snake.goleft = 1;
				DragonStart(dragon);
			}
			else if (button == 'd')
			{
				snake.goright = 1;
				snake.goleft = 0;
				DragonStart(dragon);
			}
			else if (button == 's')
			{
				if (bullet.appearance == 0)
				{
					bullet.appearance = 1;
					bullet.x = snake.x + 3;
					bullet.y = snake.y - 3;
				}

			}
		}

		FlyingBullet(bullet);

		if (snake.goleft + snake.goright > 0)
		{
			Move(snake);
		}

		DragonMoving(dragon);

		if (fireball.appearance == 0)
		{
			fireball.appearance = 1;
			fireball.x = dragon.x + 7;
			fireball.y = dragon.y + 7;
		}
		FlyingFireball(fireball);

		// Kiem tra SNAKE DEAD
		if (DEAD(fireball, snake) == 1)
		{
			system("cls");
			ManHinhThua(25, 15);
			gotoXY(3, 36);
			system("pause");
			system("cls");
			//L?u thông tin ng??i ch?i (N?u n?m trong top 5 ng??i ?i?m cao nh?t)
			LuuDanhSachNguoiChoiDiemCaoNhat(ten_nguoi_choi, diem);
			man = 0;
			break;
		}
		// Kiem Tra Dragon -LIFE
		if (DragonDead(dragon, bullet, soundOn) == 1)
		{
			diem += 50;
			man++;
			LuuDanhSachNguoiChoiDiemCaoNhat(ten_nguoi_choi, diem);
			break;
		}

		gotoXY(6, 1);
		cout << "Dragon 's Life: ";
		DragonHP(36, 1, dragon.life);
		Sleep(20);
	}
	setTextColor(7);
}

//  **********************************************************************
//  **********************************************************************
//  **********************************************************************
//  **********************************************************************


void DrawSnake(SNAKE& snake)
{
	setTextColor(3);
	gotoXY(snake.x, snake.y); cout << "  _----_  ";
	gotoXY(snake.x, snake.y + 1); cout << " (      ) ";
	gotoXY(snake.x, snake.y + 2); cout << "|  0  0  |";
	gotoXY(snake.x, snake.y + 3); cout << "|        |";
}


void DeleteTheOldSnake(int oldx, int oldy)
{
	gotoXY(oldx, oldy); cout << " ";
	gotoXY(oldx, oldy + 1); cout << "          ";
	gotoXY(oldx, oldy + 2); cout << "          ";
	gotoXY(oldx, oldy + 3); cout << "          ";
}

void Move(SNAKE& snake)
{
	// delete the previous snake
	int oldx = snake.x;
	int oldy = snake.y;
	if (snake.goright + snake.goleft > 0)
	{
		DeleteTheOldSnake(oldx, oldy);
	}

	//
	if (snake.goright == 1)
	{
		if (snake.x < 100)
		{
			snake.x++;
		}
		else if (snake.x == 100)
		{
			snake.x = 99;
			snake.goleft = 1;
			snake.goright = 0;
		}
	}
	else if (snake.goleft == 1)
	{
		if (snake.x > 5)
		{
			snake.x--;
		}
		else if (snake.x == 5)
		{
			snake.x = 6;
			snake.goleft = 0;
			snake.goright = 1;
		}
	}
	// move

	DrawSnake(snake);

}

// _______________  BULLET  ________________________


void FlyingBullet(BULLET& bullet)
{

	setTextColor(10);
	if (bullet.appearance == 1)
	{
		if (bullet.y > 4)
		{
			bullet.y--;
			gotoXY(bullet.x, bullet.y); cout << " ^^ ";
			gotoXY(bullet.x, bullet.y + 1); cout << "^^^^";
			gotoXY(bullet.x, bullet.y + 2); cout << "^  ^";
		}
		else if (bullet.y == 4)
		{

			bullet.y--;
			gotoXY(bullet.x, bullet.y + 1); cout << "^^^^";
			gotoXY(bullet.x, bullet.y + 2); cout << "^  ^";
		}
		else if (bullet.y == 3)
		{

			bullet.y--;
			gotoXY(bullet.x, bullet.y + 2); cout << "^  ^";
		}
		else if (bullet.y == 2)
		{
			bullet.y--;
			bullet.appearance = 0;

		}

		// delete previous bullet
		if (bullet.y < 28)
		{
			gotoXY(bullet.x, bullet.y + 3);
			cout << "    ";
		}
	}
}


// ___________________  FIREBALL  _________________________________
void FlyingFireball(FIREBALL& fireball)
{
	setTextColor(12);
	if (fireball.appearance == 1)
	{
		if (fireball.y < 31)
		{
			fireball.y++;
			gotoXY(fireball.x, fireball.y); cout << "  | |  ";
			gotoXY(fireball.x, fireball.y + 1); cout << " | | | ";
			gotoXY(fireball.x, fireball.y + 2); cout << "|||||||";
			gotoXY(fireball.x, fireball.y + 3); cout << " -___- ";
		}
		else if (fireball.y == 31)
		{

			fireball.y++;
			gotoXY(fireball.x, fireball.y); cout << "  | |  ";
			gotoXY(fireball.x, fireball.y + 1); cout << " | | | ";
			gotoXY(fireball.x, fireball.y + 2); cout << "|||||||";
		}
		else if (fireball.y == 32)
		{

			fireball.y++;
			gotoXY(fireball.x, fireball.y); cout << "  | |  ";
			gotoXY(fireball.x, fireball.y + 1); cout << " | | | ";
		}
		else if (fireball.y == 33)
		{

			fireball.y++;
			gotoXY(fireball.x, fireball.y); cout << "  | |  ";
		}
		else if (fireball.y == 34)
		{
			fireball.y++;
			fireball.appearance = 0;
		}

		// delete previous fireball		
		if (fireball.y < 37)
		{
			gotoXY(fireball.x, fireball.y - 1);
			cout << "       ";
		}
	}
}

// ______________________________ DRAGON __________________________
void DragonStart(DRAGON& dragon)
{
	if (dragon.goleft + dragon.goright == 0)
	{
		dragon.goleft = 1;
		dragon.goright = 0;
	}
}

void DrawDragon(DRAGON dragon)
{
	setTextColor(6);
	gotoXY(dragon.x, dragon.y); cout << " {                 }   ";
	gotoXY(dragon.x, dragon.y + 1); cout << "  {{             }}    ";
	gotoXY(dragon.x, dragon.y + 2); cout << "   {{           }}     ";
	setTextColor(5);
	gotoXY(dragon.x, dragon.y + 3); cout << "   {   {     }   }     ";
	gotoXY(dragon.x, dragon.y + 4); cout << ".   (  (.) (.)  )   .  ";
	gotoXY(dragon.x, dragon.y + 5); cout << "  ..  |_     _|  ..    ";
	gotoXY(dragon.x, dragon.y + 6); cout << "..  ' . (   ) . '   .. ";
	gotoXY(dragon.x, dragon.y + 7); cout << "       IIIIIII         ";

	setTextColor(14);
	gotoXY(dragon.x + 7, dragon.y + 4); cout << "(.) (.)";

	setTextColor(8);
	gotoXY(dragon.x + 7, dragon.y + 7); cout << "IIIIIII";

	setTextColor(14);
	gotoXY(dragon.x + 6, dragon.y + 6); cout << ".";
	gotoXY(dragon.x + 14, dragon.y + 6); cout << ".";

	setTextColor(4);
	gotoXY(dragon.x + 4, dragon.y + 6); cout << "'";
	gotoXY(dragon.x + 16, dragon.y + 6); cout << "'";

	setTextColor(12);
	gotoXY(dragon.x + 2, dragon.y + 5); cout << "..";
	gotoXY(dragon.x + 17, dragon.y + 5); cout << "..";

	setTextColor(6);
	gotoXY(dragon.x, dragon.y + 6); cout << "..";
	gotoXY(dragon.x + 20, dragon.y + 6); cout << "..";
}

// delete the previous dragon
void DeleteTheOldDragon(int oldx, int oldy)
{
	gotoXY(oldx, oldy); cout << "                       ";
	gotoXY(oldx, oldy + 1); cout << "                       ";
	gotoXY(oldx, oldy + 2); cout << "                       ";
	gotoXY(oldx, oldy + 3); cout << "                       ";
	gotoXY(oldx, oldy + 4); cout << "                       ";
	gotoXY(oldx, oldy + 5); cout << "                       ";
	gotoXY(oldx, oldy + 6); cout << "                       ";
	gotoXY(oldx, oldy + 7); cout << "                       ";
}

// Move
void DragonMoving(DRAGON& dragon)
{
	// delete the previous dragon
	int oldx = dragon.x;
	int oldy = dragon.y;
	DeleteTheOldDragon(oldx, oldy);

	//
	if (dragon.goright == 1)
	{
		if (dragon.x < 87)
		{
			dragon.x++;
		}
		else if (dragon.x == 87)
		{
			dragon.x = 86;
			dragon.goleft = 1;
			dragon.goright = 0;
		}
	}
	else if (dragon.goleft == 1)
	{
		if (dragon.x > 5)
		{
			dragon.x--;
		}
		else if (dragon.x == 5)
		{
			dragon.x = 6;
			dragon.goleft = 0;
			dragon.goright = 1;
		}
	}
	// move
	DrawDragon(dragon);

	dragon.countdown--;
	if (dragon.countdown <= 0)
	{
		dragon.countdown = 200;
		if (dragon.goleft == 1)
		{
			dragon.goleft = 0;
			dragon.goright = 1;
		}
		else if (dragon.goright == 1)
		{
			dragon.goleft = 1;
			dragon.goright = 0;
		}
	}

}



// **********************************************************************************
// **********************************************************************************
// **********************************************************************************

// _____  SNAKE DIE  ____  

int DEAD(FIREBALL fireball, SNAKE snake)
{
	int check = 0;
	for (int i = 2; i <= 7; i++)
	{
		for (int j = 0; j <= 6; j++)
		{
			if (snake.x + i == fireball.x + j && snake.y == fireball.y + 3)
			{
				check = 1;
			}
			if (snake.x + i == fireball.x + j && snake.y + 1 == fireball.y + 3)
			{
				check = 1;
			}
		}
	}

	return check;
}


// ____________________  DRAGON DEAD  ___________________________

int DragonDead(DRAGON& dragon, BULLET bullet, int soundOn)
{
	int check = 0;

	for (int i = 7; i <= 13; i++)
	{
		for (int j = 0; j <= 3; j++)
		{
			if (dragon.x + i == bullet.x + j && dragon.y + 7 == bullet.y)
			{
				check = 1;
			}
			if (dragon.x + i == bullet.x + j && dragon.y + 7 == bullet.y + 1)
			{
				check = 1;
			}
		}
	}

	for (int i = 6; i <= 14; i++)
	{
		for (int j = 0; j <= 3; j++)
		{
			if (dragon.x + i == bullet.x + j && dragon.y + 6 == bullet.y)
			{
				check = 1;
			}
			if (dragon.x + i == bullet.x + j && dragon.y + 6 == bullet.y + 1)
			{
				check = 1;
			}
		}
	}

	for (int i = 5; i <= 15; i++)
	{
		for (int j = 0; j <= 3; j++)
		{
			if (dragon.x + i == bullet.x + j && dragon.y + 5 == bullet.y)
			{
				check = 1;
			}
			if (dragon.x + i == bullet.x + j && dragon.y + 5 == bullet.y + 1)
			{
				check = 1;
			}
		}
	}

	for (int i = 4; i <= 16; i++)
	{
		for (int j = 0; j <= 3; j++)
		{
			if (dragon.x + i == bullet.x + j && dragon.y + 4 == bullet.y)
			{
				check = 1;
			}
			if (dragon.x + i == bullet.x + j && dragon.y + 4 == bullet.y + 1)
			{
				check = 1;
			}
		}
	}

	for (int i = 3; i <= 16; i++)
	{
		for (int j = 0; j <= 3; j++)
		{
			if (dragon.x + i == bullet.x + j && dragon.y + 3 == bullet.y)
			{
				check = 1;
			}
			if (dragon.x + i == bullet.x + j && dragon.y + 3 == bullet.y + 1)
			{
				check = 1;
			}
		}
	}

	//
	if (check == 1)
	{
		if (dragon.life > 0)
		{
			dragon.life--;
			if (soundOn == 1)
			{
				PlaySound(L"uhuhuh.wav", NULL, SND_ASYNC);
			}
			check = 0;
		}
		else if (dragon.life <= 0)
		{
			check = 1;
			if (soundOn == 1)
			{
				PlaySound(L"ohno.wav", NULL, SND_SYNC);
			}
		}
	}

	return check;
}

void DragonHP(int x, int y, int HP)
{
	gotoXY(x, y);
	for (int i = 0; i < HP; i++)
	{
		cout << char(219);
	}
	gotoXY(x + HP, y);
	cout << " ";
}