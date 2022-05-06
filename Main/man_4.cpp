#include "man_4.h"
#include "mylib.h"
#include "menu.h"
#include "bangdiem.h"
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

#define gachxeotrai (char)92
#define gachduoi (char) 95
#define gachxeophai (char)47
#define mongoac (char)40
#define dongngoac (char)41
#define gachdung (char)124


void VeVatCanBenTrongManBon(ToaDo vat_can[], int& so_o_vat_can)
{
	so_o_vat_can = 0;
	for (int i = 0; i < 20; i++)//Tuong 1(vat_can[0]->vat_can[19]
	{
		vat_can[i].x = i + 15;
		vat_can[i].y = 8;
		gotoXY(vat_can[i].x, vat_can[i].y);
		cout << char(219);
		so_o_vat_can++;
	}
	for (int i = 20; i < 27; i++)//Tuong 2(vat_can[20]->vat_can[26]
	{
		vat_can[i].x = 15;
		vat_can[i].y = i - 20 + 9;
		gotoXY(vat_can[i].x, vat_can[i].y);
		cout << char(219);
		so_o_vat_can++;
	}
	for (int i = 27; i < 47; i++)//Tuong 3(vat_can[27]->vat_can[46]
	{
		vat_can[i].x = i - 27 + 15;
		vat_can[i].y = 30;
		gotoXY(vat_can[i].x, vat_can[i].y);
		cout << char(219);
		so_o_vat_can++;
	}
	for (int i = 47; i < 54; i++)//Tuong 4
	{
		vat_can[i].x = 15;
		vat_can[i].y = i - 32 + 8;
		gotoXY(vat_can[i].x, vat_can[i].y);
		cout << char(219);
		so_o_vat_can++;
	}
	for (int i = 54; i < 74; i++)//Tuong 5
	{
		vat_can[i].x = TUONG_PHAI - 32 + i - 54;
		vat_can[i].y = 8;
		gotoXY(vat_can[i].x, vat_can[i].y);
		cout << char(219);
		so_o_vat_can++;
	}
	for (int i = 74; i < 81; i++)//Tuong 6
	{
		vat_can[i].x = TUONG_PHAI - 13;
		vat_can[i].y = i - 74 + 9;
		gotoXY(vat_can[i].x, vat_can[i].y);
		cout << char(219);
		so_o_vat_can++;
	}
	for (int i = 81; i < 101; i++)//TUOng 7
	{
		vat_can[i].x = TUONG_PHAI - 32 + i - 81;
		vat_can[i].y = 30;
		gotoXY(vat_can[i].x, vat_can[i].y);
		cout << char(219);
		so_o_vat_can++;
	}
	for (int i = 101; i < 108; i++)//Tuong 8
	{
		vat_can[i].x = TUONG_PHAI - 13;
		vat_can[i].y = i - 101 + 23;
		gotoXY(vat_can[i].x, vat_can[i].y);
		cout << char(219);
		so_o_vat_can++;
	}
	for (int i = 108; i < 128; i++)
	{
		vat_can[i].x = TUONG_TRAI + 24 + i - 108;
		vat_can[i].y = 12;
		gotoXY(vat_can[i].x, vat_can[i].y);
		cout << char(219);
		so_o_vat_can++;
	}
	for (int i = 128; i < 148; i++)
	{
		vat_can[i].x = TUONG_TRAI + 24 + i - 128;
		vat_can[i].y = 26;
		gotoXY(vat_can[i].x, vat_can[i].y);
		cout << char(219);
		so_o_vat_can++;
	}
	for (int i = 148; i < 161; i++)
	{
		vat_can[i].x = 26;
		vat_can[i].y = 13 + i - 148;
		gotoXY(vat_can[i].x, vat_can[i].y);
		cout << char(219);
		so_o_vat_can++;
	}
	for (int i = 161; i < 181; i++)
	{
		vat_can[i].x = TUONG_PHAI - 13 - 31 + i - 161;
		vat_can[i].y = 26;
		gotoXY(vat_can[i].x, vat_can[i].y);
		cout << char(219);
		so_o_vat_can++;
	}
	for (int i = 181; i < 201; i++)
	{
		vat_can[i].x = TUONG_PHAI - 13 - 31 + i - 181;
		vat_can[i].y = 12;
		gotoXY(vat_can[i].x, vat_can[i].y);
		cout << char(219);
		so_o_vat_can++;
	}
	for (int i = 148; i < 161; i++)
	{
		vat_can[i].x = 86;
		vat_can[i].y = 13 + i - 148;
		gotoXY(vat_can[i].x, vat_can[i].y);
		cout << char(219);
		so_o_vat_can++;
	}
}
void TaoVatCanDiChuyenTuTrai(ToaDo vat_di_chuyen_1_1[], int do_dai_vat_can, int deltaX, int deltaY)
{
	for (int i = 0; i < do_dai_vat_can; i++)
	{
		vat_di_chuyen_1_1[0].x = TUONG_TRAI + do_dai_vat_can - i;
		vat_di_chuyen_1_1[0].y = 17 + deltaY;;
	}
}
void TaoVatCanDiChuyenTuPhai(ToaDo vat_di_chuyen[], int do_dai_vat_can, int deltaX, int deltaY)
{
	for (int i = do_dai_vat_can - 1; i >= 0; i--)
	{
		vat_di_chuyen[0].x = TUONG_PHAI - do_dai_vat_can - i + deltaX;
		vat_di_chuyen[0].y = 17 + deltaY;;
	}
}
void HienThiVatDiChuyen(ToaDo vat_di_chuyen_1[], int do_dai_vat_can, ToaDo dot_cuoi_cu)
{
	for (int i = 0; i < do_dai_vat_can; i++)
	{
		gotoXY(vat_di_chuyen_1[i].x, vat_di_chuyen_1[i].y);
		cout << "S";
	}
	gotoXY(dot_cuoi_cu.x, dot_cuoi_cu.y);
	cout << " ";
}
void DiChuyenVatCanDiChuyenTuTrai(ToaDo vat_di_chuyen_1[], int do_dai_vat_can, ToaDo& dot_cuoi_cu, int deltaX, int deltaY)
{
	dot_cuoi_cu.x = vat_di_chuyen_1[do_dai_vat_can - 1].x;
	dot_cuoi_cu.y = vat_di_chuyen_1[do_dai_vat_can - 1].y;
	for (int i = do_dai_vat_can - 1; i >= 1; i--)
	{
		vat_di_chuyen_1[i].x = vat_di_chuyen_1[i - 1].x;
		vat_di_chuyen_1[i].y = vat_di_chuyen_1[i - 1].y;
	}
	if (vat_di_chuyen_1[0].x == 22 + deltaX && vat_di_chuyen_1[0].y + deltaY != 10)
	{
		vat_di_chuyen_1[0].y--;
	}
	else if (vat_di_chuyen_1[0].x + deltaX == TUONG_PHAI - 18 && vat_di_chuyen_1[0].y + deltaY >= 10 && vat_di_chuyen_1[0].y + deltaY <= 18)
	{
		vat_di_chuyen_1[0].y++;
	}
	else
	{
		vat_di_chuyen_1[0].x++;
	}

	HienThiVatDiChuyen(vat_di_chuyen_1, do_dai_vat_can, dot_cuoi_cu);
}
void DiChuyenVatCanDiChuyenTuPhai(ToaDo vat_di_chuyen_1[], int do_dai_vat_can, ToaDo& dot_cuoi_cu, int deltaX, int deltaY)
{
	dot_cuoi_cu.x = vat_di_chuyen_1[do_dai_vat_can - 1].x;
	dot_cuoi_cu.y = vat_di_chuyen_1[do_dai_vat_can - 1].y;
	for (int i = do_dai_vat_can - 1; i >= 1; i--)
	{
		vat_di_chuyen_1[i].x = vat_di_chuyen_1[i - 1].x;
		vat_di_chuyen_1[i].y = vat_di_chuyen_1[i - 1].y;
	}
	if (vat_di_chuyen_1[0].x == TUONG_PHAI - 18 + deltaX && vat_di_chuyen_1[0].y + deltaY != 27)
	{
		vat_di_chuyen_1[0].y++;
	}
	else if (vat_di_chuyen_1[0].x + deltaX == TUONG_TRAI + 16 && vat_di_chuyen_1[0].y + deltaY >= 20 && vat_di_chuyen_1[0].y + deltaY <= 27)
	{
		vat_di_chuyen_1[0].y--;
	}
	else
	{
		vat_di_chuyen_1[0].x--;
	}

	HienThiVatDiChuyen(vat_di_chuyen_1, do_dai_vat_can, dot_cuoi_cu);
}
void VeManBon(ToaDo tuong_trong[], int& so_o_vat_can, int x, int y, int vung_ran_di_chuyen_dai, int bang_diem_dai, int rong, int man)
{
	VeVatCanBenTrongManBon(tuong_trong, so_o_vat_can);
	resizeConsole(2000, 1200);
	FixConsoleWindow();
	ve_vung_ran_di_chuyen(x, y, vung_ran_di_chuyen_dai, rong);
	ve_bang_diem(x + vung_ran_di_chuyen_dai + 1, y, bang_diem_dai, rong, man);
}
void TaoNhen(ToaDo nhen[][9])
{
	nhen[2][0].x = 54; nhen[2][0].y = TUONG_TREN + 1;
	nhen[6][0].x = 58; nhen[6][0].y = TUONG_TREN + 1;
	for (int i = 0; i < 9; i++)
	{
		nhen[i][1].x = 52 + i; nhen[i][1].y = TUONG_TREN + 2;
	}
	for (int i = 1; i < 8; i++)
	{
		nhen[i][2].x = 53 + i - 1; nhen[i][2].y = TUONG_TREN + 3;
	}
	nhen[3][3].x = 55; nhen[3][3].y = TUONG_TREN + 4;
	nhen[5][3].x = 57; nhen[5][3].y = TUONG_TREN + 4;
}
void HienThiNhen(ToaDo nhen[][9])
{
	gotoXY(nhen[2][0].x, nhen[2][0].y); cout << gachxeophai;
	gotoXY(nhen[6][0].x, nhen[6][0].y); cout << (char)92;
	char a[] = { gachxeotrai,gachduoi,gachxeotrai,mongoac,gachduoi,dongngoac,gachxeophai,gachduoi,gachxeophai };
	for (int i = 0; i < 9; i++)
	{
		gotoXY(nhen[i][1].x, nhen[i][1].y); cout << a[i];
	}
	char b[] = { 'x', gachduoi,gachxeophai,gachdung,'O',gachdung,gachxeotrai,gachduoi };
	for (int i = 1; i < 8; i++)
	{
		gotoXY(nhen[i][2].x, nhen[i][2].y); cout << b[i];
	}
	gotoXY(nhen[3][3].x, nhen[3][3].y); cout << gachxeotrai;
	gotoXY(nhen[5][3].x, nhen[5][3].y); cout << gachxeophai;
}
void DiChuyenNhen(ToaDo nhen[][9], ToaDo dot_cuoi_cu[])
{
	for (int i = 0; i < 9; i++)
	{
		dot_cuoi_cu[i].x = nhen[i][1].x; dot_cuoi_cu[i].y = nhen[i][1].y;
	}
	gotoXY(53, 7); cout << " ";
	dot_cuoi_cu[2].x = nhen[2][0].x; dot_cuoi_cu[2].y = nhen[2][0].y;
	dot_cuoi_cu[6].x = nhen[6][0].x; dot_cuoi_cu[6].y = nhen[6][0].y;
	nhen[0][1].y++; nhen[8][1].y++;
	nhen[2][0].y++; nhen[6][0].y++;
	for (int i = 1; i < 8; i++)
	{
		nhen[i][1].y++;
		nhen[i][2].y++;
	}
	nhen[3][3].y++; nhen[5][3].y++;
	for (int i = 0; i < 9; i++)
	{
		gotoXY(dot_cuoi_cu[i].x, dot_cuoi_cu[i].y); cout << " ";
	}
	HienThiNhen(nhen);
}
bool RanChamNhen(ToaDo ran[], int ran_dot, ToaDo nhen[][9])
{
	for (int j = 0; j < ran_dot; j++)
	{
		if (ran[j].x == nhen[2][0].x && ran[j].y == nhen[2][0].y)
		{
			return true;
		}
		if (ran[j].x == nhen[6][0].x && ran[j].y == nhen[6][0].y)
		{
			return true;
		}
		for (int i = 0; i < 9; i++)
		{
			if (ran[j].x == nhen[i][1].x && ran[j].y == nhen[i][1].y)
			{
				return true;
			}
		}
		for (int i = 1; i < 8; i++)
		{
			if (ran[j].x == nhen[i][2].x && ran[j].y == nhen[i][2].y)
			{
				return true;
			}
		}
		if (ran[j].x == nhen[3][3].x && ran[j].y == nhen[3][3].y)
		{
			return true;
		}
		if (ran[j].x == nhen[5][3].x && ran[j].y == nhen[5][3].y)
		{
			return true;
		}
	}
	return false;
}

