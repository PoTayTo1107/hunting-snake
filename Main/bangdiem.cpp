#include "bangdiem.h"
#include "mylib.h"
#include <iostream>

void DocFileBangDiem(ifstream& fileIn, BangDiem bangDiem[], int& so_luong)
{
	fileIn >> so_luong;
	for (int i = 0; i < so_luong; i++)
	{
		fileIn >> bangDiem[i].STT;
		char c;
		fileIn >> c;
		fileIn.getline(bangDiem[i].ten_nguoi_choi, 40, ',');
		fileIn >> bangDiem[i].diem;
	}
}

void XuatFileBangDiem(ofstream& fileOut, BangDiem bangDiem[], int so_luong)
{
	fileOut << so_luong << endl;
	for (int i = 0; i < so_luong; i++)
	{
		fileOut << bangDiem[i].STT << ",";
		fileOut << bangDiem[i].ten_nguoi_choi << ",";
		fileOut << bangDiem[i].diem << "\n";
	}
}

void XapSepLaiBangDiem(BangDiem bangDiem[], int& so_luong, char* ten_nguoi_choi, int diem)
{
	int i;
	int flag = 0; // Không n?m trong top 5 ng??i ch?i cao nh?t
	for (i = 0; i < so_luong; i++)
	{
		if (bangDiem[i].diem < diem)
		{
			flag = 1; // N?m trong top 5 ng??i ch?i cao nh?t
			break;
		}
	}
	if (flag)
	{
		if (so_luong < 5)
		{
			so_luong++;
		}
		for (int j = so_luong - 1; j > i; j--)
		{
			bangDiem[j] = bangDiem[j - 1];
			bangDiem[j].STT++;
		}
		strcpy_s(bangDiem[i].ten_nguoi_choi, 40, ten_nguoi_choi);
		bangDiem[i].diem = diem;
	}
	else if (so_luong < 5)
	{
		bangDiem[so_luong].STT = so_luong + 1;
		strcpy_s(bangDiem[so_luong].ten_nguoi_choi, 40, ten_nguoi_choi);
		bangDiem[so_luong].diem = diem;
		so_luong++;
	}

}

void GiaoDienBangDiem(int x, int y, int dai, int rong, BangDiem bangDiem[], int so_luong)
{
	//V? c?nh trên và d??i
	for (int i = x; i <= x + dai; i++)
	{
		//V? c?nh trên
		gotoXY(i, y);
		std::cout << char(205);

		//V? c?nh d??i
		gotoXY(i, y + rong);
		std::cout << char(205);

		//V? c?nh gi?a
		gotoXY(i, y + 2);
		std::cout << char(205);
	}
	//V? c?nh trái - c?nh ph?i - c?nh phân chia vùng r?n di chuy?n và b?ng ?i?m
	for (int i = y; i <= y + rong; i++)
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
	gotoXY(x, y + rong); cout << char(200);
	//V? góc ph?i d??i
	gotoXY(x + dai, y + rong); cout << char(188);


	string str = "BANG XEP HANG TOP 5 NGUOI CHOI CO DIEM CAO NHAT";
	gotoXY((x + dai) / 2 - str.length() / 2, y - 1);
	cout << str;

	int khoang_cach = 32;
	gotoXY(x + 5, y + 1);
	std::cout << "STT";
	gotoXY(x + khoang_cach, y + 1);
	std::cout << "Ten";
	gotoXY(x + khoang_cach * 3, y + 1);
	std::cout << "Diem";

	for (int i = 0; i < so_luong; i++)
	{
		gotoXY(x + 5, y + 4 + i * 2);
		cout << bangDiem[i].STT;
		gotoXY(x + khoang_cach, y + 4 + i * 2);
		cout << bangDiem[i].ten_nguoi_choi;
		gotoXY(x + khoang_cach * 3, y + 4 + i * 2);
		cout << bangDiem[i].diem;
	}
}

void LuuDanhSachNguoiChoiDiemCaoNhat(char* ten_nguoi_choi, int diem)
{
	int so_luong = 0;
	BangDiem bangDiem[5];

	//??c thông tin top 5 ng??i có ?i?m cao nh?t t? file
	ifstream fileIn;
	fileIn.open("bangdiem.txt", ios::in);
	DocFileBangDiem(fileIn, bangDiem, so_luong);
	fileIn.close();

	if (ten_nguoi_choi == NULL)
	{
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
		cout << "Nhap ten: ";
		ten_nguoi_choi = new char[50];
		cin.getline(ten_nguoi_choi, 50);
	}

	XapSepLaiBangDiem(bangDiem, so_luong, ten_nguoi_choi, diem);
	//Ghi thông tin top 5 ng??i có ?i?m cao nh?t vào file
	ofstream fileOut;
	fileOut.open("bangdiem.txt", ios::out);
	XuatFileBangDiem(fileOut, bangDiem, so_luong);
	fileOut.close();
}