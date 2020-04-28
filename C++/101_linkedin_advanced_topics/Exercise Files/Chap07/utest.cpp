// utest.cpp by Bill Weinman <http://bw.org/>
// as of 2018-11-12
#include <cstdio>
#include <cstring>
#include <string>
#include "BWUTest.h"

constexpr bool summary_flag = true;
constexpr size_t maxlen = 128;
unsigned long int tpass = 0, tfail = 0;

int main()
{
    printf("BWUTest version: %s\n", BWUTest::version());
    
    BWUTest u("stringtest");
    u.summary(summary_flag);
    
    printf("\nTesting string -----\n");
    
    const char * _ctest = "   \tfoo   \r\n";
    size_t csz = strnlen(_ctest, maxlen);
    
    std::string ttest = _ctest;
    u.test("cstring ctor", ttest.length() == csz);
    
    std::string other = std::move(ttest);
    u.test("move ctor", other.size() == csz && ttest.length() == 0);
    ttest = std::move(other);
    u.test("move assignment", other.length() == 0 && ttest.length() == csz);
    other = ttest;
    u.test("copy assignment", other.length() == csz && ttest.length() == csz);
    
    _ctest = "this is a string";
    csz = strnlen(_ctest, maxlen);
    ttest = _ctest;
    
    u.test("length is 16", ttest.size() == csz && ttest.size() == csz);
    u.test("substr", ttest.substr(10, 3) == std::string("str"));
    
    std::string x = "foo";
    std::string y = "bar";
    std::string z = x + "baz" + y;
    
    u.test("concat", z.length() == 9 && memcmp(z.c_str(), "foobazbar", 10) == 0);
    
    x = y = "foo";
    u.test("foo == foo",   (x == y));
    u.test("foo  > foo",  !(x  > y));
    u.test("foo >= foo",   (x >= y));
    u.test("foo  < foo",  !(x  < y));
    u.test("foo <= foo",   (x <= y));
    
    x = "bar";
    u.test("bar == foo",  !(x == y));
    u.test("bar  > foo",  !(x  > y));
    u.test("bar >= foo",  !(x >= y));
    u.test("bar  < foo",   (x  < y));
    u.test("bar <= foo",   (x <= y));
    
    u.test("foo == bar",  !(y == x));
    u.test("foo  > bar",   (y  > x));
    u.test("foo >= bar",   (y >= x));
    u.test("foo  < bar",  !(y  < x));
    u.test("foo <= bar",  !(y <= x));
    
    u.test("subscript x[0]", x[0] == 'b');
    u.test("subscript x[1]", x[1] == 'a');
    u.test("subscript x[2]", x[2] == 'r');
    u.test("subscript terminator x[3]", x[3] == 0);
    
    tpass += u.pass_count();
    tfail += u.fail_count();
    u.report();
    
    printf("\nTotals: pass: %ld, fail: %ld\n", tpass, tfail);
    
    return 0;   // Done. Yay!
}
