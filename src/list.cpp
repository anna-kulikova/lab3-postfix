#include "list.h"

Node* List::Find(ValueType key)
{
	while ((First != 0) && (key == First->key))
		First = First->Next;
	return First;
}

void List::PushAfter(Node* l, ValueType key)
{
	Node* tmp = Find(key);
	if (l == 0)
		return;
	l->Next = tmp->Next;
	tmp->Next = l;
	return;
}

void List::PushEnd(Node* l)
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

Node* List::GetFirst(void)
{
	if (First == 0)
		return First;
	while (First != 0)
		First = First->Next;
	return First;
}

void List::Remove(ValueType key)
{
	Node* tmp = Find(key);
	if (First == 0)
		return;

}