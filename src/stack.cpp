#include "stack.h"

Stack::Stack()
{
	list = new List;
}

int Stack::IsEmpty(void)const
{
	return(list->GetFirst() == 0);
}

int Stack::IsFull(void)const
{
	Node *tmp;
	try
	{
		tmp = new Node;
	}
	catch (...)
	{
		return 1;
	}
	delete tmp;
	return 0;
}

void Stack::Push(const ValueType key)
{
	if (IsFull())
		throw
		exception("Stack is full");
	list->PushStart(key);
}

ValueType Stack::Pop(ValueType key)
{
	if (IsEmpty())
		throw
		exception("Stack is empty");
	ValueType tmp = list->GetFirst()->key;
	list->Remove(key);
	return tmp;
}

