#include "savegame.h"
#include "mylib.h"
#include "man_2.h"
#include "man_3.h"
#include "menu.h"
#include <iostream>
#include <Windows.h>
#include <malloc.h>
#include <string>
#include <fstream>
using namespace std;

char* ChuyenSoThanhChu(int a)
{
	char* str = new char[10];
	int i = 0;
	while (a > 0)
	{
		int dvi = a % 10;
		str[i] = char(dvi) + 48;
		a /= 10;
		i++;
	}
	str[i] = '\0';
	return str;
}

bool KiemTraTenFileHopLe(string* data, int nData, string str)
{
	for (int i = 0; i < nData; i++)
	{
		if (str.compare(data[i]) == 0)
		{
			return false;
		}
	}
	return true;
}

void LuuManChoi(string* data, int& nData, NguoiChoi nguoiChoi, int STT)
{
	if (STT == -1)
	{
		STT = nData;
		string str;
		nData++;
		do
		{
			int temp = 0 + rand() % (200 + 1 - 0);
			str = "LoadGame_";
			str += string(ChuyenSoThanhChu(temp));
			str += ".txt";
		} while (!KiemTraTenFileHopLe(data, nData, str));
		data[STT] = str;
	}

	int ran_dot = nguoiChoi.ran_dot;
	if (ran_dot == 0)
	{
		delete (data + STT - 1);
		return;
	}

	ofstream fileOut;
	fileOut.open(data[STT], ios::out);
	fileOut << nguoiChoi.ten_nguoi_choi << "\n";
	fileOut << nguoiChoi.diem << "\n";
	fileOut << nguoiChoi.ran_dot << " ";
	int dot = nguoiChoi.ran_dot;
	for (int j = 0; j < dot; j++)
	{
		fileOut << nguoiChoi.Ran[j].x << " ";
		fileOut << nguoiChoi.Ran[j].y << " ";
	}
	fileOut << "\n";
	fileOut << nguoiChoi.SPEED << "\n";
	fileOut << nguoiChoi.huong << "\n";
	fileOut << nguoiChoi.man;
	if (nguoiChoi.man >= 3)
	{
		fileOut << "\n" << nguoiChoi.VatCanSoO << " ";
		int vat_can_dong_so_o = nguoiChoi.VatCanSoO;
		for (int j = 0; j < vat_can_dong_so_o; j++)
		{
			fileOut << nguoiChoi.VatCanDong[j].x << " ";
			fileOut << nguoiChoi.VatCanDong[j].y << " ";
		}
		fileOut << endl;
		if (nguoiChoi.man == 4)
		{
			fileOut << nguoiChoi.Nhen[2][0].x << " " << nguoiChoi.Nhen[2][0].y << endl;
			fileOut << nguoiChoi.Nhen[6][0].x << " " << nguoiChoi.Nhen[6][0].y << endl;
			for (int i = 0; i < 9; i++)
			{
				fileOut << nguoiChoi.Nhen[i][1].x << " " << nguoiChoi.Nhen[i][1].y << endl;
			}
			for (int i = 0; i < 7; i++)
			{
				fileOut << nguoiChoi.Nhen[i][2].x << " " << nguoiChoi.Nhen[i][2].y << endl;
			}
			fileOut << nguoiChoi.Nhen[3][3].x << " " << nguoiChoi.Nhen[3][3].y << endl;
			fileOut << nguoiChoi.Nhen[5][3].x << " " << nguoiChoi.Nhen[5][3].y << endl;
		}
	}
	else
	{
		fileOut << "\n" << 0;
	}
	fileOut.close();
	fileOut.open("data.txt", ios::out);
	fileOut << nData;
	for (int i = 0; i < nData; i++)
	{
		fileOut << "\n" << data[i];
	}
	fileOut.close();

}

