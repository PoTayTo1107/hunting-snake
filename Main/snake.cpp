#include "snake.h"
#include "mylib.h"
#include <iostream>
using namespace std;

#define LEN 1;
#define XUONG 2;
#define TRAI 3;
#define PHAI 4;
#define TUONG_TREN 3
#define TUONG_DUOI 35
#define TUONG_TRAI 3
#define TUONG_PHAI 110

#define KEY_UP		1072
#define KEY_DOWN	1080
#define KEY_LEFT	1075
#define KEY_RIGHT	1077


/*
int x, int y truy?n t?a ?? (x, y) c?a góc trên cùng bên trái c?a vùng di chuy?n c?a con r?n
int vung_ran_di_chuyen_dai truy?n ?? dài c?a vùng di chuy?n c?a con r?n
int rong truy?n ?? r?ng c?a vùng di chuy?n c?a con r?n
*/
//V? vùng con r?n ???c di chuy?n
void ve_vung_ran_di_chuyen(int x, int y, int vung_ran_di_chuyen_dai, int rong)
{
	//V? c?nh trên và d??i
	for (int i = x; i <= x + vung_ran_di_chuyen_dai; i++)
	{
		//V? c?nh trên
		gotoXY(i, y);
		std::cout << char(219);

		//V? c?nh d??i
		gotoXY(i, y + rong);
		std::cout << char(219);
	}
	//V? c?nh trái - c?nh ph?i - c?nh phân chia vùng r?n di chuy?n và b?ng ?i?m
	for (int i = y; i <= y + rong; i++)
	{
		//V? c?nh trên
		gotoXY(x, i);
		std::cout << char(219);

		//V? c?nh d??i
		gotoXY(x + vung_ran_di_chuyen_dai, i);
		std::cout << char(219);

	}
}

void TaoNut(int x, int y, int nut)
{
	gotoXY(x, y); cout << char(218);
	gotoXY(x + 1, y); cout << char(196);
	gotoXY(x + 2, y); cout << char(191);
	gotoXY(x, y + 1); cout << char(179);
	gotoXY(x + 1, y + 1); cout << char(nut);
	gotoXY(x + 2, y + 1); cout << char(179);
	gotoXY(x, y + 2); cout << char(192);
	gotoXY(x + 1, y + 2); cout << char(196);
	gotoXY(x + 2, y + 2); cout << char(217);
}

void TaoPhimDiChuyen(int x, int y, int len, int xuong, int trai, int phai)
{
	TaoNut(x, y, len);
	TaoNut(x, y + 3, xuong);
	TaoNut(x - 3, y + 3, trai);
	TaoNut(x + 3, y + 3, phai);
}




