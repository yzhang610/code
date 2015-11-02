#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;
class Solution 
{
	public:
		//外面两次循环，中间左右加逼求解 
		vector< vector<int> > fourSum(vector<int> &nums, int target)
		{
			vector< vector<int> > result;
			if (nums.size() < 4)
				return result;
			//排序操作
			sort(nums.begin(), nums.end());
			//左右加逼实现4sum
			for (int i = 0; i < nums.size() - 3; i++)
			{
				for (int j = i + 1; j < nums.size() - 2; j++)
				{
					int begin = j + 1;
					int end = nums.size() - 1;
					while (begin < end)
					{
						int sum = nums[i] + nums[j] + nums[begin] + nums[end];
						if (sum < target)
						{
							begin++; 
						}
						else if (sum > target)
						{
							--end;
						}
						else
						{
							vector<int> res;
							res.push_back(nums[i]);
							res.push_back(nums[j]);
							res.push_back(nums[begin]);
							res.push_back(nums[end]);
							result.push_back(res);
							begin++;
							end--;
						 } 
					}
				}
			} 
			sort(result.begin(), result.end());
			result.erase(unique(result.begin(), result.end()), result.end()); 
			return result; 
		}
};
int main()
{
	vector<int> num;
	num.push_back(1);
	num.push_back(0);
	num.push_back(-1);
	num.push_back(0);
	num.push_back(-2);
	num.push_back(2);
	int target = 0;
	Solution s;
	vector < vector<int> > result;
	result = s.fourSum(num, target);
	for (int i = 0; i < result.size(); i++)
	{
		for (int j = 0; j < result[0].size(); j++)
		{
			cout<<result[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
