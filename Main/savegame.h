#pragma once
#include <fstream>
#include <iostream>
#include "snake.h"
using namespace std;

void LuuManChoi(string* data, int& nData, NguoiChoi nguoiChoi, int STT);
NguoiChoi* XuatDanhSachNguoiChoi(ifstream& fileIn, string* data, int nData, int& nNguoiChoi);

void GiaoDienLoadGame(int x, int y, int dai, int rong, NguoiChoi danhSachNguoiChoi[], int nNguoiChoi);


void to_mau_1_dong(int x, int y, int dai, int rong, int khoang_cach, NguoiChoi nguoiChoi);

void huy_to_mau_1_dong(int x, int y, int dai, int rong, int khoang_cach, NguoiChoi nguoiChoi);

int logic_load_game(int x, int y, int khoang_cach, NguoiChoi danhSachNguoiChoi[], int nNguoiChoi);

char* ChuyenSoThanhChu(int a);
bool KiemTraTenFileHopLe(string* data, int nData, string str);

void LoadLaiGame(char*& ten_nguoi_choi, int& diem, int& ran_dot, ToaDo ran[], int& SPEED, int& huong, int& man,
	int& vat_can_so_o, ToaDo vat_can[], ToaDo nhen[][9], NguoiChoi* danhSachNguoiChoi, int nguoiChoiThuI);

void LuuNhieuMangVao1Mang(ToaDo vat_can_dong[], int& vat_can_dong_so_o, ToaDo vat_di_chuyen_1_1[],
	ToaDo vat_di_chuyen_1_2[], ToaDo vat_di_chuyen_2_1[], ToaDo vat_di_chuyen_2_2[], int vat_di_chuyen_so_o);

void Tach1MangVaoNhieuMang(ToaDo vat_can_dong[], int& vat_can_dong_so_o, ToaDo vat_di_chuyen_1_1[],
	ToaDo vat_di_chuyen_1_2[], ToaDo vat_di_chuyen_2_1[], ToaDo vat_di_chuyen_2_2[], int vat_di_chuyen_so_o);
void NutLuuGame(char* ten_nguoi_choi, int diem, int ran_dot, ToaDo* ran, int SPEED, int huong, int man, int vat_can_dong_so_o,
	ToaDo* vat_can_dong, ToaDo nhen[][9], string* data, int nData, NguoiChoi& nguoiChoi, int STT); // ToaDo nhen[][9]

void XoaFileText(string* data, int& nData, int STT);