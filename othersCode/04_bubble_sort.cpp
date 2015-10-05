//冒泡排序：原理非常简单，它重复地走访过要排序的序列，一次比较两个元素，
//          如果他们顺序错误，就把它们交换过来
//基本步骤：
//1、比较相邻的元素，如果第一个比第二个大，就交换他们两个
//2、对第0个到第n-1个数据做同样的工作，这时，最大的数就“浮”到了数组最后的位置上
//3、针对所有元素重复以上步骤，除了最后一个
//4、持续每次对越来越少的元素重复上面的步骤，直到没有任何一对数字需要比较。 
#include <stdio.h>
void bubble_sort(int *a, int n)
{
	int i, j, temp = 0, flag = 0;
	for (i = 0; i < n - 1; i++)
	{
		flag = 0;
		for (j = n - 1; j > i; j--)
		{
			if (a[j] < a[j - 1])
			{
				temp = a[j];
				a[j] = a[j - 1];
				a[j - 1] = temp;
				flag = 1;
			}
		}
		if (flag == 0)
		break;
	}
}
int main()
{
	int i = 0; 
	int a[10] = {5, 4, 9, 8, 7, 6, 0, 1, 3, 2};
	bubble_sort(a, 10);
	for (i; i < 10; i++)
		printf("%d ", a[i]);
	return 0;
 } 
