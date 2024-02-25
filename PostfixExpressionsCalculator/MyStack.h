#include "StackADT.h"
#include "Node.h"

using namespace std;
#pragma once
template <class T>
class MyStack : public StackADT<T>
{
public:
	MyStack()
	{
		this->topOfStack = NULL;
		
	}
	void  Initilization()override
	{
		while (this->IsEmpty())
		{
			Node<T>* temp;
			temp = this->topOfStack;
			this->topOfStack = this->topOfStack->link;
			delete temp;
		}
	}
	bool IsEmpty()override
	{
		return this->topOfStack == NULL;
	}
	bool IsFull()override
	{
		return false;
	}

	void Push(T newItem)override
	{
		Node<T>* newNode = new Node<T>;
		newNode->data = newItem;
		newNode->link = this->topOfStack;
		this->topOfStack = newNode;
	}
	T Top()override {
		if (!IsEmpty())
		{
			return this->topOfStack->data;
		}
		else
			throw runtime_error("Stack is empty");
	}
	void Pop()override
	{
		if (!IsEmpty())
		{
			Node<T>* temp;
			temp = this->topOfStack;
			this->topOfStack = this->topOfStack->link;
			delete temp;

		}
		else
			throw runtime_error("Stack is empty");
	}

private:
	Node<T>*topOfStack;
	
	//T* items;
};