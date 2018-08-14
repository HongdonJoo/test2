// Copyright 2018 <Author>
#include "typing_machine.h"
#include <string>
#define MAX_DATA_SIZE 100

TypingMachine::TypingMachine() {
	home = new Node(' ');
	current = home;
	end = home;
	size = 0;
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
	if (current != home)
		current = current -> GetPreviousNode ();
	return;
}

void TypingMachine::RightKey() {
	if ( current->GetNextNode() != nullptr)
		current = current->GetNextNode();
	return;
}

bool TypingMachine::TypeKey(char key) {
	if (key < 32 || key >126 || size >= MAX_DATA_SIZE)
		return false;
	size++;

	Node * insertNode = current->InsertNextNode(key);

	if (current == end)
		end = insertNode;
	current = insertNode;

	return true;
}

bool TypingMachine::EraseKey() {
	if (size == 0 || current == home)
		return false;
	size--;
	current = current->GetPreviousNode();
	current-> EraseNextNode();
	if (current->GetNextNode() == nullptr)
		end = current;
		
	return true;
}

std::string TypingMachine::Print(char separator) {
	Node *tempNode;

	buffer.clear();
	tempNode = home;
	if (tempNode == current  && separator != 0)
		buffer.push_back(separator);
	for (tempNode = tempNode->GetNextNode(); tempNode != nullptr; tempNode = tempNode->GetNextNode())
	{
		buffer.push_back(tempNode->GetData());
		if (tempNode == current && separator != 0)
			buffer.push_back(separator);
	}

	return buffer;
}