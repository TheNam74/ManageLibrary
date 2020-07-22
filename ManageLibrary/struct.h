#ifndef struct_h
#define struct_h
#include "All.h"
struct Day {
	int Date;
	int Month;
	int Year;
};
//Chức năng 1
struct User
{
	char Username[45];
	char Password[45];
	char Fullname[45];
	Day DOB;
	char ID[45];
	char Address[101];
	int Sex;
	bool Active;
	int Classification;
};
struct DNodeUser {
	User user;
	DNodeUser* Next;
	DNodeUser* Prev;
};
struct DListUser {
	DNodeUser* Head;
	DNodeUser* Tail; 
};

//Chức năng 2
struct Reader {
	unsigned Code;
	char Fullname[45];
	char ID[45];
	Day DOB;
	int Sex;
	char Email[101];
	char Address[101];
	Day CreatedDate;
	Day ExpirationDate;
};
struct DNodeReader {
	Reader reader;
	DNodeReader* Next;
	DNodeReader* Prev;
};
struct DListReader {
	DNodeReader* Head;
	DNodeReader* Tail;
};
//Chức năng 3
struct Book
{
	char ISBN[14];
	char Name[101];
	char Author[45];
	char Publisher[101];
	int PublishingYear;
	char Category[101];
	char Price[101];
	int Number;//Number of books
	int Borrowed;
}; 
struct DNodeBook {
	Book book;
	DNodeBook* Next;
	DNodeBook* Prev;
};
struct DListBook {
	DNodeBook* Head;
	DNodeBook* Tail;
};
//Thẻ mượn 
struct BorrowingCard {
	unsigned Code;
	char ISBN[14];
	Day BorrowedDay;
	Day ReturnDay;
};
struct DNodeBorrowingCard {
	BorrowingCard borrowingcard;
	DNodeBorrowingCard* Next;
	DNodeBorrowingCard* Prev;
};
struct DListBorrowingCard {
	DNodeBorrowingCard* Head;
	DNodeBorrowingCard* Tail;
};


#endif