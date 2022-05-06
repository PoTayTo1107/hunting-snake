#pragma once
#include "snake.h"
#include "savegame.h"
#pragma comment(lib, "winmm.lib")
void VeVatCanBenTrongManBon(ToaDo vat_can[], int& so_o_vat_can);
void TaoVatCanDiChuyenTuTrai(ToaDo vat_di_chuyen_1_1[], int do_dai_vat_can, int deltaX, int deltaY);
void TaoVatCanDiChuyenTuPhai(ToaDo vat_di_chuyen[], int do_dai_vat_can, int deltaX, int deltaY);
void HienThiVatDiChuyen(ToaDo vat_di_chuyen_1[], int do_dai_vat_can, ToaDo dot_cuoi_cu);
void DiChuyenVatCanDiChuyenTuTrai(ToaDo vat_di_chuyen_1[], int do_dai_vat_can, ToaDo& dot_cuoi_cu, int deltaX, int deltaY);
void DiChuyenVatCanDiChuyenTuPhai(ToaDo vat_di_chuyen_1[], int do_dai_vat_can, ToaDo& dot_cuoi_cu, int deltaX, int deltaY);
void VeManBon(ToaDo tuong_trong[], int& so_o_vat_can, int x, int y, int vung_ran_di_chuyen_dai, int bang_diem_dai, int rong, int man);
void TaoNhen(ToaDo nhen[][9]);
void HienThiNhen(ToaDo nhen[][9]);
void DiChuyenNhen(ToaDo nhen[][9], ToaDo dot_cuoi_cu[]);
bool RanChamNhen(ToaDo ran[], int ran_dot, ToaDo nhen[][9]);
bool RanChamVatDiChuyenMan4(ToaDo ran[], int ran_dot, ToaDo vat_di_chuyen_1_1[],
	ToaDo vat_di_chuyen_1_2[], ToaDo vat_di_chuyen_2_1[], ToaDo vat_di_chuyen_2_2[], int do_dai_vat_can);
bool RanChamVatCanTinhMan4(ToaDo ran[], int ran_dot, ToaDo tuong_trong[], int so_o_tuong_trong);
bool KiemTraThuaVatCan_4(ToaDo ran[], ToaDo vat_di_chuyen_1_1[], ToaDo vat_di_chuyen_1_2[], ToaDo vat_di_chuyen_2_1[],
	ToaDo vat_di_chuyen_2_2[], int do_dai_vat_can, ToaDo nhen[][9], ToaDo tuong_trong[], int so_o_tuong_trong, int ran_dot);
bool KiemTraThuaManBon(ToaDo ran[], int ran_dot, ToaDo vat_di_chuyen_1_1[], ToaDo vat_di_chuyen_1_2[], ToaDo vat_di_chuyen_2_1[],
	ToaDo vat_di_chuyen_2_2[], int do_dai_vat_can, ToaDo nhen[][9], ToaDo tuong_trong[], int so_o_tuong_trong);
bool KiemTraToaDoQuaKhaThiMan4(int x, int y, ToaDo vat_di_chuyen_1_1[], ToaDo vat_di_chuyen_1_2[], ToaDo vat_di_chuyen_2_1[],
	ToaDo vat_di_chuyen_2_2[], int do_dai_vat_can, ToaDo nhen[][9], ToaDo tuong_trong[], int so_o_tuong_trong);
void FoodMan4(QUA& food, ToaDo vat_di_chuyen_1_1[], ToaDo vat_di_chuyen_1_2[], ToaDo vat_di_chuyen_2_1[], ToaDo vat_di_chuyen_2_2[], int do_dai_vat_can,
	ToaDo nhen[][9], ToaDo tuong_trong[], int so_o_tuong_trong, ToaDo cong_win[], int cong_win_so_o);
void AnQuaMan4(ToaDo ran[], QUA& food, int& ran_dot, int& trung_doc, int& SPEED, int& diem, ToaDo vat_di_chuyen_1_1[], ToaDo vat_di_chuyen_1_2[],
	ToaDo vat_di_chuyen_2_1[], ToaDo vat_di_chuyen_2_2[], int do_dai_vat_can, ToaDo nhen[][9], ToaDo tuong_trong[], int so_o_tuong_trong, ToaDo cong_win[], int cong_win_so_o, int soundOn);
void Man_4(char* ten_nguoi_choi, ToaDo ran[], int& ran_dot, int x, int y, int vung_ran_di_chuyen_dai,
	int bang_diem_dai, int rong, int& diem, int& SPEED, int& huong, int& man, ToaDo vat_can[], int vat_can_so_o, ToaDo nhen[][9],
	string* data, int& nData, NguoiChoi& nguoiChoi, int STT, int soundOn);
void Color(int color);