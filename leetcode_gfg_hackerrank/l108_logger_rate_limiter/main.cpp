

// babak poursartip
// Dec 03, 2022

#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Logger
{
 private:
  unordered_map<string, int> mym;

 public:
  Logger() {}

  bool shouldPrintMessage(int timestamp, string message)
  {
    auto it = mym.find(message);
    bool out = true;

    if (it != end(mym) && it->second > timestamp)
      out = false;
    else if (it != end(mym) && it->second <= timestamp)
      mym[message] = timestamp + 10;
    else
      mym.insert({message, timestamp + 10});

    // cout << " -----\n";
    // for_each(begin(mym), end(mym), [](auto x){cout << x.first <<" - " << x.second << endl; });
    // cout << " -----\n";

    return out;
  }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */

int main(int argc, char* argv[])
{
  std::cout << " starts ... \n";

  Logger logger;
  cout << boolalpha << logger.shouldPrintMessage(1, "foo")
       << endl;  // return true, next allowed timestamp for "foo" is 1 + 10 = 11
  cout << boolalpha << logger.shouldPrintMessage(2, "bar")
       << endl;  // return true, next allowed timestamp for "bar" is 2 + 10 = 12
  cout << boolalpha << logger.shouldPrintMessage(3, "foo") << endl;   // 3 < 11, return false
  cout << boolalpha << logger.shouldPrintMessage(8, "bar") << endl;   // 8 < 12, return false
  cout << boolalpha << logger.shouldPrintMessage(10, "foo") << endl;  // 10 < 11, return false
  cout << boolalpha << logger.shouldPrintMessage(11, "foo")
       << endl;  // 11 >= 11, return true, next allowed timestamp for "foo" is 11 + 10 = 21

  // string out = t.shouldPrintMessage(timestamp, message);
  // cout << " answer: " << boolalpha<< out << endl;

  std::cout << " done \n";
  return 0;
}
