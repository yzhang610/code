#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
using namespace std;
struct ListNode
{
	int val;
	ListNode *next;
};
//创建单链表 
ListNode *createList()
{
	ListNode *head = (ListNode *)malloc(sizeof(ListNode));
	ListNode *p = head;
	printf("请输入链表中的数据(以-1结束)):\n");
	int data;
	scanf("%d", &data);
	if (data != -1)
	{
		p->val = data;
	}
	else
	{
		head->next = NULL;
		return head;
	}
	while (1)
	{
		scanf("%d", &data);
		if (data == -1)
			break;
		else
		{
			ListNode *temp = (ListNode *)malloc(sizeof(ListNode));
			temp->val = data;
			p->next = temp;
			p = p->next;	
		} 
	}
	p->next = NULL;
	return head; 
}
//显示单链表 
void printList(ListNode *head)
{
	ListNode *p = head;
	if (p == NULL)
	{
		printf("The list is empty.\n");
		return ;
	}
	while(p!=NULL)
	{
		printf("%d ", p->val);
		p = p->next;
	}
	printf("\n");
}
//合并两个有序单链表
ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
{
	ListNode *head = (ListNode *)malloc(sizeof(ListNode));
	head->val = -1;
	head->next = NULL;
	ListNode *temp = head;
	ListNode *p = l1, *q = l2;
	while(p != NULL && q != NULL)
	{
		if (p->val <= q->val)
		{
			temp->next = p;
			temp = temp->next;
			p = p->next;
		}
		else if (p->val > q->val)
		{
			temp->next = q;
			temp = temp->next;
			q = q->next;
		}
	}
	if (p != NULL)
	{
		temp->next = p;
	}
	else if (q != NULL)
	{
		temp->next = q;
	}
	return head->next;  
} 
//合并k个有序的单链表
ListNode *mergeKLists(vector<ListNode *> &lists)
{
	if (lists.size() == 0)
		return NULL;
	if (lists.size() == 1)
		return lists[0];
	vector<ListNode *> newLists;
	int start = 0;
	if (lists.size() % 2 != 0)
	{
		newLists.push_back(lists[0]);
		start++;
	}
	for (int i = start; i < lists.size(); i += 2)
	{
		ListNode *temp = mergeTwoLists(lists[i], lists[i + 1]);
		newLists.push_back(temp);
	} 
	return mergeKLists(newLists);
} 
int main()
{
	ListNode *head1, *head2, *head3, *head;
	head1 = createList();
	printList(head1);
	head2 = createList();
	printList(head2);
	head3 = createList();
	printList(head3);
	vector<ListNode *> lists;
	lists.push_back(head1);
	lists.push_back(head2);
	lists.push_back(head3);
	head = mergeKLists(lists);
	printList(head);
	return 0;
}

