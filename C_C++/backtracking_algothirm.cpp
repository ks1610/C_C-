#include<iostream>

int X[100], check[100];
int n = 3;

void print(){
    for(int i = 1; i <= n; i++){
        std::cout<< X[i];
    }
    std::cout<<std::endl;
}

/*int Try(int i){
    for(int j = 0; j <= 1; j++){
        X[i] = j;
        if(i==n){
            print();
        }
        else{
            Try(i+1);
        }
    }
}*/


int Try(int i){
    for(int j = 1; j <= n; j++){
        if(check[j] == 0){    
            X[i] = j;
            check[j] = 1;
            if(i==n){
                print();
            }
            else{
                Try(i+1);
            }
            check[j]=0;
        }
    }
}

int main(){
    
    Try(1);

    return 0;
}