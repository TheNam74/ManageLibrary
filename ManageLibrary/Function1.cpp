#include "Function1.h"
void WriteUsername(char* username) {
	FILE* file;
	file = fopen("user/login.txt", "w");
	fprintf(file, "%s", username);
	fclose(file);
}
int login(char* username, char* password) {
	clear();
	FILE* file;
	if (strcmp(username, "admin") == 0 && strcmp(password, "admin") == 0) {
		WriteUsername(username);
		return 1;
	}
	User user;
	file = fopen("user/users.bin", "rb");
	fseek(file, 0, SEEK_END);
	int endfile = ftell(file);
	fseek(file, 0, SEEK_SET);
	while (ftell(file) != endfile) {
		fread(&user, sizeof(User), 1, file);
		if (strcmp(username, user.Username) == 0 && strcmp(password, user.Password) == 0)
			if (user.Classification == 1)
			{
				cout << "Quan li" << endl;
				WriteUsername(username);
				return 2;
			}
				
			else {
				cout << "Chuyen vien" << endl;
				WriteUsername(username);
				return 3;
			}
	}
	fclose(file);	
	return 0;
}
void inputLogin(char* username, char* password) {
	cout << "Nhap ten dang nhap: " << endl;
	cin.getline(username, 44);
	cout << "Nhap mat khau: " << endl;
	cin.getline(password, 44);
}
void CreateUser() {
	User user;
	drawRectangle(36, 5, 40, 23, 3);
	gotoxy(38, 6);
	textBgColor(0, 3);
	cout << "Username ";
	drawRectangle(38, 7, 36, 1, 7);
	gotoxy(38, 8);
	textBgColor(0, 3);
	cout << "Password ";
	drawRectangle(38, 9, 36, 1, 7);

	gotoxy(38, 10);
	textBgColor(0, 3);
	cout << "Ho va ten ";
	drawRectangle(38, 11, 36, 1, 7);

	gotoxy(38, 12);
	textBgColor(0, 3);
	cout << "Ngay sinh: dd/mm/yyyy ";
	drawRectangle(38, 13, 36, 1, 7);

	gotoxy(38, 14);
	textBgColor(0, 3);
	cout << "CMND ";
	drawRectangle(38, 15, 36, 1, 7);

	gotoxy(38, 16);
	textBgColor(0, 3);
	cout << "Dia chi ";
	drawRectangle(38, 17, 36, 1, 7);

	gotoxy(38, 18);
	textBgColor(0, 3);
	cout << "Gioi tinh: 1->Nam ; 0:->Nu";
	drawRectangle(38, 19, 36, 1, 7);

	gotoxy(38, 20);
	textBgColor(0, 3);
	cout << "Phan quyen:1->Quan li;0:->Chuyen vien";
	drawRectangle(38, 21, 36, 1, 7);


	DirectPanel(0);
	textBgColor(0, 7);
	gotoxy(38, 7);
	cin.getline(user.Username, 44);
	gotoxy(38, 9);
	cin.getline(user.Password, 44);
	gotoxy(38, 11);
	cin.getline(user.Fullname, 44);
	gotoxy(38, 13);
	user.DOB = inputDay();
	gotoxy(38, 15);
	cin.getline(user.ID, 44);
	gotoxy(38, 17);
	cin.getline(user.Address, 44);
	gotoxy(38, 19);
	user.Sex = input1num();
	gotoxy(38, 21);
	user.Classification = inputnNum(1);
	user.Active = 1;
	//check tk xem tồn tại chưa rồi mới write
	textBgColor(7, 0);
	WriteUser(user);
}
void WriteUser(User user) {
	FILE* file;
	file = fopen("user/users.bin", "ab");
	fwrite(&user, sizeof(user), 1, file);
	cout << ftell(file);
	fclose(file);
	return;
}
void PrintUser(User user) {
	cout << user.Username << endl;
	cout << user.Password << endl;
	cout << user.Fullname << endl;
	printDay(user.DOB);
	cout << endl;
	cout << user.ID << endl;
	cout << user.Address << endl;
	cout << user.Sex << endl;
	cout << user.Active << endl;
	cout << user.Classification << endl;
}
DNodeUser* CreateUserNode(User user) {
	DNodeUser *Node = new DNodeUser;
	Node->user = user;
	Node->Next = NULL;
	Node->Prev = NULL;
	return Node;
}
void AddTailDListUser(DListUser &list,DNodeUser *Node) {
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
DListUser ReadUser() {
	DListUser list = {NULL,NULL};
	FILE* file;
	DNodeUser* Node;
	User user;
	file = fopen("user/users.bin", "rb");
	fseek(file, 0, SEEK_END);
	int endfile = ftell(file);
	fseek(file, 0, SEEK_SET);
	while (ftell(file) != endfile) {
		fread(&user, sizeof(User), 1, file);
		Node = CreateUserNode(user);
		AddTailDListUser(list, Node);
	}
	fclose(file);
	return list;
}
void WriteDListUser(DListUser list) {
	FILE* file;
	file = fopen("user/users.bin", "wb");
	for (DNodeUser* p = list.Head; p; p = p->Next)
		fwrite(&p->user, sizeof(User), 1, file);
	fclose(file);
}
void GetUsername(char* username) {
	FILE* file;
	file = fopen("user/login.txt", "r");
	fscanf(file, "%s", username);
	fclose(file);
}
void ChangeUserPassword() {
	FILE* file;
	char username[45];
	char currentPassword[45];
	char newPassword[45];
	char ConfirmPassword[45];
	cout << "Nhap mat khau hien tai: ";
	cin.getline(currentPassword, 44);
	cout << "Nhap mat khau moi: ";
	cin.getline(newPassword, 44);
	cout << "Nhap lai mat khau moi: ";
	cin.getline(ConfirmPassword, 44);
	if (strcmp(newPassword, ConfirmPassword) != 0)
	{
		cout << "Mat khau moi khong trung khop";
		return;
	}
	DListUser list = ReadUser();
	//Lấy username của tài khoản đang sử dụng
	GetUsername(username);
	cout << "\nDoi mat khau cua tai khoan: " << username<<endl;
	DNodeUser* p;
	for ( p = list.Head; p; p = p->Next)
		if (strcmp(username, p->user.Username) == 0)
		{
			if (strcmp(p->user.Password, currentPassword) != 0)
			{
				cout << "Nhap sai mat khau cu";
				return;
			}
			else
			{
				strcpy(p->user.Password, newPassword);
				WriteDListUser(list);
				cout << "Da doi mat khau";
				return;
			}
		}
}
void EditUserInfo(){
	char Fullname[45];
	Day DOB;
	char ID[45];
	char Address[101];
	int Sex;
	DListUser list = ReadUser();
	char username[45];
	GetUsername(username);
	for (DNodeUser* p = list.Head; p; p = p->Next)
	{
		if (strcmp(username, p->user.Username) == 0)
		{
			ViewOneUser(p->user);
			char KeyBoard;
			do
			{
				KeyBoard = _getch();
				if (KeyBoard == 51)
				{
					drawRectangle(36, 5, 40, 23, 3);
					gotoxy(38, 6);
					textBgColor(0, 3);
					cout << "Username ";
					drawRectangle(38, 7, 36, 1, 7);
					gotoxy(38, 7);
					cout << p->user.Username;
					gotoxy(38, 8);
					textBgColor(0, 3);
					cout << "Password ";
					drawRectangle(38, 9, 36, 1, 7);
					gotoxy(38, 9);
					cout<<p->user.Password;
					gotoxy(38, 10);
					textBgColor(0, 3);
					cout << "Ho va ten ";
					drawRectangle(38, 11, 36, 1, 7);
					gotoxy(38, 12);
					textBgColor(0, 3);
					cout << "Ngay sinh: dd/mm/yyyy ";
					drawRectangle(38, 13, 36, 1, 7);
					gotoxy(38, 14);
					textBgColor(0, 3);
					cout << "CMND ";
					drawRectangle(38, 15, 36, 1, 7);
					gotoxy(38, 16);
					textBgColor(0, 3);
					cout << "Dia chi ";
					drawRectangle(38, 17, 36, 1, 7);
					gotoxy(38, 18);
					textBgColor(0, 3);
					cout << "Gioi tinh: 1->Nam ; 0:->Nu";
					drawRectangle(38, 19, 36, 1, 7);
					gotoxy(38, 20);
					textBgColor(0, 3);
					cout << "Phan quyen:1->Quan li;0:->Chuyen vien";
					drawRectangle(38, 21, 36, 1, 7);
					gotoxy(38, 21);
					cout << p->user.Classification;
					//bat dau edit
					DirectPanel(14);
					textBgColor(0, 7);
					gotoxy(38, 11);
					cin.getline(p->user.Fullname, 44);
					gotoxy(38, 13);
					p->user.DOB = inputDay();
					gotoxy(38, 15);
					cin.getline(p->user.ID, 44);
					gotoxy(38, 17);
					cin.getline(p->user.Address, 44);
					gotoxy(38, 19);
					p->user.Sex = input1num();
					//check valid
					WriteDListUser(list);
					AlertPanel("CHINH SUA THANH CONG", 2, 1);
					Sleep(2500);
					return;
				}
			} while (KeyBoard!=48);
		}
	}
}
//------------------Các hàm tạm thời---------------------
void ReadUserTemp() {
	FILE* file;
	User user;
	int Count = 1;
	file = fopen("user/users.bin", "rb");
	fseek(file, 0, SEEK_END);
	int endfile = ftell(file);
	fseek(file, 0, SEEK_SET);
	while (ftell(file) != endfile) {
		cout << "------" << Count++ << "-----" << endl;
		fread(&user, sizeof(User), 1, file);
		cout << "------" << ftell(file) << "-----" << endl;
		PrintUser(user);
	}
	fclose(file);
}
void PrintDListUser(DListUser list) {
	for (DNodeUser* p = list.Head; p; p = p->Next)
		PrintUser(p->user);
}
void ViewOneUser(User user) {
	drawRectangle(36, 5, 40, 23, 3);

	gotoxy(38, 6);
	textBgColor(0, 3);
	cout << "Username ";
	drawRectangle(38, 7, 36, 1, 7);
	gotoxy(38, 7);
	cout << user.Username;

	gotoxy(38, 8);
	textBgColor(0, 3);
	cout << "Password ";
	drawRectangle(38, 9, 36, 1, 7);
	gotoxy(38, 9);
	cout << user.Password;

	gotoxy(38, 10);
	textBgColor(0, 3);
	cout << "Ho va ten ";
	drawRectangle(38, 11, 36, 1, 7);
	gotoxy(38, 11);
	cout << user.Fullname;

	gotoxy(38, 12);
	textBgColor(0, 3);
	cout << "Ngay sinh: dd/mm/yyyy ";
	drawRectangle(38, 13, 36, 1, 7);
	gotoxy(38, 13);
	printDay(user.DOB);

	gotoxy(38, 14);
	textBgColor(0, 3);
	cout << "CMND ";
	drawRectangle(38, 15, 36, 1, 7);
	gotoxy(38, 15);
	cout << user.ID;

	gotoxy(38, 16);
	textBgColor(0, 3);
	cout << "Dia chi ";
	drawRectangle(38, 17, 36, 1, 7);
	gotoxy(38, 17);
	cout << user.Address;

	gotoxy(38, 18);
	textBgColor(0, 3);
	cout << "Gioi tinh: 1->Nam ; 0:->Nu";
	drawRectangle(38, 19, 36, 1, 7);
	gotoxy(38, 19);
	cout << user.Sex;

	gotoxy(38, 20);
	textBgColor(0, 3);
	cout << "Phan quyen:1->Quan li;0:->Chuyen vien";
	drawRectangle(38, 21, 36, 1, 7);
	gotoxy(38, 21);
	cout << user.Classification;
	//bat dau edit
	DirectPanel(14);
}
