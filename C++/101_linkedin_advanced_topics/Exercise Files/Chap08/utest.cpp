// utest.cpp by Bill Weinman <http://bw.org/>
// version of 2018-10-12

#include <cstdio>
#include "BWUTest.h"
#include "BWString.h"

bool summary_flag = false;

int main()
{
    
    // Versions n things
    printf("BWString version: %s\n", BWString::version());
    printf("BWUTest version: %s\n", BWUTest::version());
    
    BWUTest u("BWLib");
    u.summary(summary_flag);
    
    // BWString
    printf("\nTesting BWString -----\n");
    u.init("BWString");
    
    // test constructors
    const char * _ctest = "   \tfoo   \r\n";
    BWString ttest = _ctest;
    u.test("cstring ctor", ttest.length() == 12);
    
    puts(ttest);
    
    BWString other = std::move(ttest);
    u.test("move ctor", other.length() == 12 && ttest.length() == 0);
    ttest = std::move(other);
    
    // assignment operators
    u.test("move assignment", other.length() == 0 && ttest.length() == 12);
    other = ttest;
    u.test("copy assignment", other.length() == 12 && ttest.length() == 12);
    
    // concat operators
    BWString x = "foo";
    BWString y = "bar";
    x += y;
    u.test("concat +=", x.length() == 6 && memcmp(x.c_str(), "foobar", 7) == 0);
    
    BWString z;
    z = x + "baz";
    u.test("concat +", z.length() == 9 && memcmp(z.c_str(), "foobarbaz", 10) == 0);
    z = "baz" + x;
    u.test("concat +", z.length() == 9 && memcmp(z.c_str(), "bazfoobar", 10) == 0);
    
    // comparison operators
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
    
    // subscript
    u.test("subscript x[0]", x[0] == 'b');
    u.test("subscript x[1]", x[1] == 'a');
    u.test("subscript x[2]", x[2] == 'r');
    u.test("subscript terminator x[3]", x[3] == 0);
    
    ttest.trim();
    u.test("trim", ttest.length() == 3);
    
    ttest = "this is a string";
    u.test("length is 16", ttest.length() == 16 && ttest.size() == 16);
    u.test("substr", ttest.substr(10, 3) == BWString("str"));
    u.test("charfind", ttest.char_find('s') == 3);
    u.test("charfind (not found)", ttest.char_find('z') == -1);
    
    BWString string_upper = ttest.upper();
    BWString string_lower = string_upper.lower();
    u.test("upper and lower", string_upper == BWString("THIS IS A STRING") && string_lower == BWString("this is a string"));
    
    x = "this is a big string ###foobarbaz### this is a big string";
    x = x.replace("###foobarbaz###", "foo bar baz");
    u.test("replace", x.length() == 53 && memcmp(x.c_str(), "this is a big string foo bar baz this is a big string", 54) == 0);
    
    x = "line one/line two/line three";
    auto & r = x.split('/');
    
    u.test("split_count is 3", x.split_count() == 3);
    u.test("split result 1", memcmp(r[0]->c_str(), "line one", 8) == 0);
    u.test("split result 2", memcmp(r[1]->c_str(), "line two", 8) == 0);
    u.test("split result 3", memcmp(r[2]->c_str(), "line three", 10) == 0);
    u.test("split test end", !r[3]);
    
    u.test("format test", memcmp(x.format("format test %d", 42).c_str(), "format test 42", 14) == 0);
    
    // report results
    puts("");
    u.report();
    
    return 0;   // Done. Yay!
}
