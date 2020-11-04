//============================================================================
// Name        : FizzBuzz.cpp
//
// FizzBuzz Code Kata:
// Write a function that receives and prints a passed in number.
// But for multiples of three print "Fizz"
// instead of the number and for the multiples of five print "Buzz".
// For numbers which are multiples of
// both three and five print "FizzBuzz".
//============================================================================

#include <gtest/gtest.h>

bool isMultiple( int value, int base ){
	return (0 == (value % base));
}

std::string fizzBuzz(int value){
	if( isMultiple(value, 3) && isMultiple(value, 5) )
		return "FizzBuzz";
	if( isMultiple(value, 3) )
		return "Fizz";
	if( isMultiple(value, 5) )
		return "Buzz";
	return std::to_string(value);
}

void checkFizzBuzz(int value, std::string expectedResult ){
	std::string result = fizzBuzz(value);
	ASSERT_STREQ(expectedResult.c_str(), result.c_str());
}

TEST(FizzBuzzTests, returns1With1PassedIn){
	checkFizzBuzz(1, "1");
}

TEST(FizzBuzzTests, returns2With2PassedIn){
	checkFizzBuzz(2, "2");
}

TEST(FizzBuzzTests, returnsFizzWith3PassedIn){
	checkFizzBuzz(3, "Fizz");
}

TEST(FizzBuzzTests, returnsBuzzWith5PassedIn){
	checkFizzBuzz(5, "Buzz");
}

TEST(FizzBuzzTests, returnsFizzWith6PassedIn){
	checkFizzBuzz(6, "Fizz");
}

TEST(FizzBuzzTests, returnsBuzzWith10PassedIn){
	checkFizzBuzz(10, "Buzz");
}

TEST(FizzBuzzTests, returnsFizzBuzzWith15PassedIn){
	checkFizzBuzz(15, "FizzBuzz");
}

