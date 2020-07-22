#ifndef consoleGraphing_h
#define consoleGraphing_h
#include "All.h"
// Hàm thay đổi kích cỡ của khung cmd với tham số truyền vào là chiều cao, chiều rộng.
void resizeConsole(int width, int height);

// Hàm tô màu.
void textcolor(int x);

// Hàm dịch chuyển con trỏ đến tọa độ x, y.
void gotoxy(int x, int y);

// Hàm xóa màn hình.
void XoaManHinh();

// x, y là tọa độ con trỏ cần nhảy đến để viết, a là chuỗi cần truyền vào, color là màu truyền vào.
void ToMau(int x, int y, char* a, int color);

//Ẩn con trỏ
void Nocursortype();
//Chỉnh màu chữ và màu nền
void textBgColor(int colorText, int colorBG);

//Vẽ hình chữ nhật
void drawRectangle(int positionX, int positionY, int width, int height, int color);

int whereX();
int whereY();
void clear();
#endif