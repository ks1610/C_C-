#include <iostream>
#include "linkedlistlib.h"

// Khoi tao danh sach
void listInit(List & list);

// Huy danh sach
void listDestroy(List & list);

// Kiem tra danh sach rong
bool listIsEmpty(List & list);

// Lay phan tu dau danh sach
T listFront(List & list);

// Chen vao dau danh sach
void listPushFront(List & list, T e);

// Xoa phan tu dau danh sach
void listPopFront(List & list);

// YEU CAU THUC HANH
//   Khai bao cac ham thuc hien cac viec sau:
//     1. Tra ve kich thuoc cua danh sach
//     2. In cac phan tu trong danh sach len man hinh
//     3. Tra ve phan tu o vi tri k trong danh sach (vi tri bat dau tu 0)
//     4. Kiem tra xem mot gia tri x co mat trong danh sach hay khong
//     5. Chen mot phan tu moi vao truoc x (neu x ton tai trong danh sach)
//     6. Xoa phan tu x (neu x ton tai trong danh sach)
//     7. Chen mot phan tu moi vao cuoi danh sach

// VIET CODE CUA BAN O DAY...

// Kiem Tra Kich Thuoc Phan Tu
int Listgetsize(List & list);

// In Phan Tu
void Listprint(List & list);

//Kiem Tra Vi Tri Phan Tu
int Listposition(List & list, int e);

//Kiem Tra Phan Tu Co Trong Danh Sach
bool Listcheckposition(List & list, int e);

//Chen Phan Tu O Phia Truoc
void Listinsertbefore(List & list, int x, int e);

//Xoa Phan Tu X
void Listdeletx(List & list, int x);

//Chen Phan Tu O Vi Tri Cuoi
void Listinsertlast(List & list, T x);
