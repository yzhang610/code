//#include<iostream>
//#include<algorithm>
//#include<vector>
//using namespace std;
//class Solution
//{
//	public:
//		vector< vector<int> > threeSum(vector<int>& nums)
//		{
//			vector < vector <int> > result;
//			if (nums.size() < 3)
//				return result;
//			sort(nums.begin(), nums.end());
//			for (vector<int>::const_iterator it = nums.begin(); it != nums.end(); ++it)
//			{
//				if(it != nums.begin() && *it == *(it-1))
//				{
//					continue;
//				}
//				vector<int>::const_iterator front = it + 1;
//				vector<int>::const_iterator last = nums.end() - 1;
//				while(front < last)
//				{
//					int sum = *it + *front + *last;
//					if(sum > 0)
//					{
//						--last;
//					}
//					else if(sum < 0)
//					{
//						++front;
//					}
//					else if(front != it + 1 && *front == *(front - 1))
//					{
//						++front;
//					}
//					else if(last != nums.end() - 1 && *last == *(last + 1))
//					{
//						--last;
//					}
//					else
//					{
//						vector<int> ret;
//						ret.push_back(*it);
//						ret.push_back(*front);
//						ret.push_back(*last);
//						result.push_back(ret);
//						++front;
//						--last;
//					}
//				}
//			}
//			return result;		
//		}
//};
//int main()
//{
//	vector<int> nums;
//	nums.push_back(-1);
//	nums.push_back(2);
//	nums.push_back(-2);
// 	nums.push_back(-1);
//	nums.push_back(5);
//	nums.push_back(3);
//	nums.push_back(5);
//	nums.push_back(6);
//	nums.push_back(3);
//	nums.push_back(-8);
//	nums.push_back(4);
//	nums.push_back(4);
//	nums.push_back(6);
//	nums.push_back(-4);
//	nums.push_back(-5);
//	nums.push_back(1);
//	nums.push_back(8);
//	nums.push_back(-8);
//	nums.push_back(-5);
//	nums.push_back(1);
//	Solution s;
//	vector< vector<int> > result;
//	result = s.threeSum(nums);
//	for(int i = 0; i < result.size(); i++)
//	{
//		for(int j = 0; j < result[i].size(); j++)
//		{
//			cout<<result[i][j]<<" ";
//		}
//		cout<<endl;
//	}
//	return 0;
//}

//实现原理：先进行排序，然后左右加逼求解 
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
	public:
	//暴力方法
//		vector< vector<int> > threeSum(vector<int> &num)
//		{
//			vector< vector<int> > result;
//			sort(num.begin(), num.end());
//			
//			for (int i = 0; i < num.size() - 2; i++)
//			{
//				for (int j = i + 1; j < num.size() - 1; j++)
//				{
//					for (int k = j + 1; k < num.size(); k++)
//					{
//						int sum = num[i] + num[j] + num[k];
//						if (sum == 0)
//						{
//							vector<int> tmp;
//							tmp.push_back(num[i]);
//							tmp.push_back(num[j]);
//							tmp.push_back(num[k]);
//							result.push_back(tmp);
//						} 
//					}
//				}
//			}
//			//去除重复元素
//			vector< vector<int> >::iterator result_unique = unique(result.begin(), result.end());
//			result.erase(result_unique, result.end());
//			return result; 
//		}
		vector< vector<int> > threeSum(vector<int> &num)
		{
			vector< vector<int> > result;
			if (num.size() < 3)
				return result;
			//对给定的数据进行排序 
			sort(num.begin(), num.end());
			//加逼求值
			for (int i = 0; i < num.size() - 2; i++)
			{
				//加快循环 
				if (i != 0 && num[i] == num[i - 1])
				{
					continue;
				} 
				int begin = i + 1;
				int end = num.size() - 1;
				while(begin < end)
				{
					int sum = num[i] + num[begin] + num[end];
					if(sum > 0)
    				{
    					end--;
    				}
    				else if(sum < 0)
    				{
    					begin++;
    				}
    				//其中begin！=i + 1和end ！= num.size() - 1防止丢到000情况 
    				else if(begin != i + 1 && num[begin] == num[begin - 1])
    				{
    					begin++;
    				}
    				else if(end != num.size() - 1 && num[end] == num[end + 1])
    				{
    					end--;
    				}
    				else
    				{
    					vector<int> ret;
    					ret.push_back(num[i]);
    					ret.push_back(num[begin]);
    					ret.push_back(num[end]);
    					result.push_back(ret);
    					begin++;
    					end--;
    				}
				}
			}
			return result; 
		} 
};
int main()
{
	vector <int> nums;
	nums.push_back(-1);
	nums.push_back(2);
	nums.push_back(1);
	nums.push_back(-1);
	nums.push_back(-4);
	Solution s;
	vector< vector<int> > result;
	result = s.threeSum(nums);
	for (int i = 0; i < result.size(); i++)
	{
		for (int j = 0; j < result[0].size(); j++)
		{
			cout << result[i][j] << " ";
		}
		cout << endl;
	}
}
 
