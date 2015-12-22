#pragma once
#include "list.h"


template<class ValueType>
class Stack
{
private:
	List<ValueType> *list;
public:
	Stack();
	Stack(const Stack<ValueType>*);
	~Stack();
	int IsEmpty(void)const;
	int IsFull(void)const;
	void Push(const ValueType);
	ValueType Pop();
	ValueType GetKey(const ValueType);
};

template<class ValueType>
Stack<ValueType>::Stack();

template<class ValueType>
int Stack<ValueType>::IsEmpty(void)const;

template<class ValueType>
int Stack<ValueType>::IsFull(void)const;

template<class ValueType>
void Stack<ValueType>::Push(const ValueType k);

template<class ValueType>
ValueType Stack<ValueType>::Pop();
