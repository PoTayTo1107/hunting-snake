#include <Windows.h>
#pragma once
void ve_ten_game();
void ve_logo_game();
void input_menu(int& goup, int& enter);
void ve_khung_chu_nhat(int x, int y, int dai, int rong, char* noi_dung);
void huy_to_mau(int x, int y, int rong, int dai, char* noi_dung);
void to_mau(int x, int y, int rong, int dai, const char* noi_dung);
int logic_menu(int x, int y, int rong, int dai, char noi_dung[][30], int soundOn);
int menu_new_game(int soundOn);

void TaoBang(int x, int y, int dai, int rong, char* noi_dung);
void BangHuongDanChoiGame(int x, int y, int dai, int rong);
void menuHuongDanChoi();
int MenuTamDung();