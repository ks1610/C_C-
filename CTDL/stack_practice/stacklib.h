#ifndef STACKLIB_H
#define STACKLIB_H

#include <iostream> // For std::cout

typedef int T; // Type of the stack elements

struct Stack {
    T *theArray;    // Pointer to the array holding the stack elements
    int topOfStack; // Index of the top element in the stack
};

void stackInit(Stack & stack, int capacity)
{
	stack.theArray = new T[capacity]; // Tao mang chua cac phan tu
	stack.topOfStack = -1;            // "= -1" nghia la ban dau ngan xep rong
}

void stackDestroy(Stack & stack)
{
	delete[] stack.theArray; // Xoa mang da duoc cap phat dong trong ham khoi tao
}

bool stackIsEmpty(Stack & stack)
{
	return (stack.topOfStack == -1);
}

int stackGetSize(Stack & stack)
{
	return (stack.topOfStack + 1);
}

void stackPush(Stack & stack, T e)
{
	stack.topOfStack++;
	stack.theArray[stack.topOfStack] = e;
}

void stackPop(Stack & stack)
{
	stack.topOfStack--;
}

T stackTop(Stack & stack)
{
	return stack.theArray[stack.topOfStack];
}

void stackPrint(Stack & stack){
    if(stack.theArray != NULL){
        for(int i = stack.topOfStack; i >= 0; i--){
            std::cout<<stack.theArray[i]<<" ";
        }
        std::cout<<std::endl;
    }
    else
     std::cout<<"Danh sach rong"<<std::endl;
}

bool stackCheck(Stack & stack, T e){
    if(stack.theArray != NULL){
        for(int i = stack.topOfStack; i >= 0; i--){
            if(stack.theArray[i] == e)
                return true;
        }
    }
    return false;
}

void stackRemove(Stack & stack){
    int i = stack.topOfStack;
    while(!stackIsEmpty(stack)){
        std::cout<<"...Xoa Phan Tu: "<<stack.theArray[i]<<std::endl;
        stackPop(stack);
        i--;
    }
}
// YEU CAU THUC HANH
//   1. Dinh nghia ham in tat ca cac phan tu trong ngan xep len man hinh
//   2. Dinh nghia ham kiem tra xem mot gia tri x co trong ngan xep hay khong

// VIET CODE CUA BAN O DAY
// ...

#endif // STACKLIB_H