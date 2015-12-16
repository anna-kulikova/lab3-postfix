#include "list.h"
#include <gtest.h>

/*TEST(LIST, can_create_list)
{
	ASSERT_NO_THROW(List<int> list());
}

TEST(LIST, can_create_list_by_key)
{
	ASSERT_NO_THROW(List<int> list(5));
}*/



TEST(LIST, created_list_is_empty)
{
	ASSERT_NO_THROW(0, List<int> list()->GetFirst());
}


TEST(LIST, can_push_element_at_the_end)
{
	List<int>* list;
	list = new List<int>();
	Node<int>* n;
	ASSERT_NO_THROW(list.PushEnd(Node<int>()));
}

TEST(LIST, can_push_element_after)
{
	List<int>* list = new List<int>();
	ASSERT_NO_THROW(list.Pus)
}