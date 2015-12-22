#include "list.h"
#include "list.cpp"
#include <gtest.h>


TEST(LIST, can_create_list)
{
	ASSERT_NO_THROW(new List<int>());
}

TEST(LIST, can_create_list_by_key)
{
	ASSERT_NO_THROW(List<int> list(5));
}


TEST(LIST, created_list_is_empty)
{
	ASSERT_NO_THROW(0, List<int> list()->GetFirst());
}


TEST(LIST, can_push_element_at_the_end)
{
	List<int>* list;
	list = new List<int>(4);
	Node<int>* n = new Node<int>(2);
	ASSERT_NO_THROW(list->PushEnd(n));
}

TEST(LIST, can_push_element_after)
{
	List<int>* list;
	list = new List<int>(4);
	Node<int>* n = new Node<int>(2);
	list->PushEnd(n);
	ASSERT_NO_THROW(list->PushAfter(n, 6));
}

TEST(LIST, can_compare_equal_lists)
{
	List<int>* l = new List<int>(5);
	List<int>* l2 = new List<int>(5);
	EXPECT_EQ(*l, *l2);
}

TEST(LIST, can_compare_different_lists)
{
	List<int>* l = new List<int>(5);
	List<int>* l2 = new List<int>(4);
	EXPECT_NE(*l, *l2);
}

TEST(LIST, copied_list_is_equal_to_source_one)
{
	List<int>* l = new List<int>(3);
	List<int>* l1;
	l->PushStart(2);	
	l1 = new List<int>(l);
	EXPECT_EQ(*l, *l1);
}

TEST(LIST, can_remove_node)
{
	List<int>* l = new List<int>(3);
	l->PushStart(2);
	ASSERT_NO_THROW();
}

TEST(LIST, can_remove_node_from_the_beginning)
{
	List<int>* l = new List<int>(3);
	l->PushStart(2);
	ASSERT_NO_THROW();
}

TEST(LIST, can_push_node_at_the_beginning)
{
	List<int>* list;
	list = new List<int>(4);
	ASSERT_NO_THROW(list->PushStart(3));
}

TEST(LIST, can_find_key)
{
	List<int>* list;
	list = new List<int>(4);
	Node<int>* n = new Node<int>(2);
	list->PushEnd(n);
	EXPECT_EQ(list->Find(4), list->GetFirst());
}

