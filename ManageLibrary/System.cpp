#include "System.h"
bool isFileExists(const char* filename) {
	FILE* file;
	if (file=fopen(filename,"r")) {
		fclose(file);
		return 1;
	}
	return 0;
}

void initSystemFolder()
{
	FILE* file;
	_mkdir("books");
	_mkdir("borrowcards");
	_mkdir("readers");
	_mkdir("user");
	file = fopen("user/users.bin", "a");
	fclose(file);
}

void MainMenu(int status) {
	char KeyBoard;
	switch (status)
	{
	case 1://admin
		do
		{
			clear();
			cout << "1Cap nhat thong tin" << endl;
			cout << "2Doi mat khau" << endl;
			cout << "3Tao nguoi dung" << endl;
			cout << "4Quan ly doc gia" << endl;
			cout << "5Quan ly sach" << endl;
			cout << "6Lap phieu muon sach" << endl;
			cout << "7Lap phieu tra sach" << endl;
			cout << "8Thong ke" << endl;
			cout << "0Dang xuat" << endl;
			KeyBoard = _getch();
			switch (KeyBoard)
			{
			case 49:
				cout << "Cap nhat thong tin" << endl;
				break;
			case 50:
				cout << "Doi mat khau" << endl;
				break;
			case 51:
				cout << "Tao nguoi dung" << endl;
				CreateUser();
				break;
			case 52:
				MenuFunction2(status);
				break;
			case 53:
				cout << "Quan ly sach" << endl;
				MenuFunction3(status);
				break;
			case 54:
				cout << "Lap phieu muon sach" << endl;
				CreateBorrowCard();
				break;
			case 55:
				cout << "Lap phieu tra sach" << endl;
				ReturnBook();
				break;
			case 56:
				cout << "Thong ke" << endl;
				Statistic();
				break;
			default:
				break;
			}
		} while (KeyBoard != 48);
		cout << "Da dang xuat" << endl;
		return;
	case 2://manager
		do
		{
			cout << "\n1Cap nhat thong tin" << endl;
			cout << "2Doi mat khau" << endl;
			cout << "3Quan ly doc gia" << endl;
			cout << "4Quan ly sach" << endl;
			cout << "5Lap phieu muon sach" << endl;
			cout << "6Lap phieu tra sach" << endl;
			cout << "7Thong ke" << endl;
			cout << "0Dang xuat\n-----------------" << endl;
			KeyBoard = _getch();
			switch (KeyBoard)
			{
			case 49:
				cout << "Cap nhat thong tin" << endl;
				break;
			case 50:
				cout << "Doi mat khau" << endl;
				ChangeUserPassword();
				break;
			case 51:
				MenuFunction2(status);
				break;
			case 52:
				cout << "Quan li sach" << endl;
				break;
			case 53:
				cout << "Lap phieu muon sach" << endl;
				break;
			case 54:
				cout << "Lap phieu tra sach" << endl;
				break;
			case 55:
				cout << "Thong ke" << endl;
				break;
			default:
				break;
			}
		} while (KeyBoard != 48);
		cout << "Da dang xuat" << endl;
		return;
	case 3://expert
		do
		{
			cout << "\n1Cap nhat thong tin" << endl;
			cout << "2Doi mat khau" << endl;
			cout << "3Quan ly doc gia" << endl;
			cout << "4Quan ly sach" << endl;
			cout << "5Lap phieu muon sach" << endl;
			cout << "6Lap phieu tra sach" << endl;
			cout << "7Thong ke" << endl;
			cout << "0Dang xuat\n-----------------" << endl;
			KeyBoard = _getch();
			switch (KeyBoard)
			{
			case 49:
				cout << "Cap nhat thong tin" << endl;
				break;
			case 50:
				cout << "Doi mat khau" << endl;
				ChangeUserPassword();
				break;
			case 51:
				MenuFunction2(status);
				break;
			case 52:
				cout << "Quan li sach" << endl;
				break;
			case 53:
				cout << "Lap phieu muon sach" << endl;
				break;
			case 54:
				cout << "Lap phieu tra sach" << endl;
				break;
			case 55:
				cout << "Thong ke" << endl;
				break;
			default:
				break;
			}
		} while (KeyBoard != 48);
		cout << "Da dang xuat" << endl;
		return;
	default:
		return;
	}
}
void MenuFunction2(int status) {
	char KeyBoard;
	switch (status)
	{
	case 1:
		do
		{
			clear();
			cout << "1Xem danh sach cac doc gia" << endl;
			cout << "2Them doc gia" << endl;
			cout << "3Chinh sua thong tin doc gia" << endl;
			cout << "4Xoa thong tin doc gia" << endl;
			cout << "5Tim kiem doc gia theo CMND" << endl;
			cout << "6Tim kiem doc gia theo ten" << endl;
			cout << "0Quay lai" << endl;
			KeyBoard = _getch();
			switch (KeyBoard)
			{
			case 49:
				cout << "1Xem danh sach cac doc gia" << endl;
				ViewReaders();
				break;
			case 50:
				cout << "2Them doc gia" << endl;
				CreateReader();
				break;
			case 51:
				cout << "3Chinh sua thong tin doc gia" << endl;
				EditReaderInfo();
				break;
			case 52:
				cout << "4Xoa thong tin doc gia" << endl;
				RemoveReader();
				break;
			case 53:
				cout << "5Tim kiem doc gia theo CMND" << endl;
				FindReaderByID();
				break;
			case 54:
				cout << "6Tim kiem doc gia theo ten" << endl;
				FindReaderByName();
				break;
			default:
				break;
			}
		} while (KeyBoard != 48);
		return;
	case 2:
		do
		{
			cout << "1Xem danh sach cac doc gia" << endl;
			cout << "2Them doc gia" << endl;
			cout << "3Chinh sua thong tin doc gia" << endl;
			cout << "4Xoa thong tin doc gia" << endl;
			cout << "5Tim kiem doc gia theo CMND" << endl;
			cout << "6Tim kiem doc gia theo ten" << endl;
			cout << "0Quay lai" << endl;
			KeyBoard = _getch();
			switch (KeyBoard)
			{
			case 49:
				cout << "1Xem danh sach cac doc gia" << endl;
				break;
			case 50:
				cout << "2Them doc gia" << endl;
				break;
			case 51:
				cout << "3Chinh sua thong tin doc gia" << endl;
				break;
			case 52:
				cout << "4Xoa thong tin doc gia" << endl;
				break;
			case 53:
				cout << "5Tim kiem doc gia theo CMND" << endl;
				break;
			case 54:
				cout << "6Tim kiem doc gia theo ten" << endl;
				break;
			default:
				break;
			}
		} while (KeyBoard != 48);
		return;
	case 3:
		do
		{
			cout << "1Xem danh sach cac doc gia" << endl;
			cout << "2Them doc gia" << endl;
			cout << "3Chinh sua thong tin doc gia" << endl;
			cout << "4Tim kiem doc gia theo CMND" << endl;
			cout << "5Tim kiem doc gia theo ten" << endl;
			cout << "0Quay lai" << endl;
			KeyBoard = _getch();
			switch (KeyBoard)
			{
			case 49:
				cout << "1Xem danh sach cac doc gia" << endl;
				break;
			case 50:
				cout << "2Them doc gia" << endl;
				break;
			case 51:
				cout << "3Chinh sua thong tin doc gia" << endl;
				break;
			case 52:
				cout << "4Tim kiem doc gia theo CMND" << endl;
				break;
			case 53:
				cout << "5Tim kiem doc gia theo ten" << endl;
				break;
			default:
				break;
			}
		} while (KeyBoard != 48);
		return;
	default:
		return;
	}
}
void MenuFunction3(int status) {
	char KeyBoard;
	switch (status)
	{
	case 1:
		do
		{
			clear();
			cout << "1Xem danh sach cac sach" << endl;
			cout << "2Them sach" << endl;
			cout << "3Chinh sua thong tin sach" << endl;
			cout << "4Xoa thong tin sach" << endl;
			cout << "5Tim kiem sach theo ISBN" << endl;
			cout << "6Tim kiem sach theo ten" << endl;
			cout << "0Quay lai" << endl;
			KeyBoard = _getch();
			switch (KeyBoard)
			{
			case 49:
				cout << "1Xem danh sach cac sach" << endl;
				ViewBook();
				break;
			case 50:
				cout << "2Them sach" << endl;
				CreateBook();
				break;
			case 51:
				cout << "3Chinh sua thong tin sach" << endl;
				EditBookInfo();
				break;
			case 52:
				cout << "4Xoa thong tin sach" << endl;
				RemoveBook();
				break;
			case 53:
				cout << "5Tim kiem sach theo ISBN" << endl;
				FindBookByISBN();
				break;
			case 54:
				cout << "6Tim kiem sach theo ten" << endl;
				FindBookByName();
				break;
			default:
				break;
			}
		} while (KeyBoard != 48);
		return;
	case 2:
		do
		{
			cout << "1Xem danh sach cac sach" << endl;
			cout << "2Them sach" << endl;
			cout << "3Chinh sua thong tin sach" << endl;
			cout << "4Xoa thong tin sach" << endl;
			cout << "5Tim kiem sach theo ISBN" << endl;
			cout << "6Tim kiem sach theo ten" << endl;
			cout << "0Quay lai" << endl;
			KeyBoard = _getch();
			switch (KeyBoard)
			{
			case 49:
				cout << "1Xem danh sach cac sach" << endl;
				break;
			case 50:
				cout << "2Them sach" << endl;
				break;
			case 51:
				cout << "3Chinh sua thong tin sach" << endl;
				break;
			case 52:
				cout << "4Xoa thong tin sach" << endl;
				break;
			case 53:
				cout << "5Tim kiem sach theo ISBN" << endl;
				break;
			case 54:
				cout << "6Tim kiem sach theo ten" << endl;
				break;
			default:
				break;
			}
		} while (KeyBoard != 48);
		return;
	case 3:
		do
		{
			cout << "1Xem danh sach cac sach" << endl;
			cout << "2Them sach" << endl;
			cout << "3Chinh sua thong tin sach" << endl;
			cout << "4Tim kiem sach theo ISBN" << endl;
			cout << "5Tim kiem sach theo ten" << endl;
			cout << "0Quay lai" << endl;
			KeyBoard = _getch();
			switch (KeyBoard)
			{
			case 49:
				cout << "1Xem danh sach cac sach" << endl;
				break;
			case 50:
				cout << "2Them sach" << endl;
				break;
			case 51:
				cout << "3Chinh sua thong tin sach" << endl;
				break;
			case 52:
				cout << "4Tim kiem sach theo ISBN" << endl;
				break;
			case 53:
				cout << "5Tim kiem sach theo ten" << endl;
				break;
			default:
				break;
			}
		} while (KeyBoard != 48);
		return;
	default:
		return;
	}
}


