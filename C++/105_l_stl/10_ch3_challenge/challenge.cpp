
// Babak Poursartip
// 08/15/2020

// stack example

#include <iostream>
#include <stack>

int main() {
  puts(" code starts ...");

  std::stack<std::string> urls_back, urls_forward;
  std::string tmp;

  puts(" pushing back: ");
  while (tmp != "exit") {
    printf(" [1] visit url [2] back [3] forward \n");
    std::cin >> tmp;
    if (tmp == "exit")
      break;

    if (tmp == "1") {
      puts("enter url:");
      std::cin >> tmp;
      urls_back.push(tmp);
      urls_forward = std::stack<std::string>(); // empty the forward stack

    } else if (tmp == "2") {
      printf(" going back \n");
      urls_forward.push(urls_back.top());
      urls_back.pop();
    } else if (tmp == "3") {
      if (urls_forward.empty())
        puts(" no forward history");
      else {
        printf(" going forward \n");
        urls_back.push(urls_forward.top());
        urls_forward.pop();
      }
    }

    if (urls_back.empty())
      break;
    std::cout << " current url: " << urls_back.top() << "\n";
  }

  puts(" terminates successfully.");
  return 0;
}