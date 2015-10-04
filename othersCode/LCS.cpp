////递归法求解最长公共子序列问题（LCS）
//#include <iostream>
//#include <string>
//using namespace std;
//
//int max(int a, int b)
//{
//	return (a > b) ? a : b;
//}
//
//int lcs(string &x, string &y, int m, int n)
//{
//	if (m == 0 || n == 0)
//	{
//		return 0;
//	}
//	if (x[m - 1] == y[n - 1])
//	{
//		return lcs(x, y, m - 1, n - 1) + 1;
//	}
//	else
//	{
//		return max(lcs(x, y, m, n - 1), lcs(x, y, m - 1, n));
//	}
//}
//
//int main()
//{
//	string x = "ABCBDAB";
//	string y = "BDCABA";
//	cout<<"The length of LCS is "<<lcs(x, y, x.length(), y.length())<<endl;
//	getchar();
//	return 0;
//}

//递归方法求解最长公共子序列问题（LCS）
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int max(int a, int b)
{
	return (a > b) ? a : b;
}

int lcs(string &x, string &y, int m, int n)
{
	//动态规划表，大小为 (m + 1) * (n + 1)
	vector < vector <int> > table(m + 1, vector <int>(n + 1));
	for (int i = 0; i < m + 1; ++i)
	{
		for (int j = 0; j < n + 1; ++j)
		{
			if (i == 0 || j == 0)
				table[i][j] = 0;
			else if (x[i - 1] == y[j -1])
				table[i][j] = table[i - 1][j - 1] + 1;
			else
				table[i][j] = max(table[i - 1][j], table[i][j - 1]);
		}
	}
	return table[m][n];
}

int main()
{
	string x = "ABCBDAB";
	string y = "BDCABA";
	cout<<"The length of LCS is "<<lcs(x, y, x.length(), y.length())<<endl;
	getchar();
	return 0;
}


