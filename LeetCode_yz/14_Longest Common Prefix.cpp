#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution
{
	public:
		string longestCommonPrefix(vector<string> &strs)
		{
			if (strs.size() <= 0)
				return "";
			if (strs.size() == 1)
				return strs[0];
			int t = strs[0].length();
			for (int i = 0; i < t; i++)
			{
				for (int j = 0 ; j < strs.size(); j++)
				{
					if (strs[j][i] != strs[0][i])
					{
						return strs[0].substr(0, i);
					}
				}
			}
			return strs[0];
		}
};
int main()
{
	vector<string> strs;
	strs.push_back("abab");
	strs.push_back("aba");
	strs.push_back("");
	Solution s;
	string result = s.longestCommonPrefix(strs);
	cout << result << endl; 
}
