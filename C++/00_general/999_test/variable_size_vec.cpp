
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;


int main() {

  ifstream input("in.txt");
  int n, q;
  input >> n >> q ;

  vector<vector<int>> vec;
  vector<int> vec2;
  int k, m;
  for (int i = 0; i < n; ++i){
  input >> k;
  vec2.resize(k);
    for (int j = 0; j < k; ++j){
      input >> m;
      vec2[j] = m;
    }
      vec.push_back(vec2);
  }

  for (auto c : vec){
    for (auto l : c)
      cout << l << " ";
    cout << "\n";
    }

  int a,b;
  for (int i = 0; i<q; ++i){
    input >> a >> b;
    cout << vec[a][b] << "\n";
  }

  return 0;
}

