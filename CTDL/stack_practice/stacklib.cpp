#include <iostream> // For std::cout
#include "stacklib.h"

// Ham khoi tao (capacity la dung luong cua ngan xep)
void stackInit(Stack & stack, int capacity = 100);

// Ham huy
void stackDestroy(Stack & stack);

// Kiem tra ngan xep rong
bool stackIsEmpty(Stack & stack);

// Tra ve kich thuoc cua ngan xep (so phan tu hien co)
int stackGetSize(Stack & stack);

// Chen phan tu e vao dinh ngan xep
void stackPush(Stack & stack, T e);

// Xoa phan tu o dinh ngan xep
void stackPop(Stack & stack);

// Tra ve phan tu o dinh ngan xep (nhung khong xoa)
T stackTop(Stack & stack);

// YEU CAU THUC HANH
//   1. Khai bao ham in tat ca cac phan tu trong ngan xep len man hinh
//   2. Khai bao ham kiem tra xem mot gia tri x co trong ngan xep hay khong

// VIET CODE CUA BAN O DAY
// ...

// In Phan Tu
void stackPrint(Stack & stack);

// Kiem Tra Phan Tu Co Trong Ngan Xep
bool stackCheck(Stack & stack, T e);

// Xoa Toan Bo Phan Tu Trong Ngan Xep
void stackRemove(Stack & stack);
