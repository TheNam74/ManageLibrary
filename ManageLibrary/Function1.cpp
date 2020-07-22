#include "Function1.h"
void WriteUsername(char* username) {
	FILE* file;
	file = fopen("user/login.txt", "w");
	fprintf(file, "%s", username);
	fclose(file);
}
int login(char* username, char* password) {
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
	cout << "Username: "<<endl;
	cin.getline(user.Username,44);
	cout << "Password: " << endl;
	cin.getline(user.Password, 44);
	cout << "Ho va ten: " << endl;
	cin.getline(user.Fullname, 44);
	cout << "Ngay sinh: dd/mm/yyyy" << endl;
	user.DOB = inputDay();
	cout << "CMND: " << endl;
	cin.getline(user.ID, 44);
	cout << "Dia chi: " << endl;
	cin.getline(user.Address,100);
	cout << "Gioi tinh: 1->Nam ; 0:->Nu " << endl;
	user.Sex = input1num();
	user.Active = 1;
	cout << "Phan quyen: 1->Quan li ; 0:->Chuyen vien " << endl;
	user.Classification = input1num();
	//check tk xem tồn tại chưa rồi mới write
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
void ChangeUserInfo(){
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
			cout << p->user.Fullname<<endl;
			cout << "Thay doi: Nhan 1 ; Giu nguyen : Nhan 0" << endl;

			return;
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
