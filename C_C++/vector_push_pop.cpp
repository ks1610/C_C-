#include<bits/stdc++.h>

int main(){
    int n;
    std::vector<int> x;
    std::cin>>n;
    while(n){
        int tt;
        std::cout<<"tt: ";
        std::cin>>tt;
        if(tt == 1){
            std::cout<<"num: ";
            int tm; std::cin>>tm;
            x.push_back(tm);
        }
        else{
            if(x.empty())
                x.pop_back();
        } 
        n--;
    }
    for(int a : x)
        std::cout<< a <<" ";
    return 0;
}