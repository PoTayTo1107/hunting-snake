#include "man_1.h"
#include "man_2.h"
#include "mylib.h"
#include "snake.h"
#include "bangdiem.h"
#include <iostream>
#include "menu.h"

using namespace std;

#define LEN 1;
#define XUONG 2;
#define TRAI 3;
#define PHAI 4;
#define TUONG_TREN 3
#define TUONG_DUOI 35
#define TUONG_TRAI 3
#define TUONG_PHAI 110

void AnQua1(ToaDo ran[], QUA& food, int& ran_dot, int& SPEED, int& diem, ToaDo vat_can[], int so_o_vat_can, ToaDo cong_win[], int cong_win_so_o, int soundOn)
{
	AnQua2(ran, food, ran_dot, SPEED, diem, vat_can, so_o_vat_can, cong_win, cong_win_so_o, soundOn);
}

//Ki?m tra thua màn 1
bool KiemTraThuaMan1(ToaDo ran[], int ran_dot, ToaDo vat_can[], int so_o_vat_can)
{
	if (RanChamThan(ran, ran_dot))
	{
		return true;
	}
	if (RanChamTuong(ran))
	{
		return true;
	}
	return false;
}


void Man_1(char* ten_nguoi_choi, ToaDo ran[], int& ran_dot, int x, int y, int vung_ran_di_chuyen_dai,
	int bang_diem_dai, int rong, int& diem, int& SPEED, int& huong, int& man, ToaDo vat_can[], int vat_can_so_o,
	string* data, int& nData, NguoiChoi& nguoiChoi, int STT, int soundOn)
{
	char huong_vao_cong[] = "len";
	int temp = SPEED;
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

	TaoQua1(food);//T?o qu? ??u tiên
	VeQua1(food);
	VeRan(ran, ran_dot);
	ToaDo nhen[1][9];

	ToaDo cong_win[7];
	int cong_win_so_o = 0; //s? ô t?o thành 1 c?ng win

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
		AnQua1(ran, food, ran_dot, SPEED, diem, vat_can, vat_can_so_o, cong_win, cong_win_so_o, soundOn);//Ki?m tra ?n qu?

		if (KiemTraThuaMan1(ran, ran_dot, vat_can, vat_can_so_o) || (win && RanChamCongWin(ran, cong_win, cong_win_so_o)))//Hàm ki?m tra thua
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
				ve_man_choi(3, 3, vung_ran_di_chuyen_dai, bang_diem_dai, rong, vat_can, vat_can_so_o, man);//Hàm v? màn 1

				diem = diemTam;
				SPEED = temp;
				food.count = 0;
				ran_dot = ran_dot_Tam;
				for (int i = 0; i < 100; i++)  ran[i] = ranTam[i];
				huong = huongTemp;
				TaoQua1(food);//T?o qu? ??u tiên
				VeQua1(food);
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


