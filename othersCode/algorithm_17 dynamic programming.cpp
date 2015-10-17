//动态规划——钢条实现 
//#include <iostream>
//using namespace std;
//void ExtendedBUCutRod(const int *p, int n, int *r, int *s)
//{
//	r[0] = 0;
//	for (int i = 1; i <= n; ++i)
//	{
//		int q = -1;
//		for (int j = 1; j <= i; ++j)
//		{
//			int tmp = p[j - 1] + r[i - j];
//			if (q < tmp)
//			{
//				q = tmp;
//				s[i] = j;
//			}
//		}
//		r[i] = q;
//	}
//}
//void PrintBUCutRod(const int *p, int n, int *r, int *s)
//{
//	ExtendedBUCutRod(p, n, r, s);
//	cout << "长度为" << n <<"的钢条最大收益为:" << r[n] << endl;
//	cout << "最优方案的钢条长度分别为:" ;
//	while (n > 0)
//	{
//		cout << s[n] << " ";
//		n = n - s[n];	
//	} 
//	cout << endl;
//}
//int main()
//{
//	int n;
//	while (cin >> n)
//	{
//		int *p = new int[n];
//		for (int i = 0; i < n; ++i)
//		{
//			cin >> p[i];
//		}
//		int *r = new int[n + 1];
//		int *s = new int[n + 1];
//		PrintBUCutRod(p, n, r, s); 
//	}
//	return 0;
//}

//动态规划——矩阵相乘（递归实现） 
//#include <stdio.h> 
//#include <limits.h>
//int MatrixChainOrder(int p[], int i, int j)
//{
//	if (i == j)
//		return 0;
//	int k;
//	int min = INT_MAX;
//	int count;
//	//计算最小计算次数 
//	for (k = i; k < j; k++)
//	{
//		count = MatrixChainOrder(p, i, k) + MatrixChainOrder(p, k + 1, j) + p[i - 1] * p[k] * p[j];
//		if (count < min)
//			min = count;
//	}
//	return min; 
//}
//int main()
//{
//	int arr[] = {30, 35, 15, 5, 10, 20, 25};
//	int n = sizeof(arr) / sizeof(arr[0]);
//	printf("Min number of multiplication is %d", MatrixChainOrder(arr, 1, n - 1));
//	return 0;
//}

////动态规划——矩阵相乘（非递归实现） 
// #include <stdio.h> 
// //计算最佳括号的方式，得m和s矩阵
// void maxtrix_order(int *p, int n, int m[6][6], int s[6][6])
// {
// 	int q = 0;
// 	int j = 0;
// 	for (int i = 0; i < n; i++)
// 	{
// 		m[i][j] = 0;
//	}
//	for (int l = 2; l <= n; l++)
//	{
//		for (int i = 0; i < n - 1; i++)
//		{
//			j = i + l - 1;
//			m[i][j] = 1000000;
//			for (int k = i; k < j; k++)
//			{
//				q = m[i][k] + m[k + 1][j] + p[i] * p[k + 1] * p[j + 1];
//				if (q < m[i][j])
//				{
//					m[i][j] = q;
//					s[i][j] = k;
//				}
//			} 
//		} 
//	 } 
// } 
// //打印加括号的位置
// void print_order(int s[6][6], int i, int j)
// {
// 	if (i == j)
// 		printf("A%d", i + 1);
// 	else
// 	{
// 		printf("(");
// 		print_order(s, i, s[i][j]);
// 		print_order(s, s[i][j] + 1, j); //递归调用 
// 		printf(")");
//	 }
//  } 
// int main()
// {
//	int p[7] = {30, 35, 15, 5, 10, 20, 25};   //记录6个矩阵的行和列
//	int m[6][6] = {0};   //存储第i个矩阵到第j个矩阵的计算代价（乘法次数）
//	int s[6][6] = {0};   //存储第i个矩阵到第j个矩阵的最小代价，分两部分位置
//	int n = 6;           //矩阵个数
//	maxtrix_order(p, n, m, s);
//	printf("最终加括号的形式为: ");
//	print_order(s, 0, 5);      //计算从第1个矩阵到第6个矩阵的最优化括号方法
//	printf("\n");
//	return 0; 
// } 