NguoiChoi* XuatDanhSachNguoiChoi(ifstream& fileIn, string* data, int nData, int& nNguoiChoi)
{
	if (nData < 1)
	{
		nNguoiChoi = 0;
		return NULL;
	}
	nNguoiChoi = nData;
	NguoiChoi* danhSachNguoiChoi = new NguoiChoi[nNguoiChoi];

	for (int i = 0; i < nNguoiChoi; i++)
	{
		fileIn.open(data[i], ios::in);
		danhSachNguoiChoi[i].ten_nguoi_choi = new char[50];
		fileIn.getline(danhSachNguoiChoi[i].ten_nguoi_choi, 50, '\n');
		fileIn >> danhSachNguoiChoi[i].diem;
		fileIn >> danhSachNguoiChoi[i].ran_dot;
		int dot = danhSachNguoiChoi[i].ran_dot;
		for (int j = 0; j < dot; j++)
		{
			fileIn >> danhSachNguoiChoi[i].Ran[j].x;
			fileIn >> danhSachNguoiChoi[i].Ran[j].y;
		}
		fileIn >> danhSachNguoiChoi[i].SPEED;
		fileIn >> danhSachNguoiChoi[i].huong;
		fileIn >> danhSachNguoiChoi[i].man;
		fileIn >> danhSachNguoiChoi[i].VatCanSoO;
		int vat_can_dong_so_o = danhSachNguoiChoi[i].VatCanSoO;
		for (int j = 0; j < vat_can_dong_so_o; j++)
		{
			fileIn >> danhSachNguoiChoi[i].VatCanDong[j].x;
			fileIn >> danhSachNguoiChoi[i].VatCanDong[j].y;
		}
		if (danhSachNguoiChoi[i].man == 4)
		{
			fileIn >> danhSachNguoiChoi[i].Nhen[2][0].x;
			fileIn >> danhSachNguoiChoi[i].Nhen[2][0].y;
			fileIn >> danhSachNguoiChoi[i].Nhen[6][0].x;
			fileIn >> danhSachNguoiChoi[i].Nhen[6][0].y;
			for (int j = 0; j < 9; j++)
			{
				fileIn >> danhSachNguoiChoi[i].Nhen[j][1].x;
				fileIn >> danhSachNguoiChoi[i].Nhen[j][1].y;
			}
			for (int j = 0; j < 7; j++)
			{
				fileIn >> danhSachNguoiChoi[i].Nhen[j][2].x;
				fileIn >> danhSachNguoiChoi[i].Nhen[j][2].y;
			}
			fileIn >> danhSachNguoiChoi[i].Nhen[3][3].x;
			fileIn >> danhSachNguoiChoi[i].Nhen[3][3].y;
			fileIn >> danhSachNguoiChoi[i].Nhen[5][3].x;
			fileIn >> danhSachNguoiChoi[i].Nhen[5][3].y;
		}
		fileIn.close();
	}
	return danhSachNguoiChoi;
}

void GiaoDienLoadGame(int x, int y, int dai, int rong, NguoiChoi danhSachNguoiChoi[], int nNguoiChoi)
{

	//V? c?nh trên và d??i
	for (int i = x; i <= x + dai; i++)
	{
		//V? c?nh trên
		gotoXY(i, y);
		std::cout << char(205);

		//V? c?nh d??i
		gotoXY(i, y + rong + 2 * nNguoiChoi);
		std::cout << char(205);

		//V? c?nh gi?a
		gotoXY(i, y + 2);
		std::cout << char(205);
	}
	//V? c?nh trái - c?nh ph?i - c?nh phân chia vùng r?n di chuy?n và b?ng ?i?m
	for (int i = y; i <= y + rong + nNguoiChoi * 2; i++)
	{
		//V? c?nh trên
		gotoXY(x, i);
		std::cout << char(186);

		//V? c?nh d??i
		gotoXY(x + dai, i);
		std::cout << char(186);
	}
	//V? góc trái trên
	gotoXY(x, y); cout << char(201);
	//V? góc ph?i trên
	gotoXY(x + dai, y); cout << char(187);
	//V? góc trái d??i
	gotoXY(x, y + rong + 2 * nNguoiChoi); cout << char(200);
	//V? góc ph?i d??i
	gotoXY(x + dai, y + rong + 2 * nNguoiChoi); cout << char(188);


	string str = "TIEP TUC CHOI";
	gotoXY((x + dai) / 2 - str.length() / 2, y - 1);
	cout << str;


	int khoang_cach = 46;
	gotoXY(x + 5, y + 1);
	cout << "Ten";
	gotoXY(x + 5 + khoang_cach, y + 1);
	cout << "Man";
	gotoXY(x + 5 + khoang_cach * 2, y + 1);
	cout << "Diem";

	for (int i = 0; i < nNguoiChoi; i++)
	{
		gotoXY(x + 5, y + 4 + i * 2);
		cout << danhSachNguoiChoi[i].ten_nguoi_choi;
		gotoXY(x + 5 + khoang_cach, y + 4 + i * 2);
		cout << danhSachNguoiChoi[i].man;
		gotoXY(x + 5 + khoang_cach * 2, y + 4 + i * 2);
		cout << danhSachNguoiChoi[i].diem;
	}

}


