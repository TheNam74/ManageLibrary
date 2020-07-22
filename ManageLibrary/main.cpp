#include "All.h"

int main(int argc, char** argv) {
	EditBookInfo();
	/*char username[45], password[45];
	int status;
	do
	{
		inputLogin(username, password);
		status = login(username, password);
		MainMenu(status);
	} while (true);*/
	
}
//Viết hàm xóa Dlist sau khi dùng
//Chỉnh hàm nhập 1 num 2 num khi nhấn enter thì loop tiếp chứ k văng ra
// Dựa vào số lượng argc để chọn cách đăng nhập thẳng hay gián tiếp
//drawRectangle(36, 5, 48, 23, 3); lấy điểm (36,5) làm gốc
//Thêm phần check nếu reader, user, book trống(NULL)
//Hàm nhập số lượng sách có vấn đề khi mà số lượng sách ko biết trước 1 số hay 2 số
