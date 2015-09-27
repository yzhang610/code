#include<iostream>
#include<math.h>
using namespace std;
class Solution
{
	public:
		//利用递归公式 
		int mySqrt(int x)
		{
			if(x < 0)
				return -1;
			if(x == 0)
				return 0;
			else
			{
				double x2 = 1;
				double x1;
				do
				{
					x1 = x2;
					x2 = (x1 + x / x1) / 2;
				}while(abs(x2 - x1) > 0.00001);
				return (int)x2;
			}
		}
		//利用折半查找 
	int mySqrt2(int x)
	{
		if(x < 0)
			return -1;
		if(x == 0)
			return 0;
		int first = 1;
		int last = x / 2 + 1;
		int mid;
		while(first <= last)
		{
			mid = (first + last) / 2.0;
			if(mid * mid == x )
				return (int)mid;
			if((x / mid >= mid) && ((mid + 1) > x / (mid + 1)))
				return mid;
			else if(x / mid < mid)
				last = mid - 1;
			else
				first = mid + 1;
		}
		return -1;
	}
};
int main()
{
	int n = 1;
	Solution s;
	int t = s.mySqrt2(n);
	cout<<t<<endl;
}
