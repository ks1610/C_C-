// Thuc hanh Vector

#include <iostream>

using namespace std;

typedef int T;

struct Vector {
    int size;
    int capacity;
    T * array;
};

// Khoi tao vector
void vecInit(Vector & vec, int initCapacity = 16);

// Huy vector
void vecDestroy(Vector & vec);

// Sao chep vector
void vecCopy(Vector & vec, Vector & vec2);

// Lay kich thuoc vector
int  vecGetSize(Vector & vec);

// Kiem tra vector rong
bool vecIsEmpty(Vector & vec);

// Lay phan tu
T vecGetElem(Vector & vec, int index);

// Cap nhat phan tu
void vecSetElem(Vector & vec, int index, T newValue);

// Tang dung luong vector
void vecExpand(Vector & vec, int newCapacity);

// Chen vao cuoi vector
void vecPushBack(Vector & vec, T newElement);

// Chen vao giua vector
void vecInsert(Vector & vec, int pos, T newElement);

// Xoa phan tu cuoi vector
void vecPopBack(Vector & vec);

// Xoa tat ca cac phan tu
void vecClear(Vector & vec);

// Xoa phan tu o giua vector
void vecErase(Vector & vec, int pos);

// YEU CAU THUC HANH
//   Khai bao cac ham thuc hien cac viec sau:
//     1. Lay dung luong cua vector
//     2. Cat bo phan dung luong du thua cua vector
//     3. In tat ca cac phan tu cua vector len man hinh
//     4. Tim kiem tuan tu tren vector
//     5. Tim kiem nhi phan tren vector (gia su vector da sap xep tang dan)
//     6. Xoa cac phan tu nam o cac vi tri tu pos1 den pos2 tren vector

// VIET CODE CUA BAN O DAY...

int vecStorage(Vector & vec);

int vecRemoveCapacity(Vector & vec);

void VecSort(Vector & vec);

int vecBinSearch(Vector & vec, int x);

void vecRemovePos(Vector & vec, int start, int end);

int main()
{
	// Khai bao bien vector
	Vector vec;	

	// Khoi tao vector
	vecInit(vec);

	// Chen mot so phan tu vao cuoi vector
	vecPushBack(vec, 4); // 4
	vecPushBack(vec, 8); // 4 8
	vecPushBack(vec, 3); // 4 8 3
	vecPushBack(vec, 9); // 4 8 3 9
	vecPushBack(vec, 5); // 4 8 3 9 5

    Vector vec1;
    
    vecInit(vec1);
    
    for(int i = 0; i < vec.size; i++)
        vec1.array[i] = vec.array[i];
    

	// YEU CAU THUC HANH
	//   Viet code goi cac ham da viet de lam cac viec sau:
	
    //     1. In dung luong cua vector len man hinh
    std::cout<<"Bai1: "<<std::endl;
    std::cout << "dung luong cua vector: "<<vecStorage(vec) <<std::endl;
    int memory = vecStorage(vec);
    
    //     2. Cat bo phan dung luong du thua cua vector
    std::cout<<"Bai2: "<<std::endl;
    vecRemoveCapacity(vec);
    std::cout <<"dung luong cua vector sau khi cat bo phan du thua: "<<vecStorage(vec) <<std::endl;

    //     3. In kich thuoc va dung luong cua vector xem co bang nhau hay khong
    std::cout<<"Bai3: "<<std::endl;
    std::cout << "kich thuoc vector: "<<vec.size << std::endl;
    std::cout << "dung luong vector: "<<memory << std::endl;
    std::cout << (vec.size == memory ? "Bang" : "Khong Bang")<<std::endl;

    //     4. In tat ca cac phan tu cua vector len man hinh
    std::cout<<"Bai4: " << std::endl;
    for(int i = 0 ; i < vec.size; i++)
        std::cout<<vecGetElem(vec, i) << " ";
    std::cout<<std::endl;

    //     5. Tim kiem tuan tu tren vector
    std::cout<<"Bai5: " << std::endl;
    int yourelement, position;
    std::cout<<"Type the element here: ";
    std::cin>> yourelement;
    for(int i = 0 ; i < vec.size; i++)
    {
        if(yourelement == vecGetElem(vec, i)){
            position = i;
            break;
        }
        else 
            position = -1;
    }
    std::cout <<"vi tri: "<< position <<std::endl;

    //     6. Tim kiem nhi phan tren vector (hay tao mot vector khac
	//        chua cac phan tu sap xep tang dan)
    std::cout<<"Bai6: "<<std::endl;
    
    int yourelement1;
    
    std::cout<<"Type the element here: ";
    std::cin>> yourelement1;

    VecSort(vec);
    
    for(int i = 0 ; i < vec.size; i++)
        std::cout<<vecGetElem(vec, i) <<" ";
    
    std::cout<<std::endl;
    std::cout <<"vi tri: "<< vecBinSearch(vec, yourelement1) <<std::endl;
	
    
    //     7. Xoa cac phan tu nam o cac vi tri tu pos1 den pos2 tren vector
    
    std::cout<<"Bai7: "<<std::endl;
    
    int pos1, pos2;
	std::cout<<"Nhap vi tri 1: ";
    std::cin>>pos1;
    std::cout<<"Nhap vi tri 2: ";
    std::cin>>pos2;
    
    std::cout<<"Before: ";
    
    for(int i = 0; i < vec.size; i++){
        std::cout<<vec.array[i]<<" ";
    }
    std::cout<<std::endl;
    // 4 8 3 9 5
    
    vecRemovePos(vec, pos1, pos2);
    
    std::cout<<"After: ";
    for(int i = 0; i < vec.size; i++){
        std::cout<<vec.array[i]<<" ";
    }
    std::cout<<std::endl;
    

	// VIET CODE CUA BAN O DAY...
	


	// Huy vector
	vecDestroy(vec);
	vecDestroy(vec1);
	
	return 0;
}

