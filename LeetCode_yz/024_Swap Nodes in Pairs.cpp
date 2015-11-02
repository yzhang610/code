#include <stdio.h>
#include <stdlib.h>
struct ListNode 
{
	int val;
	ListNode *next;
};
//�������� 
ListNode *createList()
{
	ListNode *head = (ListNode *)malloc(sizeof(ListNode));
	int data;
	printf("�����������е�����: \n");
	scanf("%d", &data);
	ListNode *p = head;
	if (data == -1)
	{
		head->next = NULL;
		return head; 
	}
	if (data != -1)
	{
		p->val = data;
	}
	while (1)
	{
	
		scanf("%d", &data);	
		if (data == -1)
			break;
		ListNode *temp = (ListNode *)malloc(sizeof(ListNode));
		temp->val = data;
		p->next = temp;
		p = p->next;
	}
	p->next = NULL;
	return head;
}
//��ӡ���� 
void printList(ListNode *head)
{
	ListNode *p = head;
	while(p != NULL)
	{
		printf("%d ", p->val);
		p = p->next;
	}
	printf("\n");
}
//�ɶԽ�������ڵ�
ListNode *swapPairs(ListNode *head)
{
	if (head == NULL || head->next == NULL)
		return head;
	ListNode *pre = head->next;
	ListNode *cur = pre->next;
	pre->next = head;
	head->next = cur;
	head = pre;
	pre = pre->next;
	while (pre)
	{
		ListNode *post;
		cur = pre->next;
		if (cur && cur->next)
			post = cur->next;
		else
			break;
		pre->next = post;
		pre = post->next;
		post->next = cur;
		cur->next = pre;
		pre = cur;
	}
	return head;
} 
int main()
{
	ListNode *head, *head1;
	head = createList();
	printList(head); 
	head1 = swapPairs(head);
	printList(head1);
	return 0;
}
