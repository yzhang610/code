//快速排序通常明显比同为O(nlogn)的其他算法更快，因此常被采用，而且快排采用了分治法的思想， 
//所以在很多笔试面试中能经常看到快排的影子。
//基本步骤：
//1、从数列中挑出一个元素作为基准数
//2、分区过程，将比基准数大的放到右边，小于或等于它的数都放到左边
//3、再对左右区间递归执行第二步，直到各区间只有一个数。 
#include <stdio.h>
int partition(int *arr, int low, int high)
{
	int pivot = arr[high];
	int i = low - 1;
	int j, tmp;
	for (j = low; j < high; ++j)
	{
		if (arr[j] < pivot)
		{
			tmp = arr[++i];
			arr[i] = arr[j];
			arr[j] = tmp;
		}
	}
	tmp = arr[i + 1];
	arr[i + 1] = arr[high];
	arr[high] = tmp;
	return i + 1;
}
void quick_sort(int *arr, int low, int high)
{
	if (low < high)
	{
		int mid = partition(arr, low, high);
		quick_sort(arr, low, mid - 1);
		quick_sort(arr, mid + 1, high);
	}
}
int main()
{
	int arr[10] = {1, 4, 6, 2, 5, 8, 7, 6, 9, 12};
	quick_sort(arr, 0, 9);
	int i;
	for (i = 0; i < 10; ++i)
	{
		printf("%d ", arr[i]);
	} 
}