void vecInit(Vector & vec, int initCapacity) {
    vec.size = 0;
    vec.capacity = initCapacity;
    vec.array = new T[vec.capacity];
}

void vecDestroy(Vector & vec) {
    delete[] vec.array;
}

void vecCopy(Vector & vec, Vector & vec2) {
    if (&vec != &vec2) {
        vec.size = vec2.size;
        vec.capacity = vec2.capacity;
        delete[] vec.array;
        vec.array = new T[vec.capacity];
    
        for (int i = 0; i < vec.size; i++)
            vec.array[i] = vec2.array[i];
    }
}

int vecGetSize(Vector & vec) {
    return vec.size;
}

bool vecIsEmpty(Vector & vec) {
    return (vec.size == 0);
}

T vecGetElem(Vector & vec, int index) {
    return vec.array[index];
}

void vecSetElem(Vector & vec, int index, T newValue) {
    vec.array[index] = newValue;
}

void vecExpand(Vector & vec, int newCapacity) { 
    if (newCapacity <= vec.size)
        return;
    
    T * old = vec.array;
    vec.array = new T[newCapacity];
    for (int i = 0; i < vec.size; i++)
        vec.array[i] = old[i];
    
    delete[] old;
    
    vec.capacity = newCapacity;
}

void vecPushBack(Vector & vec, T newElement) {
    if (vec.size == vec.capacity)
        vecExpand(vec, 2 * vec.capacity);
    
    vec.array[vec.size] = newElement;

    vec.size++;
}

void vecInsert(Vector & vec, int pos, T newElement) {
    if (vec.size == vec.capacity)
        vecExpand(vec, 2 * vec.capacity);

    for (int i = vec.size; i > pos; i--)
        vec.array[i] = vec.array[i - 1];

    vec.array[pos] = newElement;

    vec.size++;
}

void vecPopBack(Vector & vec) {
    vec.size--;
}

void vecClear(Vector & vec) {
    vec.size = 0;
}

void vecErase(Vector & vec, int pos) {
    for (int i = pos; i < vec.size - 1; i++)
        vec.array[i] = vec.array[i + 1];

    vec.size--;
}

int vecStorage(Vector & vec){
    return vec.capacity;
}

int vecRemoveCapacity(Vector & vec){
    Vector vec1;
    vec1.capacity = vec.size;

    if(vec.size == vec.capacity){
        return vec.capacity;
    }
    else{
        vec.capacity = vec1.capacity;
    }

    return vec.capacity;
}

void VecSort(Vector & vec){
    for(int i = 1; i< vec.size; i++){
        int key = vec.array[i];
        int j = i - 1;
        while(j >= 0 && vec.array[j] > key){
            vec.array[j + 1] = vec.array[j];
            j--;
        }
        vec.array[j+1] = key;
    }
}

int vecBinSearch(Vector & vec, int x){
    int left = 0, 
    right = vec.size - 1;
    
    while(left <= right){
        int mid = left + (right - left)/2;
        if(x == vec.array[mid])
            return mid + 1;
        else if(x > vec.array[mid])
            left = mid + 1 ;
        else 
            right = mid - 1;
    }
    return -1;
}

void vecRemovePos(Vector & vec, int start, int end){
    
    if(start > vec.size || end > vec.size)
        std::cout<<"Invaild"<<std::endl;
    
    int NumtoRemove = end - start + 1;
    for(int i = end + 1; i < vec.size; i++){
        vec.array[i - NumtoRemove] = vec.array[i];
    }
    
    vec.size -= NumtoRemove;
}
// YEU CAU THUC HANH
//   Dinh nghia cac ham thuc hien cac viec sau:
//     1. Lay dung luong cua vector
//     2. Cat bo phan dung luong du thua cua vector
//     3. In tat ca cac phan tu cua vector len man hinh
//     4. Tim kiem tuan tu tren vector
//     5. Tim kiem nhi phan tren vector (gia su vector da sap xep tang dan)
//     6. Xoa cac phan tu nam o cac vi tri tu pos1 den pos2 tren vector

// VIET CODE CUA BAN O DAY...
