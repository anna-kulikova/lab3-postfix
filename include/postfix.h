#pragma once
#include "stack.h"

class Postfix
{
private:
	Stack<char> Result;
	Stack<char> Operator;
	Stack<float> Number;
	string expression;
	int op;
	int RightBracket();
	int Priority(const char)const;
	int IsOperator(const char)const;
	int IsOperand(const char)const;
	void Value();
	int Errors()const;
	void LessPriority(int);
public:
	Postfix();
	~Postfix();	
	void Record();
	void Print()const;
	float Count();
};