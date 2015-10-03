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
	cout<<"������һ������";
	int n;
	cin>>n;
	Solution s;
	int count = s.hammingWeight(n); 
	cout<<"�����д���"<<count<<"��1"<<endl; 
}
