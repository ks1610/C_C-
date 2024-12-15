#include <bits/stdc++.h>

class Solution{

public:
	unsigned int demthaotac(unsigned int n, unsigned int m, const std::vector<unsigned int>& b, unsigned int X)
	{
		unsigned int count= 0;
		unsigned int a = b[0];
		for(unsigned int i = 1; i< n; ++i){
			if(a == b[i]) continue;

			unsigned int dist = (b[i] - a + m) % m;	
			
			if(b[i] == X)
			{
				count += 1;
				a = X;
			}
			else
			{
				count += dist;
				a = b[i];
			}
		}
		return count;
	}
};

int main(){
	Solution s;
	
	unsigned int n, m;
	std::cin>>n>>m;
	std::vector<unsigned int> b(n);
	for(unsigned int i = 0; i < n; ++i)
		std::cin>>b[i];
	
	unsigned int min_operation = INT_MAX;
	for(unsigned int i = 0; i < n; ++i){
		min_operation =  std::min(s.demthaotac(n, m, b, b[i]), min_operation);
	}
	std::cout<<min_operation;
}
