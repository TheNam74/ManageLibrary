#include "All.h"

int main(int argc, char** argv) {
	initSystemFolder();
	DListBorrowCard list = ReadBorrowCard();
	PrintDListBorrowCard(list);
	ReturnBook();
	ViewBook();
	/*
	char username[45], password[45];
	int status;
	do
	{
		inputLogin(username, password);
		status = login(username, password);
		if(status!=0)
			MainMenu(status);
	} while (true);
	*/
}
//Viết hàm xóa Dlist sau khi dùng
//Chỉnh hàm nhập 1 num 2 num khi nhấn enter thì loop tiếp chứ k văng ra(nhập n num k chỉnh)
// Dựa vào số lượng argc để chọn cách đăng nhập thẳng hay gián tiếp
//drawRectangle(36, 5, 48, 23, 3); lấy điểm (36,5) làm gốc
//Hàm nhập số lượng sách có vấn đề khi mà số lượng sách ko biết trước 1 số hay 2 số
//Lưu ý khi chưa có file nào mà đòi xem thì sẽ mở file không thành công nên phải báo trống.(mở không được thì return)
//check valid user name,reader,book(thông tin hợp lệ(các thông tin là số nhưng nhập char) + trùng)

//làm 1 hàm thông báo lên màn hình với đầu vào là 1 string.
//viết trường hợp trả sau hạn hoặc mất sách.