int input1num() {
	char KeyBoard;
	do
	{
		KeyBoard = _getch();
	} while (KeyBoard != 48 && KeyBoard != 49);
	cout << KeyBoard - 48;
	return KeyBoard - 48;
}
int inputnNum(int n) {
	char* Num = new char[n + 1];
	char KeyBoard;
	int pos = 0;
	do
	{
		KeyBoard = _getch();
		if (KeyBoard == 13)
			break;
		else if (KeyBoard >= 48 && KeyBoard <= 57)
		{
			Num[pos++] = KeyBoard;
			cout << KeyBoard;
		}
	} while (pos<n);
	Num[pos] = '\0';
	return atoi(Num);
}
//Ngày tháng
Day GetCurrentDate() {
	Day day;
	time_t now = time(0);
	tm* ltm = localtime(&now);
	day.Year = 1900 + ltm->tm_year;
	day.Month = 1 + ltm->tm_mon;
	day.Date = ltm->tm_mday;
	return day;
}
Day inputDay(){
	Day day;
	day.Date = inputnNum(2);
	cout<<"/";
	day.Month = inputnNum(2);
	cout << "/";
	day.Year = inputnNum(4);
	return day;
}
void printDay(Day day) {
	cout << day.Date << "/" << day.Month << "/" << day.Year;
}
Day CountDaysAfter(Day D1, int day)
{
	while (day > 0)
	{
		if (D1.Date == 31 && D1.Month == 12)
		{
			D1.Year++;
			D1.Month = 1;
			D1.Date = 0;
		}
		switch (D1.Month)
		{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			if (D1.Date == 31)
			{
				D1.Date = 0;
				D1.Month++;
			}
			break;
		case 2:
			if (D1.Date == 28 && LeapYear(D1.Year) == 0)
			{
				D1.Date = 0;
				D1.Month++;
			}
			if (D1.Date == 29 && LeapYear(D1.Year) == 1)
			{
				D1.Date = 0;
				D1.Month++;
			}
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			if (D1.Date == 30)
			{
				D1.Date = 0;
				D1.Month++;
			}
			break;
		}
		day--;
		D1.Date++;
	}
	return D1;
}
bool LeapYear(int year)
{
	if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
		return 1;
	return 0;
}
bool IsAfter(Day D1, Day D2) {
	if (D2.Year > D1.Year)
		return 1;
	if (D2.Year < D1.Year)
		return 0;
	if (D2.Month > D1.Month)
		return 1;
	if (D2.Month < D1.Month)
		return 0;
	if (D2.Date > D1.Date)
		return 1;
	return 0;
}
int Duration(Day D1, Day D2)
{
	int day = 0;
	while (D1.Date != D2.Date || D1.Month != D2.Month || D1.Year != D2.Year)
	{
		if (D1.Date == 31 && D1.Month == 12)
		{
			D1.Year++;
			D1.Month = 1;
			D1.Date = 0;
		}
		switch (D1.Month)
		{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			if (D1.Date == 31)
			{
				D1.Date = 0;
				D1.Month++;
			}
			break;
		case 2:
			if (D1.Date == 28 && LeapYear(D1.Year) == 0)
			{
				D1.Date = 0;
				D1.Month++;
			}
			if (D1.Date == 29 && LeapYear(D1.Year) == 1)
			{
				D1.Date = 0;
				D1.Month++;
			}
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			if (D1.Date == 30)
			{
				D1.Date = 0;
				D1.Month++;
			}
			break;
		}
		day++;
		D1.Date++;
	}
	return day;
}
//Vẽ
void DirectPanel(int function) {
	if (function == 21)
	{
		drawRectangle(36, 24, 40, 4, 3);
		gotoxy(44, 25);
		cout << "1: PREVIOUS";
		gotoxy(60, 25);
		cout << "2: NEXT";
		gotoxy(60, 26);
		cout << "0: THOAT";
		drawRectangle(36, 27, 40, 1, 3);
		return;
	}
	else if (function == 22)
	{
		drawRectangle(36, 24, 40, 4, 3);
		gotoxy(44, 25);
		cout << "1: PREVIOUS";
		gotoxy(60, 25);
		cout << "2: NEXT";
		gotoxy(60, 26);
		cout << "0: LUU VA THOAT";
		drawRectangle(36, 27, 40, 1, 3);
		return;
	}
	else if (function == 24)
	{
		drawRectangle(36, 24, 40, 4, 3);
		gotoxy(44, 25);
		cout << "1: PREVIOUS";
		gotoxy(60, 25);
		cout << "2: NEXT";
		gotoxy(44, 26);
		cout << "3: XOA DOC GIA";
		gotoxy(60, 26);
		cout << "0: THOAT";
		drawRectangle(36, 27, 40, 1, 3);
		return;
	}
	else if (function == 23)
	{
		drawRectangle(36, 24, 40, 4, 3);
		gotoxy(44, 25);
		cout << "1: PREVIOUS";
		gotoxy(60, 25);
		cout << "2: NEXT";
		gotoxy(44, 26);
		cout << "3: CHINH SUA";
		gotoxy(60, 26);
		cout << "0: THOAT";
		drawRectangle(36, 27, 40, 1, 3);
		return;
	}
	else if (function == 34)
	{
		drawRectangle(36, 24, 40, 4, 3);
		gotoxy(44, 25);
		cout << "1: PREVIOUS";
		gotoxy(60, 25);
		cout << "2: NEXT";
		gotoxy(44, 26);
		cout << "3: XOA SACH";
		gotoxy(60, 26);
		cout << "0: THOAT";
		drawRectangle(36, 27, 40, 1, 3);
		return;
	}
	else if (function == 0) {
		drawRectangle(36, 24, 40, 4, 3);
		gotoxy(60, 26);
		cout << "0: THOAT";
		drawRectangle(36, 27, 40, 1, 3);
		return;
	}
}
void AlertPanel(const char* title,int Color,int type) {
	int x =36+ (40 - strlen(title)) / 2;
	if (type == 0) {//ở trên
		drawRectangle(36, 7, 40, 3, Color);
		gotoxy(x, 8.5);
		textBgColor(0, 7);
		cout <<title;
	}
	else if (type == 1) {
		drawRectangle(36, 14, 40, 3, Color);
		gotoxy(x, 15.5);
		textBgColor(0, 7);
		cout << title;
	}
	textBgColor(7, 0);
}


