#include "stack.h"
#include "stack.cpp"
#include <gtest.h>

TEST(STACK, can_create_stack)
{
	ASSERT_NO_THROW(new Stack<int>());
}

TEST(STACK, can_check_emptiness)
{
	Stack<int>* s = new Stack<int>;
	EXPECT_EQ(s->IsEmpty(), 1);
}

TEST(STACK, can_check_fullness)
{
	Stack<int>* s = new Stack<int>;
	s->Push(5);
	EXPECT_EQ(s->IsFull(), 0);
}

TEST(STACK, can_push_element)
{
	Stack<int>* s = new Stack<int>;
	ASSERT_NO_THROW(s->Push(2));
}

TEST(STACK, can_pop_element)
{
	Stack<int>* s = new Stack<int>();
	s->Push(4);
	s->Push(6);
	ASSERT_NO_THROW(s->Pop());
}

