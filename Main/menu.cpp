#include "menu.h"
#include "mylib.h"
#include "snake.h"
#include <iostream>
#include <string.h>
#include <conio.h>
using namespace std;

void ve_ten_game()
{
	/*
______   ___   __    ________   ___   ___   ______       _______    ________   ___ __ __   ______
/_____/\ /__/\ /__/\ /_______/\ /___/\/__/\ /_____/\     /______/\  /_______/\ /__//_//_/\ /_____/\
\::::_\/_\::\_\\  \ \\::: _  \ \\::.\ \\ \ \\::::_\/_    \::::__\/__\::: _  \ \\::\| \| \ \\::::_\/_
 \:\/___/\\:. `-\  \ \\::(_)  \ \\:: \/_) \ \\:\/___/\    \:\ /____/\\::(_)  \ \\:.      \ \\:\/___/\
  \_::._\:\\:. _    \ \\:: __  \ \\:. __  ( ( \::___\/_    \:\\_  _\/ \:: __  \ \\:.\-/\  \ \\::___\/_
	/____\:\\. \`-\  \ \\:.\ \  \ \\: \ )  \ \ \:\____/\    \:\_\ \ \  \:.\ \  \ \\. \  \  \ \\:\____/\
	\_____\/ \__\/ \__\/ \__\/\__\/ \__\/\__\/  \_____\/     \_____\/   \__\/\__\/ \__\/ \__\/ \_____\/
																										*/

	setTextColor(14);
	gotoXY(30, 2); cout << "  ______   ___   __    ________   ___   ___   ______       _______    ________   ___ __ __   ______    ";
	gotoXY(30, 3); cout << " /_____/\\ /__/\\ /__/\\ /_______/\\ /___/\\/__/\\ /_____/\\     /______/\\  /_______/\\ /__//_//_/\\ /_____/\\";
	gotoXY(30, 4); cout << " \\::::_\\/_\\::\\_\\\\  \\ \\\\::: _  \\ \\\\::.\\ \\\\ \\ \\\\::::_\\/_    \\::::__\\/__\\::: _  \\ \\\\::\| \\| \\ \\\\::::_\\/_   ";
	gotoXY(30, 5); cout << "  \\:\\/___/\\\\:. `-\\  \\ \\\\::(_)  \\ \\\\:: \\/_) \\ \\\\:\\/___/\\    \\:\\ /____/\\\\::(_)  \\ \\\\:.      \\ \\\\:\\/___/\\";
	gotoXY(30, 6); cout << "   \\_::._\\:\\\\:. _    \\ \\\\:: __  \\ \\\\:. __  ( ( \\::___\\/_    \\:\\\\_  _\\/ \\:: __  \\ \\\\:.\\-/\\  \\ \\\\::___\\/_";
	gotoXY(30, 7); cout << " 	/____\\:\\\\. \\`-\\  \\ \\\\:.\\ \\  \\ \\\\: \\ )  \\ \\ \\:\\____/\\    \\:\\_\\ \\ \\  \\:.\\ \\  \\ \\\\. \\  \\  \\ \\\\:\\____/\\";
	gotoXY(30, 7); cout << "	  \\_____\\/ \\__\\/ \\__\\/ \\__\\/\\__\\/ \\__\\/\\__\\/  \\_____\\/     \\_____\\/   \\__\\/\\__\\/ \\__\\/ \\__\\/ \\_____\\/";
	setTextColor(7);

}

