#include "man_3.h"
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

void FoodRound3(QUA& food, ToaDo vat_can[], int so_o_vat_can, ToaDo ran[], int ran_dot, ToaDo cong_win[], int cong_win_so_o)
{
	if (food.count == 5)
	{
		do
		{
			TaoQua10(food);
		} while (!KiemTraToaDoQuaKhaThi(food.qua10.x, food.qua10.y, vat_can, so_o_vat_can) || !KiemTraToaDoQuaKhaThi(food.qua10.x, food.qua10.y, ran, ran_dot)
			|| food.qua10.x == 38 || food.qua10.x == 73 || !KiemTraToaDoQuaKhaThi(food.qua1.x, food.qua1.y, cong_win, cong_win_so_o));
		VeQua10(food);
	}
	else if (food.count == 6)
	{
		do
		{
			TaoQuaDoc(food);
		} while (!KiemTraToaDoQuaKhaThi(food.quaDoc.x, food.quaDoc.y, vat_can, so_o_vat_can) || !KiemTraToaDoQuaKhaThi(food.quaDoc.x, food.quaDoc.y, ran, ran_dot)
			|| food.quaDoc.x == 38 || food.quaDoc.x == 73 || !KiemTraToaDoQuaKhaThi(food.quaDoc.x, food.quaDoc.y, cong_win, cong_win_so_o));
		VeQuaDoc(food);
	}
	else
	{
		do
		{
			TaoQua1(food);
		} while (!KiemTraToaDoQuaKhaThi(food.qua1.x, food.qua1.y, vat_can, so_o_vat_can) || !KiemTraToaDoQuaKhaThi(food.qua1.x, food.qua1.y, ran, ran_dot)
			|| food.qua1.x == 38 || food.qua1.x == 73 || !KiemTraToaDoQuaKhaThi(food.qua10.x, food.qua10.y, cong_win, cong_win_so_o));
		VeQua1(food);
	}
}


//Tao vat can dong
void tao_vat_can_dong_man_3(int x, int y, int vung_ran_di_chuyen_dai, int rong, ToaDo vat_can_dong[], int& vat_can_dong_so_o)
{
	int chieu_dai_thanh_vat_can = 10;
	for (int i = y + 1; i <= y + chieu_dai_thanh_vat_can; i++) // T?o 1 thanh v?t c?n d?c phía bên trái (4 ô)
	{
		vat_can_dong[vat_can_dong_so_o].x = x + vung_ran_di_chuyen_dai / 3;
		vat_can_dong[vat_can_dong_so_o].y = i;
		vat_can_dong_so_o++;
	}

	for (int i = y + rong - chieu_dai_thanh_vat_can; i <= y + rong - 1; i++) // T?o 1 thanh v?t c?n d?c phía bên ph?i (4 ô)
	{
		vat_can_dong[vat_can_dong_so_o].x = x + 2 * (vung_ran_di_chuyen_dai / 3);
		vat_can_dong[vat_can_dong_so_o].y = i;
		vat_can_dong_so_o++;
	}
}
//Vat can di chuyen
void di_chuyen_vat_can_dong_man_3(int x, int y, int vung_ran_di_chuyen_dai, int rong, ToaDo vat_can_dong[], int vat_can_dong_so_o, bool& up)
{

	// X? lý di chuy?n thanh d?c bên trái ( 4 ô ??u tiên trong m?ng vat_can[])
	if (up)
	{
		//V?t c?n bên trái
		gotoXY(vat_can_dong[vat_can_dong_so_o / 2 - 1].x, vat_can_dong[vat_can_dong_so_o / 2 - 1].y);
		cout << " ";
		for (int i = 0; i < vat_can_dong_so_o / 2; i++)
		{
			vat_can_dong[i].y--;
		}
		gotoXY(vat_can_dong[0].x, vat_can_dong[0].y);
		cout << char(219);

		//V?t c?n bên ph?i
		gotoXY(vat_can_dong[vat_can_dong_so_o / 2].x, vat_can_dong[vat_can_dong_so_o / 2].y);
		cout << " ";
		for (int i = vat_can_dong_so_o / 2; i < vat_can_dong_so_o; i++)
		{
			vat_can_dong[i].y++;
		}
		gotoXY(vat_can_dong[vat_can_dong_so_o - 1].x, vat_can_dong[vat_can_dong_so_o - 1].y);
		cout << char(219);

		if (vat_can_dong[0].y == y + 1)
		{
			up = false;
		}

	}
	else
	{
		//V?t c?n bên trái
		gotoXY(vat_can_dong[0].x, vat_can_dong[0].y);
		cout << " ";

		for (int i = 0; i < vat_can_dong_so_o / 2; i++)
		{
			vat_can_dong[i].y++;
		}

		gotoXY(vat_can_dong[vat_can_dong_so_o / 2 - 1].x, vat_can_dong[vat_can_dong_so_o / 2 - 1].y);
		cout << char(219);

		//V?t c?n bên ph?i
		gotoXY(vat_can_dong[vat_can_dong_so_o - 1].x, vat_can_dong[vat_can_dong_so_o - 1].y);
		cout << " ";
		for (int i = vat_can_dong_so_o / 2; i < vat_can_dong_so_o; i++)
		{
			vat_can_dong[i].y--;
		}
		gotoXY(vat_can_dong[vat_can_dong_so_o / 2].x, vat_can_dong[vat_can_dong_so_o / 2].y);
		cout << char(219);


		if (vat_can_dong[vat_can_dong_so_o / 2 - 1].y == y + rong - 1)
		{
			up = true;
		}
	}

}

