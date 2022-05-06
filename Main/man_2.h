#pragma once
#pragma comment(lib, "winmm.lib")
#include "savegame.h"

//T?o v?t c?n màn 2
void tao_vat_can_man_2(int x, int y, int vung_ran_di_chuyen_dai, int rong, ToaDo vat_can[], int& vat_can_so_o);

//Tao qua
void FoodRound2(QUA& food, ToaDo vat_can[], int so_o_vat_can, ToaDo ran[], int ran_dot, ToaDo cong_win[], int cong_win_so_o);

//An qua
void AnQua2(ToaDo ran[], QUA& food, int& ran_dot, int& SPEED, int& diem, ToaDo vat_can[], int so_o_vat_can, ToaDo cong_win[], int cong_win_so_o, int soundOn);

//Ki?m tra thua do ??ng v?t c?n màn 1 
bool KiemTraThuaVatCan2(ToaDo ran[], ToaDo vat_can[], int so_o_vat_can);

//Ki?m tra thua màn 1
bool KiemTraThuaMan2(ToaDo ran[], int ran_dot, ToaDo vat_can[], int so_o_vat_can);

void Man_2(char* ten_nguoi_choi, ToaDo ran[], int& ran_dot, int x, int y, int vung_ran_di_chuyen_dai,
	int bang_diem_dai, int rong, int& diem, int& SPEED, int& huong, int& man, ToaDo vat_can[], int vat_can_so_o,
	string* data, int& nData, NguoiChoi& nguoiChoi, int STT, int soundOn);