bool RanChamVatDiChuyenMan4(ToaDo ran[], int ran_dot, ToaDo vat_di_chuyen_1_1[], ToaDo vat_di_chuyen_1_2[], ToaDo vat_di_chuyen_2_1[], ToaDo vat_di_chuyen_2_2[], int do_dai_vat_can)
{
	for (int i = 0; i < do_dai_vat_can; i++)
	{
		for (int j = 0; j < ran_dot; j++)
		{
			if (ran[j].x == vat_di_chuyen_1_1[i].x && ran[j].y == vat_di_chuyen_1_1[i].y)
			{
				return true;
			}
			if (ran[j].x == vat_di_chuyen_1_2[i].x && ran[j].y == vat_di_chuyen_1_2[i].y)
			{
				return true;
			}
			if (ran[j].x == vat_di_chuyen_2_1[i].x && ran[j].y == vat_di_chuyen_2_1[i].y)
			{
				return true;
			}
			if (ran[j].x == vat_di_chuyen_2_2[i].x && ran[j].y == vat_di_chuyen_2_2[i].y)
			{
				return true;
			}
		}
	}
	return false;
}

bool RanChamVatCanTinhMan4(ToaDo ran[], int ran_dot, ToaDo tuong_trong[], int so_o_tuong_trong)
{
	for (int i = 0; i < so_o_tuong_trong; i++)
	{
		if (ran[0].x == tuong_trong[i].x && ran[0].y == tuong_trong[i].y)
		{
			return true;
		}
	}
	return false;
}

