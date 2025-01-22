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
	
	for(int i = 0; i < n; i++){
		//std::cout <<"i: "<< day[i] <<std::endl;
		int x = day[i];// Check X from day[1] to day[n-1]

		for(int j = 0; j < n; j++)
		{
			//std::cout <<"j: "<< day[j] <<std::endl;
			int a = day[j]; // assign a to each elements
			a=(a+1) % m;
			if(day[j+1] == x){ // Assign a to operation 1 if the next element is X
				step += 1; //step up to 1
				//std::cout<<"TT1_case1: "<<step<<std::endl;
			}
			else if(day[j+1] > x && day[j] < x && day[j] < day[j+1]){
				//a = x;
				//a=(a+1) % m;
				step+= (day[j+1] - x) + 1;
				//std::cout<<"TT1_case2: "<<step<<std::endl;
			}
			else{
				if(a==0){
					if(day[j+1] == 0){
						step += 1;
						//std::cout<<"TT2_case1_1: "<<step<<std::endl;
					}
					else if(day[j] > day[j+1]){
						step += (day[j] - day[j+1]) - 1;
						//std::cout<<"TT2_case1_2: "<<step<<std::endl;
					}
					else{ 
						step += (day[j+1] - day[j]) + 1;
						//std::cout<<"TT2_case1_3: "<<step<<std::endl;
					}
				}
				else{
					if(a == day[i+1]){
						step += 1;
					}
					else if(day[j] < day[j+1]){
						step += day[j+1] - day[j];
						//std::cout<<"TT2_case2_1: "<<step<<std::endl;
					}
					else{ 
						step += day[j+1];
						//std::cout<<"TT2_case2_2: "<<step<<std::endl;
					}
				}
			}
			//save the current number of steps
			save = step;
		}
		step = 0;
		//std::cout << "Current = "<< save <<std::endl;
		//check the min step
		min = std::min(save, min);
		//std::cout<<"Min: "<<min<<std::endl;
	}
	std::cout << min;
}
