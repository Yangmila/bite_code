#include <iostream.h>
#include <stdlib.h>
template <class T>
class stack
{
  public:
	  stack (int size);
	  ~stack ()
	  { delete [] stck; }
	  void push (T i);
	  T pop ();
  private:
	  int tos, length;
	  T *stck;
};

template <class T>
stack <T>::stack (int size)
{
	stck=new T[size];
    if (!stck)
	{
		cout<<"Cannot allocate stack.\n";	exit (1);
	}
	length=size;
	tos=0;
}

template <class T>
void stack <T>::push (T i)
{
	if (tos==length)
		cout<<"Stack is full. \n";
	stck [tos]=i;
	tos++;
}

template <class T>
T stack <T>::pop ()
{
	if (tos==0)
		cout<<"Stack underflow. \n";
	tos--;
	return stck[tos];
}

void main ()
{
	stack <int>  a(10);
	stack <double>  b(10);
	stack <char>  c(10);
	a.push (15);
	b.push (18-1.5);
	a.push (18);
	a.push (8+6);
	b.push (2*1.5);
	cout<<a.pop ()<<',';
	cout<<a.pop ()<<',';
	cout<<a.pop ()<<',';
	cout<<b.pop ()<<',';
	cout<<b.pop ()<<endl;
	for(int i (0); i<10; i++)
		c.push ('j'-i);//'j'=109
	for (i=0; i<10; i++)
		cout<<c.pop ();
	cout<<endl;
}
