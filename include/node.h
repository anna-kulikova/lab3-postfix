#pragma once

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

template<class ValueType>
class Node
{
public:
	Node *Next;
	ValueType key;

	Node();
	Node(const ValueType&);
	Node(const Node*);
	~Node();
};

template<class ValueType>
Node<ValueType>::Node();

template<class ValueType>
Node<ValueType>::Node(const ValueType&);

template<class ValueType>
Node<ValueType>::Node(const Node<ValueType>*);

template<class ValueType>
Node<ValueType>::~Node();