

/*

The median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value,
and the median is the mean of the two middle values.

For example, for arr = [2,3,4], the median is 3.
For example, for arr = [2,3], the median is (2 + 3) / 2 = 2.5.
Implement the MedianFinder class:

MedianFinder() initializes the MedianFinder object.
void addNum(int num) adds the integer num from the data stream to the data structure.
double findMedian() returns the median of all elements so far. Answers within 10-5 of the actual answer will be
accepted.


Example 1:

Input
["MedianFinder", "addNum", "addNum", "findMedian", "addNum", "findMedian"]
[[], [1], [2], [], [3], []]
Output
[null, null, null, 1.5, null, 2.0]

Explanation
MedianFinder medianFinder = new MedianFinder();
medianFinder.addNum(1);    // arr = [1]
medianFinder.addNum(2);    // arr = [1, 2]
medianFinder.findMedian(); // return 1.5 (i.e., (1 + 2) / 2)
medianFinder.addNum(3);    // arr[1, 2, 3]
medianFinder.findMedian(); // return 2.0


Constraints:

-105 <= num <= 105
There will be at least one element in the data structure before calling findMedian.
At most 5 * 104 calls will be made to addNum and findMedian.


Follow up:

If all integer numbers from the stream are in the range [0, 100], how would you optimize your solution?
If 99% of all integer numbers from the stream are in the range [0, 100], how would you optimize your solution?


*/

// babak poursartip
// June 14, 2025

#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <vector>

using namespace std;

class MedianFinder2
{
 public:
  multiset<int> stream;
  MedianFinder2() {}

  void addNum(int num) { stream.insert(num); }

  double findMedian()
  {
    int n = stream.size();
    if (n % 2 == 0)  // even number of elements
    {
      int index = n / 2;
      auto it1 = stream.begin();
      auto it2 = stream.begin();
      advance(it1, index);
      advance(it2, index - 1);
      return (*it1 + *it2) / 2.0;
    }
    else  // odd number of elements
    {
      int index = (n - 1) / 2.0;
      auto it = stream.begin();
      advance(it, index);
      return *it;
    }
  }
};

class MedianFinder
{
 public:
  priority_queue<int> maxpq;
  priority_queue<int, vector<int>, greater<int>> minpq;

  MedianFinder() {}

  void addNum(int num)
  {
    if (maxpq.size() == 0 || maxpq.top() > num)
    {
      maxpq.push(num);
    }
    else
    {
      minpq.push(num);
    }

    if (maxpq.size() >= minpq.size() + 1)
    {
      int tmp = maxpq.top();
      maxpq.pop();
      minpq.push(tmp);
    }

    if (maxpq.size() < minpq.size())
    {
      int tmp = minpq.top();
      minpq.pop();
      maxpq.push(tmp);
    }
  }

  double findMedian()
  {
    double ret = maxpq.top();
    if (maxpq.size() == minpq.size()) ret = (maxpq.top() + minpq.top()) / 2.0;
    return ret;
  }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

int main()
{
  MedianFinder *obj = new MedianFinder();

  obj->addNum(1);
  obj->addNum(2);
  cout << " median: " << obj->findMedian() << endl;
  obj->addNum(3);
  cout << " median: " << obj->findMedian() << endl;

  return 0;
}
