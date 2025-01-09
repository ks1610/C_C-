#include <iostream>
#include <vector>
#include <algorithm>

typedef int T;

struct BinaryHeap {
    int currentSize = 0; // Initialize current size
    std::vector<T> array;

    BinaryHeap() {
        array.push_back(0); // Placeholder for 1-based indexing
    }
};

// Heapify a subtree rooted at index i
void heapify(BinaryHeap &bh, int i) {
    int smallest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    if (left <= bh.currentSize && bh.array[left] < bh.array[smallest]) {
        smallest = left;
    }
    if (right <= bh.currentSize && bh.array[right] < bh.array[smallest]) {
        smallest = right;
    }

    if (smallest != i) {
        std::swap(bh.array[i], bh.array[smallest]);
        heapify(bh, smallest);
    }
}

// Initialize the heap from a list of elements
void init(BinaryHeap &bh, std::vector<T> &elems) {
    bh.array = {0}; // Placeholder for 1-based indexing
    bh.array.insert(bh.array.end(), elems.begin(), elems.end());
    bh.currentSize = elems.size();

    // Build the heap
    for (int i = bh.currentSize / 2; i > 0; i--) {
        heapify(bh, i);
    }
}

// Insert a new element into the heap
void insert(BinaryHeap &bh, T x) {
    if (bh.currentSize + 1 == bh.array.size()) {
        bh.array.resize(bh.array.size() * 2);
    }
    bh.currentSize++;
    int hole = bh.currentSize;

    while (hole > 1 && x < bh.array[hole / 2]) {
        bh.array[hole] = bh.array[hole / 2];
        hole /= 2;
    }
    bh.array[hole] = x;
}

// Perform heap sort and return sorted elements
std::vector<T> heapSort(BinaryHeap &bh) {
    std::vector<T> sorted;
    int originalSize = bh.currentSize;

    while (bh.currentSize > 0) {
        // Extract the root and add it to sorted vector
        sorted.push_back(bh.array[1]);
        bh.array[1] = bh.array[bh.currentSize];
        bh.currentSize--;
        heapify(bh, 1);
    }

    // Restore the heap's original size
    bh.currentSize = originalSize;

    return sorted; // Sorted elements in ascending order
}

void percolateDown(BinaryHeap & bh, int hole) 
{
    T x = bh.array[hole];
    int child;
    while (hole * 2 <= bh.currentSize) {
        child = hole * 2;
        if (child < bh.currentSize && bh.array[child + 1] < bh.array[child])
        child++;
        if (x > bh.array[child]) {
            bh.array[hole] = bh.array[child];
            hole = child;
        }
    else
    break;
    }
    bh.array[hole] = x;
}

void deleteMin(BinaryHeap & bh) 
{
    bh.array[1] = bh.array[bh.currentSize];
    bh.currentSize--;

    // Thẩm thấu xuôi (xem slide sau)
    percolateDown(bh, 1);
}
int main() 
{
    BinaryHeap bh;
    std::vector<T> array = {2, 3, 4, 5, 7};
    init(bh, array);

    insert(bh, 6);

    deleteMin(bh);
    
    // Sort and output the array in sorted order
    std::vector<T> sorted = heapSort(bh);
    for (T x : sorted) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    return 0;
}
