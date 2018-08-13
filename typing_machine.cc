// Copyright 2018 <Author>
#include "typing_machine.h"
#include <string>
#define MAX_DATA_SIZE 100
TypingMachine::TypingMachine() {
	home = nullptr;
	current = nullptr;
	end = nullptr;
	size = 0;
  return;
}

void TypingMachine::HomeKey() {
	current = nullptr;
  return;
}

void TypingMachine::EndKey() {
	current = end;
  return;
}

void TypingMachine::LeftKey() {
	if (current != nullptr)
	    current = current -> GetPreviousNode ();
  return;
}

void TypingMachine::RightKey() {
	if (current == nullptr)
		current = home;
	else if ( current->GetNextNode() != nullptr)
	    current = current->GetNextNode();
  return;
}

bool TypingMachine::TypeKey(char key) {
	if (key < 32 || key >126)
		return false;
	if (size >= MAX_DATA_SIZE)
		return false;
	size++;
	if (current == nullptr)
	{
		if (home != nullptr)
		{
			home = home->InsertPreviousNode(key);
			current = home;
		}
		else {
			current = new Node(key);
			home = end = current;
		}
	}
	else {
		Node * insertNode = current->InsertNextNode(key);
		if (current == end)
			end = insertNode;
		current = insertNode;

	}
	return true;
}

bool TypingMachine::EraseKey() {
	if (current == nullptr)
		return false;
	size--;
	if (current->GetPreviousNode() != nullptr)
	{
		current = current->GetPreviousNode();
		current->EraseNextNode();
		if (current->GetNextNode() == nullptr)
			end = current;
	}
	else if (current->GetNextNode() != nullptr)
	{
		current = current->GetNextNode();
		current->ErasePreviousNode();
		home = current ;
		current = nullptr;
	}
	else {
		delete  current;
		home = current = end = nullptr;
	}
		
  return true;
}

std::string TypingMachine::Print(char separator) {
	Node *tempNode;

	buffer.clear();

	if (current == nullptr && separator != 0)
		buffer.push_back(separator);
	for (tempNode = home; tempNode != nullptr; tempNode = tempNode->GetNextNode())
	{
		buffer.push_back(tempNode->GetData());
		if (tempNode == current && separator != 0)
			buffer.push_back(separator);
	}

	return buffer;
}
