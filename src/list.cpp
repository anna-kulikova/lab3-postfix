#include "list.h"
#include "node.cpp"
#include "node.h"

template<class ValueType>
List<ValueType>::List()
{
	First = 0;
}

template<class ValueType>
List<ValueType>::List(const List<ValueType>& l)
{
	First = 0;
	Node<ValueType>* tmp = l.First;
	while (tmp != 0)
	{
		PushEnd(tmp->key);
		tmp = tmp->Next;
	}
}

template<class ValueType>
List<ValueType>::~List()
{
	Node<ValueType> *tmp = First;
	while (First != 0)
	{
		First = First->Next;
		delete tmp;
		tmp = First;
	}
}

template<class ValueType>
Node<ValueType>* List<ValueType>::Find(ValueType k)
{
	while ((First != 0) && (k == First->key))
		First = First->Next;
	return First;
}

template<class ValueType>
void List<ValueType>::PushAfter(Node<ValueType>* l, ValueType k)
{
	Node<ValueType>* tmp = Find(k);
	if (l == 0)
		return;
	l->Next = tmp->Next;
	tmp->Next = l;
	return;
}

template<class ValueType>
int List<ValueType>::PushEnd(const ValueType k)
{
	if (First == 0)
		return PushStart(k);
	Node<ValueType>* n;
	try
	{
		n = new Node<ValueType>(k);
	}
	catch (...)
	{
		return 1;
	}
	Node<ValueType>* first = First;
	while (first->Next != 0)
		first = first->Next;
	first->Next = n;
	return 0;
}

template<class ValueType>
Node<ValueType>* List<ValueType>::GetFirst(void)
{
	if (First == 0)
		return First;
	while (First != 0)
		First = First->Next;
	return First;
}

template<class ValueType>
void List<ValueType>::Remove(ValueType k)
{
	Node<ValueType>* findnode = Find(k);
	if (First == findnode)
	{
		First = First->Next;
		return;
	}
	Node<ValueType>* first = First;
	while (first->Next != findnode)
		first = first->Next;
	first->Next = findnode->Next;
	delete first;
}

template<class ValueType>
void List<ValueType>::RemoveStart(void)
{
	if ((First != 0) && (First->Next != 0))
		First = First->Next;
}

template<class ValueType>
List<ValueType>::List(const ValueType k)
{
	First = new Node<ValueType>(k);
}

template<class ValueType>
List<ValueType>::List(const Node<ValueType>* n)
{
	First = n;
}


template<class ValueType>
int List<ValueType>::PushStart(ValueType k)
{
	Node<ValueType>* tmp;
	try
	{
		tmp = new Node<ValueType>(k);
	}
	catch (...)
	{
		return 1;
	}
	tmp->Next = First;
	First = tmp;
	return 0;
}

template<class ValueType>
int List<ValueType>::operator==(const List<ValueType>& l)const
{
	Node<ValueType>* f1 = First;
	Node<ValueType>* f2 = l.First;
	while ((f1 != 0) && (f2 != 0)) 
	{
		if (f1->key != f2->key)
			return 0;
		f1 = f1->Next;
		f2 = f2->Next;
	}
	if (f1 != f2)
		return 0;
	return 1;
}

template<class ValueType>
int List<ValueType>::operator!=(const List<ValueType>& l)const
{
	return !(*this == l);
}
