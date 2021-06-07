#include <iostream>
using namespace std;

class A
{
	public:
	    A()
	    {
	        cout << "constructor of class A" << endl;
	    }
		void fnc()
		{
			cout << "This is class A" << endl;
		}
};
class B: public A
{
	int a;
	public:
	    B()
	    {
	        cout << "constructor of class B" << endl;
	    }
		void fnc()
		{
			cout << "This is class B" << endl;
		}
};

class C: public B
{
	public:
	    C()
	    {
	        cout << "constructor of class C" << endl;
	    }
		void fnc()
		{
			cout <<"This is class C" << endl;
		}
};

int main()
{
	C obj;
// 	obj.fnc();
// 	obj.B::fnc();
// 	obj.A::fnc();
	cout << sizeof(obj);
	
}