#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>


class person{
    private:
        std::string name;
        int age;
    public:
        void set_name(){
            std::string a;
            std::cin >> a;
            name = a;
        }
        void set_age(){
            int b;
            std::cin >> b;
            age = b;
        }
        void print_name(){
            std::cout<< name <<" ";
        }
        void print_age(){
            std::cout<< age <<" ";
        }
};

class professor : public person{
    private:
        int publication;
        static int id;
    public:
        void get_data(){
            set_name();
            set_age();
            std::cin >> publication;
        }
        void put_data(){
            ++id;
            print_name();
            print_age();
            std::cout << publication << ' ' << id <<std::endl;
        }  
};

int professor::id = 0;

class student : public person{
    private:
        int mark[6];
        int sum = 0;
        static int id;
    public:
        void get_data(){
            set_name();
            set_age();
            for(int i = 0; i < 6; i++){
                std::cin >> mark[i];
                sum += mark[i];
            }
        }
        void put_data(){
            ++id;
            print_name();
            print_age();
            std::cout << sum << ' ' << id <<std::endl;
            sum = 0;
        }
};

int student::id = 0;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    professor a;
    student b;
    int n;
    std::cin >> n;
    while(n--){
        int k;
        std::cin >> k;
        if(k == 1){
            a.get_data();
            a.put_data();
        }
        else if(k == 2){
            b.get_data();
            b.put_data();
        }
    }  
    return 0;
}
