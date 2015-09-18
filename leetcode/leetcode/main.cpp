
//***********************4***********************************************************
/*
1、
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution
{
public:
	double findMedianSortedArrays(int A[], int m, int B[], int n)
	{
		int *a=new int[m+n];
		memcpy(a,A,sizeof(int)*m);
		memcpy(a+m,B,sizeof(int)*n);
		sort(a,a+n+m);
		double median=(double)((n+m)%2?a[(m+n)/2]:(a[(m+n-1)/2]+a[(m+n)/2])/2.0);
		delete a;
		return median;
	}
};
int main()
{
	int A[5]={1,2,3,5,7};
	int B[2]={2,7};
	Solution t;
	double result=t.findMedianSortedArrays(A,5,B,2);
	cout<<result<<endl;
	return 0;
}
*/
/*
2、
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution
{
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
	{
		int m=nums1.size();
		int n=nums2.size();
		vector<int> sum;
		for(int i=0;i<m;i++)
		{
			sum.push_back(nums1[i]);
		}
		for(i=0;i<n;i++)
		{
			sum.push_back(nums2[i]);
		}
		sort(sum.begin(),sum.end());
		return (m+n)%2?(double)sum.at((m+n)/2):(sum.at((m+n-1)/2)+sum.at((m+n)/2))/2.0;
	}
};
int main()
{
	int *A=new int [0];
	vector<int> a(A,A+0);
	int B[]={2,3};
	vector<int> b(B,B+2);
	Solution t;
	double result=t.findMedianSortedArrays(a,b);
	cout<<result<<endl;
	return 0;
}
*/
/*
#include<iostream>
using namespace std;
double findKth(int a[],int m,int b[],int n,int k)
{
	if(m>n)
		return findKth(b,n,a,m,k);
	if(m==0)
		return b[k-1];
	if(k==1)
		return (a[0]>b[0]?b[0]:a[0]);
	int pa=k/2>m?m:k/2,pb=k-pa;
	if(a[pa-1]<b[pb-1])
		return findKth(a+pa,m-pa,b,n,k-pa);
	else if(a[pa-1]>b[pb-1])
		return findKth(a,m,b+pb,n-pb,k-pb);
	else
		return a[pa-1];
}
class Solution
{
public:
	double findMedianSortedArrays(int A[],int m,int B[],int n)
	{
		int total=m+n;
		if(total&0x1)
			return findKth(A,m,B,n,total/2+1);
		else
			return (findKth(A,m,B,n,total/2)+findKth(A,m,B,n,total/2+1))/2.0;
	}
};
int main()
{
	int A[5]={1,2,3,5,7};
	int B[3]={2,4,7};
	Solution t;
	double result=t.findMedianSortedArrays(A,5,B,3);
	cout<<result<<endl;
	return 0;
}*/
//************************************* 4 end ***********************************************************

