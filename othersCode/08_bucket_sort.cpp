//Ͱ���򣺽�����ֵ�����������Ͱ���Ȼ���ÿ��Ͱ���ڷֱ������п�����ʹ�ñ��
//�����㷨�����Եݹ鷽ʽ����ʹ��Ͱ����������򣩣���󽫸���Ͱ�е���������ĺϲ���
//�������裺
//1������������һ����ͳһ�ķֲ���һ����Χ�У�������һ��Χ���ֳɼ����ӷ�Χ��Ҳ����Ͱ
//2�����������һ�������ֵ�������Щ��Ͱ������Ͱ�е����ݽ�������
//3��������Ͱ�ӵ���������ĺϲ�����
#include <iostream>
#include <list>
using namespace std;
struct Node
{
	double value;
	Node *next;
};
void bucket_sort(double *arr, int length)
{
	Node key[10];
	int number = 0;
	Node *p, *q;//����ڵ���ʱ����
	int counter = 0;
	for (int i = 0; i < 10; i++)
	{
		key[i].value = 0;
		key[i].next = NULL;
	}
	for (int i = 0; i < length; i++)
	{
		Node *insert = new Node();
		insert->value = arr[i];
		insert->next = NULL;
		number = arr[i] * 10;
		if (key[number].next == NULL)
		{
			key[number].next = insert;
		}
		else
		{
			p = &key[number];
			q = key[number].next;
			while((q != NULL) && (q->value <= arr[i]))
			{
				q = q->next;
				p = p->next;
			}
			insert->next = q;
			p->next = insert;
		 } 
	}
	for (int i = 0; i < 10; i++)
	{
		p = key[i].next;
		if (p == NULL)
			continue;
		while (p != NULL)
		{
			arr[counter++] = p->value;
			p = p->next;
		}
	}
}
int main()
{
	double a[] = {0.78, 0.17, 0.39, 0.26, 0.72, 0.94, 0.21, 0.12, 0.23, 0.68};
	bucket_sort(a, 10);
	for (int i = 0; i < 10; i++)
	{
		cout<<a[i]<<" "; 
	}
	cout<<endl;
	return 0;
}
