#include <iostream>
#include <math.h>
using namespace std;
class Solution
{
	public:
		int numSquares(int n)
		{
			while (n % 4 == 0)
				n /= 4;
			if (n % 8 == 7)
				return 4;
			for(int a = 0; a * a <= n; ++a)
			{
				int b = sqrt(n - a * a);
				if (a * a + b * b == n)
					return !!a + !!b;
				}	
				return 3;
		}
};
int main()
{
	int n = 15;
	Solution s;
	int t = s.numSquares(n);
	cout<<t<<endl;
}

