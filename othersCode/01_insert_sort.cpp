//���������㷨����
//1���ӵ�һ��Ԫ�ؿ�ʼ����Ԫ�ؿ�����Ϊ�Ѿ�������
//2��ȡ����һ��Ԫ�أ����Ѿ������Ԫ�������дӺ���ǰɨ��
//3�������Ԫ�أ������򣩴�����Ԫ�أ�����Ԫ���Ƶ���һ��λ��
//4���ظ�����3��ֱ���ҵ��������Ԫ��С�ڻ��ߵ�����Ԫ�ص�λ��
//5��ǿ��Ԫ�ز嵽��λ����
//6���ظ�����2~5 
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
