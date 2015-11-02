#include <stdio.h>
#include <stdlib.h>
struct ListNode
{
	int val;
	ListNode *next;
};
//����������� 
ListNode *createList()
{
	ListNode *head, *current, *p;
	int data;
	head = (ListNode *)malloc(sizeof(ListNode));
	p = head;
	printf("�����������е�����:\n");
	scanf("%d", &data);
	if (data != -1)
	{
		p->val = data;
	}
	else
	{
		head->next = NULL; //ֻ��ͷ���
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
//��ӡ����
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
//ɾ��������n�����������뷨��һ�α���������������Ϊn�ǿ�ʼ����pre��curָ���¼���n��С�������ڵ㣬���������ɨ�輴�ɡ� 
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
