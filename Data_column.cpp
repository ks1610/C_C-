#include<iostream>
#include<string>

int main(){
    int data[3], count = 0;
    std::string input[3];
    //while(true){
    for(int i = 0; i < 3; i++){
        std::cout<<"text: ";
        std::getline(std::cin >> std::ws, input[i]);
        std::cout<<"data: ";
        std::cin >> data[i];

    }

    for(int i = 0; i < 3; i++){
        std::cout<<input[i]<<std::endl;
    }
}