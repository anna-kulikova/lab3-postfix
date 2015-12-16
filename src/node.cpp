#include "node.h"

template<class ValueType>
Node<ValueType>::Node()
{
	Next = 0;
}

template<class ValueType>
Node<ValueType>::Node(const ValueType& k)
{
	Next = 0;
	key = k;
}

template<class ValueType>
Node<ValueType>::Node(const Node<ValueType>* n)
{
	key = n->key;
	Next = n->Next;
}

template<class ValueType>
Node<ValueType>::~Node()
{
	delete Next;
}