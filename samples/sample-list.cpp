#include <iostream>
#include "list.h"
#include "list.cpp"

using namespace std;


void main(void)
{
	List<int>* l = new List<int>(5);
	cout << "You have created a list with key = 5" << ' ' << l->GetFirst()->key << endl;
	Node<int>* n = new Node<int>(2);
	l->PushEnd(n);
	cout << "You have pushed a node with key = 2 at the end" << ' ' << l->GetFirst()->key << ' ' << l->GetFirst()->Next->key << endl;
	l->PushAfter(n, 6);
	cout << "You have pushed a node with key = 6 after a node with key = 2" << ' ' << l->GetFirst()->key << ' ' << l->GetFirst()->Next->key << ' ' << l->GetFirst()->Next->Next->key << endl;
	l->Remove(2);
	cout << "You have removed a node with key = 2" << ' ' << l->GetFirst()->key << ' ' << l->GetFirst()->Next->key << endl;
	l->RemoveStart();
	cout << "You have removed first node" << ' ' << l->GetFirst()->key << endl;
	l->PushStart(8);
	cout << "You have pushed a node with key = 8 at the beginning" << ' ' << l->GetFirst()->key << ' ' << l->GetFirst()->Next->key << endl;
	return;
}