void to_mau_1_dong(int x, int y, int dai, int rong, int khoang_cach, NguoiChoi nguoiChoi)
{
	TextColor(192); //N?n ?? ch? ?en
	for (int i = x + 1; i < x + dai; i++)
	{
		gotoXY(i, y);
		cout << " ";
	}
	gotoXY(x + 5, y);
	cout << nguoiChoi.ten_nguoi_choi;
	gotoXY(x + 5 + khoang_cach, y);
	cout << nguoiChoi.man;
	gotoXY(x + 5 + khoang_cach * 2, y);
	cout << nguoiChoi.diem;
}

void huy_to_mau_1_dong(int x, int y, int dai, int rong, int khoang_cach, NguoiChoi nguoiChoi)
{
	TextColor(7); //N?n ?? ch? ?en
	for (int i = x + 1; i < x + dai; i++)
	{
		gotoXY(i, y);
		cout << " ";
	}
	gotoXY(x + 5, y);
	cout << nguoiChoi.ten_nguoi_choi;
	gotoXY(x + 5 + khoang_cach, y);
	cout << nguoiChoi.man;
	gotoXY(x + 5 + khoang_cach * 2, y);
	cout << nguoiChoi.diem;
}


int logic_load_game(int x, int y, int khoang_cach, NguoiChoi* danhSachNguoiChoi, int nNguoiChoi)
{
	int goup;
	int enter;
	int temp_y = 0;
	int dai = 147;
	int rong = 32;
	GiaoDienLoadGame(x, y, dai, rong, danhSachNguoiChoi, nNguoiChoi);
	if (danhSachNguoiChoi == NULL)
	{
		return -1;
	}
	to_mau_1_dong(x, y + 4 + temp_y, dai, rong, khoang_cach, danhSachNguoiChoi[temp_y]);
	while (1)
	{
		input_menu(goup, enter);
		if (goup == 1)
		{
			huy_to_mau_1_dong(x, y + 4 + temp_y, dai, rong, khoang_cach, danhSachNguoiChoi[temp_y / 2]); // h?y tô màu ? ô ?ã ch?n tr??c ?ó
			if (temp_y != 0) // N?u mà ô ???c ch?n tr??c ?ó ch?a là ô trên cùng thì lên 1 ô
			{
				temp_y -= 2;
			}
			else // N?u mà ô ???c ch?n tr??c ?ó là ô trên cùng thì chuy?n ô ???c là ô d??i cùng
			{
				temp_y = (nNguoiChoi - 1) * 2;
			}
			to_mau_1_dong(x, y + 4 + temp_y, dai, rong, khoang_cach, danhSachNguoiChoi[temp_y / 2]); // Tô màu cho ô ch?n hi?n t?i
			goup = 0;
		}
		else if (goup == -1)
		{
			huy_to_mau_1_dong(x, y + 4 + temp_y, dai, rong, khoang_cach, danhSachNguoiChoi[temp_y / 2]);// h?y tô màu ? ô ?ã ch?n tr??c ?ós
			if (temp_y != (nNguoiChoi - 1) * 2) // N?u mà ô ???c ch?n tr??c ?ó ch?a là ô d??i cùng thì chuy?n xu?ng 1 ô
			{
				temp_y += 2;
			}
			else // N?u mà ô ???c ch?n tr??c ?ó là ô d??i cùng thì ô ???c ch?n là ô trên cùng
			{
				temp_y = 0;
			}
			to_mau_1_dong(x, y + 4 + temp_y, dai, rong, khoang_cach, danhSachNguoiChoi[temp_y / 2]); // Tô màu cho ô ch?n hi?n t?i
			goup = 0;
		}
		else if (enter == 1)
		{
			TextColor(7);
			return temp_y / 2;
		}
	}
}



