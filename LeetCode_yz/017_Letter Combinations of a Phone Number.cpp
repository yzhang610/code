#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution
{
	public: 
		vector<string> letterCombinations(string digits)
		{
			vector<string> res;
			if (digits.size() == 0)
				return res;
			vector<string> result(1, "");
			string changed[] = {" ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
			for (int i = 0; i < digits.size(); i++)
			{
				vector<string> tmp;
				for (int j = 0; j < result.size(); j++)
					for (int k = 0; k < changed[digits[i] - '0'].size(); k++)
						tmp.push_back(result[j] + changed[digits[i] - '0'][k]);
				result = tmp;
			}
			return result;
		}
}; 
int main()
{
	cout<<"ÇëÊäÈëÄãÒª²¥µÄºÅÂë£º"<<endl;
	string s1;
	cin>>s1;
	Solution s;
	vector<string> res = s.letterCombinations(s1);
	for (int i = 0; i < res.size(); i++)
	{
		cout<<res[i]<<" "; 
	}
	cout<<endl;
}
