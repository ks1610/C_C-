#include <iostream>
#include <vector>

void selectionSort(std::vector<int> & a) 
{
	for(int i = 0; i < a.size(); i++){
		int vt = i;
		for(int j = i+1; j < a.size(); j++){
			if(a[vt] > a[j]){
				vt = j;
			}
			if(vt != i){
				int tg = a[vt];
				a[vt] = a[i];
				a[i] = tg;
			}
		}
	}
}

void bubbleSort(std::vector<int> & a) 
{
	for(int i = 0; i < a.size(); i++){
		for(int j = i+1; j < a.size(); j++){
			if(a[i] > a[j]){
				int tg = a[j];
				a[j] = a[i];
				a[i] = tg;
			}
		}
	}
}

void insertionSort(std::vector<int> & a) 
{
	int j;
	for(int i = 1; i < a.size(); i++){
		int tmp = a[i];
		for(j = i; j > 0; j--){
			if(tmp < a[j-1]){
				a[j] = a[j - 1];
			}
			else
				break;
		}
		a[j] = tmp;
	}
}

// Trả về con trái của nút i
int leftChild(int i) 
{
	return 2 * i + 1;
}
// Thẩm thấu xuôi: i là lỗ trống, n là số phần tử đang xét
void percolateDown(std::vector<int> & a, int i, int n) 
{
	int tmp = a[i];
	while (leftChild(i) < n) {
		int child = leftChild(i);
	if (child < n - 1 && a[child] < a[child + 1])
		child++; // Cập nhật con lớn hơn
	if (tmp < a[child]) { // Vi phạm tính chất thứ tự đống
		a[i] = a[child];
		i = child;
	}
	else
		break;
	}
	a[i] = tmp;
}

// Các phần tử nằm từ vị trí 0 (thay vì 1) trong vector
void heapSort(std::vector<int> & a) 
{
	for (int i = a.size()/2 - 1; i >= 0; i--) // buildHeap
	percolateDown(a, i, a.size());
	for (int j = a.size() - 1; j > 0; j--) { // deleteMax
		int max = a[0];
		a[0] = a[j];
		a[j] = max;
		percolateDown(a, 0, j);
	}
}


// leftPos là vị trí bắt đầu của nửa trái.
// rightPos là vị trí bắt đầu của nửa phải.
// rightEnd là vị trí cuối cùng của nửa phải.
void merge(std::vector<int> & a, std::vector<int> & tmpArray, int leftPos, int rightPos, int rightEnd) {
    int leftEnd = rightPos - 1; // Vị trí cuối cùng của nửa trái
    int tmpPos = leftPos;      // Vị trí hiện hành trong mảng tạm
    int numElements = rightEnd - leftPos + 1; // Số phần tử của cả 2 nửa

    // Trộn hai nửa theo thứ tự tăng dần
    while (leftPos <= leftEnd && rightPos <= rightEnd) {
        if (a[leftPos] <= a[rightPos])
            tmpArray[tmpPos++] = a[leftPos++];
        else
            tmpArray[tmpPos++] = a[rightPos++];
    }

    // Sao chép phần còn lại của nửa trái
    while (leftPos <= leftEnd)
        tmpArray[tmpPos++] = a[leftPos++];

    // Sao chép phần còn lại của nửa phải
    while (rightPos <= rightEnd)
        tmpArray[tmpPos++] = a[rightPos++];

    // Sao chép từ mảng tạm về mảng chính
    for (int i = 0; i < numElements; i++)
        a[rightEnd--] = tmpArray[rightEnd];
}

// tmpArray là mảng tạm để chứa kết quả trộn.
// left là vị trí trái cùng của mảng con cần sắp xếp.
// right là vị trí phải cùng của mảng con cần sắp xếp.
void mergeSort(std::vector<int> & a, std::vector<int> & tmpArray, int left, int right) 
{
	if (left < right) {
		int center = (left + right) / 2;
		mergeSort(a, tmpArray, left, center);
		mergeSort(a, tmpArray, center + 1, right);
		merge(a, tmpArray, left, center + 1, right);
	}
}

void mergeSort(std::vector<int> & a) {
    std::vector<int> tmpArray(a.size());
    mergeSort(a, tmpArray, 0, a.size() - 1);
}

void quickSort(std::vector<int> & a) 
{
	if (a.size() < 2)
		return;
	std::vector<int> smaller; // Tập phần tử nhỏ hơn chốt
	std::vector<int> same; // Tập phần tử bằng chốt
	std::vector<int> larger; // Tập phần tử lớn hơn chốt
	int v = a[a.size() / 2]; // Chốt là phần tử chính giữa
	for (int i = 0; i < a.size(); i++) {
		if (a[i] < v)
		smaller.push_back(a[i]);
		else if (v < a[i])
			larger.push_back(a[i]);
		else
			same.push_back(a[i]);
	}

	quickSort(smaller); // Gọi đệ quy
	quickSort(larger); // Gọi đệ quy
	
	// Ghép các dãy con đã sắp xếp
	a.clear();
	for (int i = 0; i < smaller.size(); i++)
		a.push_back(smaller[i]);
	for (int i = 0; i < same.size(); i++)
		a.push_back(same[i]);
	for (int i = 0; i < larger.size(); i++)
		a.push_back(larger[i]);
}

int main(){
    std::vector<int> a = {2, 10, 8, 6, 7, 5, 4};

	//selectionSort(a);
	//bubbleSort(a);
	//insertionSort(a);
	//heapSort(a);
    //mergeSort(a); 
	quickSort(a);
	
    for (int x : a)
        std::cout << x << " ";
    return 0;
}
