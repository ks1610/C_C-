#include<iostream>

int sum(int n){
    if(n <= 1)  
        return 1;
    else   
        return sum(n - 1) + n;
}

int C(int k, int n){
    if(n==k || k==0)
        return 1;
    else 
        return C(k-1, n-1) + C(k, n-1);
}

int S(int n){
    if(n <= 1)
        return 1;
    else return S(n-1)*n;
}

void move(int n, char a, char b, char c){
    if(n==1)
        std::cout<<"move "<<a<<" to "<< c << std::endl;
    else{
        /*move(n-1, a, c, b);
        move(1, a, b, c);
        move(n-1, c, b, a);*/
   
        move(n-1, a, c, b);
        move(1, a, b, c);
        move(n-1, b, a, c); 
    }
}

int main(){
    /*std::cout << C(2,3);
    return 0;*/
    move(4, 'A', 'B', 'C');
}