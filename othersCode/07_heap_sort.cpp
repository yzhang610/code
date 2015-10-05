//堆排序在top K问题中使用比较频繁。堆排序是采用二叉树的数据结构实现的，虽然实质上
//还是一个二维数组、二叉堆是一个近似完全二叉树
//二叉堆具有以下性质：
//1、父节点的键值总是大于或等于（小于或等于）任何一个子节点的键值。
//2、每个节点的左右子树都是一个二叉堆（都是最大堆或最小堆）。
//基本步骤：
//1、构造最大堆（Build_Max_Heap）：若数组下标范围为0~n，考虑到单独一个元素是大根堆，
//则下标n/2开始的元素均为大根堆。于是只要从n/2-1开始，向前依次构造大跟堆，这样就能
//保证，构造到某个节点时，它的左右字数都已经是大根堆
//2、堆排序（HeapSort）：由于堆是用数组模拟的，得到一个大根堆后，数组内部并不是有序
//的。因此需要将堆化数组有序化。思想是移除根节点，并做最大调整的递归运算。第一次将
//heap[0]与heap[n-1]交换，再对heap[0...n-2]做最大堆调整。第二次将heap[0]与heap[n-2]
//交换，再对heap[0...n-3]做最大堆调整。重复该操作直至heap[0]和heap[1]交换。由于每次
//都是讲最大的数并入到后面的有序区间，故操作完后整个数组就是有序的了。
//3、最大堆调整（Max_Heapify），该方法时提供给上述两个过程调用的。目的是将堆的末端子
//节点作调整，使得子节点永远小于父节点。 
#include <stdio.h>
#include <stdlib.h>
#define PARENT(i) (i)/2
#define LEFT(i) 2*(i)+1
#define RIGHT(i) 2*(i+1)
void swap(int *a, int *b)
{
	*a = *a ^ *b;
	*b = *a ^ *b;
	*a = *a ^ *b;
}

void max_heapify(int *arr, int index, int len)
{
	int l = LEFT(index);
	int r = RIGHT(index);
	int largest;
	if (l < len && arr[l] > arr[index])
		largest = l;
	else
		largest = index;
	if (r < len && arr[r] > arr[largest])
		largest = r;
	if (largest != index)
	{
		swap(&arr[largest], &arr[index]);
		max_heapify(arr, largest, len);
	} 
} 

void build_maxheap(int *arr, int len)
{
	int i;
	if (arr == NULL || len <= 1)
		return ;
	for (i = len/2 + 1; i >= 0; --i)
		max_heapify(arr, i, len);
}

void heap_sort(int *arr, int len)
{
	int i;
	if (arr == NULL || len <= 1)
		return ;
	build_maxheap(arr, len);
	for (i = len - 1; i >= 1; --i)
	{
		swap(&arr[0], &arr[i]);
		max_heapify(arr, 0, --len);
	}
}

int main()
{
	int arr[10] = {1, 4, 6, 2, 5, 8, 7, 6, 9, 12};
	int i;
	heap_sort(arr, 10);
	for (i = 0; i < 10; ++i)
		printf("%d ", arr[i]);
	return 0;
}
