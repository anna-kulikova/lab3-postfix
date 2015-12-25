#include <iostream>
#include "stack.h"
#include "stack.cpp"

using namespace std;

void main(void)
{
	int i = 0;
	Stack<int>* s = new Stack<int>();
	for (; i < 5; i++)
		s->Push(i);
	cout << endl << "You have pushed 5 elements with key = i. " << endl;
	s->Print();	
	cout << endl << "You have popped one element. " << endl;
	s->Pop();
	s->Print();
	return;
}