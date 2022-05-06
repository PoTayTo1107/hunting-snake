#pragma once
#include "snake.h"
#include "savegame.h"
#pragma comment(lib, "winmm.lib")
void FoodRound3(QUA& food, ToaDo vat_can[], int so_o_vat_can, ToaDo ran[], int ran_dot, ToaDo cong_win[], int cong_win_so_o);
//Tao vat can dong
void tao_vat_can_dong_man_3(int x, int y, int vung_ran_di_chuyen_dai, int rong, ToaDo vat_can_dong[], int& vat_can_dong_so_o);

//Vat can di chuyen
void di_chuyen_vat_can_dong_man_3(int x, int y, int vung_ran_di_chuyen_dai, int rong, ToaDo vat_can_dong[], int vat_can_dong_so_o, bool& up);

//Ki?m tra thua do ??ng v?t c?n màn 2
bool KiemTraThuaVatCan3(ToaDo ran[], int ran_dot, ToaDo vat_can[], int so_o_vat_can);

//Ki?m tra thua màn 2
bool KiemTraThuaMan3(ToaDo ran[], int ran_dot, ToaDo vat_can[], int so_o_vat_can);


void AnQua3(ToaDo ran[], QUA& food, int& ran_dot, int& trung_doc, int& SPEED, int& diem, ToaDo vat_can[], int so_o_vat_can, ToaDo cong_win[], int cong_win_so_o, int soundOn);

//R?n trúng ??c- b? gi?m ??t
void TrungDoc(ToaDo ran[], int& ran_dot, int& thoi_gian_mat_dot);

//T?o c?ng d?ch chuy?n
void tao_cong_dich_chuyen(CongDichChuyen& cong, int x1, int y1, int x2, int y2);

//V? c?ng d?ch chuy?n
void ve_cong_dich_chuyen(CongDichChuyen& cong);

//Logic c?a c?ng d?ch chuy?n
void logic_cong(ToaDo ran[], int huong, CongDichChuyen& cong);

void Man_3(char* ten_nguoi_choi, ToaDo ran[], int& ran_dot, int x, int y, int vung_ran_di_chuyen_dai,
	int bang_diem_dai, int rong, int& diem, int& SPEED, int& huong, int& man, ToaDo vat_can[], int& vat_can_so_o,
	string* data, int& nData, NguoiChoi& nguoiChoi, int STT, int soundOn);