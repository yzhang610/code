#include <iostream>
#include <vector>
using namespace std;

class Solution
{
	public:
		int rob(vector<int>& nums)
		{
			int a = 0; 
			int b = 0;
			for (int i = 0; i < nums.size(); i++)
			{
				int m = a;
				int n = b;
				a = n + nums[i];
				b = max(m, n);
			}
			return max(a, b);
		}
};
int main()
{
	vector<int> nums;
	nums.push_back(30);
	nums.push_back(20);
	nums.push_back(50);
	nums.push_back(100);
	nums.push_back(19);
	Solution s;
	int t = s.rob(nums);
	cout<<"House Robber is £º"<<t<<endl;
	return 0; 
}
