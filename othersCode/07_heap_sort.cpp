//��������top K������ʹ�ñȽ�Ƶ�����������ǲ��ö����������ݽṹʵ�ֵģ���Ȼʵ����
//����һ����ά���顢�������һ��������ȫ������
//����Ѿ����������ʣ�
//1�����ڵ�ļ�ֵ���Ǵ��ڻ���ڣ�С�ڻ���ڣ��κ�һ���ӽڵ�ļ�ֵ��
//2��ÿ���ڵ��������������һ������ѣ��������ѻ���С�ѣ���
//�������裺
//1���������ѣ�Build_Max_Heap�����������±귶ΧΪ0~n�����ǵ�����һ��Ԫ���Ǵ���ѣ�
//���±�n/2��ʼ��Ԫ�ؾ�Ϊ����ѡ�����ֻҪ��n/2-1��ʼ����ǰ���ι������ѣ���������
//��֤�����쵽ĳ���ڵ�ʱ�����������������Ѿ��Ǵ����
//2��������HeapSort�������ڶ���������ģ��ģ��õ�һ������Ѻ������ڲ�����������
//�ġ������Ҫ���ѻ��������򻯡�˼�����Ƴ����ڵ㣬�����������ĵݹ����㡣��һ�ν�
//heap[0]��heap[n-1]�������ٶ�heap[0...n-2]�����ѵ������ڶ��ν�heap[0]��heap[n-2]
//�������ٶ�heap[0...n-3]�����ѵ������ظ��ò���ֱ��heap[0]��heap[1]����������ÿ��
//���ǽ����������뵽������������䣬�ʲ�����������������������ˡ�
//3�����ѵ�����Max_Heapify�����÷���ʱ�ṩ�������������̵��õġ�Ŀ���ǽ��ѵ�ĩ����
//�ڵ���������ʹ���ӽڵ���ԶС�ڸ��ڵ㡣 
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
