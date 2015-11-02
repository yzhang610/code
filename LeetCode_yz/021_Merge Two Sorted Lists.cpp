#include <stdio.h>
#include <stdlib.h> 
struct ListNode
{
	int val;
	ListNode *next;
};
//创建链表操作 
ListNode *createList()
{
	ListNode *head = (ListNode *)malloc(sizeof(ListNode));
	ListNode *p = head;
	int data;
	printf("请输入链表中的值，以-1结束:\n");
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
		{
			break;
		}
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
//打印链表操作 
void printList(ListNode *head)
{
	ListNode *p = head;
	if (p == NULL)
	{
		printf("List is empty!\n");
		return ;
	}
	while(p != NULL)
	{
		printf("%d ", p->val);
		p = p->next;
	}
	printf("\n");
}
//合并两个有序的链表
ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
{
	ListNode *p, *q, *temp;
	p = l1;
	q = l2;
	ListNode *head = (ListNode *)malloc(sizeof(ListNode));
	head->val = -1;
	head->next = NULL;
	temp = head;
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
int main()
{
	ListNode *head1, *head2, *head;
	head1 = createList();
	head2 = createList();
	printList(head1);
	printList(head2);
	head = mergeTwoLists(head1, head2);
	printList(head);
}
