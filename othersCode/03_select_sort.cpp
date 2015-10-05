//选择排序：简单直观排序算法 
//基本步骤 ：
//1、在未排序序列中找到最小（大）元素，存放到排序序列的起始位置
//2、在从剩余未排序元素中继续寻找最小（大）元素，然后放到已排序序列的末尾
//3、以此类推，直到所有元素均排序完毕。 
#include <stdio.h>
void select_sort(int arr[], int len)
{
	int i, j, temp;
	for (i = 0; i < len; i++)
	{
		for (j = i + 1; j < len; j++)
		{
			if (arr[i] > arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}
int main()
{
	int a[8] = {5, 2, 4, 7, 1, 3, 2, 6};
	select_sort(a, 8);
	for (int i = 0; i < 8; i++)
	{
		printf("%d ", a[i]);
	}
}