void ve_logo_game()
{

	/*
		   _____
		 _|     |_______
		|.   )    |     |__
		|.                 |
		|_   )   _|__     _|
		  |_____|    |     |
				  _|    _|
			_______|    _|
		  _|          _|
		 |           |_________________________                      __________________________________________
		 |_                                    |____________________|  _____________________|
		   |________________________________                          |
											|_________________________|
	*/

	setTextColor(12);
	gotoXY(5, 0); cout << "       _____ ";
	gotoXY(5, 1); cout << "     _|     |_______ ";
	gotoXY(5, 2); cout << "    |.   )    |     |__ ";
	gotoXY(5, 3); cout << "    |.                 |";
	gotoXY(5, 4); cout << "    |_   )   _|__      |";
	gotoXY(5, 5); cout << "      |_____|    |     |";
	gotoXY(5, 6); cout << "               _|    _|";
	gotoXY(5, 7); cout << "       _______|    _| ";
	gotoXY(5, 8); cout << "     _|          _| ";
	gotoXY(5, 9); cout << "    |           |_________________________                      __________________________________________ ";
	gotoXY(5, 10); cout << "    |_                                    |____________________|  _____________________| ";
	gotoXY(5, 11); cout << "      |________________________________                          | ";
	gotoXY(5, 12); cout << "                                       |_________________________| ";
}


void input_menu(int& goup, int& enter)
{
	if (_kbhit())
	{
		char phim = _getch();
		if (phim == 'w' || phim == 'W' || int(phim) == 72)
		{
			goup = 1;
			enter = 0;
		}
		else if (phim == 's' || phim == 'S' || int(phim) == 80)
		{
			goup = -1;
			enter = 0;
		}
		else if (int(phim) == 13)
		{
			enter = 1;
		}
	}
}

void ve_khung_chu_nhat(int x, int y, int dai, int rong, char* noi_dung)
{
	for (int i = x + 1; i < x + dai; i++)
	{
		gotoXY(i, y);
		cout << char(196);
	}
	gotoXY(x, y);
	cout << char(218);
	gotoXY(x + dai, y);
	cout << char(191);

	for (int i = y + 1; i <= y + rong; i++)
	{
		gotoXY(x, i);
		cout << char(179);
		gotoXY(x + dai, i);
		cout << char(179);
	}
	for (int i = x; i <= x + dai; i++)
	{
		gotoXY(i, y + 2);
		cout << char(196);
	}

	gotoXY(x, y + rong);
	cout << char(192);
	gotoXY(x + dai, y + rong);
	cout << char(217);

	gotoXY(x + dai / 2 - (strlen(noi_dung) / 2), y + 1);
	cout << noi_dung;
}

void to_mau(int x, int y, int rong, int dai, char* noi_dung)
{
	gotoXY(x - 2, y + rong - 1);
	cout << char(196) << char(16); // IN ra ký t? "->" ? cu?i ô

	TextColor(192); //N?n ?? ch? ?en
	for (int i = x + 1; i < x + dai; i++)
	{
		gotoXY(i, y + 1);
		cout << ' '; //Tô màu cho ô ???c ch?n
	}
	//Ghi l?i n?i dung 
	gotoXY(x + dai / 2 - (strlen(noi_dung) / 2), y + 1);
	cout << noi_dung;
}

void huy_to_mau(int x, int y, int rong, int dai, char* noi_dung)
{
	TextColor(7); // Màu ?en
	gotoXY(x - 2, y + rong - 1);
	cout << "  "; // Xóa kí t? "->" ? cu?i ô

	for (int i = x + 1; i < x + dai; i++)
	{
		gotoXY(i, y + 1);
		cout << " "; // Tô l?i ô v?i màu ?en
	}
	//Ghi l?i n?i dung
	gotoXY(x + dai / 2 - (strlen(noi_dung) / 2), y + 1);
	cout << noi_dung;
}

