#include <iostream>
using namespace std;

class List
{
	public:
		List()
		{
			create_List();
		}
		~List()
		{
			clear();
		}
		//����ͷ���
		void create_List();
		//���뺯��
		void insert(const int &d);
		//��ָ��λ�ò���
		void insert_pos(const int &d, const int &d1);
		//ɾ��ָ������
		void erase(const int &d);
		//�޸�ָ������ 
		void update(const int &d, const int &d1);
		//��ת������
		void reverse();
		//��ӡ
		void print();
	private:
		//�ڵ�ṹ
		struct Node
		{
			int data;
			Node *next;
			Node(const int &d):data(d),next(NULL)
			{
			}
		};
		Node *head;//ͷ���
		//����������
		void clear()
		{
			Node *p = head;
			while (p)
			{
				Node *q = p->next;
				delete p;
				p = q;
			}
		 }
		 //��������d����һ���ڵ�λ�õĺ���
		 Node *find(const int &d)
		 {
		 	Node *p = head;
		 	for(; p; p = p->next)
		 	{
		 		if(p->next->data == d)
		 			break;
			 }
			 return p;
		  } 
};

//����ͷ���
void List::create_List()
{
	head = new Node(0);
 } 
//ͷ������һ�����
void List::insert(const int &d)
{
	Node *p = new Node(d);
	p->next = head->next;
	head->next = p;
 } 
//��ӡ����
void List::print()
{
	for(Node *p = head->next; p; p = p->next)
	{
		cout<<p->data<<endl;
	}
 } 
//��dλ��֮ǰ����d1
void List::insert_pos(const int& d, const int& d1)
{
	Node *p = find(d);
	Node *q = new Node(d1);
	q->next = p->next;
	p->next = q; 
 } 
//ɾ��
void List::erase(const int& d)
{
	Node *p = find(d);
	Node *q = p->next;
	p->next = p->next->next;
	delete q;
 } 
//�޸�ָ������
void List::update(const int &d, const int &d1)
{
	Node *p = find(d);
	p->next->data = d1;
 } 
//��ת����
void List::reverse()
{
	Node *p = head->next;
	Node *q = head->next->next;
	Node *m = head->next->next->next;
	p->next = NULL;
	while(m)
	{
		q->next = p;
		p = q;
		q = m;
		m = m->next;	
	}
	q->next = p;
	head->next = q;
 } 
int main()
{
	List list;
	list.insert(30);
	list.insert(20);
	list.insert(10);
	list.insert_pos(10, 5);
	list.print();
	cout<<"----------------------"<<endl;
	list.erase(10);
	list.print();
	cout<<"----------------------"<<endl;
	list.reverse();
	list.print();
	cout<<"-----------------------"<<endl;
	list.update(5, 8);
	list.print();
	return 0;
}