//Ki?m tra thua do ??ng v?t c?n màn 3
bool KiemTraThuaVatCan3(ToaDo ran[], int ran_dot, ToaDo vat_can[], int so_o_vat_can)
{
	if (ran_dot < 1)
	{
		return true;
	}
	for (int i = 0; i < so_o_vat_can; i++)
	{
		for (int j = 0; j < ran_dot; j++)
		{
			if (ran[j].x == vat_can[i].x && ran[j].y == vat_can[i].y)
			{
				return true;
			}
		}
	}
	return false;
}

//Ki?m tra thua màn 2
bool KiemTraThuaMan3(ToaDo ran[], int ran_dot, ToaDo vat_can[], int so_o_vat_can)
{
	if (RanChamThan(ran, ran_dot))
	{
		return true;
	}
	if (RanChamTuong(ran))
	{
		return true;
	}
	if (KiemTraThuaVatCan3(ran, ran_dot, vat_can, so_o_vat_can))
	{
		return true;
	}
	return false;
}

void AnQua3(ToaDo ran[], QUA& food, int& ran_dot, int& trung_doc, int& SPEED, int& diem, ToaDo vat_can[], int so_o_vat_can, ToaDo cong_win[], int cong_win_so_o, int soundOn)
{
	if (food.count < 5 && ran[0].x == food.qua1.x && ran[0].y == food.qua1.y)  // +1 point , +1 dot
	{
		ran_dot++;
		SPEED -= 2;
		diem += 2;
		trung_doc = 0;
		food.count++;
		FoodRound3(food, vat_can, so_o_vat_can, ran, ran_dot, cong_win, cong_win_so_o);
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
		FoodRound3(food, vat_can, so_o_vat_can, ran, ran_dot, cong_win, cong_win_so_o);
		if (soundOn == 1)
		{
			PlaySound(L"beep.wav", NULL, SND_ASYNC);
		}
	}
	else if (food.count == 6 && ran[0].x == food.quaDoc.x && ran[0].y == food.quaDoc.y) // trúng ??c, -1 ??t
	{
		trung_doc = 1;
		diem += 5;
		SPEED -= 10;
		food.count = 0;
		FoodRound3(food, vat_can, so_o_vat_can, ran, ran_dot, cong_win, cong_win_so_o);
		if (soundOn == 1)
		{
			PlaySound(L"beep.wav", NULL, SND_ASYNC);
		}
	}
}

