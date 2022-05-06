#include "man_2.h"
#include "mylib.h"
#include "savegame.h"
#include "bangdiem.h"
#include <iostream>
#include "menu.h"
#include <Windows.h>

using namespace std;

#define LEN 1;
#define XUONG 2;
#define TRAI 3;
#define PHAI 4;
#define TUONG_TREN 3
#define TUONG_DUOI 35
#define TUONG_TRAI 3
#define TUONG_PHAI 110
/*
int x, int y truy?n t?a ?? (x, y) c?a góc trên cùng bên trái c?a vùng di chuy?n c?a con r?n
int vung_ran_di_chuyen_dai truy?n ?? dài c?a vùng di chuy?n c?a con r?n
int rong truy?n ?? r?ng c?a vùng di chuy?n c?a con r?n
ToaDo vat_can[] truy?n m?ng ch?a t?a ?? c?a các ô v?t c?n
int& vat_can_so_o truy?n bi?n ch?a t?ng s? l??ng ô v?t c?n
*/
//T?o v?t c?n màn 2
void tao_vat_can_man_2(int x, int y, int vung_ran_di_chuyen_dai, int rong, ToaDo vat_can[], int& vat_can_so_o)
{
	int khoang_cach_tu_tuong_den_vat_can = 10; // kho?ng cách t? t??ng ??n v?t c?n 
	for (int i = x + khoang_cach_tu_tuong_den_vat_can; i <= x + vung_ran_di_chuyen_dai - khoang_cach_tu_tuong_den_vat_can; i++)
	{
		//L?u t?a ?? thanh v?t c?n n?m ngang phía trên
		vat_can[vat_can_so_o].x = i;
		vat_can[vat_can_so_o].y = x + (rong / 2) / 2;
		vat_can_so_o++;

		//L?u t?a ?? thanh v?t c?n n?m ngang phía d??i
		vat_can[vat_can_so_o].x = i;
		vat_can[vat_can_so_o].y = x + rong / 2 + (rong / 2) / 2;
		vat_can_so_o++;
	}
}


//Tao qua
void FoodRound2(QUA& food, ToaDo vat_can[], int so_o_vat_can, ToaDo ran[], int ran_dot, ToaDo cong_win[], int cong_win_so_o)
{
	if (food.count < 5)
	{
		do
		{
			TaoQua1(food);
		} while (!KiemTraToaDoQuaKhaThi(food.qua1.x, food.qua1.y, vat_can, so_o_vat_can) || !KiemTraToaDoQuaKhaThi(food.qua1.x, food.qua1.y, ran, ran_dot) || !KiemTraToaDoQuaKhaThi(food.qua1.x, food.qua1.y, cong_win, cong_win_so_o));
		VeQua1(food);
	}
	else if (food.count == 5)
	{
		do
		{
			TaoQua10(food);
		} while (!KiemTraToaDoQuaKhaThi(food.qua10.x, food.qua10.y, vat_can, so_o_vat_can) || !KiemTraToaDoQuaKhaThi(food.qua10.x, food.qua10.y, ran, ran_dot) || !KiemTraToaDoQuaKhaThi(food.qua10.x, food.qua10.y, cong_win, cong_win_so_o));
		VeQua10(food);
	}
}


//An qua
void AnQua2(ToaDo ran[], QUA& food, int& ran_dot, int& SPEED, int& diem, ToaDo vat_can[], int so_o_vat_can, ToaDo cong_win[], int cong_win_so_o, int soundOn)
{
	if (food.count < 5 && ran[0].x == food.qua1.x && ran[0].y == food.qua1.y)  // +1 point , +1 dot
	{
		ran_dot++;
		diem += 2;
		SPEED -= 2;
		food.count++;
		FoodRound2(food, vat_can, so_o_vat_can, ran, ran_dot, cong_win, cong_win_so_o);
		if (soundOn == 1)
		{
			PlaySound(L"beep.wav", NULL, SND_ASYNC);
		}
	}
	else if (food.count == 5 && ran[0].x == food.qua10.x && ran[0].y == food.qua10.y) // +10 points, +1 dot
	{
		ran_dot++;
		diem += 10;
		SPEED -= 2;
		food.count = 0;
		FoodRound2(food, vat_can, so_o_vat_can, ran, ran_dot, cong_win, cong_win_so_o);
		if (soundOn == 1)
		{
			PlaySound(L"beep.wav", NULL, SND_ASYNC);
		}
	}
}



//Ki?m tra thua do ??ng v?t c?n màn 1
bool KiemTraThuaVatCan2(ToaDo ran[], ToaDo vat_can[], int so_o_vat_can)
{
	for (int i = 0; i < so_o_vat_can; i++)
	{
		if (ran[0].x == vat_can[i].x && ran[0].y == vat_can[i].y)
		{
			return true;
		}
	}
	return false;
}

//Ki?m tra thua màn 2
bool KiemTraThuaMan2(ToaDo ran[], int ran_dot, ToaDo vat_can[], int so_o_vat_can)
{
	if (RanChamThan(ran, ran_dot))
	{
		return true;
	}
	if (RanChamTuong(ran))
	{
		return true;
	}
	if (KiemTraThuaVatCan2(ran, vat_can, so_o_vat_can))
	{
		return true;
	}
	return false;
}


