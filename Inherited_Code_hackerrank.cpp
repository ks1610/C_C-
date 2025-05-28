#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>


class BadlengthExeption
{
private:
    int num;
public:
    BadlengthExeption(int n) : num(n) {}

    int what(){
        return num;
    }
};

bool checkUsername(std::string username){
    bool isValid = true;
    int n = username.length();
    if(n < 5){
        throw BadlengthExeption(n);
    }
    for(int i = 0; i < n-1; i++){
        if(username[i] == 'w' && username[i+1] == 'w'){
            isValid = false;
        }
    }
    return isValid;
}

int main() {
    int T;
    std::cin >> T;
    while(T--){
        std::string username;
        std::cin >> username;
        try{
            bool isValid = checkUsername(username);
            if(isValid) {
                std::cout << "Valid" << std::endl;
            }
            else{
                std::cout << "Invalid" << std::endl;
            }
        }
        catch (BadlengthExeption e){
            std::cout << "Too short: " << e.what() << std::endl;
        }
    }
}