//动态规划——最长公共子序列
//递归法求解
//#include <iostream>
//#include <string>
//using namespace std;
//int max(int a, int b)
//{
//	return (a > b) ? a : b;	
//} 
//int lcs(string &X, string &Y, int m, int n)
//{
//	if (m == 0 || n == 0)
//		return 0;
//	if (X[m - 1] == Y[n - 1])
//		return lcs(X, Y, m - 1, n - 1) + 1;
//	else
//		return max(lcs(X, Y, m, n - 1), lcs(X, Y, m - 1, n));
//}
//int main()
//{
//	string X = "ABCBDAB";
//	string Y = "BDCABA";
//	cout << "The length of LCS is " << lcs(X, Y, X.length(), Y.length()) << endl;
//	return 0;
//}

//动态规划——最长公共子序列
//#include <iostream>
//#include <string>
//#include <vector>
//using namespace std;
//int max(int a, int b)
//{
//	return (a > b) ? a : b;
//} 
//int lcs(string &X, string &Y, int m, int n)
//{
//	//动态规划表大小为（m+1)*(n+1)
//	vector< vector<int> > table(m + 1, vector<int>(n + 1));
//	for (int i = 0; i < m + 1; ++i)
//	{
//		for (int j = 0; j < n + 1; ++j)
//		{
//			if (i == 0 || j == 0)
//				table[i][j] = 0;
//			else if (X[i - 1] == Y[j - 1])
//				table[i][j] = table[i - 1][j - 1] + 1;
//			else
//				table[i][j] = max(table[i - 1][j], table[i][j - 1]);
//		}
//	}
//	return table[m][n];	
//}
//int main()
//{
//	string X = "ABCBDAB";
//	string Y = "BDCABA";
//	cout << "The length of LCS is " << lcs(X, Y, X.length(), Y.length()) << endl;
//	return 0;
// } 

//动态规划——最优二叉搜索树
//#include <iostream>
//using namespace std;
//const int N = 3;
//void OptimalBinarySearchTree(double a[], double b[], int n, double **m, int **s, double **w)
//{
//	for (int i = 0; i <= n; i++)
//	{
//		w[i + 1][i] = a[i];
//		m[i + 1][i] = 0;
//	}
//	for (int r = 0; r < n; r++)  //r代表起止下标的差 
//	{
//		for (int i = 1; i <= n - r; i++)   //i为起始元素下标 
//		{
//			int j = i + r;   //j为终止元素下标
//			//构造T[i][j] 填写w[i][j], m[i][j], s[i][j] 
//			//首先i作为根，其左子树为空，右子树为节点 
//			w[i][j] = w[i][j - 1] + a[j] + b[j];
//			m[i][j] = m[i + 1][j];
//			s[i][j] = i;
//			
//			//不选i作为根，设k为其根，则k=i+1...j
//			//左子树为节点，i,i+1...k-1，右子树为节点:k+1,k+2...j
//			for (int k = i + 1; k <= j; k++)
//			{
//				double t = m[i][k - 1] + m[k + 1][j];
//				if (t < m[i][j])
//				{
//					m[i][j] = t;
//					s[i][j] = k;    //根节点元素 
//				}
//			} 
//			m[i][j] += w[i][j]; 
//		}	
//	}	
//} 
//void Traceback(int n, int i, int j, int **s, int f, char ch)
//{
//	int k = s[i][j];
//	if (k > 0)
//	{ 
//		if (f == 0)  //根
//		{
//			cout << "Root: " << k << " (i:j):(" << i << "," << j <<")" <<endl; 
//		}
//		else   //子树 
//		{
//			cout << ch << "of " << f << ":" << k << " (i:j):(" << i << "," << j << ")" << endl; 
//		} 
//		int t = k - 1;
//		if (t >= i && t <= n)
//		{
//			//回溯左子树
//			Traceback(n, i, t, s, k, 'L'); 
//		}
//		t = k + 1;
//		if (t <= j)
//		{
//			//回溯右子树
//			Traceback(n, t, j, s, k, 'R'); 
//		}
//	 } 
//}
//int main()
//{
//	double a[] = {0.15, 0.1, 0.05, 0.05};
//	double b[] = {0.00, 0.5, 0.1, 0.05};
//	cout << "有序集的概率分布为: "<<endl;
//	for (int i = 0; i < N + 1; i++)
//	{
//		cout << "a" << i << "=" << a[i] << ",b" << i << "=" << b[i] << endl;
//	}
//	double **m = new double *[N + 2];
//	int **s = new int *[N + 2];
//	double **w = new double *[N + 2];
//	for (int i = 0; i < N + 2; i++)
//	{
//		m[i] = new double[N + 2];
//		s[i] = new int[N + 2];
//		w[i] = new double[N + 2]; 
//	}
//	OptimalBinarySearchTree(a, b, N, m, s, w);
//	cout << "二叉搜索树最小平均路长为: " << m[1][N] << endl;
//	cout << "构造的最优二叉树为: " << endl;
//	Traceback(N, 1, N, s, 0, '0');
//	for (int i = 0; i < N + 2; i++)
//	{
//		delete m[i];
//		delete s[i];
//		delete w[i];
//	} 
//	delete []m;
//	delete []s;
//	delete []w;
//	return 0;
//}