void Man_2(char* ten_nguoi_choi, ToaDo ran[], int& ran_dot, int x, int y, int vung_ran_di_chuyen_dai,
	int bang_diem_dai, int rong, int& diem, int& SPEED, int& huong, int& man, ToaDo vat_can[], int vat_can_so_o,
	string* data, int& nData, NguoiChoi& nguoiChoi, int STT, int soundOn)
{
	int temp = SPEED;
	tao_vat_can_man_2(x, y, vung_ran_di_chuyen_dai, rong, vat_can, vat_can_so_o);
	ve_man_choi(3, 3, vung_ran_di_chuyen_dai, bang_diem_dai, rong, vat_can, vat_can_so_o, man);//Hàm v? màn 1
	SPEED = temp;

	QUA food;
	food.count = 0;//S? l??ng qu?

	bool checkPause = false;
	int diemTam = diem;
	int ran_dot_Tam = ran_dot;
	ToaDo ranTam[100];
	for (int i = 0; i < 100; i++)  ranTam[i] = ran[i];
	int huongTemp = huong;

	VeRan(ran, ran_dot);
	ToaDo nhen[1][9];

	ToaDo cong_win[7];
	int cong_win_so_o = 0; //s? ô t?o thành 1 c?ng win

	FoodRound2(food, vat_can, vat_can_so_o, ran, ran_dot, cong_win, cong_win_so_o);
	bool win = KiemTraDieuKienThang(diem, 20 * man);
	while (1)
	{
		int huongTam = huong;
		noCursorType();//Xóa con tr?(d?u nháy)
		ve_diem(diem, x + vung_ran_di_chuyen_dai + 2, y + 2, ten_nguoi_choi); // v? ?i?m
		BatSuKien(huong, checkPause);//Nh?n phím
		ToaDo dot_cuoi_cu = DiChuyen(ran, huong, ran_dot);//Di chuy?n r?n d?a trên nút ???c nh?n trên bàn phím
		HienThiRan(ran, dot_cuoi_cu, ran_dot);//Hi?n th? thân r?n m?i sau khi di chuy?n

		if (huong == -1)
		{
			int temp_1 = STT;
			huong = huongTam;
			NutLuuGame(ten_nguoi_choi, diem, ran_dot, ran, SPEED, huong, man, 0, vat_can, nhen, data, nData, nguoiChoi, STT);
			system("cls");
			man = 0;
			break;
		}

		Sleep(SPEED);//T?c ?? r?n=100
		AnQua2(ran, food, ran_dot, SPEED, diem, vat_can, vat_can_so_o, cong_win, cong_win_so_o, soundOn);//Ki?m tra ?n qu?
		if (KiemTraThuaMan2(ran, ran_dot, vat_can, vat_can_so_o) || (win && RanChamCongWin(ran, cong_win, cong_win_so_o)))//Hàm ki?m tra thua
		{
			if (soundOn == 1)
			{
				PlaySound(L"losesound.wav", NULL, SND_SYNC);
			}
			system("cls");
			ManHinhThua(25, 15);
			gotoXY(3, 36);
			system("pause");
			system("cls");
			XoaFileText(data, nData, STT);
			//L?u thông tin ng??i ch?i (N?u n?m trong top 5 ng??i ?i?m cao nh?t)
			LuuDanhSachNguoiChoiDiemCaoNhat(ten_nguoi_choi, diem);
			man = 0;
			break;
		}
		if (checkPause == true)
		{
			int pause = MenuTamDung();

			if (pause == 0)
			{
				system("cls");
				tao_vat_can_man_2(x, y, vung_ran_di_chuyen_dai, rong, vat_can, vat_can_so_o);
				ve_man_choi(3, 3, vung_ran_di_chuyen_dai, bang_diem_dai, rong, vat_can, vat_can_so_o, man);//Hàm v? màn 1

				if (food.count < 6)
				{
					gotoXY(food.qua1.x, food.qua1.y);
					cout << "O";
				}
				else
				{
					gotoXY(food.qua10.x, food.qua10.y);
					cout << "$";
				}
			}
			if (pause == 1)
			{
				system("cls");
				tao_vat_can_man_2(x, y, vung_ran_di_chuyen_dai, rong, vat_can, vat_can_so_o);
				ve_man_choi(3, 3, vung_ran_di_chuyen_dai, bang_diem_dai, rong, vat_can, vat_can_so_o, man);//Hàm v? màn 1

				diem = diemTam;
				SPEED = temp;
				food.count = 0;
				ran_dot = ran_dot_Tam;
				for (int i = 0; i < 100; i++)  ran[i] = ranTam[i];
				huong = huongTemp;
				FoodRound2(food, vat_can, vat_can_so_o, ran, ran_dot, cong_win, cong_win_so_o);
			}
			if (pause == 2)
			{
				man = 0;
				break;
			}
			checkPause = false;
		}
		win = KiemTraDieuKienThang(diem, 5 * man); //?n qu? xong thì ki?m tra l?i xem ?i?m ?ã ?? ?? qua màn
		if (win)
		{
			XoaQua(food);
			food.count = 10;
			char huong_vao_cong[10] = "len";
			tao_cong_win(55, 18, cong_win, cong_win_so_o, huong_vao_cong);
			ve_cong_win(cong_win, cong_win_so_o);
			if (xu_ly_win(ran, cong_win))
			{
				if (soundOn == 1)
				{
					PlaySound(L"gamebeep.wav", NULL, SND_ASYNC);
				}
				man++;
				break;
			}
		}
	}
}


