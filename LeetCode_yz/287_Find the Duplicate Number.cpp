#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
	public:
		int findDuplicate(vector<int>& nums)
		{
			sort(nums.begin(), nums.end());
			for(int i = 0; i < nums.size() - 1; i++)
			{
				if(nums[i] == nums[i + 1])
					return nums[i];
			}
			return 0;
		}
};
int main()
{
	Solution s;
	vector<int> num;
	num.push_back(1);
	num.push_back(1);
	int t = s.findDuplicate(num);
	cout<<t<<endl;
}
