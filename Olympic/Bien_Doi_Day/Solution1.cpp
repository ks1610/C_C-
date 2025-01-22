// 6/20  test case accepted 
// https://oj.vnoi.info/problem/olp_kc23_tseq

#include<bits/stdc++.h>

int main(){

	//INPUT 
	int n, m;
	std::cin>>n>>m; //Type n & m

	std::vector<int> day(n);

	//Type the array with n elements
	for(int i = 0; i < n; i++){
		std::cin>>day[i];
	}
	
	//Start 
	int save = 0, step = 0;
	int min = INT16_MAX;
	
	for(int i = 1; i < n; i++){
		std::cout <<"i: "<< day[i] <<std::endl;
		int x = day[i];// Check X from day[1] to day[n-1]

		for(int j = 0; j < n; j++)
		{
			std::cout <<"j: "<< day[j] <<std::endl;
			int a = day[j]; // assign a to each elements
			a = (a + 1) % m; 
			if(day[j+1] == x){ // Assign a to operation 1 if the next element is X
				step += 1; //step up to 1
				std::cout<<"TT1: "<<step<<std::endl;
			}
			else{
				//while(a != day[i+1])
				//{
					if(x < m && a != 0 && day[j] < day[j+1]){ 
						step += day[j+1] - day[j];
						//step up to the next element minus the current if x < m, (a+1)%m != 0 and the next > current 
						std::cout<<"TT2_case_1: "<<step<<std::endl;
					}
					else if(a == 0 && a == day[i+1]){
						//if (a+1)%m = 0 and a = the next element  
						step += 1;
						std::cout<<"TT2_case_2: "<<step<<std::endl;
					}
				//}
			}
			//save the current number of steps
			save = step;
		}
		step = 0;
		std::cout << "Current = "<< save <<std::endl;
		//check the min step
		min = std::min(save, min);
		std::cout<<"Min: "<<min<<std::endl;
	}
	std::cout << min;
}
