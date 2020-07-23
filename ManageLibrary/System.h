#ifndef System_h
#define System_h
#include "All.h"
//Kiểm tra xem file có tồn tại hay không
bool isFileExists(const char* filename);
//Tạo folder và các file
void initSystemFolder();

void MainMenu(int status);
void MenuFunction2(int status);
void MenuFunction3(int status);


//Ham chi cho phep nhap so 1 hoac 0
int input1num();

//lấy ngày thực
Day GetCurrentDate();

//Nhập n số thực
int inputnNum(int n);

//Nhập ngày/tháng/năm
Day inputDay();

//In ngày/tháng/năm
void printDay(Day day);

//Tính "day" ngày sau ngày D1
Day CountDaysAfter(Day D1, int day);

bool LeapYear(int year);

//Kiểm tra ngày D2 có sau ngày D1 hay không
bool IsAfter(Day D1, Day D2);

//-------Vẽ------------
void DirectPanel(int function);
#endif
