#include <iostream>
#include <vector>
using namespace std;
class Solution
{
	public:
		int removeDuplicates(vector<int> &nums)
		{
			if (nums.size() < 2)
				return nums.size();
			vector<int>::iterator itr = nums.begin() + 1;
			while (itr != nums.end())
			{
				if (*itr == *(itr - 1))
					nums.erase(itr);
				else
					itr++;
			}
			return nums.size();
		}
};
int main()
{
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(2);
	Solution s;
	int len = s.removeDuplicates(nums); 
	cout << "new lenght is " << len << endl;
	for (int i = 0; i < nums.size(); i++)
	{
		cout << nums[i] << " ";
	}
	cout << endl;
 } 
