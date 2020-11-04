
#include <gtest/gtest.h>

bool isMultiple(int v, int base){return v%base==0;}

std::string fizzBuzz(int v){
if (isMultiple(v,5)&&isMultiple(v,3)) return "FizzBuzz";
if (isMultiple(v,3)) return "Fizz";
if (isMultiple(v,5)) return "Buzz";
return std::to_string(v);
}


/*
TEST(FizzBuzzTest, doesPas){
ASSERT_TRUE(true);
}
*/

/*
TEST(FizzBuzzTest, canCallFizzBuzz){
std::string result = fizzBuzz(1);
}
*/


/*
TEST(FizzBuzzTest, returns1With1PassedIn){
std::string result = fizzBuzz(1);
ASSERT_STREQ("1", result.c_str());
}

TEST(FizzBuzzTest, returns2With2PassedIn){
std::string result = fizzBuzz(2);
ASSERT_STREQ("2", result.c_str());
}
*/


void checkFizzBuzz(int v, std::string expectedResults){
  std::string result = fizzBuzz(v);
  ASSERT_STREQ(result.c_str(), expectedResults.c_str());
}

TEST(FizzBuzzTest, returns1With1PassedIn){
checkFizzBuzz(1,"1");
}

TEST(FizzBuzzTest, returns2With2PassedIn){
checkFizzBuzz(2,"2");
}

TEST(FizzBuzzTest, returnsFizzWith3PassedIn){
checkFizzBuzz(3,"Fizz");
}

TEST(FizzBuzzTest, returnsBuzzWith5PassedIn){
checkFizzBuzz(5,"Buzz");
}

TEST(FizzBuzzTest, returnsFizzWith6PassedIn){
checkFizzBuzz(6,"Fizz");
}

TEST(FizzBuzzTest, returnsBuzzWith10PassedIn){
checkFizzBuzz(10,"Buzz");
}

TEST(FizzBuzzTest, returnsFizzBuzzWith15PassedIn){
checkFizzBuzz(15,"FizzBuzz");
}

int main(int argc, char **argv) 
    {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
    }


