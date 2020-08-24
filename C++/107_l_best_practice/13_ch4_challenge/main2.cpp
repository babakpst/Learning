#include <iterator>
#include <iostream>
#include <fstream>
#include <vector>
//#include <boost/filesystem.hpp>
//#include <boost/filesystem/fstream.hpp>

//namespace fs = boost::filesystem;

void count_to_10() {
//  fs::path fpath{"count.txt"};
  std::ofstream ofs{"count.txt"};
  for (auto &ndx: {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}) {
    ofs << "Line #" << ndx << "\n";
  }
}

int main() {
  count_to_10();
}
