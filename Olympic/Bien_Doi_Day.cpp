// 4/20
// https://oj.vnoi.info/problem/olp_kc23_tseq

#include<bits/stdc++.h>

int main(){
	int n, m;
	std::cin>>n>>m;
	int day[n];

	for(int i = 0; i < n; i++){
		std::cin>>day[i];
	}
	
	int save = 0, step = 0;
	int min = INT16_MAX;
	for(int i = 1; i < n; i++){
		std::cout <<"i: "<< day[i] <<std::endl;
		int x = day[i];
		for(int j = 0; j < n; j++){
			std::cout <<"j: "<< day[j] <<std::endl;
			int a = day[j];
			a = (a + 1) % m;
			if(day[j+1] == x){
				step += 1;
				std::cout<<"TT1: "<<step<<std::endl;
			}
			else{
				if(x < m && a != 0 && day[j] < day[j+1]){
					step += day[j+1] - day[j];
					std::cout<<"TT2_case_1: "<<step<<std::endl;
				}
				else if(a == 0){
					step += 1;
					std::cout<<"TT2_case_2: "<<step<<std::endl;
				}
			}
			save = step;
		}
		step = 0;
		std::cout << "Current = "<< save <<std::endl;
		min = std::min(save, min);
		std::cout<<"Min: "<<min<<std::endl;
	}
	std::cout << min;
}
