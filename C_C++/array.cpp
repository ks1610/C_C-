#include <bits/stdc++.h>

void one_dementional_cumulative_array_simple(){
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for(int i = 0; i < n; i++)
        std::cin >> a[i];
    int q;
    std::cin >> q;
    int sum = 0;
    while(q--){
        int l, r;
        std::cin >> l >> r;
        --l; --r;
        for(int i = l; i <= r; i++)
            sum += a[i];
    }
}

void one_dementional_cumulative_array_advance(){
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for(int i = 0; i < n; i++)
        std::cin >> a[i];
    int q;
    std::cin >> q;
    int sum = 0;
    int F[n];
    for(int i = 0; i < n; i++){
        if(i == 0) 
            F[i] = a[i];
        else
            F[i] = F[i - 1] + a[i];
    }
    while(q--){
        int l, r;
        std::cin >> l >> r;
        --l; --r;
        if(l == 0)
            std::cout<<F[r];
        else
            std::cout<<F[r] - F[l - 1];
    }
}
int main(){
    int c, r;
    std::cin >> c >> r;
    
    int a[c][r];
    int F[c][r];

    for(int i = 0; i < c; i++){
        for(int j = 0; j < r; j++){
            std::cin >> a[i][j];
        }
    }

    std::cout << std::endl;

    for(int i = 0; i < c; i++){
        for(int j = 0; j < r; j++){
            if(i == 0 && j == 0 /*|| i != 0 && j == 0*/){
                F[i][j] = a[i][j];
                std::cout<< F[i][j] << ' ';
            }
            else if(i == 0 && j != 0){
                F[i][j] = F[i][j-1] + a[i][j];
                std::cout << F[i][j] << ' ';
            }
            else if(i != 0 && j == 0){
                F[i][j] = F[i-1][j] + a[i][j];
                std::cout<< F[i][j] << ' ';
            }
            else if(i == 1 && j != 0){
                F[1][j] = F[1][j-1] + a[0][j] + a[1][j];
                std::cout<< F[i][j] << ' ';
            }
            else{
                F[i][j] = F[i][j-1] + a[i][j] + F[i-1][j];
                std::cout << F[i][j] << ' ';
            }
        }
        std::cout << std::endl;
    }
}