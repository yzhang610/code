#include<iostream>
#include<vector>
using namespace std;
class Solution
{
	public:
		int maxArea(vector<int> &height)
		{
			if (height.size() <= 1)
				return 0;
			int first = 0;
			int last = height.size() - 1;
			int maxArea = 0;
			int area;
			while (first < last)
			{
				if(height[first] <= height[last])
				{
					area = (last - first) * height[first];
					if(area > maxArea)
						maxArea = area;
					first++;
				}
				else
				{
					area = (last - first) * height[last];
					if(area > maxArea)
						maxArea = area;
					last--;
				}
			}
			return maxArea;
		}
};
int main()
{
	vector<int> height;
	height.push_back(3);
	height.push_back(5);
	height.push_back(8);
	height.push_back(6);
	Solution s;
	int t = s.maxArea(height);
	cout<<t<<endl;
}
