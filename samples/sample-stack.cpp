#include <iostream>
#include "stack.h"
#include "stack.cpp"

using namespace std;

void main(void)
{
	Stack<int>* s = new Stack<int>();
	s->Push(7);
	cout << s->GetKey(7) << endl;
}