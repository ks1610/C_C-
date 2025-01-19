// 20/20 testcase passed 
// https://oj.vnoi.info/problem/olp_kc23_triangle

#include<bits/stdc++.h>

int main(){
  long double u, v;
  std::cin >> u >> v;
  // Ccaulate
  long double result = (u*u + v*v)/4;
  // round to 2 decimal places  
  std::cout<<std::fixed<<std::setprecision(2)<<result<<std::endl;
}
