#include <iostream>
#include <string>

int main(){
    std::string text;
    std::string c = "cat";
    std::cout<<"text: "<<std::endl;
    std::getline(std::cin, text);
    int n, s = text.size();
    std::size_t found = text.find(c);
    
    if (found!=std::string::npos)
        text.replace(found, text.size(), "dog");
            
    std::cout<<text;     
}