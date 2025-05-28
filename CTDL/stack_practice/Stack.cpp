// Thuc hanh ngan xep

#include <bits/stdc++.h>
#include "stacklib.h"

int main()
{	
	Stack s;
	stackInit(s, 100);
	
	// YEU CAU THUC HANH
	//   1. Viet code kiem tra ngan xep co dang rong hay khong
	//   2. Viet code chen vao ngan xep mot so phan tu
	//   3. Viet code in tat ca cac phan tu trong ngan xep len man hinh
	//   4. Viet code nhap vao x roi kiem tra x co trong ngan xep hay khong
	//   5. Viet code rut tung phan tu ra khoi ngan xep cho den khi ngan xep rong
	//   6. Viet code kiem tra xem ngan xep da rong hay chua
	
	// VIET CODE CUA BAN O DAY
	// ...

	//   1. Viet code kiem tra ngan xep co dang rong hay khong
    std::cout<<std::endl;
    std::cout<<"Kiem Tra Ngan Xep: ";
	std::cout<<(stackGetSize(s)? "Ngan Xep Khong Rong" : "Ngan Xep Rong")<<std::endl;
	std::cout<<std::endl;

	//   2. Viet code chen vao ngan xep mot so phan tu
	std::cout<<"Chen Phan Tu"<<std::endl;
    stackPush(s, 1);
    stackPush(s, 2);
    stackPush(s, 3);
    stackPush(s, 4);
    stackPush(s, 5);
    std::cout<<std::endl;

	//   3. Viet code in tat ca cac phan tu trong ngan xep len man hinh
    std::cout<<"In Phan Tu Da Chen: ";
    stackPrint(s);
    std::cout<<std::endl;

	//   4. Viet code nhap vao x roi kiem tra x co trong ngan xep hay khong
    std::cout<<"Kiem Tra Phan Tu x"<<std::endl;
    int x;
    std::cout<<"Nhap x: "; std::cin>>x;
    std::cout<<(stackCheck(s, x) ? "Co Phan Tu " + std::to_string(x) + " Trong Ngan Xep" : "Khong Co Phan Tu " + std::to_string(x) +" Trong Ngan Xep")<<std::endl;
    std::cout<<std::endl;

	//   5. Viet code rut tung phan tu ra khoi ngan xep cho den khi ngan xep rong
    std::cout<<"Xoa Cac Phan Tu Trong Ngan Xep"<<std::endl;
    stackRemove(s);
    std::cout<<std::endl;
    
	//   6. Viet code kiem tra xem ngan xep da rong hay chua
    std::cout<<"Kiem Tra Ngan Xep Sau Khi Xoa: ";
	std::cout<<(stackGetSize(s)? "Danh Sach Khong Rong" : "Danh Sach Rong")<<std::endl;
    std::cout<<std::endl;

	stackDestroy(s);
	
	return 0;
}

