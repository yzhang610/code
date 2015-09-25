#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class Solution
{
	public:
		vector< vector<int> > threeSum(vector<int>& nums)
		{
			vector < vector <int> > result;
			if (nums.size() < 3)
				return result;
			sort(nums.begin(), nums.end());
			for (vector<int>::const_iterator it = nums.begin(); it != nums.end(); ++it)
			{
				if(it != nums.begin() && *it == *(it-1))
				{
					continue;
				}
				vector<int>::const_iterator front = it + 1;
				vector<int>::const_iterator last = nums.end() - 1;
				while(front < last)
				{
					int sum = *it + *front + *last;
					if(sum > 0)
					{
						--last;
					}
					else if(sum < 0)
					{
						++front;
					}
					else if(front != it + 1 && *front == *(front - 1))
					{
						++front;
					}
					else if(last != nums.end() - 1 && *last == *(last + 1))
					{
						--last;
					}
					else
					{
						vector<int> ret;
						ret.push_back(*it);
						ret.push_back(*front);
						ret.push_back(*last);
						result.push_back(ret);
						++front;
						--last;
					}
				}
			}
			return result;		
		}
};
int main()
{
	vector<int> nums;
	nums.push_back(-1);
	nums.push_back(2);
	nums.push_back(-2);
 	nums.push_back(-1);
	nums.push_back(5);
	nums.push_back(3);
	nums.push_back(5);
	nums.push_back(6);
	nums.push_back(3);
	nums.push_back(-8);
	nums.push_back(4);
	nums.push_back(4);
	nums.push_back(6);
	nums.push_back(-4);
	nums.push_back(-5);
	nums.push_back(1);
	nums.push_back(8);
	nums.push_back(-8);
	nums.push_back(-5);
	nums.push_back(1);
	Solution s;
	vector< vector<int> > result;
	result = s.threeSum(nums);
	for(int i = 0; i < result.size(); i++)
	{
		for(int j = 0; j < result[i].size(); j++)
		{
			cout<<result[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
