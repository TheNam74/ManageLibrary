#ifndef Function3_h
#define Function3_h
#include "All.h"
#endif

void CreateBook();
void ViewBook();
void EditBookInfo();
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

void WriteDListBook(DListBook list);
