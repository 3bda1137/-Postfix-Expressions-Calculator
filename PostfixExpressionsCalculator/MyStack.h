#include "StackADT.h"

using namespace std;
#pragma once
template <class T>
class MyStack : public StackADT<T>
{
public:
	MyStack(int sizeOfstack = 50)
	{
		if (sizeOfstack <= 0)
			sizeOfstack = 50;

		initilization(sizeOfstack);
	}
	 void  initilization(int sizeOfstack)override
	{
		this->size = sizeOfstack;
		items = new T[size];
		topOfstack = 0;
	}
	 bool IsEmpty()override
	{
		return this->topOfstack == 0;
	}
	 bool IsFull()override {
		return this->topOfstack == this->size;
	}

	void Push(T item)override
	{
		if (!IsFull())
		{
			this->items[topOfstack] = item;
			this->topOfstack += 1;
		}
		throw runtime_error("Stack is Full");
	}
	T Top()override {
		if (!IsEmpty())
		{
			T topItem = this->items[topOfstack - 1];
			return topItem;
		}
		throw runtime_error("Stack is empty");
	}
	void Pop()override
	{
		if (!IsEmpty())
		{
			this->topOfstack -= 1;
			T topItem = this->items[topOfstack];
		}	
		throw runtime_error("Stack is empty");
	}
	void CopyStack(MyStack<T>& otherStack)
	{
		delete[] items;
		size = otherStack.size;
		topOfstack = otherStack.topOfstack;
			items = new T[size];
		
		for (int j = 0; j < topOfstack; j++)
			items[j] = otherStack.items[j];
	}

private:
	int size;
	T topOfstack;
	T* items;
};