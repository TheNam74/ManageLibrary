﻿#include "All.h"

int main(int argc, char** argv) {
	initSystemFolder();
	char username[45], password[45];
	int status;
	do
	{
		inputLogin(username, password);
		status = login(username, password);
		if (status != 0)
			MainMenu(status);
	} while (true); 
	
}
//Viết hàm xóa Dlist sau khi dùng
//Chỉnh hàm nhập 1 num 2 num khi nhấn enter thì loop tiếp chứ k văng ra(nhập n num k chỉnh)
// Dựa vào số lượng argc để chọn cách đăng nhập thẳng hay gián tiếp
//drawRectangle(36, 5, 48, 23, 3); lấy điểm (36,5) làm gốc
//Hàm nhập số lượng sách có vấn đề khi mà số lượng sách ko biết trước 1 số hay 2 số()(Nhập char rồi atoi qua int)
//Lưu ý khi chưa có file nào mà đòi xem thì sẽ mở file không thành công nên phải báo trống.(mở không được thì return)
//check valid user name,reader,book(thông tin hợp lệ(các thông tin là số nhưng nhập char) + trùng(username,ISBN)
//+Check các giá trị kiểu char nhưng sẽ được dùng như kiểu số
//+Check user name trùng
//+check isbn trùng (có một vấn đề là nếu nhập lại ISBN của chính cái đang sửa thì nó báo lỗi)
//các cin.getline nếu nhập quá số lượng cho phép sẽ lỗi


