//ѡ�����򣺼�ֱ�������㷨 
//�������� ��
//1����δ�����������ҵ���С����Ԫ�أ���ŵ��������е���ʼλ��
//2���ڴ�ʣ��δ����Ԫ���м���Ѱ����С����Ԫ�أ�Ȼ��ŵ����������е�ĩβ
//3���Դ����ƣ�ֱ������Ԫ�ؾ�������ϡ� 
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
