// func.cpp
// Defining the variable
int num = 20;
void increment() {
    // Incrementing the number.
    num++;
}

int increase_a(){
    static int a = 0;
    a++;
    return a;
}
