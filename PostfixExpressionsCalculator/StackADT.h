#pragma once
template<class T>
class StackADT
{
	virtual void initilization(int size)=0;
	virtual bool IsEmpty()=0;
	virtual bool IsFull()=0;
	virtual void Push(T item)=0;
	virtual T Top()=0;
	virtual void Pop()=0;
};

