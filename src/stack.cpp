#include "stack.h"

template<class ValueType>
Stack<ValueType>::Stack()
{
	list = new List<ValueType>;
}

template<class ValueType>
Stack<ValueType>::~Stack()
{
	delete list;
}

template<class ValueType>
Stack<ValueType>::Stack(const Stack<ValueType>* stack)
{

}

template<class ValueType>
int Stack<ValueType>::IsEmpty(void)const
{
	return(list->GetFirst() == 0);
}

template<class ValueType>
int Stack<ValueType>::IsFull(void)const
{
	Node<ValueType> *tmp;
	try
	{
		tmp = new Node<ValueType>;
	}
	catch (...)
	{
		return 1;
	}
	delete tmp;
	return 0;
}

template<class ValueType>
void Stack<ValueType>::Push(const ValueType key)
{
	if (IsFull())
		throw
		exception("Stack is full");
	list->PushStart(key);
}

template<class ValueType>
ValueType Stack<ValueType>::Pop()
{
	if (IsEmpty())
		throw
		exception("Stack is empty");
	ValueType tmp = list->GetFirst()->key;
	list->Remove(tmp);
	return tmp;
}
