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

class DemoRaii2 {
public:
  explicit DemoRaii2(int resourceId) : m_resourceId(resourceId) {
    std::cout << "DemoRaii: " << m_resourceId << "\n";
  }

  ~DemoRaii2() {
    std::cout << "~DemoRaii: " << m_resourceId << "\n";
  }

private:
  int m_resourceId;
};

void demo(bool shouldThrow) {
  std::cout << "Enter demo\n";
  DemoRaii2 ddr1(1);
  DemoRaii dr1("alpha");
  DemoRaii dr2("beta");
  DemoRaii2 ddr2(2);

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