int logic_menu(int x, int y, int rong, int dai, char noi_dung[][30], int soundOn)
{
	int goup;
	int enter;
	int temp_y = y;
	to_mau(x, temp_y, rong, dai, noi_dung[(temp_y - y) / 2]);
	while (1)
	{
		input_menu(goup, enter);
		if (goup == 1)
		{
			if (soundOn == 1)
			{
				PlaySound(L"gamebeep.wav", NULL, SND_ASYNC);
			}
			huy_to_mau(x, temp_y, rong, dai, noi_dung[(temp_y - y) / 2]); // h?y tô màu ? ô ?ã ch?n tr??c ?ó
			if (temp_y != y) // N?u mà ô ???c ch?n tr??c ?ó ch?a là ô trên cùng thì lên 1 ô
			{
				temp_y -= 2;
			}
			else // N?u mà ô ???c ch?n tr??c ?ó là ô trên cùng thì chuy?n ô ???c là ô d??i cùng
			{
				temp_y = y + rong * 5;
			}
			to_mau(x, temp_y, rong, dai, noi_dung[(temp_y - y) / 2]); // Tô màu cho ô ch?n hi?n t?i
			goup = 0;
		}
		else if (goup == -1)
		{
			if (soundOn == 1)
			{
				PlaySound(L"gamebeep.wav", NULL, SND_ASYNC);
			}
			huy_to_mau(x, temp_y, rong, dai, noi_dung[(temp_y - y) / 2]);// h?y tô màu ? ô ?ã ch?n tr??c ?ós
			if (temp_y != y + rong * 5) // N?u mà ô ???c ch?n tr??c ?ó ch?a là ô d??i cùng thì chuy?n xu?ng 1 ô
			{
				temp_y += 2;
			}
			else // N?u mà ô ???c ch?n tr??c ?ó là ô d??i cùng thì ô ???c ch?n là ô trên cùng
			{
				temp_y = y;
			}
			to_mau(x, temp_y, rong, dai, noi_dung[(temp_y - y) / 2]); // Tô màu cho ô ch?n hi?n t?i
			goup = 0;
		}
		else if (enter == 1)
		{
			if (soundOn == 1)
			{
				PlaySound(L"starteffect.wav", NULL, SND_ASYNC);
			}
			break;
		}
	}
	return (temp_y - y) / 2;
}

int menu_new_game(int soundOn)
{
	int x = 54;
	int y = 17;
	int rong = 2;
	int dai = 40;
	int Black = 7;
	int color = 192;

	ve_ten_game();
	//ve_logo_game();
	noCursorType();//Xóa con tr?(d?u nháy)
	char noi_dung[6][30] = { "BAT DAU", "TIEP TUC","BANG DIEM", "HUONG DAN", "NHAC: Bat","THOAT" };
	if (soundOn)
	{
		char noi_dung_thay_the[] = "NHAC: Tat";
		strcpy_s(noi_dung[4], strlen(noi_dung_thay_the) + 1, noi_dung_thay_the);
	}

	for (int i = 0; i < 6; i++)
	{
		ve_khung_chu_nhat(x, y + i * 2, dai, rong, noi_dung[i]);
	}
	for (int i = y + rong; i <= y + rong * 5; i += 2)
	{
		gotoXY(x, i);
		cout << char(195);
		gotoXY(x + dai, i);
		cout << char(180);
	}
	gotoXY(x, y + rong * 5 + 5);

	int result = logic_menu(x, y, rong, dai, noi_dung, soundOn);
	TextColor(Black);
	return result;
}


void TaoBang(int x, int y, int dai, int rong, char* noi_dung)
{
	ve_khung_chu_nhat(x, y, dai, rong, noi_dung);
	strcpy_s(noi_dung, 1, " ");
	ve_khung_chu_nhat(x, y + 2, dai + 12, rong, noi_dung);

}

void BangHuongDanChoiGame(int x, int y, int dai, int rong)
{
	/*

	   _     __    _  _        __    _ ___    __ _     __
|_|| |/ \|\|/__   | \|_||\|   /  |_|/ \ |    /__|_||V||_
| ||_|\_/| |\_|   |_/| || |   \__| |\_/_|_   \_|| || ||__
	*/
	//V? c?nh trên và d??i
	for (int i = x; i <= x + dai; i++)
	{
		//V? c?nh trên
		gotoXY(i, y);
		std::cout << char(219);

		gotoXY(i, y + 4);
		std::cout << char(219);

		//V? c?nh d??i
		gotoXY(i, y + rong);
		std::cout << char(219);
	}

	gotoXY(20, y + 1); cout << "	   _     __    _  _        __    _ ___    __ _     __";
	gotoXY(20, y + 2); cout << "|_|| |/ \\|\\|/__   | \\|_||\\|   /  |_|/ \\ |    /__|_||V||_";
	gotoXY(20, y + 3); cout << "| ||_|\\_/| |\\_|   |_/| || |   \\__| |\\_/_|_   \\_|| || ||__";

	//V? c?nh trái - c?nh ph?i - c?nh phân chia vùng r?n di chuy?n và b?ng ?i?m
	for (int i = y; i <= y + rong; i++)
	{
		//V? c?nh trên
		gotoXY(x, i);
		std::cout << char(219);

		//V? c?nh d??i
		gotoXY(x + dai, i);
		std::cout << char(219);
	}
}

