#include <gtest.h>
#include "postfix.h"
#include "postfix.cpp"

TEST(POSTFIX, can_calculate)
{
	Postfix p;
	string str = "a*(b+c-d)+(d/(f-c)-(k+l)/s)";
	map<char, ExpType> m;
	m['a'] = 1;
	m['b'] = 5;
	m['c'] = 3;
	m['d'] = 4;
	m['f'] = 5;
	m['k'] = 10;
	m['l'] = 15;
	m['s'] = 5;
	EXPECT_EQ(1, p.Count(p.Record(str), m));
}