//R?n trúng ??c- b? gi?m ??t
void TrungDoc(ToaDo ran[], int& ran_dot, int& thoi_gian_mat_dot)
{
	if (thoi_gian_mat_dot == 10)
	{
		gotoXY(ran[ran_dot - 1].x, ran[ran_dot - 1].y);
		cout << " ";
		ran_dot--;
		thoi_gian_mat_dot = 0;
	}
	else
	{
		thoi_gian_mat_dot++;
	}
}
//T?o c?ng d?ch chuy?n
void tao_cong_dich_chuyen(CongDichChuyen& cong, int x1, int y1, int x2, int y2)
{
	cong.cong_1.x = x1;
	cong.cong_1.y = y1;
	cong.cong_2.x = x2;
	cong.cong_2.y = y2;
}
//V? c?ng d?ch chuy?n
void ve_cong_dich_chuyen(CongDichChuyen& cong)
{
	//V? c?ng th? nh?t
	gotoXY(cong.cong_1.x, cong.cong_1.y);
	cout << char(178);
	//V? c?ng th? hai
	gotoXY(cong.cong_2.x, cong.cong_2.y);
	cout << char(178);
}
//Logic c?a c?ng d?ch chuy?n
void logic_cong(ToaDo ran[], int huong, CongDichChuyen& cong)
{
	if (ran[0].x == cong.cong_1.x && ran[0].y == cong.cong_1.y)
	{
		//V? c?ng th? nh?t
		gotoXY(cong.cong_1.x, cong.cong_1.y);
		cout << char(178);
		//X? lý logic
		if (huong == 4) // Ph?i
		{
			ran[0].x = cong.cong_2.x + 1;
			ran[0].y = cong.cong_2.y;
		}
		else if (huong == 3) // Trái
		{
			ran[0].x = cong.cong_2.x - 1;
			ran[0].y = cong.cong_2.y;
		}
		else if (huong == 1) //?i Lên
		{
			ran[0].y = cong.cong_2.y - 1;
			ran[0].x = cong.cong_2.x;
		}
		else // ?i Xu?ng
		{
			ran[0].y = cong.cong_2.y + 1;
			ran[0].x = cong.cong_2.x;
		}
	}
	else if (ran[0].x == cong.cong_2.x && ran[0].y == cong.cong_2.y)
	{
		//V? c?ng th? hai
		gotoXY(cong.cong_2.x, cong.cong_2.y);
		cout << char(178);
		// X? lý logic
		if (huong == 4) // Ph?i
		{
			ran[0].x = cong.cong_1.x + 1;
			ran[0].y = cong.cong_1.y;

		}
		else if (huong == 3) // Trái
		{
			ran[0].x = cong.cong_1.x - 1;
			ran[0].y = cong.cong_1.y;
		}
		else if (huong == 1) //?i Lên
		{
			ran[0].y = cong.cong_1.y - 1;
			ran[0].x = cong.cong_1.x;
		}
		else // ?i Xu?ng
		{
			ran[0].y = cong.cong_1.y + 1;
			ran[0].x = cong.cong_1.x;
		}
	}
}

