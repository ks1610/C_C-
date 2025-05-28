#include <iostream>
#include "test2.cpp" //use extern
#include "global.hh" //not using exterm


//num_1 = 20(not using extern)
void increasement_num(){
    num_1++;
}

// Declaring the variable as an extern.
extern int num;
void increment(); // Or extern void increment().

int main() {
    std::cout << "Number_With extern: " << num << std::endl;
    // Calling the global function.
    increment();
    std::cout << "Number_With extern: " << num << std::endl;
    increment();
    std::cout << "Number_With extern: " << num << std::endl;
    
    //static value
    std::cout<<increase_a()<<std::endl;
    std::cout<<increase_a()<<std::endl;
    std::cout<<increase_a()<<std::endl;
    std::cout<<increase_a()<<std::endl;

    increasement_num();
    std::cout<< "Number_Without extern: "<<num_1<<std::endl;
    increasement_num();
    std::cout<< "Number_Without extern: "<<num_1<<std::endl;
    return 0;
}