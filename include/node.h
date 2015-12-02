#pragma once
#include <iostream>
using namespace std;
typedef char ValueType;

struct Node
{
	Node *Next;
	ValueType key;
};