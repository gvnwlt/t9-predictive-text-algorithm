// T9PredictiveTextAlgorithm.cpp : Defines the entry point for the console application.
//

#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "Engine.h"
#include "WordsTree.h"

TEST_CASE("Called with empty digit list --> returns no results")
{
	WordsTree emptyTree; 
	Engine t9Engine(emptyTree);

	Digits digits; 

	auto result = t9Engine.GetWordByDigits(digits); 

	REQUIRE(result.size() == 0); 
}

TEST_CASE("When called with 43556 and known word then return hello")
{
	WordsTree knownWords;
	knownWords.AddWord("hello");

	Engine t9Engine(knownWords);

	Digits digits = { 4, 3, 5, 5, 6 }; 

	auto result = t9Engine.GetWordsByDigits(digits); 

	REQUIRE(result[0] == 0); 
}

TEST_CASE(PassDigitsForHelloReturnCorrectString)
{
	WordsTree emptyTree;
	Engine t9Engine(emptyTree); 

	Digits digits = { 4, 3, 5, 5, 6 }; 
	auto result = t9Engine.GetWordsByDigits(digits); 

	Assert::AreEqual(std::string("hello"), result[0]); 
}

