#pragma once
#include <stdio.h>
#include <conio.h>
#include <windows.h>

#define BLACK_COLOR			0
#define DARK_BLUE_COLOR		1
#define DARK_GREEN_COLOR	2
#define DARK_CYAN_COLOR		3
#define DARK_RED_COLOR		4
#define DARK_PINK_COLOR		5
#define DARK_YELLOW_COLOR	6
#define DARK_WHITE_COLOR	7
#define GREY_COLOR			8
#define BLUE_COLOR			9
#define GREEN_COLOR			10
#define CYAN_COLOR			11
#define RED_COLOR			12
#define PINK_COLOR			13
#define YELLOW_COLOR		14
#define WHITE_COLOR			15

#define KEY_UP		1072
#define KEY_DOWN	1080
#define KEY_LEFT	1075
#define KEY_RIGHT	1077
#define KEY_NONE	-1

// L?y nút bàn phím do ng??i dùng b?m
// Tr? v?: Mã c?a phím
int inputKey();

// Xóa màn hình
void clrscr();

// Di chuy?n con tr? console ??n v? trí có t?a ?? (x, y)
void gotoXY(int x, int y);

// L?y t?a ?? x hi?n t?i c?a con tr? console
int whereX();

// L?y t?a ?? y hi?n t?i c?a con tr? console
int whereY();

// Xóa con tr? nháy
void noCursorType();

// ??i màu ch?
// Tham s?: Mã màu
void setTextColor(int color);
void FixConsoleWindow();
//end----------------------Screen----------------------end
void SetWindowSize(SHORT width, SHORT height);
void resizeConsole(int width, int height);

void TextColor(int color);
void FontSize(int x, int y);
void DisableSelection();