// Copyright 2018 Minkyu Jo

#include "typing_machine.h"
#include "typing_machine_test.h"
#include "test.h"

class TmConstructorTestSuite
{
private:
  static void BarSeparatorTest() {
    TypingMachine tm;
    ASSERT_EQ(tm.Print('|'), std::string("|"));
	tm.TypeKey('k');
	ASSERT_EQ(tm.Print('d'), std::string("kd"));
	ASSERT_EQ(tm.Print(0), std::string("k"));
  }

public:
  static void RunTest() {
    BarSeparatorTest(); 
  }
};

class SomeOtherTestSuite
{
private:
	static void addDelTest()
	{
		TypingMachine tm;
		int i;
		ASSERT_EQ(tm.TypeKey('a'), true);
		ASSERT_EQ(tm.Print('|'), "a|");
		ASSERT_EQ(tm.TypeKey('b'), true);
		ASSERT_EQ(tm.Print('|'), "ab|");
		ASSERT_EQ(tm.TypeKey('c'), true);
		ASSERT_EQ(tm.Print('|'), "abc|");
		ASSERT_EQ(tm.TypeKey(20), false);
		ASSERT_EQ(tm.Print('|'), "abc|");
		ASSERT_EQ(tm.EraseKey(), true);
		ASSERT_EQ(tm.EraseKey(), true);
		ASSERT_EQ(tm.EraseKey(), true);
		ASSERT_EQ(tm.EraseKey(), false);

		for (i = 0; i < 100; i++)
			ASSERT_EQ(tm.TypeKey('a'), true);
		ASSERT_EQ(tm.TypeKey('a'), false);
		for (i = 0; i < 100; i++)
			ASSERT_EQ(tm.EraseKey(), true);
		ASSERT_EQ(tm.EraseKey(), false);
	}

	static void moveCursorTest()
	{
		TypingMachine tm;
		int i;
		ASSERT_EQ(tm.TypeKey('a'), true);
		ASSERT_EQ(tm.Print('|'), "a|");
		tm.HomeKey();
		tm.LeftKey();
		ASSERT_EQ(tm.Print('|'), "|a");
		tm.EndKey();
		tm.RightKey();
		ASSERT_EQ(tm.Print('|'), "a|");
		tm.LeftKey();
		ASSERT_EQ(tm.Print('|'), "|a");
		tm.RightKey();
		ASSERT_EQ(tm.Print('|'), "a|");


	}
public:
  static void RunTest() {
	  addDelTest();
	  moveCursorTest();
  }
};

void TypingMachineTest() {
  TmConstructorTestSuite::RunTest();
  SomeOtherTestSuite::RunTest();

}