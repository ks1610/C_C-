#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>


class Box
{
private:
    /* data */
    int l, b, h;

public:

    //The default constructor of the class should initialize l,b and h to .
    Box() : l(0), b(0), h(0) {}
        /*
        l = 0;
        b = 0;
        h = 0;
        */
    
    //The parameterized constructor Box(int length, int breadth, int height) should initialize Box's l,b and h to length, breadth and height.
    Box(int x, int y, int z) : l(x), b (y), h(z) {}
    
    /*The copy constructor Box (Box B) should set l,b and h to B's l,b and h, respectively.*/
    Box(const Box& B){
        this->l = B.l;
        this->b = B.b;
        this->h = B.h;
    }

    /*int getLength() - Return box's length*/
    int getLength(){
        return l;
    }

    /*int getBreadth() - Return box's breadth*/
    int getBreadth(){
        return b;
    }

    /*int getHeight() - Return box's height*/
    int getHeight(){
        return h;
    }

    /*long long CalculateVolume() - Return the volume of the box*/
    long long CalculateVolume(){
        long long volume = (long long) l * b * h;
        return volume;
    }

    /*Overload the operator < for the class Box. Box A < Box B if:
    1.A.l < B.l
    2.A.b < B.b and A.l == B.l
    3.A.h < B.h and A.b == B.b and A.l == B.l*/
    bool operator<(Box& other){
        bool condition1 = l < other.l;
        bool condition2 = b < other.b && l == other.l;
        bool condition3 = h < other.h && b == other.b && l == other.l;
        if(condition1 || condition2 || condition3)
            return true;
        return false;
    }

    /*Overload operator << for the class Box().
    If B is an object of class Box:
    cout << B should print B.l, B.b and B.h on a single line separated by spaces.*/
    
    friend std::ostream& operator<<(std::ostream& out, Box& B){
        out << B.l << ' ' << B.b << ' ' << B.h;
        return out;
    }
    //friend funtion
};
void check2()
{
    int n;
    std::cin>>n;
    Box temp;
    for(int i=0;i<n;i++)
    {
        int type;
        std::cin>>type;
        if(type ==1)
        {
            std::cout<<temp<<std::endl;
        }
        if(type == 2)
        {
            int l,b,h;
            std::cin>>l>>b>>h;
            Box NewBox(l,b,h);
            temp=NewBox;
            std::cout<<temp<<std::endl;
        }
        if(type==3)
        {
            int l,b,h;
            std::cin>>l>>b>>h;
            Box NewBox(l,b,h);
            if(NewBox<temp)
            {
                std::cout<<"Lesser\n";
            }
            else
            {
                std::cout<<"Greater\n";
            }
        }
        if(type==4)
        {
            std::cout<<temp.CalculateVolume()<<std::endl;
        }
        if(type==5)
        {
            Box NewBox(temp);
            std::cout<<NewBox<<std::endl;
        }

    }
}
int main() {
    /*
    Input handling:
    first line: how many queries
    first digit in query mean type of query,
    1 - Use overloaded operator << on previous created Box object
    2 - read 3 digits and use overloaded operator << on box created with constructor
    3 - create new box by reading input and comparee it with last created box
        print "Greater" or "Lesser" because 
        "Two boxes being compared using the < operator will not have all three dimensions equal."
        Use operator <
        Don't treat object that you creating in this query as the last one in further queries
    4 - Print volume of last created box with CalculateVolume() method
    5 - Use Copy constructor (copy previously created box) and use overloaded operator << on copied object
    */
   check2();
}
