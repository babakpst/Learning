
/*

Babak Poursartip
10/29/2020


*/
#include <future>
#include <iostream>
typedef unsigned long long ll;
typedef unsigned ui;

// ===========================
ll recursive_sum(ui lo, ui hi) {

  if ((hi - lo) > 100) { // base case
    ll sum = 0;
    for (auto i = lo; i < hi; ++i)
      sum += i;
    return sum;
  } else { // divide and conquer
    auto mid = (hi + lo) / 2;
    // spawn a new thread to do calculations
    auto left = std::async(std::launch::async, recursive_sum, lo, mid);
    // using the current thread to proces right
    auto right = recursive_sum(mid, hi);
    return left.get() + right;
  }
}

// ===========================
int main() {

  std::cout << " starts ..." << std::endl;
  ll total = recursive_sum(0, 2000000000);
  std::cout << " The result is: " << total << std::endl;
  std::cout << " finished!" << std::endl;

  return 0;
}
