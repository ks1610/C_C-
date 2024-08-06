#include <iostream>

// Define the structure with a function pointer
typedef struct obj {
    int value;
    int (*area)(struct obj); // Correctly define the function pointer to take a struct obj
} obj;

// Function to calculate the area of a square
int sqrarea(struct obj a) {
    return (int)(a.value * a.value);
}

// Function to calculate the area of a circle
int cirarea(struct obj a) {
    return (int)(a.value * a.value * 3.14); // Cast the result to int
}

int main() {
    obj sqr;
    sqr.value = 5;
    sqr.area = &cirarea; // Assign the function directly

    std::cout << "Area = " << sqr.area(sqr) << std::endl;
    return 0;
}
