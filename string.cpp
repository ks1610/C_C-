#include <bits/stdc++.h>

int main(){
    /*std::string s;
    std::cin >> s;
    if(s.size() % 2 != 0)
        std::cout<<s[(s.size()-1)/2]<<std::endl;
    else    
        std::cout<<"Deo thay"<<std::endl;
    
    int n = stoi(s);
    long long l = stoll(s);
    double d = stod(s);
    std::cout<< n <<std::endl;

    int m = 543432432;
    std::string sm = std::to_string(m);
    std::cout<< sm <<std::endl;*/


    std::string s = "lap trinh cc";
    std::stringstream ss(s);
    std::string tmp;
    while(ss >> tmp){
        std::cout<< tmp <<std::endl;
    }
}