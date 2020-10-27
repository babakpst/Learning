#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int maxPoint(vector<pair<int, int>> &point) {

  int n = point.size(); // number of points in the set
  if (n == 2)
    return 2;
  else if (n < 2)
    return 0;

  int max_point = 0; // maximum number of points on the line
  int line;          // current maximum points on a line
  int same_points;   // tracks identical points

  map<pair<int, int>, int> slope;
  for (int i = 0; i < n; i++) {
    line = 0;
    same_points = 0;

    for (int j = i + 1; j < n; j++) {
      if (point[i].first == point[j].first &&
          point[i].second == point[j].second) {
        // points are the same
        same_points++;
      } else {
        int diffx = point[i].first - point[j].first;
        int diffy = point[i].second - point[j].second;

        // a function to find the largest divisor
        int divisor = __gcd(diffx, diffy);
        diffx /= divisor;
        diffy /= divisor;

        slope[make_pair(diffx, diffy)]++;
        line = max(line, slope[make_pair(diffx, diffy)]);
        // cout << "line: " << line << endl;
      }
    }
    max_point = max(max_point, line + same_points + 1);

    slope.clear();
  }

  return max_point;
};

int main() {

  //[2, 3] [2, 4], [3, 4], [5, 6]
  vector<pair<int, int>> points;
  points.push_back(make_pair(1, 1));
  points.push_back(make_pair(1, 1));
  points.push_back(make_pair(2, 2));
  points.push_back(make_pair(2, 3));
  points.push_back(make_pair(2, 4));
  points.push_back(make_pair(3, 4));
  points.push_back(make_pair(5, 6));
  points.push_back(make_pair(5, 6));
  points.push_back(make_pair(4, 5));
  points.push_back(make_pair(6, 7));
  points.push_back(make_pair(10, 15));
  points.push_back(make_pair(7, 8));

  cout << " max no. of points on a line: " << maxPoint(points) << endl;

  return 0;
}
