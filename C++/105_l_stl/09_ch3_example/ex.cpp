
// Babak Poursartip
// 08/15/2020

// stack example

#include <iostream>
#include <stack>

int main() {
  puts(" code starts ...");

  std::stack<std::string> urls;
  std::string tmp;

  puts(" pushing back: ");
  while (tmp != "exit") {
    printf(" [1] visit url [2] back \n");
    std::cin >> tmp;
    if (tmp == "exit")
      break;

    if (tmp == "1") {
      puts("enter url:");
      std::cin >> tmp;
      urls.push(tmp);
    } else if (tmp == "2") {
      printf(" going back \n");
      urls.pop();
    }
    if (urls.empty())
      break;
    std::cout << " current url: " << urls.top() << "\n";
  }

  puts(" terminates successfully.");
  return 0;
}