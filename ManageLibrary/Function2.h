#ifndef Function2_h
#define Function2_h
#include "All.h"
//Nhập và ghi reader vào file readers.bin
void CreateReader();

//Ghi reader vào file readers.bin
void WriteReader(Reader reader);

//In một reader ra màn hình
void PrintReader(Reader reader);

//Tạo một Node reader
DNodeReader* CreateReaderNode(Reader reader);

//Thêm đuôi vào dlist reader
void AddTailDListReader(DListReader& list, DNodeReader* Node);

//Đọc tất cả reader vào 1 dlist
DListReader ReadReader();

//Ghi một dlist reader vào readers.bin
void WriteDListReader(DListReader list);

//Chức năng xem danh sách độc giả
void ViewReaders();

//Vẽ 1 reader ra màn hình
void ViewOneReader(Reader reader, int Function);

void RemoveReader();

//Xóa DNodeReader tại vị trí K
void DeleteDNodeReaderAtK(DListReader& list, int K);
//Chỉnh sửa thông tin độc giả
void EditReaderInfo();
//Tìm kiếm độc giả bằng tên
void FindReaderByName();
//Tìm kiếm độc giả bằng CMND
void FindReaderByID();

//--------------hàm tạm------------
//In tất cả reader trong 1 dlist ra console

#endif
