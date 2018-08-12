// Copyright 2018 <Author>
#include "typing_machine.h"
#include <string>
using namespace std;

TypingMachine::TypingMachine() {
	home = new Node(' ');
	current = home;
	end = home;
  return;
}

void TypingMachine::HomeKey() {
	current = home;
  return;
}

void TypingMachine::EndKey() {
	current = end;
  return;
}

void TypingMachine::LeftKey() {
	current = current ->GetPreviousNode ();
  return;
}

void TypingMachine::RightKey() {
	current = current->GetNextNode();
  return;
}

bool TypingMachine::TypeKey(char key) {
	Node * insertNode = current->InsertNextNode(key);
	if (current == end)
		end = insertNode;

  return false;
}

bool TypingMachine::EraseKey() {
	current -> EraseNextNode();
	if (current->GetNextNode() == nullptr)
		end = current;
		
  return false;
}

std::string TypingMachine::Print(char separator) {
	Node *tempNode;

	buffer.clear();
	for (tempNode = home; tempNode != nullptr;)
	{
		if (tempNode == current)
			buffer.push_back(separator);
		buffer.push_back(tempNode->GetData());
		tempNode = tempNode->GetNextNode();
	}

	return buffer;
}
