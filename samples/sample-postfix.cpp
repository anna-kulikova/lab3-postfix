#include <iostream>
#include "postfix.h"
#include "postfix.cpp"

using namespace std;


int main(void)
{
	string str = "a*(b+c-d)+(d/(f-c)-(k+l)/s)";
	Postfix p;
	cout << str << endl;
	map<char, ExpType> m;
	m['a'] = 1;
	cout << "a = " << m['a'] << endl;
	m['b'] = 5;
	cout << "b = " << m['b'] << endl;
	m['c'] = 3;
	cout << "c = " << m['c'] << endl;
	m['d'] = 4;
	cout << "d = " << m['d'] << endl;
	m['f'] = 5;
	cout << "f = " << m['f'] << endl;
	m['k'] = 10;
	cout << "k = " << m['k'] << endl;
	m['l'] = 15;
	cout << "l = " << m['l'] << endl;
	m['s'] = 5;
	cout << "s = " << m['s'] << endl;
	string str1 = p.Record(str);
	ExpType res = p.Count(str1, m);
	cout << "Result: " << res << endl;
	return 0;
}