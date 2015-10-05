//归并排序：是建立在归并操作上的一种有效的排序算法。该算法是采用分治法的一个非常典型的应用。
//算法步骤：
//1、申请空间，是其大小为两个已经排序序列之和，该空间用来存放合并后的序列
//2、设定两个指针，最初位置分别为两个已经排序序列的其实位置
//3、比较两个指针所指向的元素，选择相对较小的元素放入并合并空间，并移动指针到下一个位置
//4、重复步骤3，直到某一指针达到序列尾
//5、将另一个序列剩下的所有元素直接复制到合并序列尾
#include <stdio.h>
#include <stdlib.h>
#define MAX_INT ~(1<<31)//最大整数
void merge(int *arr, int p, int q, int r)
{
	if (arr == NULL)
		return ;
	int n1 = q - p + 1;
	int n2 = r - q;
	int *L = (int *)malloc((n1 + 1) * sizeof(int));
	int *R = (int *)malloc((n2 + 1) * sizeof(int));
	int i, j;
	for (i = 0; i < n1; ++i)
		L[i] = arr[p + i];
	for (j = 0; j < n2; ++j)
		R[j] = arr[q + j + 1];
	//哨兵元素赋值
	L[n1] = MAX_INT;
	R[n2] = MAX_INT;
	int k;
	i = 0, j = 0;
	for (k = p; k <= r; ++k)
	{
		if (L[i] <= R[j])
			arr[k] = L[i++];
		else
			arr[k] = R[j++];
	 } 
	 free(L);
	 free(R);
}  
void merge_sort(int *arr, int p, int r)
{
	if (p < r)
	{
		int q = (r + p) / 2;
		merge_sort(arr, p, q);//分治操作 
		merge_sort(arr, q + 1, r);
		merge(arr, p, q, r);//合并结果 
	}
}
int main()
{
	int arr[8] = {32, 3, 4, 5, 6, 7, 9, 106};
	merge_sort(arr, 0, 7);
	for (int i = 0; i < 8; i++)
		printf("%d ", arr[i]);
	return 0; 
}
