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
	ListNode *head, *current, *p;
	int data;
	head = (ListNode *)malloc(sizeof(ListNode));
	p = head;
	printf("请输入链表中的数据:\n");
	scanf("%d", &data);
	if (data != -1)
	{
		p->val = data;
	}
	else
	{
		head->next = NULL; //只有头结点
		return head; 
	}
	while (1)
	{
		scanf("%d", &data);
		if (data == -1)
			break;
		current = (ListNode *)malloc(sizeof(ListNode));
		current->val = data;
		p->next = current;
		p = p->next;
	}
	p->next = NULL;
	return head;
}
//打印链表
void printList(ListNode *head) 
{
	ListNode *p =head;
	if (p == NULL)
	{
		printf("List is empty!\n");
		return ;
	}
	while (p != NULL)
	{
		printf("%d ", p->val);
		p = p->next;
	}
	printf("\n");
}
//删除倒数第n个数，基本想法是一次遍历链表，当链表长度为n是开始利用pre和cur指针记录相差n大小得两个节点，并继续向后扫描即可。 
ListNode * removeNthFromEnd(ListNode *head, int n)
{
    ListNode *p = head;
 	ListNode *pre = NULL; 
 	ListNode *cur = NULL;
 	int i = 0;
 	while (p != NULL)
 	{
 		if (i == n - 1)
 		{
 			pre = head;
 			cur = head;
 		}
 		if (i == n)
 		{
 			pre = head;
 			cur = head->next;
 		}
 		if (i > n)
 		{
 			pre = pre->next;
 			cur = cur->next;
 		}
 		p = p->next;
 		i++;	
 	}
 	if (i == 1 && pre == head)
 	{
 		return NULL;
 	}
 	else if (i == n && pre == head)
 	{
 		head = head->next;
 		free(pre);
 		return head; 
 	}
 	if (i > n)
 	{
 		pre->next = cur->next;
 		free(cur);
 		return head;
 	}
}
int main()
{
	ListNode *head, *change;
	head = createList();
	printList(head);
	change = removeNthFromEnd(head, 2);
	printList(change);
}
