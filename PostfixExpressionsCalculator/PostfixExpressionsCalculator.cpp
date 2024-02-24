
#include <iostream>
#include "MyStack.h"
using namespace std;
int main()
{
	MyStack<int> t(10);
	t.Push(1);
	t.Push(4);
	cout << t.Top() << endl;
}