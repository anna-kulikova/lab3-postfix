#pragma once
#include "list.h"

class Stack
{
private:
	List *list;
public:
	Stack();
	Stack(const Stack*);
	~Stack();
	int IsEmpty(void)const;
	int IsFull(void)const;
	void Push(const ValueType);
	ValueType Pop(ValueType);
};
