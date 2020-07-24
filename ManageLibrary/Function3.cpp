#include "Function3.h"
void CreateBook() {
	clear();
	Book book;
	drawRectangle(36, 5, 40, 23, 3);
	gotoxy(38, 6);
	textBgColor(0, 3);
	cout << "ISBN: ";
	drawRectangle(38, 7, 36, 1, 7);
	gotoxy(38, 8);
	textBgColor(0, 3);
	cout << "Ten sach: ";
	drawRectangle(38, 9, 36, 1, 7);

	gotoxy(38, 10);
	textBgColor(0, 3);
	cout << "Tac gia: ";
	drawRectangle(38, 11, 36, 1, 7);

	gotoxy(38, 12);
	textBgColor(0, 3);
	cout << "Nha xuat ban: ";
	drawRectangle(38, 13, 36, 1, 7);

	gotoxy(38, 14);
	textBgColor(0, 3);
	cout << "Nam xuat ban: ";
	drawRectangle(38, 15, 36, 1, 7);

	gotoxy(38, 16);
	textBgColor(0, 3);
	cout << "The loai: ";
	drawRectangle(38, 17, 36, 1, 7);

	gotoxy(38, 18);
	textBgColor(0, 3);
	cout << "Gia sach: (VND)";
	drawRectangle(38, 19, 36, 1, 7);

	gotoxy(38, 20);
	textBgColor(0, 3);
	cout << "So luong sach: ";
	drawRectangle(38, 21, 36, 1, 7);


	DirectPanel(24);
	textBgColor(0, 7);
	gotoxy(38, 7);
	cin.getline(book.ISBN, 14);
	gotoxy(38, 9);
	cin.getline(book.Name, 44);
	gotoxy(38, 11);
	cin.getline(book.Author, 44);
	gotoxy(38, 13);
	cin.getline(book.Publisher, 44);
	gotoxy(38, 15);
	book.PublishingYear = inputnNum(4);
	gotoxy(38, 17);
	cin.getline(book.Category, 44);
	gotoxy(38, 19);
	cin.getline(book.Price, 44);
	gotoxy(38, 21);
	book.Number = inputnNum(1);
	book.Borrowed = 0;
	//check valid book
	//vẽ 1 bảng alert lưu thành công
	WriteBook(book);
	textBgColor(7, 0);
}
void ViewBook() {
	DListBook list = ReadBook();
	char KeyBoard;
	DNodeBook* p = list.Head;
	ViewOneBook(p->book, 21);
	do
	{
		KeyBoard = _getch();
		if (KeyBoard == 49 && p->Prev != NULL)
		{
			p = p->Prev;
			ViewOneBook(p->book, 21);
		}
		else if (KeyBoard == 50 && p->Next != NULL)
		{
			p = p->Next;
			ViewOneBook(p->book, 21);
		}
	} while (KeyBoard != 48);
	textBgColor(7, 0);
}
void EditBookInfo() {
	clear();
	DListBook list = ReadBook();
	if (list.Head == NULL)
		cout << "Khong co quyen sach nao";
	char KeyBoard;
	DNodeBook* p = list.Head;
	ViewOneBook(p->book, 23);
	int Count = 1;
	do
	{
		KeyBoard = _getch();
		if (KeyBoard == 49 && p->Prev != NULL)
		{
			Count--;
			p = p->Prev;
			ViewOneBook(p->book, 23);
		}
		else if (KeyBoard == 50 && p->Next != NULL)
		{
			Count++;
			p = p->Next;
			ViewOneBook(p->book, 23);
		}
		else if (KeyBoard == 51)
		{
			drawRectangle(36, 5, 40, 23, 3);
			gotoxy(38, 6);
			textBgColor(0, 3);
			cout << "ISBN: ";
			drawRectangle(38, 7, 36, 1, 7);
			
			gotoxy(38, 8);
			textBgColor(0, 3);
			cout << "Ten sach: ";
			drawRectangle(38, 9, 36, 1, 7);
			
			gotoxy(38, 10);
			textBgColor(0, 3);
			cout << "Tac gia: ";
			drawRectangle(38, 11, 36, 1, 7);
			
			gotoxy(38, 12);
			textBgColor(0, 3);
			cout << "Nha xuat ban: ";
			drawRectangle(38, 13, 36, 1, 7);
			
			gotoxy(38, 14);
			textBgColor(0, 3);
			cout << "Nam xuat ban: ";
			drawRectangle(38, 15, 36, 1, 7);
			
			gotoxy(38, 16);
			textBgColor(0, 3);
			cout << "The loai: ";
			drawRectangle(38, 17, 36, 1, 7);
			gotoxy(38, 18);
			textBgColor(0, 3);
			cout << "Gia sach: ";
			drawRectangle(38, 19, 36, 1, 7);
			gotoxy(38, 20);
			textBgColor(0, 3);
			cout << "So luong sach: ";
			drawRectangle(38, 21, 36, 1, 7);
			gotoxy(38, 22);
			textBgColor(0, 3);
			cout << "So luong sach da duoc muon: ";
			drawRectangle(38, 23, 36, 1, 7);
			gotoxy(38, 23);
			cout << p->book.Borrowed;
			//Bắt đầu input edited info
			DirectPanel(23);
			textBgColor(0, 7);
			gotoxy(38, 7);
			cin.getline(p->book.ISBN, 14);
			gotoxy(38, 9);
			cin.getline(p->book.Name, 100);
			gotoxy(38, 11);
			cin.getline(p->book.Author, 44);
			gotoxy(38, 13);
			cin.getline(p->book.Publisher, 100);
			gotoxy(38, 15);
			p->book.PublishingYear = inputnNum(4);
			gotoxy(38, 17);
			cin.getline(p->book.Category, 100);
			gotoxy(38, 19);
			cin.getline(p->book.Price, 101);
			gotoxy(38, 21);
			p->book.Number = inputnNum(2);
		}
	} while (KeyBoard != 48);
	WriteDListBook(list);
	textBgColor(7, 0);
}
void RemoveBook() {
	DListBook list = ReadBook();
	if (list.Head == NULL)
		cout << "Khong co quyen sach nao nao";
	char KeyBoard;
	DNodeBook* p = list.Head;
	ViewOneBook(p->book, 34);
	int Count = 1;
	do
	{
		KeyBoard = _getch();
		if (KeyBoard == 49 && p->Prev != NULL)
		{
			Count--;
			p = p->Prev;
			ViewOneBook(p->book, 34);
		}
		else if (KeyBoard == 50 && p->Next != NULL)
		{
			Count++;
			p = p->Next;
			ViewOneBook(p->book, 34);
		}
		else if (KeyBoard == 51)
		{
			if (Count == 1)
			{
				if (p->Next != NULL) {//Xóa đầu và list có hơn 1 DNode
					p = p->Next;
					DeleteDNodeBookAtK(list, Count);
				}
				else {
					DeleteDNodeBookAtK(list, Count);
					break;
				}
			}//Xóa những chỗ khác
			else {
				p = p->Prev;
				DeleteDNodeBookAtK(list, Count);
				Count--;
			}
			ViewOneBook(p->book, 34);
		}
	} while (KeyBoard != 48);
	WriteDListBook(list);
	textBgColor(7, 0);
}
void FindBookByName() {
	DListBook list = ReadBook();
	char Name[45];
	cout << "Nhap ten sach muon tim: ";
	cin.getline(Name, 44);
	for (DNodeBook* p = list.Head; p; p = p->Next) {
		if (_stricmp(Name, p->book.Name) == 0)
		{
			ViewOneBook(p->book, 0);
			_getch();
			textBgColor(7, 0);
			return;
		}
	}
	cout << "Khong co sach nao ten " << Name<<" trong thu vien";
	_getch();
	clear();
}
void FindBookByISBN() {
	DListBook list = ReadBook();
	char ISBN[14];
	cout << "Nhap ISBN cua sach muon tim: ";
	cin.getline(ISBN, 13);
	DNodeBook *temp=FindBookByISBN(list, ISBN);
	if (temp != NULL)
	{
		ViewOneBook(temp->book,0);
		_getch();
		textBgColor(7, 0);
		return;
	}
	else
	{
		cout << "Khong co sach nao co ISBN la: " << ISBN << " trong thu vien";
		_getch();
	}
	clear();
}
void CreateBorrowCard() {
	DListBook list = ReadBook();
	DListReader list2 = ReadReader();
	BorrowCard card;
	GetCode_ISBN(card.Code, card.ISBN);
	//check độc giả có tồn tại không
	DNodeReader* preader;
	for (preader = list2.Head; preader; preader = preader->Next) {
		if (atoi(card.Code) == preader->reader.Code)
			break;
	}
	if (preader == NULL)
	{
		cout << "Doc gia khong ton tai";
		return;
	}
	//check sách có tồn tại và còn không
	DNodeBook* pbook = FindBookByISBN(list, card.ISBN);
	if (pbook != NULL && pbook->book.Borrowed == pbook->book.Number)
	{
		cout << "Quyen sach nay da bi muon het";
		return;
	}
	else if (pbook == NULL)
	{
		cout << "Quyen sach nay khong ton tai";
		return;
	}
	//ISBN va Code hợp lệ
	card.BorrowedDay = GetCurrentDate();
	card.ReturnDay = CountDaysAfter(card.BorrowedDay, 7);
	pbook->book.Borrowed++;
	WriteBorrowCard(card);
	WriteDListBook(list);
	cout << "Muon thanh cong";
	textBgColor(7,0);
}
void ReturnBook() {
	DListBorrowCard list = ReadBorrowCard();
	DListBook list2 = ReadBook();
	BorrowCard card;
	GetCode_ISBN(card.Code, card.ISBN);
	DNodeBorrowCard* p = list.Head;
	int Count = 1;
	for (p; p; p = p->Next) {
		if (atoi(p->borrowcard.Code) == atoi(card.Code) && atoi(p->borrowcard.ISBN) == atoi(card.ISBN))
		{
			break;
		}
		Count++;
	}
	//Thẻ không tồn tại
	if (p == NULL) {
		AlertPanel("THE MUON NAY KHONG TON TAI", 4, 0);
		return;
	}
	else {
		//giảm số lượng sách mượn trong books.bin và xóa đi thẻ mượn;
		DNodeBook* temp = FindBookByISBN(list2, p->borrowcard.ISBN);
		temp->book.Borrowed--;
		//báo mất hoặc bị trễ hạn;
		AlertPanel("1:TRA SACH \t 2:BAO MAT", 2, 0);
		char KeyBoard;
		do
		{
			KeyBoard = _getch();
			if (KeyBoard == 50) {//mat sach
				char TITLE[50] = "THANH TOAN: ";
				char Pay[20];
				_itoa(atoi(temp->book.Price) * 2, Pay, 10);
				strcat(TITLE, Pay);
				strcat(TITLE, " VND");
				AlertPanel(TITLE, 4, 0);
			}
			else if (KeyBoard == 49)
			{
				Day RealReturnDay = GetCurrentDate();
				if (IsAfter(p->borrowcard.ReturnDay, RealReturnDay)==1)//tra sai han
				{
					char TITLE[50] = "THANH TOAN TRA TRE HAN: ";
					int LateDay = Duration(card.ReturnDay, RealReturnDay);
					char Pay[20];
					_itoa(5000 * LateDay, Pay, 10);
					strcat(TITLE, Pay);
					strcat(TITLE, " VND");
					AlertPanel(TITLE, 4, 0);
				}
				else//tra dung han
				{
					AlertPanel("TRA DUNG HAN", 2, 0);
				}

			}
		} while (KeyBoard != 49 && KeyBoard != 50);
		
		DeleteDNodeBorrowCardAtK(list, Count);
		WriteDListBook(list2);
		WriteDListBorrowCard(list);
	}
	Sleep(3000);
}
void Statistic() {
	DListBook booklist = ReadBook();
	DListBook booklist_category = { NULL,NULL };//6.2
	DListReader readerlist = ReadReader();
	DListBorrowCard cardlist = ReadBorrowCard();
	int NumberofBook=0;//6.1
	int NumberofBorrowedBook = 0;//6.5
	int NumberofReader = 0;//6.3
	int NumberofMaleReader = 0;//6.4
	int NumberofFemaleReader = 0;//6.4
	int NumberofLateReader = 0;//6.6
	bool flag;
	for (DNodeBook* p = booklist.Head; p;p=p->Next) {
		flag = 0;
		for (DNodeBook* p1 = booklist_category.Head; p1; p1 = p1->Next) {
			if (strcmp(p1->book.Category, p->book.Category) == 0)//sách đã có nên cộng thêm số lượng
			{
				p1->book.Number += p->book.Number;
				flag = 1;
				break;
			}
		}
		if (flag == 0)//chưa trùng nên bây giờ add vào danh sách
		{
			DNodeBook* temp = CreateBookNode(p->book);
			AddTailDListBook(booklist_category, temp);
		}
		NumberofBorrowedBook += p->book.Borrowed;
		NumberofBook += p->book.Number;
	}
	for (DNodeReader* p = readerlist.Head; p; p = p->Next) {
		NumberofReader++;
		p->reader.Sex == 1 ? NumberofMaleReader++ : NumberofFemaleReader++;
	}
	Day currentday = GetCurrentDate();
	for (DNodeBorrowCard* p = cardlist.Head; p; p = p->Next) {
		if (IsAfter(p->borrowcard.ReturnDay, currentday))
		{
			flag=1;
			for (DNodeBorrowCard* p1 = cardlist.Head; p1 != p; p = p->Next)
			{
				if (strcmp(p->borrowcard.ISBN, p1->borrowcard.ISBN) == 0 && IsAfter(p1->borrowcard.ReturnDay, currentday) == 1)
				{
					flag = 0;
					break;
				}
			}
			if (flag == 1)
				NumberofLateReader++;
		}
	}
	cout << "THONG KE THU VIEN" << endl;
	cout << "-So luong sach trong thu vien: " << NumberofBook << endl;
	cout << "-So luong sach trong thu vien theo the loai: " << endl;
	for (DNodeBook* p = booklist_category.Head; p; p = p->Next) {
		cout <<"    +"<< p->book.Category << ": " << p->book.Number << " quyen" << endl;
	}
	cout << "-So luong doc gia: " << NumberofReader << endl;
	cout << "-So luong doc gia la nam: " << NumberofMaleReader << endl;
	cout << "-So luong doc gia la nu: " << NumberofFemaleReader << endl;
	cout << "-So luong sach dang duoc muon: " << NumberofBorrowedBook << endl;
	cout << "-So luong doc gia dang tre han: " << NumberofLateReader << endl;
	cout << "BAM PHIM BAT KI DE QUAY LAI";
	_getch();
}
//utility
void WriteBook(Book book) {
	FILE* file;
	file = fopen("books/books.bin", "ab");
	fwrite(&book, sizeof(book), 1, file);
	fclose(file);
	return;
}
DNodeBook* CreateBookNode(Book book) {
	DNodeBook* Node = new DNodeBook;
	Node->book = book;
	Node->Next = NULL;
	Node->Prev = NULL;
	return Node;
}
void AddTailDListBook(DListBook& list, DNodeBook* Node) {
	if (list.Head == NULL)
	{
		list.Head = Node;
		list.Tail = Node;
	}
	else {
		list.Tail->Next = Node;
		Node->Prev = list.Tail;
		list.Tail = Node;
	}
}
DListBook ReadBook() {
	DListBook list = { NULL,NULL };
	FILE* file;
	DNodeBook* Node;
	Book book;
	file = fopen("books/books.bin", "rb");
	fseek(file, 0, SEEK_END);
	int endfile = ftell(file);
	fseek(file, 0, SEEK_SET);
	while (ftell(file) != endfile) {
		fread(&book, sizeof(book), 1, file);
		Node = CreateBookNode(book);
		AddTailDListBook(list, Node);
	}
	fclose(file);
	return list;
}
void ViewOneBook(Book book, int Function) {
	//Nocursortype();
	drawRectangle(36, 5, 40, 23, 3);
	gotoxy(38, 6);
	textBgColor(0, 3);
	cout << "ISBN: ";
	drawRectangle(38, 7, 36, 1, 7);
	gotoxy(38, 7);
	cout << book.ISBN;
	gotoxy(38, 8);
	textBgColor(0, 3);
	cout << "Ten sach: ";
	drawRectangle(38, 9, 36, 1, 7);
	gotoxy(38, 9);
	cout << book.Name;
	gotoxy(38, 10);
	textBgColor(0, 3);
	cout << "Tac gia: ";
	drawRectangle(38, 11, 36, 1, 7);
	gotoxy(38, 11);
	cout << book.Author;
	gotoxy(38, 12);
	textBgColor(0, 3);
	cout << "Nha xuat ban: ";
	drawRectangle(38, 13, 36, 1, 7);
	gotoxy(38, 13);
	cout << book.Publisher;
	gotoxy(38, 14);
	textBgColor(0, 3);
	cout << "Nam xuat ban: ";
	drawRectangle(38, 15, 36, 1, 7);
	gotoxy(38, 15);
	cout << book.PublishingYear;
	gotoxy(38, 16);
	textBgColor(0, 3);
	cout << "The loai: ";
	drawRectangle(38, 17, 36, 1, 7);
	gotoxy(38, 17);
	cout << book.Category;
	gotoxy(38, 18);
	textBgColor(0, 3);
	cout << "Gia sach: ";
	drawRectangle(38, 19, 36, 1, 7);
	gotoxy(38, 19);
	cout << book.Price;
	gotoxy(38, 20);
	textBgColor(0, 3);
	cout << "So luong sach: ";
	drawRectangle(38, 21, 36, 1, 7);
	gotoxy(38, 21);
	cout << book.Number;
	gotoxy(38, 22);
	textBgColor(0, 3);
	cout << "So luong sach da duoc muon: ";
	drawRectangle(38, 23, 36, 1, 7);
	gotoxy(38, 23);
	cout << book.Borrowed;
	DirectPanel(Function);
}
void WriteDListBook(DListBook list) {
	FILE* file;
	file = fopen("books/books.bin", "wb");
	for (DNodeBook* p = list.Head; p; p = p->Next)
		fwrite(&p->book, sizeof(Book), 1, file);
	fclose(file);
}
void DeleteDNodeBookAtK(DListBook& list, int K) {
	if (K == 1) {//delete head
		DNodeBook* temp = list.Head;
		list.Head = list.Head->Next;
		if (list.Head != NULL)
			list.Head->Prev = NULL;
		delete temp;
		return;
	}
	int Count = 1;
	for (DNodeBook* p = list.Head; p; p = p->Next)
	{
		if (Count == K)
		{
			if (p->Next == NULL)//delete tail
			{
				list.Tail = list.Tail->Prev;
				delete list.Tail->Next;
				list.Tail->Next = NULL;
				return;
			}
			else {
				p->Next->Prev = p->Prev;
				p->Prev->Next = p->Next;
				delete p;
				return;
			}
		}
		Count++;
	}
}
void GetCode_ISBN(char* Code, char* ISBN) {
	drawRectangle(36, 5, 40,7, 3);
	gotoxy(38, 6);
	textBgColor(0, 3);
	cout << "Ma doc gia: ";
	drawRectangle(38, 7, 36, 1, 7);
	gotoxy(38, 8);
	textBgColor(0, 3);
	cout << "ISBN sach muon muon: ";
	drawRectangle(38, 9, 36, 1, 7);
	textBgColor(0, 7);
	//input
	gotoxy(38, 7);
	cin.getline(Code, 13);
	gotoxy(38, 9);
	cin.getline(ISBN, 13);
}
DNodeBook* FindBookByISBN(DListBook list, char* ISBN) {
	for (DNodeBook* p = list.Head; p; p = p->Next) {
		if (atoi(ISBN) == atoi(p->book.ISBN))
			return p;
	}
	return NULL;
}

