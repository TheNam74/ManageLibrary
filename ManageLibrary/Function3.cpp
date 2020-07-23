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
	cin.getline(ISBN, 14);
	for (DNodeBook* p = list.Head; p; p = p->Next) {
		if (atoi(ISBN)==atoi(p->book.ISBN))
		{
			ViewOneBook(p->book, 0);
			_getch();
			textBgColor(7, 0);
			return;
		}
	}
	cout << "Khong co sach nao co ISBN la: " << ISBN<< " trong thu vien";
	_getch();
	clear();
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

