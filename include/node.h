#pragma once

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

template<class ValueType>
class Node
{
public:
	Node<ValueType> *Next;
	ValueType key;

	Node();
	Node(const ValueType&);
	Node(const Node<ValueType>*);
	~Node();
};

template<class ValueType>
Node<ValueType>::Node();

template<class ValueType>
Node<ValueType>::Node(const ValueType& key);

template<class ValueType>
Node<ValueType>::Node(const Node<ValueType>* node);

template<class ValueType>
Node<ValueType>::~Node();