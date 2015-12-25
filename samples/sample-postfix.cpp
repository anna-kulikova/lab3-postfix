#include <iostream>
#include "postfix.h"
#include "postfix.cpp"

using namespace std;


void main(void)
{
	string str = "";
	cout << "Enter the  expression:" << endl;
	cin >> str;
	Postfix p;
	p.Set(str);
	p.Record();
	p.Print();
	ExpType res = p.Count();
	cout << res << endl;
}