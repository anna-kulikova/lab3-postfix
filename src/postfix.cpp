#include "stack.h"
#include "stack.cpp"
#include "postfix.h"

Postfix::Postfix()
{
	expression = "";
	result = "";
	Operator = new Stack<char>();
	Operand = new Stack<char>();
	Result = new Stack<ExpType>();
	op = 0;
}

Postfix::~Postfix()
{
	delete Operator;
	delete Operand;
	delete Result;
}

int Postfix::RightBracket()
{
	char tmp = Operator->Pop();
	while (tmp != '(')
	{
		Operand->Push(tmp);
		tmp = Operator->Pop();
	}
	if (!Operator->IsEmpty())
	{
		tmp = Operator->Pop();
		Operator->Push(tmp);
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
	if (expression.length() == 0)
	{
		cout << "Enter the expression" << endl;
		cin >> expression;
		if (Line())
			throw("Incorrect string");
	}
	int curpriority = 0;
	int lastpriority = 0;
	for (int i = 0; i < expression.length(); i++)
	{
		if (IsOperand(expression[i]))
		{
			Operand->Push(expression[i]);
		}
		else if (IsOperator(expression[i]))
		{

			if (expression[i] == ')')
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
			Operator->Push(expression[i]);
		}
		else 
			continue;
	}
	while (!Operator->IsEmpty())
		Operand->Push(Operator->Pop());
}

void Postfix::PriorityDecrease(int k)
{
	char i = Operator->Pop();
	while ((k <= Priority(i)) && (!Operator->IsEmpty()))
	{
		Operand->Push(i);
		i = Operator->Pop();
	}
	if (Priority(i) < k)
		Operator->Push(i);
	Operator->Push(k);
}

int Postfix::Line(void)const
{
	int l = 0;
	int r = 0;
	for (int i = 0; i < expression.length(); i++)
	{
		if (expression[i] == '(')
			l++;
		if (expression[i] == ')')
			r++;
	}
	if (l != r)
		return 0;
	int m = 0;
	int j = 1;
	char k, t;
	if (expression.length() > 0)
		if (IsOperator(expression[0]))
			if (expression[0] != '-')
				return 0;
	while (j < expression.length()) 
	{
		if (expression[j] == ' ')
		{
			j++;
			continue;
		}
			k = expression[m];
			t = expression[j];
			if ((IsOperand(m)) && (IsOperand(t)))
				return 0;
			if ((IsOperator(k)) && (IsOperator(t)))
				if (((k == '(') && (t != ')') && (t != '(') && (t != '-')) || ((k != '(') && (t == ')') && (k != ')')))
					return 0;
			m = j++;
	}

	return 1;
}

ExpType Postfix::Count()
{
	if (op != 0)
		throw("Error");
	ExpType l = 0;
	ExpType r = 0;
	ExpType ex = 0;
	for (int i = 0; i < result.length(); i++)
	{
		if (IsOperand(result[i])) {
			cout << "Enter the '" << result[i] << "'" << endl;
			cin >> ex;
			Result->Push(ex);
			continue;
		}
		if (IsOperand(result[i]))
		{
			cout << result[i] << endl;
			cin >> ex;
			Result->Push(ex);
			continue;
		}
		if (Result->IsEmpty())
			throw("There is no result");
		l = Result->Pop();
		if (Result->IsEmpty())
			if (result[i] != '-')
			{
				l = -l;
				Result->Push(l);
				continue;
			}
			else
				throw("Error");
		r = Result->Pop();
		switch (result[i])
		{
		case '+':
			Result->Push(l + r);
			break;
		case '-':
			Result->Push(l - r);
			break;
		case '*':
			Result->Push(l * r);
			break;
		case '/':
			Result->Push(l / r);
			break;
		}
	}
	return Result->Pop();
}

void Postfix::Print()
{
	if (op)
		cout << result << endl;
	else
		cout << "String wasn't processed" << endl;
}

int Postfix::Set(const string& str)
{
	expression = str;
	int t = Line();
	op = 0;
	return t;
}