//动态规划——最优二叉查找树
#include <iostream>
using namespace std;
const int MaxVal = 9999;
const int n = 5;
//搜索到根节点和虚拟键的概率 
double p[n + 1] = {-1, 0.15, 0.1, 0.05, 0.1, 0.2};
double q[n + 1] = {0.05, 0.1, 0.05, 0.05, 0.05, 0.1};

int root[n + 1][n + 1];//记录根节点 
double w[n + 2][n + 2];//子树概率总和 
double e[n + 2][n + 2];//子树期望代价

void optimalBTS(double *p, double *q, int n)
{
	//初始化只包括虚拟键的子树
	for (int i = 1; i <= n + 1; ++i)
	{
		w[i][i - 1] = q[i - 1];
		e[i][i - 1] = q[i - 1];
	}
	//由上到下，由左到右逐步计算
	for (int len = 1; len <= n; ++len)
	{
		for (int i = 1; i <= n - len + 1; ++i)
		{
			int j = i + len - 1;
			e[i][j] = MaxVal;
			w[i][j] = w[i][j - 1] + p[j] + q[j];
			//求取最小代价的子树的根
			for (int k = i; k <= j; ++k)
			{
				double temp = e[i][k - 1] + e[k + 1][j] + w[i][j];
				if (temp < e[i][j])
				{
					e[i][j] = temp;
					root[i][j] = k;
				}
			} 
		}
	} 
}
 //输出最优二叉查找树所有子树的根
void printRoot()
{
 	cout<<"各子树的根："<<endl;
	for (int i = 1; i <= n; ++i)
	{
	 	for (int j = 1; j <= n; ++j)
	 	{
	 		cout<<root[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl; 
} 
 //打印最优二叉查找树的结构
 //打印出[i,j]子树，它是根r的左子树和右子树
void printOptimalBST(int i, int j, int r)
{
 	int rootChild = root[i][j];//子树根节点
	if (rootChild == root[1][n])
	{
		//输出整棵树的根
		cout<<"k"<<rootChild<<"是根"<<endl;
		printOptimalBST(i, rootChild - 1, rootChild);
		printOptimalBST(rootChild + 1, j, rootChild);
		return ; 
	}
	if (j < i - 1)
	{
		return ;
	} 
	else if (j == i - 1)
	{
		if (j < r)
		{
			cout <<"d"<<j<<"是"<<"k"<<r<<"的左孩子"<<endl; 
		}
		else
		{
			cout <<"d"<<j<<"是"<<"k"<<r<<"的右孩子"<<endl;
		}
		return ; 
	}
	else //遇到内部节点
	{
		if (rootChild < r)
		{
			cout <<"k"<<j<<"是"<<"k"<<r<<"的左孩子"<<endl; 
		}
		else
		{
			cout <<"k"<<j<<"是"<<"k"<<r<<"的右孩子"<<endl; 
		} 
	 } 
	printOptimalBST(i, rootChild - 1, rootChild);
	printOptimalBST(rootChild + 1, j, rootChild);
}
int main()
{
	optimalBTS(p, q, n);
	printRoot();
	cout<<"最优二叉树结构："<<endl;
	printOptimalBST(1, n, -1); 
}
   






