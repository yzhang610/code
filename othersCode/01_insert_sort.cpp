//插入排序算法描述
//1、从第一个元素开始，该元素可以认为已经被排序
//2、取出下一个元素，在已经排序的元素序列中从后向前扫描
//3、如果该元素（已排序）大于新元素，将该元素移到下一个位置
//4、重复步骤3，直到找到已排序的元素小于或者等于新元素的位置
//5、强新元素插到该位置中
//6、重复步骤2~5 
#include <stdio.h>
void insert_sort(int arr[], int n)
{
	int i, j;
	int temp = 0;
	for (i = 1; i < n; i++)
	{
		temp = arr[i];
		for (j = i; j > 0 && temp < arr[j - 1]; j--)
		{
			if (temp < arr[j - 1])
			{
				arr[j] = arr[j -1];
			}
		}
		arr[j] = temp;
	}
}
int main()
{
	int i;
	int arr[5] = {20, 30, 24, 40, 35};
	insert_sort(arr, 5);
	for (i = 0; i < 5; i++)
	{
		printf("%4d ", arr[i]);
	}
}