/*
int x, int y truy?n t?a ?? (x, y) c?a góc trên cùng bên trái c?a b?ng ?i?m
int bang_diem_dai truy?n ?? dài c?a b?ng ?i?m
int rong truy?n ?? r?ng c?a b?ng ?i?m
*/
void ve_bang_diem(int x, int y, int bang_diem_dai, int rong, int man)
{
	//V? KHUNG ---------------------------------------------
	//V? c?nh trên và d??i
	for (int i = x; i <= x + bang_diem_dai; i++)
	{
		//V? c?nh trên
		gotoXY(i, y);
		std::cout << char(219);

		//V? c?nh phân chia vùng ?i?m và vùng h??ng d?n
		gotoXY(i, y + 12);
		std::cout << char(219);

		//V? c?nh phân chia gi?a vùng h??ng d?n và vùng tên màng
		gotoXY(i, y + rong - 7);
		std::cout << char(219);

		//V? c?nh d??i
		gotoXY(i, y + rong);
		std::cout << char(219);
	}
	//V? c?nh trái - c?nh ph?i - c?nh phân chia vùng r?n di chuy?n và b?ng ?i?m
	for (int i = y; i <= y + rong; i++)
	{
		//V? c?nh trên
		gotoXY(x, i);
		std::cout << char(219);

		//V? c?nh d??i
		gotoXY(x + bang_diem_dai, i);
		std::cout << char(219);
	}
	//--------------------------------------------------- V? KHUNG 

	//V? CÁC NÚT--------------------------------------------------
	setTextColor(14);
	gotoXY(x + 5, y + 14); cout << "Z : SAVE GAME";
	gotoXY(x + 5, y + 16); cout << "P : PAUSE GAME";
	TaoPhimDiChuyen(x + 4, y + 18, 87, 83, 65, 68);
	gotoXY(x + 10, y + 22); cout << ": MOVE SNAKE";
	setTextColor(7);
	//--------------------------------------------------V? CÁC NÚT

	//V? TÊN MÀN ------------------------
	/*
  __  __
 |  \/  |__ _ _ _
 | |\/| / _` | ' \
 |_|  |_\__,_|_||_|

	*/

	setTextColor(9);
	char str[] = "MAN 1";
	int khoang_cach_tang_them = bang_diem_dai / 2 - 12;
	gotoXY(x + khoang_cach_tang_them, y + rong - 6); std::cout << " __  __ ";
	gotoXY(x + khoang_cach_tang_them, y + rong - 5); std::cout << "|  \\/  |__ _ _ _ ";
	gotoXY(x + khoang_cach_tang_them, y + rong - 4); std::cout << "| |\\/| / _` | ' \\";
	gotoXY(x + khoang_cach_tang_them, y + rong - 3); std::cout << "|_|  |_\\__,_|_||_|";

	khoang_cach_tang_them += 20;
	switch (man)
	{
	case 1:
		/*
		 _
		/ |
		| |
		|_|

		*/
		gotoXY(x + khoang_cach_tang_them, y + rong - 6); std::cout << " _ ";
		gotoXY(x + khoang_cach_tang_them, y + rong - 5); std::cout << "/ |";
		gotoXY(x + khoang_cach_tang_them, y + rong - 4); std::cout << "| |";
		gotoXY(x + khoang_cach_tang_them, y + rong - 3); std::cout << "|_|";
		break;
	case 2:
		/*
		  ___
		 |_  )
		  / /
		 /___|

		*/
		gotoXY(x + khoang_cach_tang_them, y + rong - 6); std::cout << " ___ ";
		gotoXY(x + khoang_cach_tang_them, y + rong - 5); std::cout << "|_  )";
		gotoXY(x + khoang_cach_tang_them, y + rong - 4); std::cout << " / / ";
		gotoXY(x + khoang_cach_tang_them, y + rong - 3); std::cout << "/___|";
		break;
	case 3:
		/*
		 ____
		|__ /
		 |_ \
		|___/
		*/
		gotoXY(x + khoang_cach_tang_them, y + rong - 6); std::cout << " ____";
		gotoXY(x + khoang_cach_tang_them, y + rong - 5); std::cout << "|__ /";
		gotoXY(x + khoang_cach_tang_them, y + rong - 4); std::cout << " |_ \\";
		gotoXY(x + khoang_cach_tang_them, y + rong - 3); std::cout << "|___/";
		break;
	case 4:
		/*
		 _ _
		| | |
		|_  _|
		  |_|
		*/
		gotoXY(x + khoang_cach_tang_them, y + rong - 6); std::cout << " _ _ ";
		gotoXY(x + khoang_cach_tang_them, y + rong - 5); std::cout << "| | | ";
		gotoXY(x + khoang_cach_tang_them, y + rong - 4); std::cout << "|_  _|";
		gotoXY(x + khoang_cach_tang_them, y + rong - 3); std::cout << "  |_| ";
		break;
	case 5:
		/*
		 ___
		| __|
		|__ \
		|___/
		*/
		gotoXY(x + khoang_cach_tang_them, y + rong - 6); std::cout << " ___ ";
		gotoXY(x + khoang_cach_tang_them, y + rong - 5); std::cout << "| __|";
		gotoXY(x + khoang_cach_tang_them, y + rong - 4); std::cout << "|__ \\";
		gotoXY(x + khoang_cach_tang_them, y + rong - 3); std::cout << "|___/";
		break;
	}
	setTextColor(7);
	//---------------------------------V? TÊN MÀN

}


