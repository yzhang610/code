#include <iostream>
#include <vector>
using namespace std;
class Solution
{
	public:
	void moveZeros(vector<int>& nums)
	{
		int i = 0;
		int j = 0;
		for (; i < nums.size(); i++ )
		{
			if(nums[i] != 0)
			{
				nums[j] = nums[i];
				j++;
			}
		}
		for(j; j < nums.size(); j++)
		{
			nums[j] = 0;
		}
	}
};
int main()
{
	vector<int> nums;
	nums.push_back(0);
	nums.push_back(1);
	nums.push_back(0);
	nums.push_back(3);
	nums.push_back(12);
	Solution s;
	s.moveZeros(nums);
	for (int i = 0; i < nums.size(); i++)
	{
		cout<<nums[i]<<" "<<endl;
	}
	return 0;
}
