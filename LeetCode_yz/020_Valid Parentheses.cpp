#include <iostream>
#include <stack>
using namespace std;
class Solution
{
	public:
		//利用栈实现括号匹配 
		bool isValid(string s)
		{
			stack<char> st;
			for (int i = 0; i < s.length(); i++)
			{
				char c;
				if (s[i] == '(' || s[i] == '{' || s[i] == '[')
					st.push(s[i]);
				else if (s[i] == ')' && st.size() != 0)
				{	
					if (st.top() != '(')
						return false;
					st.pop();
				}	
				else if (s[i] == ']' && st.size() != 0)
				{
					if (st.top() != '[')
						return false;	
					st.pop();	
				}
				else if (s[i] == '}' && st.size() != 0)
				{
					if (st.top() != '{')
						return false;
					st.pop();	
				}
				else 
				{
					return false;
				}	
			}
			return st.size() == 0;	
		}
};
int main()
{
	string check = "[])";
	Solution s;
	if (s.isValid(check) == true)
	{
		cout<< check << " is valid!" << endl;
	}
	else
	{
		cout<< check << " is not valid!" << endl;
	}
	return 0;
}
