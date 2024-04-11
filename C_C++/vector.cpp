#include <bits/stdc++.h>
#include <vector>
#include <algorithm>

int main(){
    std::vector<int> v(3, 100);
    v.push_back(3);
    v.push_back(2);
    v.push_back(5);
    
    //v = {100, 100, 100, 3, 2, 5}
    
    for(int x : v){
        std::cout << x <<" ";
    }
    std::cout<<std::endl;
    

    std::vector<int>::iterator it = v.begin();
    //auto it = v.begin();

    std::cout<< *it <<std::endl; // v[0]

    it += 3; // v[3]
    std::cout<< *it <<std::endl;    
    
    v.insert(v.begin()+2, 6);   

    v.erase(v.begin()+4);

    for(it = v.begin(); it != v.end(); it++)
        std::cout<< *it <<" ";    
    std::cout<<std::endl;

    /*std::vector<int> x;
    int n = 5;
    for(int i = 0; i < n; i++){
        int tmp;
        std::cin>>tmp;
        x.push_back(tmp);
    }
    for(int a : x)
        std::cout<< a <<" ";
    std::cout<<std::endl;*/

    std::set<int> se;
    se.insert(1);
    se.insert(3);
    se.insert(2);
    se.insert(5);
    se.insert(6);
    se.insert(7);

    for(int a: se)
        std::cout<< a <<' ';
    std::cout<<std::endl;
    //{1, 3, 2, 5, 6, 7}

    for(auto it = se.rbegin(); it != se.rend(); it++)
        std::cout<< *it <<' ';
    std::cout<<std::endl;
    //{7, 6, 5, 2, 3, 1}

    if(se.count(8) != 0)
        std::cout<<"found";
    else  
        std::cout<<"not found";
    std::cout<<std::endl;

    /*std::set<int> se2;
    int a[5];
    for(int i = 0; i < 5; i++){
        std::cin>>a[i];
    }
    for(int i = 0; i < 5; i++){
        se2.insert(a[i]);
    }

    for(int x: se2){
        std::cout<< x <<' ';
    }
    std::cout<<std::endl;

    std::cout<<se.count(2);*/

    std::multiset<int> se3;
    int a[5];
    for(int i = 0; i < 5; i++){
        std::cin>>a[i];
    } 
    for(int i = 0; i < 5; i++){
        se3.insert(a[i]);
    }

    for(int x: se3){
        std::cout<< x <<' ';
    }   
    std::cout<<std::endl;

    std::cout<<se3.count(1);
    std::cout<<std::endl;

}