#include <utility>
#include <iostream>


class DemoRaii {
public:
  explicit DemoRaii(std::string name) : m_name(std::move(name)) {
    std::cout << "DemoRaii: " << m_name << "\n";
  }

  ~DemoRaii() {
    std::cout << "~DemoRaii: " << m_name << "\n";
  }

private:
  std::string m_name;
};

void demo(bool shouldThrow) {
  std::cout << "Enter demo\n";
  DemoRaii dr1("alpha");
  DemoRaii dr2("beta");
  if (shouldThrow) {
    throw std::runtime_error("Allocation Error!!!");
  }
  std::cout << "Exit demo clean\n";
}

int main() {
  try {
    demo(true);
  } catch (std::exception& e) {
    std::cout << "Error: " << e.what() << "\n";
  }
  return 0;
}