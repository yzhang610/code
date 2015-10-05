//桶排序：将数组分到有限数量的桶子里，然后对每个桶子在分别排序（有可能在使用别的
//排序算法或是以递归方式继续使用桶排序进行排序），最后将各个桶中的数据有序的合并。
//基本步骤：
//1、假设待排序的一组数统一的分布在一个范围中，并将这一范围划分成几个子范围，也就是桶
//2、将带排序的一组数，分档归入这些子桶，并将桶中的数据进行排序
//3、将各个桶子的数据有序的合并起来
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
	Node *p, *q;//插入节点临时变量
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
