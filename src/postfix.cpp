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
		Operand.Push(tmp);
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

void Postfix::Record()
{
	int curpriority = 0;
	int lastpriority = 0;
	for (int i = 0; i < expression.length(); i++)
	{
		if (IsOperand(expression[i]))
		{
			Operand.Push(expression[i]);
		}
		else if (IsOperator(expression[i])) {

			if (expression[i] = ')')
			{
				lastpriority = RightBracket();
				continue;
			}

			curpriority = Priority(expression[i]);
			if (curpriority < lastpriority)
			{
				PriorityDecrease(curpriority);
				lastpriority = curpriority;
				continue;
			}
			lastpriority = curpriority;
			Operator.Push(expression[i]);
		}
		else 
			continue;
	}
	while (!Operator.IsEmpty())
		Operand.Push(Operator.Pop());
}

void Postfix::PriorityDecrease(int k)
{
	char i = Operator.Pop();
	while ((k <= Priority(i)) && (!Operator.IsEmpty()))
	{
		Operand.Push(i);
		i = Operator.Pop();
	}
	if (Priority(i) < k)
		Operator.Push(i);
	Operator.Push(k);
}