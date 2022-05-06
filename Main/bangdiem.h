#pragma once
#include <fstream>
using namespace std;

struct BangDiem
{
	int STT;
	char ten_nguoi_choi[40];
	int diem;
};

void DocFileBangDiem(ifstream& fileIn, BangDiem bangDiem[], int& so_luong);
void XuatFileBangDiem(ofstream& fileOut, BangDiem bangDiem[], int so_luong);
void XapSepLaiBangDiem(BangDiem bangDiem[], int& so_luong, char* ten_nguoi_choi, int diem);
void GiaoDienBangDiem(int x, int y, int dai, int rong, BangDiem bangDiem[], int so_luong);
void LuuDanhSachNguoiChoiDiemCaoNhat(char* ten_nguoi_choi, int diem);