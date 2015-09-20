#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
//    string longestCommonPrefix(vector<string>& strs) {
//       if(strs.empty())
//			return "";
//		for(int i = 0; i < strs[0].size(); ++i)
//		{
//			for(int j = 0; j < strs.size(); ++j)
//			{
//				if(strs[j][i] != strs[0][i])
//					return strs[0].substr(0, i);
//			}
//		}
//		return strs[0];
//    }
	string longestCommonPrefix(vector<string> &strs)
	{
		if(strs.size() == 0)
			return "";
		int len = strs[0].size() - 1;
		for(int i = 0; i < strs.size(); i++)
		{
			for(int j = 0; j <= len; j++)
			{
				if(strs[i][j] != strs[0][j])
				{
					len = j - 1;
				}
			}
		}
		return strs[0].substr(0, len + 1);
	}  
};
int main()
{
	vector<string> strs;
	strs.push_back("hehe");
	strs.push_back("he");
	Solution s;
	cout<<s.longestCommonPrefix(strs)<<endl;
	return 0;
}