bool KiemTraThuaVatCan_4(ToaDo ran[], ToaDo vat_di_chuyen_1_1[], ToaDo vat_di_chuyen_1_2[], ToaDo vat_di_chuyen_2_1[], ToaDo vat_di_chuyen_2_2[], int do_dai_vat_can, ToaDo nhen[][9], ToaDo tuong_trong[], int so_o_tuong_trong, int ran_dot)
{
	if (RanChamVatDiChuyenMan4(ran, ran_dot, vat_di_chuyen_1_1, vat_di_chuyen_1_2, vat_di_chuyen_2_1, vat_di_chuyen_2_2, do_dai_vat_can))
	{
		return true;
	}
	if (RanChamNhen(ran, ran_dot, nhen))
	{
		return true;
	}
	if (RanChamVatCanTinhMan4(ran, ran_dot, tuong_trong, so_o_tuong_trong))
	{
		return true;
	}
	return false;
}
bool KiemTraThuaManBon(ToaDo ran[], int ran_dot, ToaDo vat_di_chuyen_1_1[], ToaDo vat_di_chuyen_1_2[], ToaDo vat_di_chuyen_2_1[], ToaDo vat_di_chuyen_2_2[], int do_dai_vat_can, ToaDo nhen[][9], ToaDo tuong_trong[], int so_o_tuong_trong)
{
	if (RanChamThan(ran, ran_dot))
	{
		return true;
	}
	if (RanChamTuong(ran))
	{
		return true;
	}
	if (KiemTraThuaVatCan_4(ran, vat_di_chuyen_1_1, vat_di_chuyen_1_2, vat_di_chuyen_2_1, vat_di_chuyen_2_2, do_dai_vat_can, nhen, tuong_trong, so_o_tuong_trong, ran_dot))
	{
		return true;
	}
	return false;
}
bool KiemTraToaDoQuaKhaThiMan4(int x, int y, ToaDo vat_di_chuyen_1_1[], ToaDo vat_di_chuyen_1_2[], ToaDo vat_di_chuyen_2_1[], ToaDo vat_di_chuyen_2_2[], int do_dai_vat_can, ToaDo nhen[][9], ToaDo tuong_trong[], int so_o_tuong_trong)
{
	//Kiem tra voi vat di chuyen
	for (int i = 0; i < do_dai_vat_can; i++)
	{
		if (x == vat_di_chuyen_1_1[i].x && y == vat_di_chuyen_1_1[i].y)
		{
			return true;
		}
		if (x == vat_di_chuyen_1_2[i].x && y == vat_di_chuyen_1_2[i].y)
		{
			return true;
		}
		if (x == vat_di_chuyen_2_1[i].x && y == vat_di_chuyen_2_1[i].y)
		{
			return true;
		}
		if (x == vat_di_chuyen_2_2[i].x && y == vat_di_chuyen_2_2[i].y)
		{
			return true;
		}
	}
	//Kiem tra voi nhen
	if (x == nhen[2][0].x && y == nhen[2][0].y)
	{
		return true;
	}
	if (x == nhen[6][0].x && y == nhen[6][0].y)
	{
		return true;
	}
	for (int i = 0; i < 9; i++)
	{
		if (x == nhen[i][1].x && y == nhen[i][1].y)
		{
			return true;
		}
	}
	for (int i = 1; i < 8; i++)
	{
		if (x == nhen[i][2].x && y == nhen[i][2].y)
		{
			return true;
		}
	}
	if (x == nhen[3][3].x && y == nhen[3][3].y)
	{
		return true;
	}
	if (x == nhen[5][3].x && y == nhen[5][3].y)
	{
		return true;
	}
	//Kiem tra voi tuong trong
	for (int i = 0; i < so_o_tuong_trong; i++)
	{
		if (x == tuong_trong[i].x && y == tuong_trong[i].y)
		{
			return true;
		}
	}
	return false;
}

