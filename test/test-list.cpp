#include "list.h"
#include "list.cpp"
#include <gtest.h>


TEST(LIST, can_create_list)
{
	ASSERT_NO_THROW(new List<int>());
}

TEST(LIST, can_get_pointer_on_first_node)
{
	List<int>* list = new List<int>(5);
	ASSERT_NO_THROW(list->GetFirst());
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
	ASSERT_NO_THROW(list->PushEnd(2));
}


TEST(LIST, can_push_element_after)
{
	List<int>* list;
	list = new List<int>(4);
	Node<int>* n = new Node<int>(2);
	list->PushEnd(2);
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

TEST(LIST, compare_equal_lists_return_true)
{
	List<int>* list = new List<int>(5);
	List<int>* list1 = new List<int>(5);
	list->PushStart(1);
	list1->PushStart(1);
	EXPECT_EQ(*list1, *list);
}

TEST(LIST, compare_non_equal_lists_return_false)
{
	List<int>* list = new List<int>(5);
	List<int>* list1 = new List<int>(5);
	list->PushStart(1);
	list1->PushStart(2);
	EXPECT_NE(*list1, *list);
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
	list->PushEnd(2);
	EXPECT_EQ(list->Find(4), list->GetFirst());
}

TEST(LIST, copied_list_is_equal_to_source_one)
{
	List<int>* list = new List<int>(5);
	list->PushStart(1);
	List<int>* list1 = new List<int>(*list);
	EXPECT_EQ(*list, *list1);
}