// Copyright 2018 <Author>

#include "node.h"


Node::Node(char data) {
	nodeData = data;
	previousNode = nullptr;
	nextNode = nullptr;
	return;
}

char Node::GetData() {
	return nodeData;
}

Node* Node::GetPreviousNode() {
	return previousNode;
}

Node* Node::GetNextNode() {
	return nextNode;
}

Node* Node::InsertPreviousNode(char data) {

	Node * insertNode = new Node(data);

	if (previousNode)
		previousNode->nextNode = insertNode;
	// Insert Node Parameter set
	insertNode -> previousNode = previousNode;
	insertNode -> nextNode = this;

	//Previous node parameter set
	previousNode = insertNode;
	return insertNode;

}

Node* Node::InsertNextNode(char data) {
	Node * insertNode = new Node(data);

	insertNode->previousNode = this;
	insertNode->nextNode = nextNode;

	if (nextNode)
		nextNode->previousNode = insertNode;
	
	nextNode = insertNode;
	return insertNode;
}

bool Node::ErasePreviousNode() {

	if (previousNode == nullptr)
		return false;

	Node * ppreviousNode = previousNode->GetPreviousNode();
	if (ppreviousNode)
		ppreviousNode->nextNode = this;
	delete previousNode;
	previousNode = ppreviousNode;
	return true;
}

bool Node::EraseNextNode() {
	if ( nextNode == nullptr)
		return false;

	Node * nnextNode = nextNode->GetNextNode();
	if (nnextNode != nullptr)
		nnextNode->previousNode =this;
	delete nextNode;
	nextNode = nnextNode;
	return true;
}
