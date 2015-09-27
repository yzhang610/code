#include <iostream>
using namespace std;
class Solution 
{
	public:
		double myPow(double x, int n)
		{
			if (x == 0 || x == 1)
				return x;
			if (n == 0)
		    	return 1;
		    if (n < 0 && n != INT_MIN)
		    	return 1.0 / myPow(x, -n);
		    double p = myPow(x, n /2);
		    if(n % 2 == 0)
		    {
		    	return p * p;
			}
			else
			{
				return p * p * x;
			}
		}	
};
int main()
{
	int n = 2;
	Solution s;
	double t = s.myPow(2, 3);
	cout<<t<<endl;
	return 0;
}
