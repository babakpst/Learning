
// Babak Poursartip
// 08/15/2020

// map example

#include <iostream>
#include <map>
#include <unordered_map>

int main() {
  puts(" code starts ...");

  // choose the right one.
  // std::map<int, std::string> num; // no duplicate
  // std::multimap<int, std::string> num; // accepts duplicates
  std::unordered_map<int, std::string> num;
  // std::unordered_multimap<int, std::string> num;

  int tmp;
  std::string str;
  std::pair<int, std::string> pr;

  puts(" insert in the map: ");
  while (tmp >= 0) {
    puts(" enter key");
    std::cin >> tmp;
    if (tmp >= 0) {
      pr.first = tmp;
      puts("enter name: ");
      std::cin >> str;
      pr.second = str;
      num.insert(pr);
    }
  }

  printf("map [");
  for (auto it = num.begin(); it != num.end(); ++it) {
    std::cout << it->first << "--" << it->second << "  ";
  }
  puts("]");

  printf(" removing elements from map");
  tmp = 0;
  while (tmp >= 0) {
    printf(" enter a the key to be deleted: ");
    std::cin >> tmp;
    if (tmp >= 0)
      num.erase(tmp);
  }

  printf("map [");
  for (auto it = num.begin(); it != num.end(); ++it) {
    std::cout << it->first << "--" << it->second << "  ";
  }
  puts("]");

  puts(" terminates successfully.");
  return 0;
}
