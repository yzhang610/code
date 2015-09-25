#include<iostream>
#include<string>
using namespace std;
class Solution
{
	public:
		string intToRoman(int num)
		{
			string result = "";
			int i = 3;
			int j = 1000;
			if(num >= 4000 || num <= 0)
				return "";
			string s[35] = { "", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX",
						     "", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC",
						     "", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM",
						     "", "M", "MM", "MMM" };
			while(num > 0)
			{
				int t = num / j;
				result += s[i * 10 + t];
				num = num - t * j;
				j = j / 10;
				i--;
			}
			return result;	
		}
};
int main()
{
	Solution s;
	int t = 1230;
	string result = s.intToRoman(t);
	cout<<result<<endl;
}
