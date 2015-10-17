#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;
class Solution
{
	public:
         //暴力搜索方法 
//		int threeSumClosest(vector<int> &nums, int target)
//		{
//			int min = 999999;
//			for (int i = 0; i < nums.size() - 2; i++)
//			{
//				for (int j = i + 1; j < nums.size() - 1; j++)
//				{
//					for (int k = j + 1; k < nums.size(); k++)
//					{
//						int sum = nums[i] + nums[j] + nums[k];
//						if (abs(sum - target) < abs(min))
//						{
//							min = sum - target;
//						 } 
//					}
//				}
//			}
//			return min + target;
//		}
         //target参与大片sum的相减中了 
//		int threeSumClosest(vector<int> &nums, int target)
//		{
//			if (nums.size() < 3)
//				return 0;
//			//对nums数组进行排序
//			sort(nums.begin(), nums.end()); 
//			int min = nums[0] + nums[1] + nums[2] - target;
//			for (int i = 0; i < nums.size() - 2; i++)
//			{
//				int begin = i + 1;
//				int end = nums.size() - 1;
//				while (begin < end)
//				{
//					int sum = nums[i] + nums[begin] + nums[end] - target;
//					if (sum == 0)
//						return target;
//					if (abs(min) > abs(sum))
//					{
//						min = sum;
//					}
//					if (sum > 0)
//					{
//						end--;
//					}
//					if (sum < 0)
//					{
//						begin++;
//					}
//				}
//			}
//			return min + target; 
//		}
		//先排序，然后加逼求解
		int threeSumClosest(vector<int> &nums, int target)
		{
			//先排序
			if (nums.size() < 3)
				return -1;
			sort(nums.begin(), nums.end());	
			//左右加逼进行求解
			int min = nums[0] + nums[1] + nums[2] - target;
			for (int i = 0; i < nums.size() - 2; i++)
			{
				int begin = i + 1;
				int end = nums.size() - 1;
				while(begin < end)
				{
					int sum = nums[i] + nums[begin] + nums[end];
					if (sum - target == 0)
						return sum;
					if (abs(sum - target) < abs(min))
					{
						min = sum - target;
					}
					if (sum - target < 0)
						begin++;
					else 
						end--;
				}
			 }
			 return min + target; 
		} 
};
int main()
{
	vector<int> nums;
	nums.push_back(-1);
	nums.push_back(10);
	nums.push_back(1);
	nums.push_back(-4);
	int target = 1;
	Solution s;
	int sum = s.threeSumClosest(nums, target);
	cout << sum << endl;
}
