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

TEST(POSTFIX, can_record)
{
	Postfix p;
	string str = "a*(b+c-d)+(d/(f-c)-(k+l)/s)*k";
	string str1 = p.Record(str);
	EXPECT_EQ("abc+d-*dfc-/kl+s/-k*+", str1);
}

TEST(POSTFIX, throws_when_enter_anavailable_symbol)
{
	Postfix p;
	string str = "�";
	ASSERT_ANY_THROW(p.Record(str));
}

TEST(POSTFIX, throws_when_string_is_empty)
{
	Postfix p;
	string str = "";
	ASSERT_ANY_THROW(p.Record(str));
}

TEST(POSTFIX, throws_when_string_is_empty_when_count)
{
	Postfix p;
	string str = "";
	string str1;
	map<char, ExpType> m;
	m['a'] = 1;
	m['b'] = 5;
	m['c'] = 3;
	m['d'] = 4;
	m['f'] = 5;
	m['k'] = 10;
	m['l'] = 15;
	m['s'] = 5;
	ASSERT_ANY_THROW(str1 = p.Count(str, m));
}

TEST(POSTFIX, throws_when_divide_by_zero)
{
	Postfix p;
	string str = "a/f";
	string str1;
	map<char, ExpType> m;
	m['a'] = 1;
	m['f'] = 0;
	ASSERT_ANY_THROW(str1 = p.Count(str, m));
}