//*************************************5 start***********************************************************
/*1
#include<iostream>
#include<string>
using namespace std;
class Solution
{
public:
	string SearchAround(string s,int c1,int c2)
	{
		int front=c1,rear=c2;
		int n=s.length();
		while(front>=0&&rear<n&&s[front]==s[rear])
		{
			front--;
			rear++;
		}
		return s.substr(front+1,rear-front-1);
	}
	string longestPalindrome(string s)
	{
		int n=s.length();
		if(n==0)
			return "";
		string longstring=s.substr(0,1);
		for(int i=0;i<n-1;i++)
		{
			string s1=SearchAround(s,i,i);
			if(s1.length()>longstring.length())
			{
				longstring=s1;
				
			}
			string s2=SearchAround(s,i,i+1);
			if(s2.length()>longstring.length())
			{
				longstring=s2;
			}
		}
		return longstring;
	}	
};
void main()
{
	string s="ababdbdbdbd";
	Solution sou;
	string t;
	t=sou.longestPalindrome(s);
	cout<<t<<endl;
}
*/
/*
#include<iostream>
#include<string>
using namespace std;
const int MAX=110000+10;
char s[MAX*2];
int p[MAX];
int main()
{
	while(scanf("%s",s)!=EOF)
	{
		int len=strlen(s);
		int id=0,maxlen=0;
		for(int j=len;j>=0;--j)
		{
			s[j+j+2]=s[j];
			s[j+j+1]='#';
		}
		s[0]='*';
		for(int i=2;i<2*len+1;i++)
		{
			if(p[id]+id>i)
				p[i]=(s[2*id-i])>(p[id]-(i-id))?(p[id]+id-i):(s[2*id-i]);
			else
				p[i]=1;
			while(s[i-p[i]]==s[i+p[i]])
				++p[i];
			if(id+p[id]<i+p[i])
				id=i;
			if(maxlen<p[i])
				maxlen=p[i];
		}
		cout<<maxlen-1<<endl;
		cout<<id<<endl;
	}
	return 0;
}
*/
//*************************************5  end ***********************************************************
//*************************************6 start***********************************************************
/*
#include<iostream>
#include<string>
using namespace std;
class Solution
{
public:
	string convert(string s, int numRows)
	{
		int length = s.length();
		if(length == 0 || numRows <= 0)
			return "";
		if(numRows == 1)
			return s;
		if(length <= numRows)
			return s;
		string t;
		int period = 2*numRows-2;
		for(int i = 0; i < numRows; i++)
		{
			for(int j = i; j < length; j += period)
			{
				t += s[j];
				if(i != 0 && i != numRows - 1 && j + period -2*i < length)
					t += s[(j + period - 2*i)];
			}
		}
		cout<<t<<endl;
		return t;
	}
};
void main()
{
	string str = "abcd";
	Solution sol;
	int n = 3;
	sol.convert(str, n);
	return;
}
*/
//*************************************6  end ***********************************************************
//*************************************7 start***********************************************************
/*
#include<iostream>
#include<cmath>
using namespace std;
int reverse(int x)
{
	long result=0, temp;
	while(x != 0)
	{
		temp = x%10;
		result = result*10 + temp;
		x = x/10;
	}
	if(result <= INT_MAX || result >= INT_MIN)
		return (int)result;
	else
		return 0;
}
int main()
{
	int x=1534236469;
	int t=reverse(x);
	cout<<t<<endl;
	cout<<INT_MAX<<"&&&"<<"2147483647"<<endl;
	cout<<INT_MIN<<"***"<<"-2147483648"<<endl;
	return 0;
}
*/
//*************************************6  end ***********************************************************
//*************************************7 start***********************************************************
//存在问题数组越界问题，在我这里不出现错误了，但leetcode不能通过
/*#include<iostream>
using namespace std;

int myAtoi(char* str) {
    long num=0;
    int flag=1;
    int i=0;
    while(str[i]==' '&&str[i]!='\0')
        i++;
    if(str[i]=='-'||str[i]=='+')
    {
        if(str[i]=='-')
            flag=-1;
        i++;
    }
    if(str[i]>'9'||str[i]<'0')
        return 0;
    while(str[i]=='0'&&str[i]!='\0')
        i++;
    while(str[i]!='\0'&&(str[i]>='0'&&str[i]<='9'))
    {
        num=num*10+str[i]-'0';
        i++;
		if(flag==-1&&num<0)
			return -2147483648;
		if(flag==1&&num<0)
			return 2147483647;
    }
    return flag*num;
}
int main()
{
    char *s="2147483648";
    int t;
    t=myAtoi(s);
	printf("转换后为:%d\t",t);
    return 0;
}*/
//*************************************7  end ***********************************************************
//*************************************8 start***********************************************************
/*
#include<iostream>
using namespace std;
bool isPalindrome(int x) 
{
	if(x<0)
		return false;
	int d=1;
	int t=x;
	while(t>=10)
	{
		d=d*10;
		t=t/10;
	} 
	while(x)
	{
		if(x/d!=x%10)
			return false;
		x=x%d/10;
		d=d/100;
	}
	return true;
}
void main()
{
	int x=1021;
	bool flag;
	flag=isPalindrome(x);
	if(flag==true)
		cout<<"是"<<endl;
	else
		cout<<"不是"<<endl;
}
*/
//*************************************8  end ***********************************************************
//*************************************9 start***********************************************************
/*
#include<iostream>
using namespace std;
bool isMatch (char* s, char* p) 
{
	if (s == NULL || p == NULL)
		return false;
	if (*p == '\0')
		return *s == '\0';
	if (*(p + 1) == '*')
	{
		while ((*s != '\0' && *p =='.') || *s == *p)
		{
			if (isMatch(s, p+2)) 
				return true;
			++s;
		}
		return isMatch (s, p+2);
	}
	else if ((*s != '\0' && *p == '.') || *s == *p)
	{
		return isMatch (s+1, p+1);
	}
	return false;
}
void main()
{
	char *s = "aaaaaaaab";
	char *p = "c*a*b";
	bool result = isMatch (s, p);
	if (result == true)
		cout<<"匹配"<<endl;
	else
		cout<<"不匹配"<<endl;
}
*/
//*************************************9  end ***********************************************************
//************************************10 start***********************************************************
/*
#include<iostream>
#include<cmath>
using namespace std;
//时间复杂度为n
int maxArea(int* height, int heightSize) 
{
	int i, j;
	int maxarea = 0;
	int area;
	for(i = 0, j = heightSize - 1 ; i < heightSize && i < j;)
	{
		area = (*(height + i) < *(height + j) ? *(height + i) : *(height + j)) * (j - i);
		if( area > maxarea)
			maxarea = area;
		if(*(height + i) > *(height + j))
			j--;
		else
			i++;
	}
	return maxarea;
}
//时间复杂度为n*n
int maxArea1(int* height, int heightSize) 
{
	int i, j;
	int maxarea = 0;
	int area;
	for(i = heightSize - 1; i >=0; i--)
	{
		for(j = 0; j < i; j++)
		{
			area = (*(height + i) < *(height + j) ? *(height + i) : *(height + j)) * (i - j);
			if(area > maxarea)
				maxarea = area;
		}
	}
	return maxarea;
}
void main()
{
	int *a = (int *)malloc(10 * sizeof(int));
	int a1[5]={2, 5, 3, 8, 2};
	a = a1;
	int t = maxArea(a, 5);
	cout<<maxArea1(a, 5)<<endl;
}
*/
//*************************************10  end ***********************************************************
//*************************************11 start***********************************************************
/*
#include<iostream>
#include<string>
using namespace std;
class Solution
{
public:
	string intToRoman(int num)
	{
		int nums[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
		string romans[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
		string s;
		int i;
		for(i = 0; num > 0; ++i)
		{
			int count = num / nums[i];
			num %= nums[i];
			for(; count > 0; count --)
				s += romans[i];
		}
		return s;
	}
};
void main()
{
	int i;
	cout<<"请输入(1-3999)之间的一个数:"<<endl;
	cin>>i;
	Solution s;
	cout<<s.intToRoman(i)<<endl;

}
*/
//*************************************11  end ***********************************************************
//*************************************12 start***********************************************************
#include<iostream>
#include<string>
using namespace std;
class Solution
{
public:
	int romanToInt(string s)
	{
		int sum = 0;
		for(int i = 0; s[i] != '\0'; i++)
		{
			if(s[i] == 'M')
			{
				sum += 1000;
				continue;
			}
			if(s[i] == 'D')
			{
				sum += 500;
				continue;
			}
			if(s[i] == 'L')
			{
				sum += 50;
				continue;
			}
			if(s[i] == 'V')
			{
				sum += 5;
				continue;
			}
			if(s[i] == 'C')
			{
				if(s[i+1] == 'M')
				{
					sum += 900;
					i++;
				}
				else if(s[i+1] == 'D')
				{
					sum += 400;
					i++;
				}
				else
					sum += 100;
				continue;
			}
			if(s[i] == 'X')
			{
				if(s[i+1] == 'C')
				{
					sum += 90;
					i++;
				}
				else if(s[i+1] == 'L')
				{
					sum += 40;
					i++;
				}
				else
					sum += 10;
				continue;
			}
			if(s[i] == 'I')
			{
				if(s[i+1] == 'X')
				{
					sum += 9;
					i++;
				}
				else if(s[i+1] == 'V')
				{
					sum += 4;
					i++;
				}
				else
					sum += 1;
				continue;
			}
			cout<<sum<<endl;
		}
		return sum;
	}
};
int main()
{
	Solution s;
	string str = "DCXXI";
	int t = s.romanToInt(str);
	cout<<t<<endl;
	return 0;
}
