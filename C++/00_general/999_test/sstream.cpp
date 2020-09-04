
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

vector<int> parseInts(string str) {
  int cnt = 0;

  for (int i = 0; i < str.size(); ++i)
    if (str[i] == ',')
      ++cnt;
  vector<int> vec(cnt + 1, 0);

  stringstream ss(str);
  char ch;
  for (int i = 0; i <= cnt; ++i)
    ss >> vec[i] >> ch;
  ss >> vec[cnt];
  return vec;
}

int main() {
  string str;
  cin >> str;
  vector<int> integers = parseInts(str);
  for (int i = 0; i < integers.size(); i++) {
    cout << integers[i] << "\n";
  }

  return 0;
}