/*
ToaDo vat_can[] truy?n m?ng ch?a t?a ?? c?a các ô v?t c?n
int vat_can_so_o truy?n bi?n ch?a t?ng s? l??ng ô v?t c?n
*/
void ve_vat_can(ToaDo vat_can[], int vat_can_so_o)
{
	for (int i = 0; i < vat_can_so_o; i++)
	{
		//V? t?ng ô v?t c?n
		gotoXY(vat_can[i].x, vat_can[i].y);
		std::cout << char(219);
	}
}

void ve_man_choi(int x, int y, int vung_ran_di_chuyen_dai, int bang_diem_dai, int rong, ToaDo vat_can[], int vat_can_so_o, int man)
{
	//v? vùng r?n di chuy?n
	ve_vung_ran_di_chuyen(x, y, vung_ran_di_chuyen_dai, rong);
	//v? b?ng ?i?m
	ve_bang_diem(x + vung_ran_di_chuyen_dai + 1, y, bang_diem_dai, rong, man);
	//v? v?t c?n màn 2
	ve_vat_can(vat_can, vat_can_so_o);
}

//Ve ran
void VeRan(ToaDo ran[], int ran_dot)
{
	int a[100] = { 2, 1, 1, 2, 7, 0, 4, 0, 2, 1, 1, 2, 7, 3, 2, 1, 2, 1, 1, 2, 7, 3, 8, 0, 2, 1, 1, 2, 7, 6, 1, 2, 2, 1, 1, 2, 7, 0, 4, 0, 2, 1, 1, 2, 7, 3, 2, 1, 2, 1, 1, 2, 7, 3, 8, 0, 2, 1, 1, 2, 7, 6, 1, 2 };
	for (int i = 0; i < ran_dot; i++)
	{
		gotoXY(ran[i].x, ran[i].y);
		cout << a[i];
	}
}
void HienThiRan(ToaDo ran[], ToaDo dot_cuoi_cu, int ran_dot)
{
	int a[100] = { 2, 1, 1, 2, 7, 0, 4, 0, 2, 1, 1, 2, 7, 3, 2, 1, 2, 1, 1, 2, 7, 3, 8, 0, 2, 1, 1, 2, 7, 6, 1, 2, 2, 1, 1, 2, 7, 0, 4, 0, 2, 1, 1, 2, 7, 3, 2, 1, 2, 1, 1, 2, 7, 3, 8, 0, 2, 1, 1, 2, 7, 6, 1, 2 };
	TextColor(10); gotoXY(ran[0].x, ran[0].y); cout << a[0];
	TextColor(7);
	for (int i = 1; i < ran_dot; i++)
	{
		gotoXY(ran[i].x, ran[i].y);
		cout << a[i];
	}
	gotoXY(dot_cuoi_cu.x, dot_cuoi_cu.y);
	cout << " ";
}

void BatSuKien(int& huong, bool& checkPause)
{
	int key = inputKey();
	if (key == 'z' || key == 'Z')
	{
		huong = -1;
		return;
	}
	if (key == 'p' || key == 'P')
	{
		checkPause = true;
		return;
	}
	if (huong == 3)
	{
		if (key == 'w' || key == 'W' || key == KEY_UP)
		{
			huong = LEN;
		}
		else if (key == 's' || key == 'S' || key == KEY_DOWN)
		{
			huong = XUONG;
		}
	}
	else if (huong == 1)
	{
		if (key == 'a' || key == 'A' || key == KEY_LEFT)
		{
			huong = TRAI;
		}
		else if (key == 'd' || key == 'D' || key == KEY_RIGHT)
		{
			huong = PHAI;
		}
	}
	else if (huong == 4)
	{
		if (key == 'w' || key == 'W' || key == KEY_UP)
		{
			huong = LEN;
		}
		else if (key == 's' || key == 'S' || key == KEY_DOWN)
		{
			huong = XUONG;
		}
	}
	else if (huong == 2)
	{
		if (key == 'a' || key == 'A' || key == KEY_LEFT)
		{
			huong = TRAI;
		}
		else if (key == 'd' || key == 'D' || key == KEY_RIGHT)
		{
			huong = PHAI;
		}
	}
}


