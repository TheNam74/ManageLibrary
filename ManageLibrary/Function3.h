#ifndef Function3_h
#define Function3_h
#include "All.h"
#endif

void CreateBook();
void ViewBook();
void EditBookInfo();
void RemoveBook();
void FindBookByName();
void FindBookByISBN();
void CreateBorrowCard();
void ReturnBook();
// Utility Functions
// viết sách vào books.bin
void WriteBook(Book book);
//Tạo DNodeBook
DNodeBook* CreateBookNode(Book book);
//Thêm đuôi DList book
void AddTailDListBook(DListBook& list, DNodeBook* Node);
//Đọc tất cả book từ books.bin vào 1 DList
DListBook ReadBook();
//In thông tin sách ra màn hình
void ViewOneBook(Book book, int Function);
//Viết DList sách ra file
void WriteDListBook(DListBook list);
//Xóa DNode sách trong DList sách
void DeleteDNodeBookAtK(DListBook& list, int K);
void GetCode_ISBN(char* Code, char* ISBN);
//Tìm sách thông qua ISBN trả về DNodeBook, không tồn tại thì trả về NULL
DNodeBook* FindBookByISBN(DListBook list, char* ISBN);

//thẻ mượn sách
void WriteBorrowCard(BorrowCard card);

DNodeBorrowCard* CreateBorrowCardNode(BorrowCard card);

void AddTailDListBorrowCard(DListBorrowCard& list, DNodeBorrowCard* Node);

DListBorrowCard ReadBorrowCard();

void WriteDListBorrowCard(DListBorrowCard list);

void DeleteDNodeBorrowCardAtK(DListBorrowCard& list, int K);

void PrintDListBorrowCard(DListBorrowCard list);