void Man_3(char* ten_nguoi_choi, ToaDo ran[], int& ran_dot, int x, int y, int vung_ran_di_chuyen_dai,
	int bang_diem_dai, int rong, int& diem, int& SPEED, int& huong, int& man, ToaDo vat_can[], int& vat_can_so_o,
	string* data, int& nData, NguoiChoi& nguoiChoi, int STT, int soundOn)
{
	int temp = SPEED;
	if (vat_can_so_o == 0)
	{
		tao_vat_can_dong_man_3(x, y, vung_ran_di_chuyen_dai, rong, vat_can, vat_can_so_o);
	}
	ve_man_choi(x, y, vung_ran_di_chuyen_dai, bang_diem_dai, rong, vat_can, vat_can_so_o, man);//Hàm v? màn 2
	SPEED = temp;

	bool up = false;
	int trung_doc = 0;
	int thoi_gian_mat_dot = 0;

	bool checkPause = false;
	int diemTam = diem;
	int ran_dot_Tam = ran_dot;
	ToaDo ranTam[100];
	for (int i = 0; i < 100; i++)  ranTam[i] = ran[i];
	int huongTemp = huong;

	QUA food;
	food.count = 0;//S? l??ng qu?

	CongDichChuyen CongThuNhat;
	tao_cong_dich_chuyen(CongThuNhat, x, 16, x + vung_ran_di_chuyen_dai, 16);
	CongDichChuyen CongThuHai;
	tao_cong_dich_chuyen(CongThuHai, x, 17, x + vung_ran_di_chuyen_dai, 17);
	CongDichChuyen CongThuBa;
	tao_cong_dich_chuyen(CongThuBa, x, 18, x + vung_ran_di_chuyen_dai, 18);
	CongDichChuyen CongThuTu;
	tao_cong_dich_chuyen(CongThuTu, x + 5, y + 5, x + vung_ran_di_chuyen_dai - 5, y + rong - 5);

	ve_cong_dich_chuyen(CongThuNhat);
	ve_cong_dich_chuyen(CongThuHai);
	ve_cong_dich_chuyen(CongThuBa);
	ve_cong_dich_chuyen(CongThuTu);

	ToaDo cong_win[7];
	int cong_win_so_o = 0; //s? ô t?o thành 1 c?ng win
	FoodRound3(food, vat_can, vat_can_so_o, ran, ran_dot, cong_win, cong_win_so_o);

	ToaDo nhen[1][9];
	bool win = KiemTraDieuKienThang(diem, 20 * man);
	while (1)
	{
		int huongTam = huong;
		noCursorType();//Xóa con tr?(d?u nháy)
		ve_diem(diem, x + vung_ran_di_chuyen_dai + 2, y + 2, ten_nguoi_choi); // v? ?i?m
		BatSuKien(huong, checkPause);//Nh?n phím
		ToaDo dot_cuoi_cu = DiChuyen(ran, huong, ran_dot);//Di chuy?n r?n d?a trên nút ???c nh?n trên bàn phím
		HienThiRan(ran, dot_cuoi_cu, ran_dot);//Hi?n th? thân r?n m?i sau khi di chuy?n
		di_chuyen_vat_can_dong_man_3(x, y, vung_ran_di_chuyen_dai, rong, vat_can, vat_can_so_o, up);
		if (huong == -1)
		{
			int temp_1 = STT;
			huong = huongTam;
			NutLuuGame(ten_nguoi_choi, diem, ran_dot, ran, SPEED, huong, man, vat_can_so_o, vat_can, nhen, data, nData, nguoiChoi, STT);
			system("cls");
			man = 0;
			break;
		}
		logic_cong(ran, huong, CongThuNhat); // Ki?m tra r?n ?i qua c?ng d?ch chuy?n th? nh?t
		logic_cong(ran, huong, CongThuHai); // Ki?m tra r?n ?i qua c?ng d?ch chuy?n th? hai
		logic_cong(ran, huong, CongThuBa); // Ki?m tra r?n ?i qua c?ng d?ch chuy?n th? Ba
		logic_cong(ran, huong, CongThuTu); // Ki?m tra r?n ?i qua c?ng d?ch chuy?n th? T?
		AnQua3(ran, food, ran_dot, trung_doc, SPEED, diem, vat_can, vat_can_so_o, cong_win, cong_win_so_o, soundOn);//Ki?m tra ?n qu?

		if (trung_doc)
		{
			TrungDoc(ran, ran_dot, thoi_gian_mat_dot);
		}
		Sleep(SPEED);//T?c ?? r?n=100
		if (KiemTraThuaMan3(ran, ran_dot, vat_can, vat_can_so_o) || ran_dot == 0 || (win && RanChamCongWin(ran, cong_win, cong_win_so_o)))//Hàm ki?m tra thua
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
			break;
		}

		if (checkPause == true)
		{
			int pause = MenuTamDung();

			if (pause == 0)
			{
				system("cls");
				ve_man_choi(x, y, vung_ran_di_chuyen_dai, bang_diem_dai, rong, vat_can, vat_can_so_o, man);//Hàm v? màn 2

				ve_cong_dich_chuyen(CongThuNhat);
				ve_cong_dich_chuyen(CongThuHai);
				ve_cong_dich_chuyen(CongThuBa);
				ve_cong_dich_chuyen(CongThuTu);

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
					cout << "#";
				}
			}
			if (pause == 1)
			{
				system("cls");
				ve_man_choi(x, y, vung_ran_di_chuyen_dai, bang_diem_dai, rong, vat_can, vat_can_so_o, man);//Hàm v? màn 2

				ve_cong_dich_chuyen(CongThuNhat);
				ve_cong_dich_chuyen(CongThuHai);
				ve_cong_dich_chuyen(CongThuBa);
				ve_cong_dich_chuyen(CongThuTu);

				diem = diemTam;
				SPEED = temp;
				food.count = 0;
				ran_dot = ran_dot_Tam;
				for (int i = 0; i < 100; i++)  ran[i] = ranTam[i];
				huong = huongTemp;
				FoodRound3(food, vat_can, vat_can_so_o, ran, ran_dot, cong_win, cong_win_so_o);
			}
			if (pause == 2)
			{
				man = 0;
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
			tao_cong_win(x + 8, 6, cong_win, cong_win_so_o, huong_vao_cong);
			ve_cong_win(cong_win, cong_win_so_o);
			if (xu_ly_win(ran, cong_win))
			{
				if (soundOn == 1)
				{
					PlaySound(L"gamebeep.wav", NULL, SND_ASYNC);
				}
				man++;
				vat_can_so_o = 0;
				break;
			}
		}

	}
}



