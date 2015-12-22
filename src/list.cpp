#include "list.h"
#include "node.cpp"
#include "node.h"

template<class ValueType>
List<ValueType>::List()
{
	First = 0;
}

template<class ValueType>
List<ValueType>::List(const List<ValueType>* cur)
{
	List<ValueType> *tmp = new List<ValueType>;
	tmp->First->key = First->key;
	cur = tmp;
	First = First->Next;
	while (First != 0)
	{
		List<ValueType> *t = new List<ValueType>;
		t->First->key = First->key;
		tmp->First->Next = t->GetFirst();
		First = First->Next;
		tmp->First = tmp->First->Next;
	}
}

template<class ValueType>
List<ValueType>::~List()
{
	delete First;
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
void List<ValueType>::PushEnd(Node<ValueType>* l)
{
	if (First == 0)
	{
		First = l;
		return;
	}
	while (First->Next != 0)
		First = First->Next;
	First->Next = l;
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
	if (First == 0)
		return;
	if (First->key = k)
		RemoveStart();
	Node<ValueType> *tmp = First;
	while ((First->Next->key != k) && (First->Next->Next != 0))
		First = First->Next;
	First->Next = tmp->Next;
	First = tmp;
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
void List<ValueType>::PushStart(ValueType k)
{
	Node<ValueType>* tmp;
	try
	{
		tmp = new Node<ValueType>(k);
	}
	catch (...)
	{
		return;
	}
	tmp->Next = First;
	First = tmp;
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
