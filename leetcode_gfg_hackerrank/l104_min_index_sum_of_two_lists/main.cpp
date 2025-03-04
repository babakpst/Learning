

// babak poursartip
// Dec 03, 2022

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution
{
 public:
  vector<string> findRestaurant(vector<string>& list1, vector<string>& list2)
  {
    unordered_map<std::string, int> myMap;
    vector<pair<std::string, int>> store;
    vector<std::string> out;

    for (int i = 0; i < list2.size(); i++) myMap.insert({list2[i], i});

    // cout << " map \n";
    // for_each(begin(myMap), end(myMap), [](auto x){cout << x.first << "-" << x.second << " | ";}  );
    // cout << " \n********* \n";

    for (int i = 0; i < list1.size(); i++)
    {
      auto it = myMap.find(list1[i]);
      if (it != end(myMap)) store.push_back({list1[i], i + it->second});
    }

    // cout << " store \n";
    // for_each(begin(store), end(store), [](auto x){cout << x.first << "-" << x.second << "======";}  );
    // cout << " ********* \n";

    int min = INT32_MAX;
    for (auto c : store) min = (c.second < min) ? c.second : min;

    for (auto c : store)
      if (c.second == min) (out.push_back(c.first));
    return out;
  }
};

int main(int argc, char* argv[])
{
  std::cout << " starts ... \n";

  // vector<std::string> list1 {"Shogun","Tapioca Express","Burger King","KFC"}, list2 {"Piatti","The Grill at Torrey
  // Pines","Hungry Hunter Steakhouse","Shogun"};
  vector<std::string> list1{"happy", "sad", "good"}, list2{"sad", "happy", "good"};

  Solution t;

  vector<std::string> out = t.findRestaurant(list1, list2);

  cout << " answer: " << endl;
  for_each(out.begin(), out.end(), [](auto x) { cout << x << " "; });
  cout << endl;

  std::cout << " done \n";
  return 0;
}
