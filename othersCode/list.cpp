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
		//创建头结点
		void create_List();
		//插入函数
		void insert(const int &d);
		//在指定位置插入
		void insert_pos(const int &d, const int &d1);
		//删除指定数据
		void erase(const int &d);
		//修改指定数据 
		void update(const int &d, const int &d1);
		//反转链表函数
		void reverse();
		//打印
		void print();
	private:
		//节点结构
		struct Node
		{
			int data;
			Node *next;
			Node(const int &d):data(d),next(NULL)
			{
			}
		};
		Node *head;//头结点
		//清理链表函数
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
		 //查找数据d的上一个节点位置的函数
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

//创建头结点
void List::create_List()
{
	head = new Node(0);
 } 
//头结点插入一个结点
void List::insert(const int &d)
{
	Node *p = new Node(d);
	p->next = head->next;
	head->next = p;
 } 
//打印函数
void List::print()
{
	for(Node *p = head->next; p; p = p->next)
	{
		cout<<p->data<<endl;
	}
 } 
//在d位置之前插入d1
void List::insert_pos(const int& d, const int& d1)
{
	Node *p = find(d);
	Node *q = new Node(d1);
	q->next = p->next;
	p->next = q; 
 } 
//删除
void List::erase(const int& d)
{
	Node *p = find(d);
	Node *q = p->next;
	p->next = p->next->next;
	delete q;
 } 
//修改指定数据
void List::update(const int &d, const int &d1)
{
	Node *p = find(d);
	p->next->data = d1;
 } 
//反转链表
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
