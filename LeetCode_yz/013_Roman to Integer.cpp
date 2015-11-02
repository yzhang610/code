#include <iostream>
#include <string>
using namespace std;
class Solution 
{
	public:
		int romanToInt(string s)
		{
			int result = 0;
			int length = s.length();
			if (length <= 0)
				return 0;
			for (int i = 0; i < length; i++)
			{
				if (s[i] == 'M')  //µ±Ç°×Ö·ûÎªM£º1000 
				{
					result += 1000;
				}
				if (s[i] == 'C' && i + 1 < length && s[i+1] == 'M')
				{
					result += 900;
					i = i + 2;
				}
				if (s[i] == 'C' && i + 1 < length && s[i+1] == 'D')
				{
					result += 400;
					i = i + 2;
				}
				if (s[i] == 'X' && i + 1 < length && s[i+1] == 'C')
				{
					result += 90;
					i = i + 2;
				}
				if (s[i] == 'X' && i + 1 < length && s[i+1] == 'L')
				{
					result += 40;
					i = i + 2; 
				}
				if (s[i] == 'I' && i + 1 < length && s[i+1] == 'X')
				{
					result += 9;
					i = i + 2;
				}
				if (s[i] == 'I' && i + 1 < length && s[i+1] == 'V')
				{
					result += 4;
					i = i + 2; 
				}
				if (s[i] == 'I')
				{
					result += 1;
				}
				if (s[i] == 'X')
				{
					result += 10;
				}
				if (s[i] == 'C')
				{
					result += 100;
				}
				if (s[i] == 'V')
				{
					result += 5;
				} 
				if (s[i] == 'L')
				{
					result += 50;
				}
				if (s[i] == 'D')
				{
					result += 500;
				} 
			}
			return result;
		}
};
int main()
{
	string s = "CMXXI";
	Solution sol;
	int result = sol.romanToInt(s);
	cout << result << endl;
}

