#pragma once
#pragma comment(lib, "winmm.lib")
#include "snake.h"

void AnQua1(ToaDo ran[], QUA& food, int& ran_dot, int& SPEED, int& diem, ToaDo vat_can[], int so_o_vat_can, ToaDo cong_win[], int cong_win_so_o, int soundOn);

//Ki?m tra thua màn 1
bool KiemTraThuaMan1(ToaDo ran[], int ran_dot, ToaDo vat_can[], int so_o_vat_can);

void Man_1(char* ten_nguoi_choi, ToaDo ran[], int& ran_dot, int x, int y, int vung_ran_di_chuyen_dai,
	int bang_diem_dai, int rong, int& diem, int& SPEED, int& huong, int& man, ToaDo vat_can[], int vat_can_so_o,
	string* data, int& nData, NguoiChoi& nguoiChoi, int STT, int soundOn);