//Thẻ mượn sách
void WriteBorrowCard(BorrowCard card) {
	FILE* file;
	file = fopen("BorrowCards/BorrowCards.bin", "ab");
	fwrite(&card, sizeof(BorrowCard), 1, file);
	fclose(file);
	return;
}
DNodeBorrowCard* CreateBorrowCardNode(BorrowCard card) {
	DNodeBorrowCard* Node = new DNodeBorrowCard;
	Node->borrowcard = card;
	Node->Next = NULL;
	Node->Prev = NULL;
	return Node;
}
void AddTailDListBorrowCard(DListBorrowCard& list, DNodeBorrowCard* Node) {
	if (list.Head == NULL)
	{
		list.Head = Node;
		list.Tail = Node;
	}
	else {
		list.Tail->Next = Node;
		Node->Prev = list.Tail;
		list.Tail = Node;
	}
}
DListBorrowCard ReadBorrowCard() {
	DListBorrowCard list = { NULL,NULL };
	FILE* file;
	DNodeBorrowCard* Node;
	BorrowCard card;
	file = fopen("BorrowCards/BorrowCards.bin", "rb");
	fseek(file, 0, SEEK_END);
	int endfile = ftell(file);
	fseek(file, 0, SEEK_SET);
	while (ftell(file) != endfile) {
		fread(&card, sizeof(card), 1, file);
		Node = CreateBorrowCardNode(card);
		AddTailDListBorrowCard(list, Node);
	}
	fclose(file);
	return list;
}
void WriteDListBorrowCard(DListBorrowCard list) {
	FILE* file;
	file = fopen("BorrowCards/BorrowCards.bin", "wb");
	for (DNodeBorrowCard* p = list.Head; p; p = p->Next)
		fwrite(&p->borrowcard, sizeof(BorrowCard), 1, file);
	fclose(file);
}
void DeleteDNodeBorrowCardAtK(DListBorrowCard& list, int K) {
	if (K == 1) {//delete head
		DNodeBorrowCard* temp = list.Head;
		list.Head = list.Head->Next;
		if (list.Head != NULL)
			list.Head->Prev = NULL;
		delete temp;
		return;
	}
	int Count = 1;
	for (DNodeBorrowCard* p = list.Head; p; p = p->Next)
	{
		if (Count == K)
		{
			if (p->Next == NULL)//delete tail
			{
				list.Tail = list.Tail->Prev;
				delete list.Tail->Next;
				list.Tail->Next = NULL;
				return;
			}
			else {
				p->Next->Prev = p->Prev;
				p->Prev->Next = p->Next;
				delete p;
				return;
			}
		}
		Count++;
	}
}
void PrintDListBorrowCard(DListBorrowCard list)
{
	for (DNodeBorrowCard* p = list.Head; p; p = p->Next)
	{
		cout << "Code: " << p->borrowcard.Code << endl;
		cout << "ISBN: " << p->borrowcard.ISBN << endl;
		cout << "Ngay muon: "; printDay(p->borrowcard.BorrowedDay);
		cout << "\nNgay tra du kien: "; printDay(p->borrowcard.ReturnDay);
	}
}