void LoadLaiGame(char*& ten_nguoi_choi, int& diem, int& ran_dot, ToaDo ran[], int& SPEED, int& huong, int& man, int& vat_can_so_o, ToaDo vat_can[], ToaDo nhen[][9], NguoiChoi* danhSachNguoiChoi, int nguoiChoiThuI)
{
	ten_nguoi_choi = new char[50];
	strcpy_s(ten_nguoi_choi, 50, danhSachNguoiChoi[nguoiChoiThuI].ten_nguoi_choi);
	diem = danhSachNguoiChoi[nguoiChoiThuI].diem;
	ran_dot = danhSachNguoiChoi[nguoiChoiThuI].ran_dot;
	for (int i = 0; i < ran_dot; i++)
	{
		ran[i] = danhSachNguoiChoi[nguoiChoiThuI].Ran[i];
	}
	SPEED = danhSachNguoiChoi[nguoiChoiThuI].SPEED;
	huong = danhSachNguoiChoi[nguoiChoiThuI].huong;
	man = danhSachNguoiChoi[nguoiChoiThuI].man;
	vat_can_so_o = danhSachNguoiChoi[nguoiChoiThuI].VatCanSoO;
	for (int i = 0; i < vat_can_so_o; i++)
	{
		vat_can[i] = danhSachNguoiChoi[nguoiChoiThuI].VatCanDong[i];
	}
	if (man == 4)
	{
		nhen[2][0] = danhSachNguoiChoi[nguoiChoiThuI].Nhen[2][0];
		nhen[6][0] = danhSachNguoiChoi[nguoiChoiThuI].Nhen[6][0];
		for (int i = 0; i < 9; i++)
		{
			nhen[i][1] = danhSachNguoiChoi[nguoiChoiThuI].Nhen[i][1];
		}
		for (int i = 0; i < 7; i++)
		{
			nhen[i][2] = danhSachNguoiChoi[nguoiChoiThuI].Nhen[i][2];
		}
		nhen[3][3] = danhSachNguoiChoi[nguoiChoiThuI].Nhen[3][3];
		nhen[5][3] = danhSachNguoiChoi[nguoiChoiThuI].Nhen[5][3];
	}

}
void LuuNhieuMangVao1Mang(ToaDo vat_can_dong[], int& vat_can_dong_so_o, ToaDo vat_di_chuyen_1_1[],
	ToaDo vat_di_chuyen_1_2[], ToaDo vat_di_chuyen_2_1[], ToaDo vat_di_chuyen_2_2[], int vat_di_chuyen_so_o)
{
	vat_can_dong_so_o = 0;
	for (int i = 0; i < vat_di_chuyen_so_o; i++)
	{
		vat_can_dong[vat_can_dong_so_o].x = vat_di_chuyen_1_1[i].x;
		vat_can_dong[vat_can_dong_so_o].y = vat_di_chuyen_1_1[i].y;
		vat_can_dong_so_o++;
	}
	for (int i = 0; i < vat_di_chuyen_so_o; i++)
	{
		vat_can_dong[vat_can_dong_so_o].x = vat_di_chuyen_1_2[i].x;
		vat_can_dong[vat_can_dong_so_o].y = vat_di_chuyen_1_2[i].y;
		vat_can_dong_so_o++;
	}
	for (int i = 0; i < vat_di_chuyen_so_o; i++)
	{
		vat_can_dong[vat_can_dong_so_o] = vat_di_chuyen_2_1[i];
		vat_can_dong_so_o++;

	}
	for (int i = 0; i < vat_di_chuyen_so_o; i++)
	{
		vat_can_dong[vat_can_dong_so_o] = vat_di_chuyen_2_2[i];
		vat_can_dong_so_o++;
	}
}

void Tach1MangVaoNhieuMang(ToaDo vat_can_dong[], int& vat_can_dong_so_o, ToaDo vat_di_chuyen_1_1[], ToaDo vat_di_chuyen_1_2[], ToaDo vat_di_chuyen_2_1[], ToaDo vat_di_chuyen_2_2[], int vat_di_chuyen_so_o)
{
	int i;
	for (i = 0; i < vat_di_chuyen_so_o; i++)
	{
		vat_di_chuyen_1_1[i] = vat_can_dong[i];
	}
	for (int j = 0; j < vat_di_chuyen_so_o; j++)
	{
		vat_di_chuyen_1_2[j] = vat_can_dong[i++];
	}
	for (int j = 0; j < vat_di_chuyen_so_o; j++)
	{
		vat_di_chuyen_2_1[j] = vat_can_dong[i++];
	}
	for (int j = 0; j < vat_di_chuyen_so_o; j++)
	{
		vat_di_chuyen_2_2[j] = vat_can_dong[i++];
	}
}

