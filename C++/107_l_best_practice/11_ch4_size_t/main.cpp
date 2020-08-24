
#include <iostream>

auto sumDown(int n) {
  if (n <= 0)
    return 0;

  return n + sumDown(n - 1);
}

int main() {

  const std::size_t N{10};
  std::size_t a[N];

  for (std::size_t n{0}; n < N; ++n) {
    a[n] = n;
  }
  std::cout << '\n';

  for (std::size_t n{N}; n-- > 0;) {
    std::cout << a[n] << " ";
  }
  std::cout << '\n';

  std::cout << "\nsum it " << sumDown(10) << std::endl;
  return 0;
}