ToaDo DiChuyen(ToaDo ran[], int huong, int ran_dot)
{
	ToaDo dot_cuoi_cu = ran[ran_dot - 1];
	for (int i = ran_dot - 1; i >= 1; i--)
	{
		ran[i] = ran[i - 1];
	}
	switch (huong)
	{
	case 1:
	{
		ran[0].y--;
		break;
	}
	case 2:
	{
		ran[0].y++;
		break;
	}
	case 3:
	{
		ran[0].x--;
		break;
	}
	case 4:
	{
		ran[0].x++;
		break;
	}
	}
	return dot_cuoi_cu;
}

//ran cham than
bool RanChamThan(ToaDo ran[], int ran_dot)
{
	for (int i = 1; i < ran_dot; i++)
	{
		if (ran[0].x == ran[i].x && ran[0].y == ran[i].y)
		{
			return true;
		}
	}
	return false;
}

//Kiem tra thua khi ran cham vao khung tro choi
bool RanChamTuong(ToaDo ran[])
{
	if (ran[0].y == TUONG_TREN)
	{
		return true;
	}
	if (ran[0].y == TUONG_DUOI)
	{
		return true;
	}
	if (ran[0].x == TUONG_TRAI)
	{
		return true;
	}
	if (ran[0].x == TUONG_PHAI)
	{
		return true;
	}
	return false;
}

//Kiem tra toa do qua kha thi
bool KiemTraToaDoQuaKhaThi(int x, int y, ToaDo vat_can[], int so_o_vat_can)
{
	for (int i = 0; i < so_o_vat_can; i++)
	{
		if (x == vat_can[i].x && y == vat_can[i].y)
		{
			return false;
		}
	}
	return true;
}

//Tao qua 1
void TaoQua1(QUA& food)  //  4 < xqua < 110;  3 < yqua < 35
{
	food.qua1.x = rand() % (109 - 5 + 1) + 5;
	food.qua1.y = rand() % (34 - 4 + 1) + 4;
}

//Ve qua 1
void VeQua1(QUA& food)
{
	gotoXY(food.qua1.x, food.qua1.y);
	cout << "O";
}

//Tao qua 10
void TaoQua10(QUA& food)  //  4 < xqua < 110;  3 < yqua < 35
{
	food.qua10.x = rand() % (109 - 5 + 1) + 5;
	food.qua10.y = rand() % (34 - 4 + 1) + 4;
}

//Ve qua 10
void VeQua10(QUA& food)
{
	gotoXY(food.qua10.x, food.qua10.y);
	cout << "$";
}

//Tao qua doc
void TaoQuaDoc(QUA& food)
{
	food.quaDoc.x = rand() % (109 - 5 + 1) + 5;
	food.quaDoc.y = rand() % (34 - 4 + 1) + 4;
}

//Ve qua doc
void VeQuaDoc(QUA& food)
{
	gotoXY(food.quaDoc.x, food.quaDoc.y);
	cout << "#";
}


void XoaQua(QUA food)
{
	if (food.count < 5)
	{
		gotoXY(food.qua1.x, food.qua1.y);
		cout << " ";
	}
	else if (food.count == 5)
	{
		gotoXY(food.qua10.x, food.qua10.y);
		cout << " ";
	}
	else
	{
		gotoXY(food.quaDoc.x, food.quaDoc.y);
		cout << " ";
	}
}

//In ra màn hình thua
//x,y:T?a ?? n?i in ra
void ManHinhThua(int x, int y)
{
	gotoXY(x, y);
	cout << "LOSE               LOSELOSELOSE      LOSELOSELOSELOSE    LOSELOSELOSELOSE      " << endl;
	y++;
	gotoXY(x, y);
	cout << "LOSE             LOSE        LOSE    LOSE                LOSELOSE              " << endl;
	y++;
	gotoXY(x, y);
	cout << "LOSE            LOSE          LOSE   LOSELOSE            LOSE                  " << endl;
	y++;
	gotoXY(x, y);
	cout << "LOSE            LOSE          LOSE   LOSELOSELOSELOSE    LOSELOSELOSELOSE      " << endl;
	y++;
	gotoXY(x, y);
	cout << "LOSE            LOSE          LOSE           LOSELOSE    LOSELOSELOSE          " << endl;
	y++;
	gotoXY(x, y);
	cout << "LOSE            LOSE          LOSE               LOSE    LOSE                  " << endl;
	y++;
	gotoXY(x, y);
	cout << "LOSELOSE         LOSE        LOSE            LOSELOSE    LOSELOSE              " << endl;
	y++;
	gotoXY(x, y);
	cout << "LOSELOSELOSE       LOSELOSELOSE      LOSELOSELOSELOSE    LOSELOSELOSELOSE      " << endl;
}

