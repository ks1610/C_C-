
// Thuc hanh danh sach lien ket don

#include <iostream>
#include "linkedlistlib.h"

using namespace std;
/*
// Kieu phan tu
typedef int T;

// Kieu cua cac nut
struct Node
{
    T elem;      // Phan tu
    Node * next; // Con tro toi nut tiep theo
    
    Node(int value){
		elem = value;
		next = NULL;
	}
};

// Kieu danh sach lien ket don
struct List
{
    Node * head; // Con tro toi nut dau danh sach
};*/

int main()
{
	// Khai bao bien danh sach
	List list;	

	// Khoi tao danh sach
	listInit(list);	

	// Chen mot so phan tu vao dau danh sach
	listPushFront(list, 4); // 4
	listPushFront(list, 8); // 8 -> 4
	listPushFront(list, 3); // 3 -> 8 -> 4
	listPushFront(list, 9); // 9 -> 3 -> 8 -> 4
	listPushFront(list, 5); // 5 -> 9 -> 3 -> 8 -> 4

    // YEU CAU THUC HANH
	//   Viet code goi cac ham da viet de chay thu
	
	// VIET CODE CUA BAN O DAY...
	
	//Bai1
	std::cout<<std::endl;
	std::cout<<"Kich Thuoc: "<<Listgetsize(list)<<std::endl;
	
	//Bai2
	std::cout<<std::endl;
	std::cout<<"Danh Sach: ";
	Listprint(list);
	std::cout<<std::endl;
	
	//Bai3
	std::cout<<std::endl;
	std::cout<<"Vi Tri Cua 9: "<<Listposition(list, 9)<<std::endl;
	
	
	//Bai5
	std::cout<<std::endl;
	std::cout<<"Chen 2 Vao Truoc 5: ";
	Listinsertbefore(list, 5, 2);
	Listprint(list);
	std::cout<<std::endl;
	
	//Bai6
	std::cout<<std::endl;
	std::cout<<"Xoa Phan Tu 2: ";
	Listdeletx(list, 2);
	Listprint(list);
	std::cout<<std::endl;
	
	//Bai7
	std::cout<<std::endl;
	std::cout<<"Chen 10 Vao Cuoi Danh Sach: ";
	Listinsertlast(list, 10);
	Listprint(list);
	std::cout<<std::endl;
	
	//Bai4
	std::cout<<std::endl;
	std::cout<<"Kiem Tra Phan Tu 2 Co Trong Danh Sach: "<< (Listcheckposition(list, 2) ? "Co" : "Khong Co");
	return 0;
	
	
	// Huy danh sach
	listDestroy(list);
}
