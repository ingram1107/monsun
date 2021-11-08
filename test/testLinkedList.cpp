#include <LinkedList.cpp>
#include <gtest/gtest.h>

TEST(NodeTest, InitVal)
{
  Node<int> n{};
  n.element = 5;

  EXPECT_EQ(5, n.element);
  EXPECT_EQ(nullptr, n.next);
}

TEST(LinkedListTest, IsEmpty)
{
  LinkedList<int> l{};

  EXPECT_TRUE(l.isEmpty());
}

TEST(LinkedListTest, InsertSucceed)
{
  LinkedList<int> l{};

  EXPECT_TRUE(l.insert(2, 1));
  EXPECT_FALSE(l.isEmpty());
}

TEST(LinkedListTest, InsertFailed)
{
  LinkedList<int> l{};

  EXPECT_FALSE(l.insert(2, 2));
  EXPECT_TRUE(l.isEmpty());
}

TEST(LinkedListTest, RetrieveSucceed)
{
  LinkedList<int> l{};
  l.insert(2, 1);
  l.insert(3, 2);
  l.insert(4, 3);

  EXPECT_EQ(3, l.retrieve(2));
}

TEST(LinkedListTest, RetrieveFailed)
{
  LinkedList<int> l{};
  l.insert(2, 1);
  l.insert(3, 2);
  l.insert(4, 3);

  EXPECT_EQ(0, l.retrieve(4));
}

TEST(LinkedListTest, SearchSucceed)
{
  LinkedList<int> l{};
  l.insert(2, 1);
  l.insert(3, 2);
  l.insert(4, 3);

  EXPECT_EQ(2, l.search(3));
}

TEST(LinkedListTest, SearchFailed)
{
  LinkedList<int> l{};
  l.insert(2, 1);
  l.insert(3, 2);
  l.insert(4, 3);

  EXPECT_EQ(0, l.search(5));
}

TEST(LinkedListTest, SortInAscendingOrder) {
  LinkedList<int> l{};
  l.insert(4, 1);
  l.insert(2, 2);
  l.insert(3, 3);
  l.sort(true);

  EXPECT_EQ(2, l.retrieve((size_t) 1));
  EXPECT_EQ(3, l.retrieve((size_t) 2));
  EXPECT_EQ(4, l.retrieve((size_t) 3));
}

TEST(LinkedListTest, SortInDescendingOrder) {
  LinkedList<int> l{};
  l.insert(4, 1);
  l.insert(2, 2);
  l.insert(3, 3);
  l.sort(false);

  EXPECT_EQ(4, l.retrieve((size_t) 1));
  EXPECT_EQ(3, l.retrieve((size_t) 2));
  EXPECT_EQ(2, l.retrieve((size_t) 3));
}

TEST(LinkedListTest, RemoveWithElement)
{
  LinkedList<int> l{};
  l.insert(2, 1);
  l.insert(3, 2);
  l.insert(4, 3);

  EXPECT_TRUE(l.remove((int) 3));
  EXPECT_FALSE(l.search(3));
  EXPECT_EQ(4, l.retrieve(2));
}

TEST(LinkedListTest, RemoveWithIndex)
{
  LinkedList<int> l{};
  l.insert(2, 1);
  l.insert(3, 2);
  l.insert(4, 3);

  EXPECT_TRUE(l.remove((size_t) 2));
  EXPECT_FALSE(l.search(3));
  EXPECT_EQ(4, l.retrieve(2));
}

TEST(LinkedListTest, MakeEmpty)
{
  LinkedList<int> l{};
  l.insert(2, 1);
  l.insert(3, 2);
  l.insert(4, 3);

  EXPECT_TRUE(l.makeEmpty());
  EXPECT_TRUE(l.isEmpty());
}

TEST(LinkedListTest, Copy)
{
  LinkedList<int> l1{};
  l1.insert(2, 1);
  l1.insert(3, 2);
  l1.insert(4, 3);

  LinkedList<int> l2 = l1;

  EXPECT_EQ(2, l2.retrieve((size_t) 1));
  EXPECT_EQ(3, l2.retrieve((size_t) 2));
  EXPECT_EQ(4, l2.retrieve((size_t) 3));
}

TEST(LinkedListTest, Assign)
{
  LinkedList<int> l1{};
  l1.insert(2, 1);
  l1.insert(3, 2);
  l1.insert(4, 3);

  LinkedList<int> l2;
  l2 = l1;

  EXPECT_EQ(2, l2.retrieve((size_t) 1));
  EXPECT_EQ(3, l2.retrieve((size_t) 2));
  EXPECT_EQ(4, l2.retrieve((size_t) 3));
}
