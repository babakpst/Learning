
// babak poursartip
// Jan 03, 2023

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

/*
class RateLimiter {
public:

    queue<int> myq;
    int nreq;
    int win;

    RateLimiter(int n, int t):nreq(n), win(t) {
    }

    bool shouldAllow(int timestamp) {
      bool ret=false;
      if (myq.size()<nreq)
      {
        myq.push(timestamp);
        ret = true;
      }
      else
      {
        if ( timestamp-myq.front()>=win )
        {
          ret = true;
          myq.pop();
          myq.push(timestamp);
        }
      }
      return ret;
    }
};
*/

class RateLimiter
{
 public:
  queue<int> myq;
  int nreq;
  int win;

  RateLimiter(int n, int t) : nreq(n), win(t) {}

  bool shouldAllow(int timestamp)
  {
    int allowed = timestamp - win + 1;
    while (myq.size() > 0 && myq.front() < allowed) myq.pop();

    if (myq.size() < nreq)
    {
      myq.push(timestamp);
      return true;
    }
    return false;
  }
};

int main(int argc, char* argv[])
{
  std::cout << " starts ... \n";

  int n = 3, t = 5;

  RateLimiter* obj = new RateLimiter(n, t);
  cout << " answer: " << boolalpha << obj->shouldAllow(1) << endl;
  cout << " answer: " << boolalpha << obj->shouldAllow(1) << endl;
  cout << " answer: " << boolalpha << obj->shouldAllow(2) << endl;
  cout << " answer: " << boolalpha << obj->shouldAllow(3) << endl;
  cout << " answer: " << boolalpha << obj->shouldAllow(8) << endl;

  std::cout << " done \n";
  return 0;
}
