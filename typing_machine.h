// Copyright 2018 <Author>

#ifndef TYPING_MACHINE_H_
#define TYPING_MACHINE_H_

#include <string>
using namespace std;
#include "node.h"

class TypingMachine {
 public:
	 Node * current;
	 Node * home;
	 Node * end;
	 string buffer;
	 int size;
  TypingMachine();
  void HomeKey();
  void EndKey();
  void LeftKey();
  void RightKey();
  bool TypeKey(char key);
  bool EraseKey();
  std::string Print(char separator);
};

#endif  // TYPING_MACHINE_H_
