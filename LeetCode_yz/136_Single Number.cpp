#include <iostream>
#include <vector>
using namespace std;
class Solution
{
	public:
		int singleNumber(vector<int>& nums)
		{
			int i;
			int result = nums[0];
			for(i = 1; i < nums.size(); i++)
			{
				result ^= nums[i];
			}
			return result;
		}
};
int main()
{
	vector<int> num;
	num.push_back(3);
	num.push_back(2);
	num.push_back(3);
	num.push_back(5);
	num.push_back(2);
	Solution s;
	int t = s.singleNumber(num);
	cout<<t<<endl;
}