void menuHuongDanChoi()
{
	BangHuongDanChoiGame(3, 3, 147, 55);
	int x = 23, y = 10;
	TaoPhimDiChuyen(x, y, 30, 31, 17, 16);
	x = 35;
	TaoPhimDiChuyen(x, y, 87, 83, 65, 68);
	gotoXY(x + 15, y + 3);
	cout << ": CAC PHIM DI CHUYEN";
	x = 20;
	gotoXY(x, y + 8);  cout << "O: QUA BINH THUONG ( +3 DIEM, +1 DOT). LA TRAI GIAI DOC KHI BI DINH DOC\n";
	gotoXY(x, y + 10); cout << "$: QUA LON (+ 5 DIEM, +1 DOT).\n";
	gotoXY(x, y + 12); cout << "#: QUA DOC( +3 DIEM, 1 DOT). KHI AN BI DINH DOC VA MAT DOT DEN CHET.CO THE GIAI DOC BANG QUA BINH THUONG\n";
	gotoXY(x, y + 14); cout << char(178) << ": CONG DICH CHUYEN - GIUP DICH CHUYEN TOI 1 CONG DICH CHUYEN KHAC\n";
	gotoXY(x, y + 16); cout << char(219) << ": TUONG - VAT CAN\n";

	int tempY = y + 18;
	gotoXY(x, tempY++); cout << " MAN CUOI (BONUS)\n";
	gotoXY(x, tempY++); cout << "----------------------------------------------------------------------------------------------------------------------------\n";
	gotoXY(x, tempY++); cout << "     {                 }    ";
	gotoXY(x, tempY++); cout << "      {{             }}             ";
	gotoXY(x, tempY++); cout << "       {{           }}             ";
	gotoXY(x, tempY++); cout << "       {   {     }   }         ";
	gotoXY(x, tempY++); cout << "    .   (  (.) (.)  )   .        : BOSS MAN CUOI ";
	gotoXY(x, tempY++); cout << "      ..  |_     _|  ..     ";
	gotoXY(x, tempY++); cout << "    ..  ' . (   ) . '   ..          ";
	gotoXY(x, tempY); cout << "           IIIIIII                         \n";

	tempY += 4;
	gotoXY(x, tempY++); cout << "                                    ";
	gotoXY(x, tempY++); cout << "             | |                         ";
	gotoXY(x, tempY++); cout << "            | | |                        ";
	gotoXY(x, tempY++); cout << "           |||||||     : QUA CAU LUA - BOSS TAN CONG";
	gotoXY(x, tempY++); cout << "            -___-                        ";

	tempY += 2;
	gotoXY(x, tempY++); cout << "              ^^                     ";
	gotoXY(x, tempY++); cout << "             ^^^^      : QUA CAU NANG LUONG - RAN TAN CONG       ";
	gotoXY(x, tempY++); cout << "             ^  ^                       ";

	tempY++;
	gotoXY(x, tempY++); cout << "           _----_  ";
	gotoXY(x, tempY++); cout << "          (      ) ";
	gotoXY(x, tempY++); cout << "         |  0  0  |     : RAN ";
	gotoXY(x, tempY++); cout << "         |        |";

	gotoXY(x, y + 50);
}


/// 
/// PAUSE_MENU
/// 

