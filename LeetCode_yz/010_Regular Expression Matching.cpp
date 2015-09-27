#include<iostream>
#include<string>
using namespace std;
class Solution
{
	public:
	bool isMatch(char *s, char *p)
	{
		if(*p == '\0')
			return *s == '\0';
		if(*(p + 1) != '*')
		{
			if(*s == *p || (*p == '.' && *s != '\0'))
				isMatch(s + 1, p + 1);
			else
				return false;
		}
		else
		{
			while(*s == *p || *p == '.' && *s != '\0')
			{
				if (isMatch(s, p + 2))
					return true;
				s++;
			}
			return isMatch(s, p+2);
		}
	} 
};
int main()
{
	char s[] = "hehehe";
	char p[] = "hea";
	Solution sol;
	sol.isMatch(s, p);
	return 0;
}
