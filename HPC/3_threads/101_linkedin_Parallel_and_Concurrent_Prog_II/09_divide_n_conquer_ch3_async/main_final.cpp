
/*

Babak Poursartip
10/29/2020

run: g++ -std=c++17 -pthread main.cpp -o main

Linkedin course on concurrent programming

divide and conquer:
1- divide a problem into subproblems of roughly equal size,
2- conquer the subproblems by solving them recursively, and
3- combine the solution to the subproblems to generate the final solution for
the original problem.

- The structure of a divide and conquer problem:
  if base
     (the smallest size of the problem which needs to be solved directly- we can
      set this smallest size)
  else
     (partition the subproblem into left and rightproblem)
     -solve left problem using divide and conquer
     -solve right problem using divide and conquer -combine the left and
      right problem

IMPORTANT:
This version of the code, spawns lots of threads and which is not efficient.

*/
#include <future>
#include <iostream>
typedef unsigned long long ll;
typedef unsigned ui;

// ===========================
ll recursive_sum(ui lo, ui hi, unsigned depth = 0) {
  // std::cout << " thread id: " << std::this_thread::get_id() << std::endl;
  if (depth > 10) { // base case
    ll sum = 0;
    for (auto i = lo; i < hi; ++i)
      sum += i;
    return sum;
  } else { // divide and conquer
    auto mid = (hi + lo) / 2;
    // spawn a new thread to do calculations
    auto left =
        std::async(std::launch::async, recursive_sum, lo, mid, depth + 1);
    // using the current thread to proces right
    auto right = recursive_sum(mid, hi, depth + 1);
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
