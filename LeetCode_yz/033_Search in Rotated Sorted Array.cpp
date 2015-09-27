#include<iostream>
#include<vector>
using namespace std;
class Solution
{
	public:
	int search(vector<int>& nums, int target)
	{
		int first = 0;
		int last = nums.size();
		int mid;
		while(first != last)
		{
			mid = (first + last) / 2;
			if(nums[mid] == target)
				return mid;
			if(nums[first] <= nums[mid])
			{
				if(nums[first] <= target && target < nums[mid])
					last = mid;
				else
					first = mid + 1;
			}
			else
			{
				if(nums[mid] < target && target <= nums[last - 1])
					first = mid + 1;
				else
					last = mid;
			}		
		}
		return -1;
	}	
};
int main()
{
	vector<int> num;
	num.push_back(9);
	num.push_back(10);
	num.push_back(11);
	num.push_back(12);
	num.push_back(0);
	num.push_back(1);
	num.push_back(2);
	num.push_back(3);
	num.push_back(4);
	num.push_back(5);
	num.push_back(6);
	num.push_back(7);
	Solution s;
	int t = s.search(num, 4);
	cout<<t<<endl;
	return 0;
}
