/*#include <iostream>
using namespace std;
class A
{
	public:
		int num;
	public:
		static A *Construct(int n)
		{
			A *pa = new A;
			pa->num = n;
			cout<<"num is:"<<pa->num<<endl;
			return pa;
		}
		static void Destruct(A *pInstance)
		{
			delete pInstance;
			pInstance = NULL;
		}
		private:
			A(){
			}
			~A()
			{
			}
};
int main()
{
	A *f = A::Construct(9);
	cout<<f->num<<endl;
	A::Destruct(f);
	return 0;
}*/
/*#include <iostream>
using namespace std;
template <typename T> class Base
{
	friend T;
	private:
		Base()
		{
		}
		~Base()
		{
		}
};
class Finalclass:virtual public Base<Finalclass>
{
	public:
		Finalclass()
		{
		}
		~Finalclass()
		{
		}
};
int main()
{
	Finalclass *p =new Finalclass;  // 堆上对象
	Finalclass fs;                  // 栈上对象 
}*/
#include <iostream>
using namespace std;
template <typename T> class Base
{
	friend T;
	private:
		Base()
		{
		}
		~Base()
		{
		}
};
class CXXX
{
	public:
		CXXX()
		{
			cout<<"I am CXXX"<<endl;
		}
		~CXXX()
		{
		}
};
class CParent:virtual public Base<CParent>, public CXXX
{
	public:
		CParent()
		{
		}
		~CParent()
		{
		}
};
class CChild:public CParent
{
};
int main()
{
	CParent a;   //可以构造 
//	CChild b;    //不可以构造 
}