void NutLuuGame(char* ten_nguoi_choi, int diem, int ran_dot, ToaDo* ran, int SPEED, int huong, int man,
	int vat_can_dong_so_o, ToaDo* vat_can_dong, ToaDo nhen[][9], string* data, int nData, NguoiChoi& nguoiChoi, int STT) // nhen[][9]
{

	/*
   _____                     ______
  / ___/____  __  _____     / ____/___ _____ ___  ___
  \__ \/ __ `/ | / / _ \   / / __/ __ `/ __ `__ \/ _ \
 ___/ / /_/ /| |/ /  __/  / /_/ / /_/ / / / / / /  __/
/____/\__,_/ |___/\___/   \____/\__,_/_/ /_/ /_/\___/

	*/
	system("cls");
	if (STT < 0 || STT >= nData)
	{
		gotoXY(23, 2); cout << "   _____                      ______                   \n";
		gotoXY(23, 3); cout << "  / ___/____  __  _____     / ____/___ _____ ___  ___ \n";
		gotoXY(23, 4); cout << "  \\__ \\/ __ `/ | / / _ \\   / / __/ __ `/ __ `__ \\/ _ \\\n";
		gotoXY(23, 5); cout << " ___/ / /_/ /| |/ /  __/  / /_/ / /_/ / / / / / /  __/\n";
		gotoXY(23, 6); cout << "/____/\__,_/ |___/\___/   \____/\__,_/_/ /_/ /_/\___/ \n";

		for (int i = 54; i <= 104; i++)
		{
			gotoXY(i, 12);
			cout << char(219);

			gotoXY(i, 14);
			cout << char(219);
		}

		for (int i = 12; i <= 14; i++)
		{
			gotoXY(54, i);
			cout << char(219);

			gotoXY(104, i);
			cout << char(219);
		}

		gotoXY(56, 13);
		if (STT == -1)
		{
			cout << "Nhap ten: ";
			ten_nguoi_choi = new char[50];
			cin.getline(ten_nguoi_choi, 50);
		}
	}
	nguoiChoi.ten_nguoi_choi = ten_nguoi_choi;
	nguoiChoi.diem = diem;
	nguoiChoi.ran_dot = ran_dot;
	for (int i = 0; i < ran_dot; i++)
	{
		nguoiChoi.Ran[i] = ran[i];
	}
	nguoiChoi.SPEED = SPEED;
	nguoiChoi.huong = huong;
	nguoiChoi.man = man;
	nguoiChoi.VatCanSoO = vat_can_dong_so_o;
	for (int j = 0; j < vat_can_dong_so_o; j++)
	{
		nguoiChoi.VatCanDong[j] = vat_can_dong[j];
	}
	if (man == 4)
	{
		nguoiChoi.Nhen[2][0] = nhen[2][0];
		nguoiChoi.Nhen[6][0] = nhen[6][0];
		for (int i = 0; i < 9; i++)
		{
			nguoiChoi.Nhen[i][1] = nhen[i][1];
		}
		for (int i = 0; i < 7; i++)
		{
			nguoiChoi.Nhen[i][2] = nhen[i][2];
		}
		nguoiChoi.Nhen[3][3] = nhen[3][3];
		nguoiChoi.Nhen[5][3] = nhen[5][3];
	}
	LuuManChoi(data, nData, nguoiChoi, STT);
}


void XoaFileText(string* data, int& nData, int STT)
{
	if (STT < 0)
	{
		return;
	}
	ofstream fileOut;
	fileOut.open(data[STT], ios::out);
	fileOut << " ";
	fileOut.close();

	for (int i = STT; i < nData - 1; i++)
	{
		data[i] = data[i + 1];
	}
	nData--;

	fileOut.open("data.txt", ios::out);
	fileOut << nData;
	for (int i = 0; i < nData; i++)
	{
		fileOut << "\n" << data[i];
	}
	fileOut.close();
}


