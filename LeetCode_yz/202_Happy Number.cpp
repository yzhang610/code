#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
class Solution
{
	public:
		bool isHappy(int n)
		{
			vector<int> m;
			while (true)
			{
				int sum = 0;
				m.push_back(n);
				while (n != 0)
				{
					int t = n % 10;
					sum += t * t;
					n = n / 10;
				}
				if (sum == 1)
					return true;
				else
				{
					n = sum;
					if (find(m.begin(), m.end(), n) != m.end())
					{
						return false;
					}
				}
			}
		}
};
int main()
{
	int n = 20;
	Solution s;
	bool result = s.isHappy(n);
	if (result == true)
	{
		cout<<n<<" is a happy number"<<endl;
	}
	else
	{
		cout<<n<<" is not a happy number"<<endl;
	}
	return 0;
}
