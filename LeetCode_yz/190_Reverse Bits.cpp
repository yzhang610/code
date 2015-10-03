#include <iostream>
#include <stdint.h>
using namespace std;
class Solution
{
	public:
		uint32_t reverseBits(uint32_t n)
		{
			int result = 0;
			for (int i = 0 ; i < 32; i++)
			{
				int bit = (n>>i) & 1;
				result |= bit<<(31 - i);
			}
			return result;
		}
};
int main()
{
	cout<<"������һ��Ҫת�õ�����";
	int n;
	cin>>n;
	Solution s;
	int t = s.reverseBits(n);
	cout<<"ת�ú����Ϊ��"<<t<<endl; 
}
