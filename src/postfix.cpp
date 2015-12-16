#include "stack.h"
#include "stack.cpp"
#include "postfix.h"

Postfix::Postfix()
{
	expression = "";
	op = 0;
}

Postfix::~Postfix()
{

}

int Postfix::RightBracket()
{
	char tmp = Operator.Pop();
	while (tmp != '(')
	{
		Result.Push(tmp);
		tmp = Operator.Pop();
	}
	if (!Operator.IsEmpty())
	{
		tmp = Operator.Pop();
		Operator.Push(tmp);
	}
	return Priority(tmp);
}

int Postfix::IsOperator(const char k)const
{
	switch (k)
	{
	case '+':
		return 1;
	case '-':
		return 1;
	case '*':
		return 1;
	case '/':
		return 1;
	case '(':
		return 1;
	case ')':
		return 1;
	default:
		return 0;
	}
}

int Postfix::IsOperand(const char k)const
{
	if ((IsOperator(k)) || (' '))
		return 0;
	return 1;
}

int Postfix::Priority(const char k)const
{
	if (IsOperator(k))
		switch (k)
		{
		case '+':
			return 2;
		case '-':
			return 2;
		case '*':
			return 3;
		case '/':
			return 3;
		case '(':
			return 1;
		case ')':
			return 1;
		}
	return -1;
}
