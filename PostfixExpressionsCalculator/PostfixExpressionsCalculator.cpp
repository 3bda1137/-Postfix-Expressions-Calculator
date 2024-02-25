
#include <iostream>
#include "MyStack.h"
using namespace std;
int main()
{
	MyStack<int> t;
	t.Push(1);
	t.Push(2);
	t.Push(3);
	t.Push(4);
	t.Push(5);
	t.Push(6);
	while (!t.IsEmpty())
	{
		cout << t.Top() << " ";
		t.Pop();
	}
}