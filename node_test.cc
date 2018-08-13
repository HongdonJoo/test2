// Copyright 2018 Minkyu Jo

#include "node.h"
#include "node_test.h"
#include "test.h"

class NodeConstructorTestSuite
{
private:
  static void SingleNodeTest() {
    Node *node = new Node('A');
    ASSERT_EQ(node->GetData(), 'A');
    delete node;
  }
  static void addDelNodeTest()
  {
	  //add test

	  Node * node = new Node('C');
	  Node * nextNode = node->InsertNextNode('E');
	  Node * prevNode = node->InsertPreviousNode('A');
	  ASSERT_EQ(node->InsertNextNode('D')->GetData(), 'D');
	  ASSERT_EQ(node ->InsertPreviousNode('B') -> GetData(), 'B');
	  ASSERT_EQ(prevNode->GetData(), 'A');
	  ASSERT_EQ(nextNode->GetData(), 'E');
	  ASSERT_EQ(node->GetData(), 'C');

	  // function test
	  ASSERT_EQ(prevNode->GetNextNode() -> GetNextNode() ->GetData(), node->GetData());
	  ASSERT_EQ(nextNode->GetPreviousNode()->GetPreviousNode()->GetData(), node->GetData());
	  ASSERT_EQ(nextNode->EraseNextNode(), false);
	  ASSERT_EQ(node->EraseNextNode(), true);
	  ASSERT_EQ(prevNode->ErasePreviousNode(), false);
	  ASSERT_EQ(node->ErasePreviousNode(), true);

	  //del test
	  ASSERT_EQ(node->EraseNextNode(), true);
	  ASSERT_EQ(node->EraseNextNode(), false);
	  ASSERT_EQ(node->ErasePreviousNode(), true);
	  ASSERT_EQ(node->ErasePreviousNode(), false);

  }

public:
  static void RunTest() {
    SingleNodeTest();
	addDelNodeTest();
  }
};

class SomeOtherTestSuite
{
private:

public:
  static void RunTest() {
    // add more..
  }
};

void NodeTest() {
  NodeConstructorTestSuite::RunTest();
  // add more..
}