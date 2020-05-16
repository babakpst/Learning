// vector-test.cpp by Bill Weinman <http://bw.org/>
// version of 2018-11-11
#include <cstdio>
#include <vector>
#include <string>
#include <utility>
using namespace std;

void message(const string & s) {
    puts(s.c_str());
    fflush(stdout);
}

void disp_t(vector<string> & v) {
    if(v.empty()) {
        puts("[empty]");
    } else {
        for( string s : v ) printf("%s ", s.c_str());
        puts("");
    }
    fflush(stdout);
}

template <typename T>
void swap(T & a, T & b) {
    message("swap()");
    T _tmp(std::move(a));
    a = std::move(b);
    b = std::move(_tmp);
}

int main() {
    vector<string> v1 = { "one", "two", "three", "four", "five" };
    vector<string> v2 = { "six", "seven", "eight", "nine", "ten" };
    
    disp_t(v1);
    disp_t(v2);
    
    return 0;
}
