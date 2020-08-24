#include <iterator>
#include <iostream>
#include <vector>
#include <boost/filesystem.hpp>
#include <boost/filesystem/fstream.hpp>

namespace fs = boost::filesystem;

void count_to_10() {
  fs::path fpath{"count.txt"};
  fs::ofstream ofs{fpath};
  for (auto &ndx: {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}) {
    ofs << "Line #" << ndx << "\n";
  }
}

int main() {
  count_to_10();
}
