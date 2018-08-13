// Copyright 2018 <Author>
#include "typing_machine.h"
#include <string>
using namespace std;

TypingMachine::TypingMachine() {
	home = nullptr;
	current = nullptr;
	end = nullptr;
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
	if (current == nullptr && home == nullptr)
	{
		current = new Node(key);
		home = current;
		end = current;
	}
	else {
		if (current != nullptr)
		{
			Node * insertNode = current->InsertNextNode(key);

			if (current == end)
				end = insertNode;
			current = insertNode;
		}
		else 
			current = home = home->InsertPreviousNode(key);

	}
	return true;
}

bool TypingMachine::EraseKey() {
	if (current == nullptr)
		return false;

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
	if (current == nullptr)
		buffer.push_back(separator);
	for (tempNode = home; tempNode != nullptr; tempNode = tempNode->GetNextNode())
	{
		buffer.push_back(tempNode->GetData());
		if (tempNode == current)
			buffer.push_back(separator);
	}

	return buffer;
}
