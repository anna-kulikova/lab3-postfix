#pragma once
#include "node.h"

class List
{
private:
	Node *First;
public:
	List();
	List(Node*);
	List(const List&);
	~List();
	Node* Find(ValueType);
	void PushEnd(Node*);
	void PushAfter(Node*, ValueType);
	void PushBefore(Node*, ValueType);
	void Remove(ValueType);
	Node* GetFirst(void);
	void PushStart(ValueType);
	void RemoveStart(void);
};
