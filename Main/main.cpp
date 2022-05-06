#include <iostream>
#include "mylib.h"
#include "snake.h"
#include "menu.h"
#include "man_1.h"
#include "man_2.h"
#include "man_3.h"
#include "man_4.h"
#include "boss.h"
#include "bangdiem.h"
#include "savegame.h"
#include <conio.h>
#include <string>
#include <thread>
#include <Windows.h>
using namespace std;


int main()
{
	FixConsoleWindow();
	FontSize(10, 18);
	int soundOn = 1;
	while (true)
	{
		srand(unsigned(time(NULL)));
		int x = 3;
		int y = 3;//T?a ?? x,y c?a góc trái trên c?a t??ng 
		int vung_ran_di_chuyen_dai = 107;//Chi?u dài vùng di chuy?n c?a r?n
		int bang_diem_dai = 40;//Chi?u dài b?ng ?i?m
		int rong = 32;//Chi?u r?ng vùng di chuy?n c?a r?n

		char* ten_nguoi_choi = NULL;

		ToaDo ran[100];//Khai báo m?ng t?a ?? con r?n
		int ran_dot = 1;//Khai báo bi?n ch?a s? ??t con r?n
		KhoiTaoRan(ran);

		ToaDo* vat_can;
		vat_can = new ToaDo[200];
		int vat_can_so_o = 0;

		ToaDo nhen[9][9];

		int STT = -1;
		int man = 1;
		int diem = 0;
		int SPEED = 150;
		int huong = 4;

		NguoiChoi nguoiChoi;
		nguoiChoi.ten_nguoi_choi = NULL;
		NguoiChoi* danhSachNguoiChoi = NULL;
		int nNguoiChoi = 0;

		string data[100];
		int nData = 0;
		ifstream In;
		In.open("data.txt", ios::in);
		In >> nData;
		string temp;
		getline(In, temp);
		//data = new string[nData];
		for (int i = 0; i < nData; i++)
		{
			getline(In, data[i], '\n');
		}
		In.close();
		int choice = -1;
		int exit = 0;
		while (true)
		{
			system("cls");//Xóa toàn b? màn hình console
			if (choice == -1)
			{
				system("cls");//Xóa toàn b? màn hình console
				resizeConsole(1300, 600);//Ch?nh s?a l?i kích th??c màn hình console
				ve_logo_game();
				choice = menu_new_game(soundOn);
			}
			else if (choice == 0)
			{
				system("cls");
				if (soundOn == 1)
				{
					PlaySound(L"startup.wav", NULL, SND_ASYNC);
				}
				if (man == 1)
				{
					Man_1(ten_nguoi_choi, ran, ran_dot, x, y, vung_ran_di_chuyen_dai, bang_diem_dai, rong,
						diem, SPEED, huong, man, vat_can, vat_can_so_o, data, nData, nguoiChoi, STT, soundOn);
					system("cls");
				}
				if (man == 2)
				{
					Man_2(ten_nguoi_choi, ran, ran_dot, x, y, vung_ran_di_chuyen_dai, bang_diem_dai, rong,
						diem, SPEED, huong, man, vat_can, vat_can_so_o, data, nData, nguoiChoi, STT, soundOn);
					system("cls");
				}
				if (man == 3)
				{
					Man_3(ten_nguoi_choi, ran, ran_dot, x, y, vung_ran_di_chuyen_dai, bang_diem_dai, rong,
						diem, SPEED, huong, man, vat_can, vat_can_so_o, data, nData, nguoiChoi, STT, soundOn);
					system("cls");
				}
				if (man == 4)
				{
					Man_4(ten_nguoi_choi, ran, ran_dot, x, y, vung_ran_di_chuyen_dai, bang_diem_dai, rong,
						diem, SPEED, huong, man, vat_can, vat_can_so_o, nhen, data, nData, nguoiChoi, STT, soundOn);
					system("cls");
				}
				if (man == 5)
				{
					BOSSMap(ten_nguoi_choi, x, y, vung_ran_di_chuyen_dai, bang_diem_dai, rong, man, diem, soundOn);
					system("cls");
				}

				if (man == 6)
				{
					system("cls");
					ManHinhThang();
					if (soundOn == 1)
					{
						PlaySound(L"amthanhchienthang.wav", NULL, SND_ASYNC);
					}
					gotoXY(3, 36);
					system("pause");
					system("cls");
					choice = 2;
					ran_dot = 1;
					vat_can_so_o = 0;
					huong = 4;
					diem = 0;
					KhoiTaoRan(ran);
				}

				if (man == 0)
				{
					man = 1;
					choice = -1;
					ran_dot = 1;
					vat_can_so_o = 0;
					huong = 4;
					diem = 0;
					KhoiTaoRan(ran);
					break;
				}
			}
			else if (choice == 1)
			{
				system("cls");
				int khoang_cach = 46;
				ifstream fileIn;
				danhSachNguoiChoi = XuatDanhSachNguoiChoi(fileIn, data, nData, nNguoiChoi);
				int temp = logic_load_game(x, y, khoang_cach, danhSachNguoiChoi, nNguoiChoi);
				choice = 0;
				if (temp == -1)
				{
					choice = -1;
					gotoXY(4, 10);
					system("pause");
				}
				else
				{
					LoadLaiGame(ten_nguoi_choi, diem, ran_dot, ran, SPEED, huong, man, vat_can_so_o, vat_can, nhen, danhSachNguoiChoi, temp);
					STT = temp;
				}

			}
			else if (choice == 2)
			{
				int so_luong = 0;
				BangDiem bangDiem[5];

				//??c thông tin top 5 ng??i có ?i?m cao nh?t t? file
				ifstream fileIn;
				fileIn.open("bangdiem.txt", ios::in);
				DocFileBangDiem(fileIn, bangDiem, so_luong);
				fileIn.close();

				//Xu?t thông tin top 5 ng??i có ?i?m cao nh?t ra console
				system("cls");
				GiaoDienBangDiem(x, y, vung_ran_di_chuyen_dai + bang_diem_dai, rong, bangDiem, so_luong);
				gotoXY(3, 36);
				system("pause");
				break;
			}
			else if (choice == 3)
			{
				system("cls");
				menuHuongDanChoi();
				system("pause");
				system("cls");
				choice = -1;
			}
			else if (choice == 4)
			{
				if (soundOn)
				{
					soundOn = 0;
				}
				else
				{
					soundOn = 1;
				}
				choice = -1;
			}
			else if (choice == 5)
			{
				exit = 1;
				break;
			}
		}
		delete[] vat_can;
		if (nguoiChoi.ten_nguoi_choi != NULL)
		{
			delete[] nguoiChoi.ten_nguoi_choi;
		}
		if (danhSachNguoiChoi != NULL)
		{
			delete[] danhSachNguoiChoi;
		}
		if (exit == 1)
		{
			system("cls");
			return 1;
		}
	}
	return 0;
}