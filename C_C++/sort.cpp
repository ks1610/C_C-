#include<bits/stdc++.h>
#include<algorithm>

void Sort_funtion(){
    int b[5];
    for(int i = 0; i < 5; i++){
        std::cin>>b[i];
    }

    std::sort(b, b + 5);
    //std::sort(b, b + 5, std::greater<int>());

    for(int x: b)
        std::cout<< x <<' ';
    std::cout<<std::endl;

}

float dis(float a, float b){
    return sqrt(pow(a, 2)+pow(b, 2));
}

bool cmp(std::pair<float, float> a, std::pair<float, float> b){
    if(dis(a.first, a.second) != dis(b.first, b.second))
        return dis(a.first,a.second) < dis(b.first, b.second);
    else if(dis(a.first,a.second) == dis(b.first, b.second)){
        return a.first < b.first;
    }
    else 
        return a.second < b.second;
}


void coordinates(){
    std::pair<float, float> xy[5];
    for(int i = 0; i < 5; i++){
        std::cin >> xy[i].first >> xy[i].second;
    }

    sort(xy, xy + 5, cmp);

    std::cout<<"sort: "<<std::endl;

    /*for(int i = 0; i < 5; i++)
        std::cout<< xy[i].first << ' ' << xy[i].second << std::endl;*/

    for(auto it : xy)
        std::cout<< it.first << ' ' << it.second << std::endl;
}

int countOddDigits(int number) {
    int count = 0;
    while (number) {
        if (number % 2 == 1) {
            ++count;
        }
        number /= 10;
    }
    return count;
}

bool compareNumbers(int a, int b) {
    int oddCountA = countOddDigits(a);
    int oddCountB = countOddDigits(b);

    if (oddCountA != oddCountB) {
        return oddCountA > oddCountB;
    } else {
        return a < b;
    }
}

void sortoddNumber(){
    int a[11];
    
    for (int i = 0; i < 11; ++i) {
        std::cin >> a[i];
    }

    // Sorting the array using compareNumbers function
    std::stable_sort(a, a + 11, compareNumbers);

    // Printing the sorted array
    std::cout << "Sorted array:" << std::endl;
    for (int i = 0; i < 11; ++i) {
        std::cout << a[i] << std::endl;
    }
}

bool isPrime(int n) {
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    return true;
}

int countPrimes(long long int num) {
    int count = 0;
    while (num > 0) {
        long long int digit = num % 10;
        if (isPrime(digit)) {
            ++count;
        }
        num /= 10;
    }
    return count;
}

bool compare_Prime_Numbers(int a, int b) {
    int oddCountA = countPrimes(a);
    int oddCountB = countPrimes(b);

    if (oddCountA != oddCountB) {
        return oddCountA > oddCountB;
    } else {
        return a < b;
    }
}

void sort_Prime_num(){
    
    int a[11];
    
    for (int i = 0; i < 11; ++i) {
        std::cin >> a[i];
    }

    // Sorting the array using compareNumbers function
    std::stable_sort(a, a + 11, compare_Prime_Numbers);

    // Printing the sorted array
    std::cout << "Sorted array:" << std::endl;
    for (int i = 0; i < 11; ++i) {
        std::cout << a[i] << std::endl;
    }
}

void sum(int &a, int &b){
    std::cout<<a+b<<std::endl;
    std::cout<<abs(a-b)<<std::endl;
}

int main() {
    int n;
    int a[100];
    std::cin>>n;
    for(int i = 0; i < n; i++)
        std::cin>>a[i];
    for(int i = n-1; i>=0; i--)
        std::cout<<a[i]<<' ';
    return 0;
}