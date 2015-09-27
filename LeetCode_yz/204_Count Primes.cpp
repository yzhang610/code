#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
class Solution
{
	public:
		int countPrimes(int n)
		{
			if (n < 2)
				return 0;
			bool *p = new bool[n];
			memset(p, true, sizeof(bool) * n);
			for (int i = 2; i * i < n; i++)
			{
				if(p[i] == true)
					for (int j = 2; i * j < n; j++)
					{
						p[i * j] = false;
					}
			}
			int count = 0;
			for (int i = 2; i < n; i++)
				if(p[i])
					count++;
			delete [] p;
			return count;
		}
};
int main()
{
	Solution s;
	int n = 10;
	int count = s.countPrimes(20);
	cout<<count<<endl;
}