void ManHinhThang()
{
	cout << R"(
                                                                                                                                                         
                                                                                                                                                         
YYYYYYY       YYYYYYY     OOOOOOOOO     UUUUUUUU     UUUUUUUU     WWWWWWWW                           WWWWWWWWIIIIIIIIIINNNNNNNN        NNNNNNNN      !!! 
Y:::::Y       Y:::::Y   OO:::::::::OO   U::::::U     U::::::U     W::::::W                           W::::::WI::::::::IN:::::::N       N::::::N     !!:!!
Y:::::Y       Y:::::Y OO:::::::::::::OO U::::::U     U::::::U     W::::::W                           W::::::WI::::::::IN::::::::N      N::::::N     !:::!
Y::::::Y     Y::::::YO:::::::OOO:::::::OUU:::::U     U:::::UU     W::::::W                           W::::::WII::::::IIN:::::::::N     N::::::N     !:::!
YYY:::::Y   Y:::::YYYO::::::O   O::::::O U:::::U     U:::::U       W:::::W           WWWWW           W:::::W   I::::I  N::::::::::N    N::::::N     !:::!
   Y:::::Y Y:::::Y   O:::::O     O:::::O U:::::D     D:::::U        W:::::W         W:::::W         W:::::W    I::::I  N:::::::::::N   N::::::N     !:::!
    Y:::::Y:::::Y    O:::::O     O:::::O U:::::D     D:::::U         W:::::W       W:::::::W       W:::::W     I::::I  N:::::::N::::N  N::::::N     !:::!
     Y:::::::::Y     O:::::O     O:::::O U:::::D     D:::::U          W:::::W     W:::::::::W     W:::::W      I::::I  N::::::N N::::N N::::::N     !:::!
      Y:::::::Y      O:::::O     O:::::O U:::::D     D:::::U           W:::::W   W:::::W:::::W   W:::::W       I::::I  N::::::N  N::::N:::::::N     !:::!
       Y:::::Y       O:::::O     O:::::O U:::::D     D:::::U            W:::::W W:::::W W:::::W W:::::W        I::::I  N::::::N   N:::::::::::N     !:::!
       Y:::::Y       O:::::O     O:::::O U:::::D     D:::::U             W:::::W:::::W   W:::::W:::::W         I::::I  N::::::N    N::::::::::N     !!:!!
       Y:::::Y       O::::::O   O::::::O U::::::U   U::::::U              W:::::::::W     W:::::::::W          I::::I  N::::::N     N:::::::::N      !!! 
       Y:::::Y       O:::::::OOO:::::::O U:::::::UUU:::::::U               W:::::::W       W:::::::W         II::::::IIN::::::N      N::::::::N          
    YYYY:::::YYYY     OO:::::::::::::OO   UU:::::::::::::UU                 W:::::W         W:::::W          I::::::::IN::::::N       N:::::::N      !!! 
    Y:::::::::::Y       OO:::::::::OO       UU:::::::::UU                    W:::W           W:::W           I::::::::IN::::::N        N::::::N     !!:!!
    YYYYYYYYYYYYY         OOOOOOOOO           UUUUUUUUU                       WWW             WWW            IIIIIIIIIINNNNNNNN         NNNNNNN      !!! 
                                                                                                                                                                                                                                                                                                                                                                       
)";
}

//Khoi tao ran
void KhoiTaoRan(ToaDo ran[])
{
	ran[0].x = 7;
	ran[0].y = 15;
}

