#pragma once
#include "node.h"


template<class ValueType>
class List
{
private:
	Node<ValueType> *First;
public:
	List();
	List(const List<ValueType>*);
	/*List(const ValueType);
	List(const Node<ValueType>*);*/
	~List();
	Node<ValueType>* Find(ValueType);
	void PushEnd(Node<ValueType>*);
	void PushAfter(Node<ValueType>*, ValueType);
	void Remove(ValueType);
	Node<ValueType>* GetFirst(void);
	void PushStart(ValueType);
	void RemoveStart(void);
	int operator==(const List<ValueType>&)const;
	int operator!=(const List<ValueType>&)const;
};

template<class ValueType>
List<ValueType>::List();

template<class ValueType>
List<ValueType>::List(const List<ValueType>* cur);

template<class ValueType>
List<ValueType>::~List();

template<class ValueType>
Node<ValueType>* List<ValueType>::Find(ValueType key);

template<class ValueType>
void List<ValueType>::PushAfter(Node<ValueType>* l, ValueType key);

template<class ValueType>
void List<ValueType>::PushEnd(Node<ValueType>* l);

template<class ValueType>
Node<ValueType>* List<ValueType>::GetFirst(void);

template<class ValueType>
void List<ValueType>::Remove(ValueType key);

template<class ValueType>
void List<ValueType>::RemoveStart(void);

/*template<class ValueType>
List<ValueType>::List(const ValueType);

template<class ValueType>
List<ValueType>::List(const Node<ValueType>*);*/


template<class ValueType>
void List<ValueType>::PushStart(ValueType);

template<class ValueType>
int List<ValueType>::operator==(const List<ValueType>&)const;

template<class ValueType>
int List<ValueType>::operator!=(const List<ValueType>&)const;
