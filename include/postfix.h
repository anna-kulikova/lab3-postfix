#pragma once
#include "stack.h"

typedef int ExpType;

class Postfix
{
private:
	Stack<char>* Operator;
	Stack<char>* Operand;
	Stack<ExpType>* Result;
	string expression;
	string result;
	int op;
	int RightBracket();
	int Priority(const char)const;
	int IsOperator(const char)const;
	int IsOperand(const char)const;		
	void PriorityDecrease(int);	
public:
	Postfix();
	~Postfix();	
	void Record();
	ExpType Count();
	void Print();
	int Set(const string&);
	int Line(void)const;
};