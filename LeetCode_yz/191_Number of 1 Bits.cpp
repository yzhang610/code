#include <iostream>
#include <stdint.h>
using namespace std;

class Solution 
{
	public:
		int hammingWeight(uint32_t n)
		 {
		 	int count = 0;
		 	for(int i = 0; i < 32; i++)
		 	{
		 		int bit = (n >> i) & 1;
				if(bit == 1)
					count++;	
			}
			return count;
		 }
};
int main()
{
	cout<<"请输入一个数：";
	int n;
	cin>>n;
	Solution s;
	int count = s.hammingWeight(n); 
	cout<<"该数中存在"<<count<<"个1"<<endl; 
}
