#include "Function2.h"
void CreateReader() {
	clear();
	Reader reader;
	// Lấy 1 số random bằng cách lấy số giây từ năm 1970
	time_t now = time(0);
	reader.Code = now;
	// Lấy ngày lập thẻ và ngày hết hạn (cộng lên 4 năm)
	reader.CreatedDate = GetCurrentDate();
	reader.ExpirationDate = reader.CreatedDate;
	reader.ExpirationDate.Year += 4;

	drawRectangle(36, 5, 40, 23, 3);
	gotoxy(38, 6);
	textBgColor(0, 3);
	cout << "Ma doc gia: ";
	drawRectangle(38, 7, 36, 1, 7);
	gotoxy(38, 7);
	cout << reader.Code;
	gotoxy(38, 8);
	textBgColor(0, 3);
	cout << "Ho va ten: ";
	drawRectangle(38, 9, 36, 1, 7);
	
	gotoxy(38, 10);
	textBgColor(0, 3);
	cout << "CMND: ";
	drawRectangle(38, 11, 36, 1, 7);
	
	gotoxy(38, 12);
	textBgColor(0, 3);
	cout << "Ngay sinh: ";
	drawRectangle(38, 13, 36, 1, 7);
	
	gotoxy(38, 14);
	textBgColor(0, 3);
	cout << "Gioi tinh: 1->Nam ; 0:->Nu ";
	drawRectangle(38, 15, 36, 1, 7);
	
	gotoxy(38, 16);
	textBgColor(0, 3);
	cout << "Email: ";
	drawRectangle(38, 17, 36, 1, 7);
	
	gotoxy(38, 18);
	textBgColor(0, 3);
	cout << "Dia chi: ";
	drawRectangle(38, 19, 36, 1, 7);
	
	gotoxy(38, 20);
	textBgColor(0, 3);
	cout << "Ngay tao the: ";
	drawRectangle(38, 21, 36, 1, 7);
	gotoxy(38, 21);
	printDay(reader.CreatedDate);
	gotoxy(38, 22);
	textBgColor(0, 3);
	cout << "Ngay het han: ";
	drawRectangle(38, 23, 36, 1, 7);
	gotoxy(38, 23);
	printDay(reader.ExpirationDate);
	DirectPanel(24);

	textBgColor(0, 7);
	gotoxy(38, 9);
	cin.getline(reader.Fullname, 44);
	gotoxy(38, 11);
	cin.getline(reader.ID, 44);
	gotoxy(38, 13);
	reader.DOB = inputDay();
	gotoxy(38, 15);
	reader.Sex = input1num();
	gotoxy(38, 17);
	cin.getline(reader.Email, 100);
	gotoxy(38, 19);
	cin.getline(reader.Address, 100);
	//vẽ 1 bảng alert lưu thành công
	//check valid user
	WriteReader(reader);
	textBgColor(7, 0);
}
void WriteReader(Reader reader) {
	FILE* file;
	file = fopen("readers/readers.bin", "ab");
	fwrite(&reader, sizeof(reader), 1, file);
	cout << ftell(file);
	fclose(file);
	return;
}
void PrintReader(Reader reader) {
	cout << reader.Code << endl;
	cout << reader.Fullname << endl;
	cout << reader.ID << endl;
	printDay(reader.DOB);
	cout << endl;
	cout << reader.Sex << endl;
	cout << reader.Email << endl;
	cout << reader.Address << endl;
	printDay(reader.CreatedDate);
	cout << endl;
	printDay(reader.ExpirationDate);
}
DNodeReader* CreateReaderNode(Reader reader) {
	DNodeReader* Node = new DNodeReader;
	Node->reader = reader;
	Node->Next = NULL;
	Node->Prev = NULL;
	return Node;
}
void AddTailDListReader(DListReader& list, DNodeReader* Node) {
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
DListReader ReadReader() {
	DListReader list = { NULL,NULL };
	FILE* file;
	DNodeReader* Node;
	Reader reader;
	file = fopen("readers/readers.bin", "rb");
	fseek(file, 0, SEEK_END);
	int endfile = ftell(file);
	fseek(file, 0, SEEK_SET);
	while (ftell(file) != endfile) {
		fread(&reader, sizeof(reader), 1, file);
		Node = CreateReaderNode(reader);
		AddTailDListReader(list, Node);
	}
	fclose(file);
	return list;
}
void WriteDListReader(DListReader list) {
	FILE* file;
	file = fopen("readers/readers.bin", "wb");
	for (DNodeReader* p = list.Head; p; p = p->Next)
		fwrite(&p->reader, sizeof(Reader), 1, file);
	fclose(file);
}
void ViewReaders() {
	DListReader list = ReadReader();
	char KeyBoard;
	DNodeReader* p = list.Head;
	ViewOneReader(p->reader,21);
	do
	{
		KeyBoard = _getch();
		if (KeyBoard == 49 && p->Prev != NULL)
		{
			p = p->Prev;
			ViewOneReader(p->reader,21);
		}
		else if (KeyBoard == 50 && p->Next != NULL)
		{
			p = p->Next;
			ViewOneReader(p->reader,21);
		}
	} while (KeyBoard!=48);
	textBgColor(7, 0);
}
void ViewOneReader(Reader reader,int Function) {
	//Nocursortype();
	drawRectangle(36, 5, 40, 23, 3);
	gotoxy(38, 6);
	textBgColor(0, 3);
	cout << "Ma doc gia: ";
	drawRectangle(38, 7, 36, 1, 7);
	gotoxy(38, 7);
	cout << reader.Code;
	gotoxy(38, 8);
	textBgColor(0, 3);
	cout << "Ho va ten: ";
	drawRectangle(38, 9, 36, 1, 7);
	gotoxy(38, 9);
	cout << reader.Fullname;
	gotoxy(38, 10);
	textBgColor(0, 3);
	cout << "CMND: ";
	drawRectangle(38, 11, 36, 1, 7);
	gotoxy(38, 11);
	cout << reader.ID;
	gotoxy(38, 12);
	textBgColor(0, 3);
	cout << "Ngay sinh: ";
	drawRectangle(38, 13, 36, 1, 7);
	gotoxy(38, 13);
	printDay(reader.DOB);
	gotoxy(38, 14);
	textBgColor(0, 3);
	cout << "Gioi tinh: ";
	drawRectangle(38, 15, 36, 1, 7);
	gotoxy(38, 15);
	cout << reader.Sex;
	gotoxy(38, 16);
	textBgColor(0, 3);
	cout << "Email: ";
	drawRectangle(38, 17, 36, 1, 7);
	gotoxy(38, 17);
	cout << reader.Email;
	gotoxy(38, 18);
	textBgColor(0, 3);
	cout << "Dia chi: ";
	drawRectangle(38, 19, 36, 1, 7);
	gotoxy(38, 19);
	cout << reader.Address;
	gotoxy(38, 20);
	textBgColor(0, 3);
	cout << "Ngay tao the: ";
	drawRectangle(38, 21, 36, 1, 7);
	gotoxy(38, 21);
	printDay(reader.CreatedDate);
	gotoxy(38, 22);
	textBgColor(0, 3);
	cout << "Ngay het han: ";
	drawRectangle(38, 23, 36, 1, 7);
	gotoxy(38, 23);
	printDay(reader.ExpirationDate);
	DirectPanel(Function);
}
void RemoveReader() {
	DListReader list = ReadReader();
	if (list.Head == NULL)
		cout << "Khong co doc gia nao";
	char KeyBoard;
	DNodeReader* p = list.Head;
	ViewOneReader(p->reader, 24);
	int Count = 1;
	do
	{
		KeyBoard = _getch();
		if (KeyBoard == 49 && p->Prev != NULL)
		{
			Count--;
			p = p->Prev;
			ViewOneReader(p->reader, 24);
		}
		else if (KeyBoard == 50 && p->Next != NULL)
		{
			Count++;
			p = p->Next;
			ViewOneReader(p->reader, 24);
		}
		else if (KeyBoard == 51)
		{
			if (Count == 1 )
			{
				if(p->Next!=NULL){//Xóa đầu và list có hơn 1 DNode
					p = p->Next;
					DeleteDNodeReaderAtK(list, Count);
				}
				else {
					DeleteDNodeReaderAtK(list, Count);
					break;
				}
			}//Xóa những chỗ khác
			else {
				p = p->Prev;
				DeleteDNodeReaderAtK(list, Count);
				Count--;
			}
			ViewOneReader(p->reader, 24);
		}
	} while (KeyBoard != 48);
	WriteDListReader(list);
	textBgColor(7, 0);
}
void DeleteDNodeReaderAtK(DListReader &list,int K) {
	if (K == 1) {//delete head
		DNodeReader* temp = list.Head;
		list.Head = list.Head->Next;
		if (list.Head != NULL)
			list.Head->Prev = NULL;
		delete temp;
		return;
	}
	int Count = 1;
	for (DNodeReader* p = list.Head; p; p = p->Next)
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
void EditReaderInfo() {
	clear();
	DListReader list = ReadReader();
	if (list.Head == NULL)
		cout << "Khong co doc gia nao";
	char KeyBoard;
	DNodeReader* p = list.Head;
	ViewOneReader(p->reader, 23);
	int Count = 1;
	do
	{
		KeyBoard = _getch();
		if (KeyBoard == 49 && p->Prev != NULL)
		{
			Count--;
			p = p->Prev;
			ViewOneReader(p->reader, 23);
		}
		else if (KeyBoard == 50 && p->Next != NULL)
		{
			Count++;
			p = p->Next;
			ViewOneReader(p->reader, 23);
		}
		else if (KeyBoard == 51)
		{
			drawRectangle(38, 9, 36, 1, 7);
			
			gotoxy(38, 10);
			textBgColor(0, 3);
			cout << "CMND: ";
			drawRectangle(38, 11, 36, 1, 7);
			
			gotoxy(38, 12);
			textBgColor(0, 3);
			cout << "Ngay sinh: ";
			drawRectangle(38, 13, 36, 1, 7);
			
			gotoxy(38, 14);
			textBgColor(0, 3);
			cout << "Gioi tinh: ";
			drawRectangle(38, 15, 36, 1, 7);
			
			gotoxy(38, 16);
			textBgColor(0, 3);
			cout << "Email: ";
			drawRectangle(38, 17, 36, 1, 7);
			
			gotoxy(38, 18);
			textBgColor(0, 3);
			cout << "Dia chi: ";
			drawRectangle(38, 19, 36, 1, 7);
			
			gotoxy(38, 20);
			textBgColor(0, 3);
			cout << "Ngay tao the: ";
			drawRectangle(38, 21, 36, 1, 7);
			gotoxy(38, 21);
			printDay(p->reader.CreatedDate);
			gotoxy(38, 22);
			textBgColor(0, 3);
			cout << "Ngay het han: ";
			drawRectangle(38, 23, 36, 1, 7);
			gotoxy(38, 23);
			printDay(p->reader.ExpirationDate);
			DirectPanel(23);
			textBgColor(0, 7);
			gotoxy(38, 9);
			cin.getline(p->reader.Fullname, 44);
			gotoxy(38, 11);
			cin.getline(p->reader.ID, 44);
			gotoxy(38, 13);
			p->reader.DOB = inputDay();
			gotoxy(38, 15);
			p->reader.Sex = input1num();
			gotoxy(38, 17);
			cin.getline(p->reader.Email, 44);
			gotoxy(38, 19);
			cin.getline(p->reader.Address, 44);
		}
	} while (KeyBoard != 48);
	WriteDListReader(list);
	textBgColor(7, 0);
}
void FindReaderByName() {
	DListReader list = ReadReader();
	char FullName[45];
	cout << "Nhap ho va ten doc gia muon tim: ";
	cin.getline(FullName, 44);
	for (DNodeReader* p = list.Head; p; p = p->Next) {
		if (_stricmp(FullName, p->reader.Fullname) == 0)
		{
			ViewOneReader(p->reader,0);
			_getch();
			textBgColor(7, 0);
			return;
		}
	}
	cout << "Khong co doc gia nao ten" << FullName;
	_getch();
	clear();
}
void FindReaderByID() {
	DListReader list = ReadReader();
	char ID[45];
	cout << "Nhap CMND cua doc gia muon tim: ";
	cin.getline(ID, 44);
	for (DNodeReader* p = list.Head; p; p = p->Next) {
		if (_stricmp(ID, p->reader.ID) == 0)
		{
			ViewOneReader(p->reader, 0);
			_getch();
			textBgColor(7, 0);
			return;
		}
	}
	cout << "Khong co so CMND la: " << ID;
	_getch();
	clear();
}
//-------hàm tạm-------

