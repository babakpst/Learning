
#include <bits/stdc++.h>
using namespace std;

// to find gradient
long double slope(vector<int> a, vector<int> b) {
  // infinity case
  if (a[0] == b[0])
    return DBL_MAX;
  return (long double)((long double)(a[1] - b[1]) / (long double)(a[0] - b[0]));
}

// whether two points are same or not
bool same(vector<int> a, vector<int> b) {
  if (a[0] == b[0] && a[1] == b[1])
    return true;
  return false;
}

//================================================
// function to find maximum points in the same line
int maxPoints(vector<vector<int>> &points) {
  if (points.size() < 2)
    return points.size();
  int maxl = 0;
  int n = points.size();
  for (int i = 0; i < n; i++) {
    map<long double, int> mymap;
    int line = 0;
    int same_points = 1;
    for (int j = 0; j < n; j++) {
      if (j != i && !same(points[i], points[j])) {
        long double p;
        p = slope(points[i], points[j]);
        // cout<<p<<endl;
        mymap[p]++;
        line = max(line, mymap[p]);
        // cout<<line<<endl;
      } else if (j != i && same(points[i], points[j])) {
        same_points++;
      }
    }
    maxl = max(maxl, same_points + line);
  }

  for (auto c : mymap)
    cout << c.first.first << " " << c.first.second << " " << c.second << "\n";

  return maxl;
}

int main() {
  int n;

  // cout << "Enter number of points\n";
  // cin >> n;

  vector<vector<int>> points;
  /*
  cout << "Enter points as <x,y> pair\n";
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    arr.push_back(vector<int>{x, y});
  }
  */

  points.push_back(vector<int>{1, 1});
  points.push_back(vector<int>{2, 2});
  points.push_back(vector<int>{2, 3});
  points.push_back(vector<int>{2, 4});
  points.push_back(vector<int>{3, 4});
  points.push_back(vector<int>{5, 6});
  points.push_back(vector<int>{4, 5});
  points.push_back(vector<int>{6, 7});
  points.push_back(vector<int>{10, 15});
  points.push_back(vector<int>{7, 8});

  cout << "maximum no of points on the same line: " << maxPoints(points)
       << endl;
  return 0;
}