int  DoDaiCuaSo(int so)
{
	if (so == 0)
	{
		return 1;
	}
	int count = 0;
	while (so > 0)
	{
		so /= 10;
		count++;
	}
	return count;
}

void ve_diem(int diem, int x, int y, char* ten_nguoi_choi)
{
	setTextColor(12);
	gotoXY(x, y);
	cout << "  _____";
	gotoXY(x, y + 1);
	cout << " / ____|";
	gotoXY(x, y + 2);
	cout << "| (___   ___ ___  _ __ ___";
	gotoXY(x, y + 3);
	cout << " \\___ \\ / __/ _ \\| '__/ _ \\";
	gotoXY(x, y + 4);
	cout << " ____) | (_| (_) | | |  __/";
	gotoXY(x, y + 5);
	cout << "|_____/ \\___\\___/|_|  \\___|";
	setTextColor(7);

	gotoXY(x, y + 6);
	cout << "-------------------------------------";
	gotoXY(x, y + 7);
	if (ten_nguoi_choi != NULL)
	{
		cout << ten_nguoi_choi << ":";;
	}
	else
	{
		cout << "player-name:";
	}
	//gotoXY(x + 36, y + 7);
	int len = DoDaiCuaSo(diem);
	gotoXY(x + 36 - len, y + 7);
	cout << diem;
	/*
	* _____
	 / ____|
	| (___   ___ ___  _ __ ___
	 \___ \ / __/ _ \| '__/ _ \
	 ____) | (_| (_) | | |  __/
	|_____/ \___\___/|_|  \___|

	*/
}

void tao_cong_win(int x, int y, ToaDo cong_win[], int& cong_win_so_o, char* huong_vao_cong)
{
	cong_win_so_o = 0;
	if (strcmp(huong_vao_cong, "len") == 0)
	{
		for (int i = -1; i <= 1; i++)
		{
			cong_win[cong_win_so_o].x = x + i;
			cong_win[cong_win_so_o].y = y;
			cong_win_so_o++;
		}
		for (int i = 1; i < 3; i++)
		{
			cong_win[cong_win_so_o].x = x - 1;
			cong_win[cong_win_so_o].y = y + i;
			cong_win_so_o++;

			cong_win[cong_win_so_o].x = x + 1;
			cong_win[cong_win_so_o].y = y + i;
			cong_win_so_o++;
		}

	}
	else if (strcmp(huong_vao_cong, "trai") == 0)
	{
		for (int i = 0; i < 2; i++)
		{
			cong_win[cong_win_so_o].x = x + i;
			cong_win[cong_win_so_o].y = y;
			cong_win_so_o++;

			cong_win[cong_win_so_o].x = x + i;
			cong_win[cong_win_so_o].y = y + 2;
			cong_win_so_o++;
		}

		for (int i = 0; i < 3; i++)
		{
			cong_win[cong_win_so_o].x = x + 2;
			cong_win[cong_win_so_o].y = y + i;
			cong_win_so_o++;
		}
	}
}

bool RanChamCongWin(ToaDo ran[], ToaDo cong_win[], int cong_win_so_o)
{
	for (int i = 0; i < cong_win_so_o; i++)
	{
		if (cong_win[i].x == ran[0].x && cong_win[i].y == ran[0].y)
		{
			return true;
		}
	}
	return false;
}

void ve_cong_win(ToaDo cong_win[], int cong_win_so_o)
{
	for (int i = 0; i < cong_win_so_o; i++)
	{
		gotoXY(cong_win[i].x, cong_win[i].y);
		cout << char(219);
	}
}
bool xu_ly_win(ToaDo ran[], ToaDo cong_win[])
{
	return (ran[0].x == cong_win[0].x + 1 && ran[0].y == cong_win[0].y + 1);
}

bool KiemTraDieuKienThang(int diem, int diem_man)
{
	int diemDK = 0;
	while (diem >= 130)
	{
		diemDK = diem % 130;
		diem /= 130;
	}
	if (diemDK >= diem_man || diem >= diem_man)
	{
		return true;
	}
	return false;
}