void ve_pause_game()
{
	cout << R"(



					 ______  ______  __    __       _____   __  __  __   __  ______    
					/\__  _\/\  __ \/\ "-./  \     /\  __-./\ \/\ \/\ "-.\ \/\  ___\   
					\/_/\ \/\ \  __ \ \ \-./\ \    \ \ \/\ \ \ \_\ \ \ \-.  \ \ \__ \  
					   \ \_\ \ \_\ \_\ \_\ \ \_\    \ \____-\ \_____\ \_\\"\_\ \_____\ 
					    \/_/  \/_/\/_/\/_/  \/_/     \/____/ \/_____/\/_/ \/_/\/_____/    

                                                             
)";
}
int logic_pause_menu(int x, int y, int rong, int dai, char noi_dung[][30])
{
	int goup;
	int enter;
	int temp_y = y;
	to_mau(x, temp_y, rong, dai, noi_dung[(temp_y - y) / 2]);
	while (1)
	{
		input_menu(goup, enter);
		if (goup == 1)
		{
			huy_to_mau(x, temp_y, rong, dai, noi_dung[(temp_y - y) / 2]); // h?y tô màu ? ô ?ã ch?n tr??c ?ó
			if (temp_y != y) // N?u mà ô ???c ch?n tr??c ?ó ch?a là ô trên cùng thì lên 1 ô
			{
				temp_y -= 2;
			}
			else // N?u mà ô ???c ch?n tr??c ?ó là ô trên cùng thì chuy?n ô ???c là ô d??i cùng
			{
				temp_y = y + rong * 3;
			}
			to_mau(x, temp_y, rong, dai, noi_dung[(temp_y - y) / 2]); // Tô màu cho ô ch?n hi?n t?i
			goup = 0;
		}
		else if (goup == -1)
		{
			huy_to_mau(x, temp_y, rong, dai, noi_dung[(temp_y - y) / 2]);// h?y tô màu ? ô ?ã ch?n tr??c ?ós
			if (temp_y != y + rong * 3) // N?u mà ô ???c ch?n tr??c ?ó ch?a là ô d??i cùng thì chuy?n xu?ng 1 ô
			{
				temp_y += 2;
			}
			else // N?u mà ô ???c ch?n tr??c ?ó là ô d??i cùng thì ô ???c ch?n là ô trên cùng
			{
				temp_y = y;
			}
			to_mau(x, temp_y, rong, dai, noi_dung[(temp_y - y) / 2]); // Tô màu cho ô ch?n hi?n t?i
			goup = 0;
		}
		else if (enter == 1)
		{
			break;
		}
	}
	return (temp_y - y) / 2;
}
int menu_pause_game()
{
	resizeConsole(1300, 600);//Ch?nh s?a l?i kích th??c màn hình console

	int x = 54;
	int y = 15;
	int rong = 2;
	int dai = 40;
	int Black = 7;
	int color = 192;

	ve_pause_game();
	noCursorType();//Xóa con tr?(d?u nháy)
	char noi_dung[4][30] = { "TIEP TUC", "CHOI LAI", "HUONG DAN", "QUAY VE MENU CHINH" };
	for (int i = 0; i < 4; i++)
	{
		ve_khung_chu_nhat(x, y + i * 2, dai, rong, noi_dung[i]);
	}
	for (int i = y + rong; i <= y + rong * 3; i += 2)
	{
		gotoXY(x, i);
		cout << char(195);
		gotoXY(x + dai, i);
		cout << char(180);
	}
	gotoXY(x, y + rong * 4 + 5);

	int result = logic_pause_menu(x, y, rong, dai, noi_dung);
	TextColor(Black);
	return result;
}

int MenuTamDung()
{
	int choice = -1;
	int exit = 0;
	while (true)
	{
		if (choice == -1)
		{
			system("cls");
			choice = menu_pause_game();
		}
		else if (choice == 0)
		{
			return 0;
		}
		else if (choice == 1)
		{
			system("cls");
			return 1;
		}
		else if (choice == 2)
		{
			system("cls");
			menuHuongDanChoi();
			system("pause");
			system("cls");
			choice = -1;
		}
		else if (choice == 3)
		{
			return 2;
		}
	}
}
