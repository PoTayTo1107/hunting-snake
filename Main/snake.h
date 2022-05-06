#pragma once 
#include <iostream>
using namespace std;

typedef struct
{
	int x;
	int y;
}ToaDo;

typedef struct
{
	char* ten_nguoi_choi;
	int diem;
	int ran_dot;
	ToaDo Ran[50];
	int SPEED;
	int huong;
	int man;
	int VatCanSoO;
	ToaDo VatCanDong[50];
	ToaDo Nhen[25][9];
}NguoiChoi;

struct QUA
{
	int count;
	ToaDo qua1;    // "O"
	ToaDo qua10;   // "$"
	ToaDo quaDoc; // "O"
};
struct HUONG
{
	int goup;     // 1: up    ;  -1: down ;  0: goright = {-1;1}
	int goright;  // 1: right ;  -1: left ;  0: goup = {-1;1}
};

struct CongDichChuyen
{
	ToaDo cong_1;
	ToaDo cong_2;
};

void ve_vung_ran_di_chuyen(int x, int y, int vung_ran_di_chuyen_dai, int rong);
void TaoNut(int x, int y, int nut);
void TaoPhimDiChuyen(int x, int y, int len, int xuong, int trai, int phai);
void ve_bang_diem(int x, int y, int bang_diem_dai, int rong, int man);
void ve_vat_can(ToaDo vat_can[], int vat_can_so_o);

void BatSuKien(int& huong, bool& checkPause);
ToaDo DiChuyen(ToaDo ran[], int huong, int ran_dot);
void HienThiRan(ToaDo ran[], ToaDo dot_cuoi_cu, int ran_dot);

//Ve ran
void VeRan(ToaDo ran[], int ran_dot);

//ran cham than
bool RanChamThan(ToaDo ran[], int ran_dot);

//Kiem tra thua khi ran cham vao khung tro choi
bool RanChamTuong(ToaDo ran[]);

//Kiem tra toa do qua kha thi
bool KiemTraToaDoQuaKhaThi(int x, int y, ToaDo vat_can[], int so_o_vat_can);

//Tao qua 1
void TaoQua1(QUA& food);  //  4 < xqua < 110;  3 < yqua < 35
//Ve qua 1
void VeQua1(QUA& food);

//Tao qua 10
void TaoQua10(QUA& food);  //  4 < xqua < 110;  3 < yqua < 35
//Ve qua 10
void VeQua10(QUA& food);

//Tao qua doc
void TaoQuaDoc(QUA& food);
//Ve qua doc
void VeQuaDoc(QUA& food);

//Xoa Qua
void XoaQua(QUA food);

//In ra màn hình thua
//x,y:T?a ?? n?i in ra
void ManHinhThua(int x, int y);
void ManHinhThang();

//Khoi tao ran
void KhoiTaoRan(ToaDo ran[]);

//Ve man choi
void ve_man_choi(int x, int y, int vung_ran_di_chuyen_dai, int bang_diem_dai, int rong, ToaDo vat_can[], int vat_can_so_o, int man);

int  DoDaiCuaSo(int so);
//v? ?i?m s?
void ve_diem(int diem, int x, int y, char* ten_nguoi_choi);

//V
void tao_cong_win(int x, int y, ToaDo cong_win[], int& cong_win_so_o, char* huong_vao_cong);
void ve_cong_win(ToaDo cong_win[], int cong_win_so_o);
//Logic c?a c?ng d?ch chuy?n
bool RanChamCongWin(ToaDo ran[], ToaDo cong_win[], int cong_win_so_o);
bool xu_ly_win(ToaDo ran[], ToaDo cong_win[]);
bool KiemTraDieuKienThang(int diem, int diem_man);