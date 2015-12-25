#include <iostream>
#include "list.h"
#include "list.cpp"

using namespace std;


void main(void)
{
	List<int>* l = new List<int>;
	l->PushStart(5);
	cout << "You have created a list with key = 5. ";
	l->Print();
	l->PushEnd(2);
	cout << endl << "You have pushed a node with key = 2 at the end. ";
	l->Print();
	l->PushAfter(5, 6);
	cout << endl << "You have pushed a node with key = 6 after a node with key = 5. ";
	l->Print();
	l->Remove(2);
	cout << endl << "You have Removed a node with key = 2. ";
	l->Print();
	l->PushStart(8);
	cout << endl << "You have pushed a node with key = 8 at the beginning. ";
	l->Print();
	l->PushBefore(6, 7);
	cout << endl << "You have pushed a node with key = 7 before a node with key = 6. ";
	l->Print();
	return;
}