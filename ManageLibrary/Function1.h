#ifndef Function1_h
#define Function1_h
#include "All.h"
//Viết username vào login.txt
void WriteUsername(char* username);

//0: fail; 1:admin; 2:manager; 3:expert
int login(char* user, char* password);

//Nhập tài khoản và mật khẩu
void inputLogin(char* username, char* password);

//Tạo người dùng và add vào file tương ứng nếu hợp lệ
void CreateUser();

//In người dùng vào file binary
void WriteUser(User user);

//In người dùng
void PrintUser(User user);

//Cấp phát Node User
DNodeUser* CreateUserNode(User user);

//Thêm phần tử vào đuôi DListUser
void AddTailDListUser(DListUser& list, DNodeUser* Node);

//Đọc các user từ file vào linkedlist
DListUser ReadUser();

//Viết từ DlistUser vào lại file users.bin
void WriteDListUser(DListUser list);

//Lấy tên username từ file login.txt
void GetUsername(char* username);

//Đổi mật khẩu
void ChangeUserPassword();

void EditUserInfo();


//------------------Các hàm tạm thời---------------------

//Đọc tất cả User trong file(trực tiếp)
void ReadUserTemp();

//In ra tất cả phần tử trong DListUser
void PrintDListUser(DListUser list);

void ViewOneUser(User user);

#endif