void FoodMan4(QUA& food, ToaDo vat_di_chuyen_1_1[], ToaDo vat_di_chuyen_1_2[], ToaDo vat_di_chuyen_2_1[], ToaDo vat_di_chuyen_2_2[], int do_dai_vat_can, ToaDo nhen[][9], ToaDo tuong_trong[], int so_o_tuong_trong, ToaDo cong_win[], int cong_win_so_o)
{
	if (food.count < 5)
	{
		do
		{
			TaoQua1(food);
		} while (KiemTraToaDoQuaKhaThiMan4(food.qua1.x, food.qua1.y, vat_di_chuyen_1_1, vat_di_chuyen_1_2, vat_di_chuyen_2_1, vat_di_chuyen_2_2, do_dai_vat_can, nhen, tuong_trong, so_o_tuong_trong)
			|| !KiemTraToaDoQuaKhaThi(food.qua1.x, food.qua1.y, cong_win, cong_win_so_o));
		VeQua1(food);
	}
	else if (food.count == 5)
	{
		do
		{
			TaoQua10(food);
		} while (KiemTraToaDoQuaKhaThiMan4(food.qua10.x, food.qua10.y, vat_di_chuyen_1_1, vat_di_chuyen_1_2, vat_di_chuyen_2_1, vat_di_chuyen_2_2, do_dai_vat_can, nhen, tuong_trong, so_o_tuong_trong)
			|| !KiemTraToaDoQuaKhaThi(food.qua10.x, food.qua10.y, cong_win, cong_win_so_o));
		VeQua10(food);
	}
	else if (food.count == 6)
	{
		do
		{
			TaoQuaDoc(food);
		} while (KiemTraToaDoQuaKhaThiMan4(food.quaDoc.x, food.quaDoc.y, vat_di_chuyen_1_1, vat_di_chuyen_1_2, vat_di_chuyen_2_1, vat_di_chuyen_2_2, do_dai_vat_can, nhen, tuong_trong, so_o_tuong_trong)
			|| !KiemTraToaDoQuaKhaThi(food.quaDoc.x, food.quaDoc.y, cong_win, cong_win_so_o));
		VeQuaDoc(food);
	}
}
void AnQuaMan4(ToaDo ran[], QUA& food, int& ran_dot, int& trung_doc, int& SPEED, int& diem, ToaDo vat_di_chuyen_1_1[], ToaDo vat_di_chuyen_1_2[],
	ToaDo vat_di_chuyen_2_1[], ToaDo vat_di_chuyen_2_2[], int do_dai_vat_can, ToaDo nhen[][9], ToaDo tuong_trong[], int so_o_tuong_trong, ToaDo cong_win[], int cong_win_so_o, int soundOn)
{
	if (food.count < 5 && ran[0].x == food.qua1.x && ran[0].y == food.qua1.y)  // +1 point , +1 dot
	{
		ran_dot++;
		SPEED -= 2;
		diem += 2;
		trung_doc = 0;
		food.count++;
		FoodMan4(food, vat_di_chuyen_1_1, vat_di_chuyen_1_2, vat_di_chuyen_2_1, vat_di_chuyen_2_2, do_dai_vat_can, nhen, tuong_trong, so_o_tuong_trong, cong_win, cong_win_so_o);
		if (soundOn == 1)
		{
			PlaySound(L"beep.wav", NULL, SND_ASYNC);
		}
	}
	else if (food.count == 5 && ran[0].x == food.qua10.x && ran[0].y == food.qua10.y) // +10 points, +1 dot
	{
		ran_dot++;
		SPEED -= 5;
		diem += 10;
		food.count++;
		FoodMan4(food, vat_di_chuyen_1_1, vat_di_chuyen_1_2, vat_di_chuyen_2_1, vat_di_chuyen_2_2, do_dai_vat_can, nhen, tuong_trong, so_o_tuong_trong, cong_win, cong_win_so_o);
		if (soundOn == 1)
		{
			PlaySound(L"beep.wav", NULL, SND_ASYNC);
		}
	}
	else if (food.count == 6 && ran[0].x == food.quaDoc.x && ran[0].y == food.quaDoc.y) // trúng ??c, -1 ??t
	{
		trung_doc = 1;
		diem += 10;
		SPEED -= 10;
		food.count = 0;
		FoodMan4(food, vat_di_chuyen_1_1, vat_di_chuyen_1_2, vat_di_chuyen_2_1, vat_di_chuyen_2_2, do_dai_vat_can, nhen, tuong_trong, so_o_tuong_trong, cong_win, cong_win_so_o);
		if (soundOn == 1)
		{
			PlaySound(L"uhuhuh.wav", NULL, SND_ASYNC);
		}
	}
}
void Man_4(char* ten_nguoi_choi, ToaDo ran[], int& ran_dot, int x, int y, int vung_ran_di_chuyen_dai,
	int bang_diem_dai, int rong, int& diem, int& SPEED, int& huong, int& man, ToaDo vat_can[], int vat_can_so_o, ToaDo nhen[][9],
	string* data, int& nData, NguoiChoi& nguoiChoi, int STT, int soundOn)
{
	ToaDo tuong_trong[300];
	int so_o_tuong_trong = 0;
	VeManBon(tuong_trong, so_o_tuong_trong, 3, 3, 107, 40, 32, man);

	ToaDo vat_di_chuyen_1_1[10];
	ToaDo dot_cuoi_cu_1;
	int do_dai_vat_can = 10;
	ToaDo vat_di_chuyen_1_2[10];
	ToaDo dot_cuoi_cu_2;

	ToaDo vat_di_chuyen_2_1[10];
	ToaDo dot_cuoi_cu_2_1;
	ToaDo vat_di_chuyen_2_2[10];
	ToaDo dot_cuoi_cu_2_2;
	if (vat_can_so_o == 0)
	{
		TaoVatCanDiChuyenTuTrai(vat_di_chuyen_1_1, do_dai_vat_can, 0, 0);
		TaoVatCanDiChuyenTuTrai(vat_di_chuyen_1_2, do_dai_vat_can, 0, 1);
		TaoVatCanDiChuyenTuPhai(vat_di_chuyen_2_1, do_dai_vat_can, 0, 0);
		TaoVatCanDiChuyenTuPhai(vat_di_chuyen_2_2, do_dai_vat_can, 0, 1);
	}
	else
	{
		Tach1MangVaoNhieuMang(vat_can, vat_can_so_o, vat_di_chuyen_1_1, vat_di_chuyen_1_2, vat_di_chuyen_2_1, vat_di_chuyen_2_2, do_dai_vat_can);
	}

	ToaDo dot_cuoi_cu_nhen[9];
	TaoNhen(nhen);

	QUA food;
	food.count = 0;//S? l??ng qu?

	bool checkPause = false;
	int diemTam = diem;
	int ran_dot_Tam = ran_dot;
	ToaDo ranTam[100];
	for (int i = 0; i < 100; i++)  ranTam[i] = ran[i];
	int huongTemp = huong;
	int trung_doc = 0;

	ToaDo cong_win[7];
	int cong_win_so_o = 0; //s? ô t?o thành 1 c?ng win

	FoodMan4(food, vat_di_chuyen_1_1, vat_di_chuyen_1_2, vat_di_chuyen_2_1, vat_di_chuyen_2_2, do_dai_vat_can, nhen, tuong_trong, so_o_tuong_trong, cong_win, cong_win_so_o);
	bool win = KiemTraDieuKienThang(diem, 20 * man);
	while (1)
	{
		int thoat = 0;
		VeManBon(tuong_trong, so_o_tuong_trong, 3, 3, 107, 40, 32, man);
		int dem = 0;
		while (1)
		{
			int huongTam = huong; //Bi?n l?u t?m h??ng di chuy?n c?a r?n
			noCursorType();//Xóa con tr?(d?u nháy)
			ve_diem(diem, x + vung_ran_di_chuyen_dai + 2, y + 2, ten_nguoi_choi); // v? ?i?m
			BatSuKien(huong, checkPause);//Nh?n phím
			ToaDo dot_cuoi_cu = DiChuyen(ran, huong, ran_dot);//Di chuy?n r?n d?a trên nút ???c nh?n trên bàn phím
			HienThiRan(ran, dot_cuoi_cu, ran_dot);//Hi?n th? thân r?n m?i sau khi di chuy?n
			if (huong == -1)
			{
				huong = huongTam;
				LuuNhieuMangVao1Mang(vat_can, vat_can_so_o, vat_di_chuyen_1_1, vat_di_chuyen_1_2, vat_di_chuyen_2_1, vat_di_chuyen_2_2, do_dai_vat_can);
				NutLuuGame(ten_nguoi_choi, diem, ran_dot, ran, SPEED, huong, man, vat_can_so_o, vat_can, nhen, data, nData, nguoiChoi, STT);
				system("cls");
				thoat = 1;
				man = 0;
				break;
			}
			noCursorType();
			DiChuyenVatCanDiChuyenTuPhai(vat_di_chuyen_2_1, do_dai_vat_can, dot_cuoi_cu_2_1, 0, 0);
			DiChuyenVatCanDiChuyenTuPhai(vat_di_chuyen_2_2, do_dai_vat_can, dot_cuoi_cu_2_2, 1, -1);
			DiChuyenVatCanDiChuyenTuTrai(vat_di_chuyen_1_1, do_dai_vat_can, dot_cuoi_cu_1, 0, 0);
			DiChuyenVatCanDiChuyenTuTrai(vat_di_chuyen_1_2, do_dai_vat_can, dot_cuoi_cu_2, 1, -1);
			if (dem % 2 == 0)
			{
				DiChuyenNhen(nhen, dot_cuoi_cu_nhen);
			}
			dem++;
			AnQuaMan4(ran, food, ran_dot, trung_doc, SPEED, diem, vat_di_chuyen_1_1, vat_di_chuyen_1_2, vat_di_chuyen_2_1, vat_di_chuyen_2_2, do_dai_vat_can, nhen, tuong_trong, so_o_tuong_trong, cong_win, cong_win_so_o, soundOn);//Ki?m tra ?n qu?

			//Reset vat can dông khi g?p t??ng
			if (vat_di_chuyen_1_1[0].x == TUONG_PHAI - 1)
			{
				TaoVatCanDiChuyenTuTrai(vat_di_chuyen_1_1, do_dai_vat_can, 0, 0);
				TaoVatCanDiChuyenTuTrai(vat_di_chuyen_1_2, do_dai_vat_can, 0, 1);
				gotoXY(TUONG_PHAI - 1, 19); cout << " ";
				gotoXY(TUONG_PHAI - 1, 20); cout << " ";
			}
			//Reset vat can dông khi g?p t??ng
			if (vat_di_chuyen_2_1[0].x == TUONG_TRAI + 1)
			{
				TaoVatCanDiChuyenTuPhai(vat_di_chuyen_2_1, do_dai_vat_can, +7, 0);
				TaoVatCanDiChuyenTuPhai(vat_di_chuyen_2_2, do_dai_vat_can, +7, 1);
				gotoXY(TUONG_TRAI + 1, 19); cout << " ";
				gotoXY(TUONG_TRAI + 1, 20); cout << " ";
			}
			//Reset nh?n khi ch?m t??ng d??i
			if (nhen[3][3].y == TUONG_DUOI - 1)
			{
				for (int i = 0; i < 9; i++)
				{
					gotoXY(nhen[i][1].x, nhen[i][1].y); cout << " ";
					if (i >= 1 && i < 8)
					{
						gotoXY(nhen[i][2].x, nhen[i][2].y); cout << " ";
					}
				}
				gotoXY(nhen[2][0].x, nhen[2][0].y); cout << " ";
				gotoXY(nhen[6][0].x, nhen[6][0].y); cout << " ";
				gotoXY(nhen[3][3].x, nhen[3][3].y); cout << " ";
				gotoXY(nhen[5][3].x, nhen[5][3].y); cout << " ";
				TaoNhen(nhen);
			}
			if (food.count < 5)
			{
				if (KiemTraToaDoQuaKhaThiMan4(food.qua1.x, food.qua1.y, vat_di_chuyen_1_1, vat_di_chuyen_1_2, vat_di_chuyen_2_1, vat_di_chuyen_2_2, do_dai_vat_can, nhen, tuong_trong, so_o_tuong_trong))
				{
					FoodMan4(food, vat_di_chuyen_1_1, vat_di_chuyen_1_2, vat_di_chuyen_2_1, vat_di_chuyen_2_2, do_dai_vat_can, nhen, tuong_trong, so_o_tuong_trong, cong_win, cong_win_so_o);
				}
			}
			else if (food.count == 5)
			{
				if (KiemTraToaDoQuaKhaThiMan4(food.qua10.x, food.qua10.y, vat_di_chuyen_1_1, vat_di_chuyen_1_2, vat_di_chuyen_2_1, vat_di_chuyen_2_2, do_dai_vat_can, nhen, tuong_trong, so_o_tuong_trong))
				{
					FoodMan4(food, vat_di_chuyen_1_1, vat_di_chuyen_1_2, vat_di_chuyen_2_1, vat_di_chuyen_2_2, do_dai_vat_can, nhen, tuong_trong, so_o_tuong_trong, cong_win, cong_win_so_o);
				}
			}
			else
			{
				if (KiemTraToaDoQuaKhaThiMan4(food.quaDoc.x, food.quaDoc.y, vat_di_chuyen_1_1, vat_di_chuyen_1_2, vat_di_chuyen_2_1, vat_di_chuyen_2_2, do_dai_vat_can, nhen, tuong_trong, so_o_tuong_trong))
				{
					FoodMan4(food, vat_di_chuyen_1_1, vat_di_chuyen_1_2, vat_di_chuyen_2_1, vat_di_chuyen_2_2, do_dai_vat_can, nhen, tuong_trong, so_o_tuong_trong, cong_win, cong_win_so_o);
				}
			}
			//gotoXY(1, 1); cout << SPEED;
			Sleep(SPEED);//T?c ?? r?n=100
			if (KiemTraThuaManBon(ran, ran_dot, vat_di_chuyen_1_1, vat_di_chuyen_1_2, vat_di_chuyen_2_1, vat_di_chuyen_2_2, do_dai_vat_can, nhen, tuong_trong, so_o_tuong_trong) || (win && RanChamCongWin(ran, cong_win, cong_win_so_o)))//Hàm ki?m tra thua
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
				thoat = 1;
				break;
			}

			if (checkPause == true)
			{
				int pause = MenuTamDung();

				if (pause == 0)
				{
					system("cls");
					VeManBon(tuong_trong, so_o_tuong_trong, 3, 3, 107, 40, 32, man);

					if (food.count < 6)
					{
						gotoXY(food.qua1.x, food.qua1.y);
						cout << "O";
					}
					else if (food.count == 6)
					{
						gotoXY(food.qua10.x, food.qua10.y);
						cout << "$";
					}
					else if (food.count == 7)
					{
						gotoXY(food.quaDoc.x, food.quaDoc.y);
						cout << "O";
					}
				}
				if (pause == 1)
				{
					system("cls");

					VeManBon(tuong_trong, so_o_tuong_trong, 3, 3, 107, 40, 32, man);
					if (vat_can_so_o == 0)
					{
						TaoVatCanDiChuyenTuTrai(vat_di_chuyen_1_1, do_dai_vat_can, 0, 0);
						TaoVatCanDiChuyenTuTrai(vat_di_chuyen_1_2, do_dai_vat_can, 0, 1);
						TaoVatCanDiChuyenTuPhai(vat_di_chuyen_2_1, do_dai_vat_can, 0, 0);
						TaoVatCanDiChuyenTuPhai(vat_di_chuyen_2_2, do_dai_vat_can, 0, 1);
					}
					else
					{
						Tach1MangVaoNhieuMang(vat_can, vat_can_so_o, vat_di_chuyen_1_1, vat_di_chuyen_1_2, vat_di_chuyen_2_1, vat_di_chuyen_2_2, do_dai_vat_can);
					}
					diem = diemTam;
					food.count = 0;
					ran_dot = ran_dot_Tam;
					for (int i = 0; i < 100; i++)  ran[i] = ranTam[i];
					huong = huongTemp;
					TaoNhen(nhen);
					FoodMan4(food, vat_di_chuyen_1_1, vat_di_chuyen_1_2, vat_di_chuyen_2_1, vat_di_chuyen_2_2, do_dai_vat_can, nhen, tuong_trong, so_o_tuong_trong, cong_win, cong_win_so_o);
				}
				if (pause == 2)
				{
					man = 0;
					thoat = 1;
					break;
				}
				checkPause = false;
			}

			win = KiemTraDieuKienThang(diem, 5 * man ); //?n qu? xong thì ki?m tra l?i xem ?i?m ?ã ?? ?? qua màn
			if (win)
			{
				XoaQua(food);
				food.count = 10;
				char huong_vao_cong[] = "trai";
				tao_cong_win(x + vung_ran_di_chuyen_dai - 5, 28, cong_win, cong_win_so_o, huong_vao_cong);
				ve_cong_win(cong_win, cong_win_so_o);
				if (xu_ly_win(ran, cong_win))
				{
					if (soundOn == 1)
					{
						PlaySound(L"gamebeep.wav", NULL, SND_ASYNC);
					}
					man++;
					thoat = 1;
					break;
				}
			}
		}//??ng trong game loop
		if (thoat)
		{
			system("cls");
			break;
		}
	}
}
void Color(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
