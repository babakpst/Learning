
/*

Babak Poursartip
01/16/2021

Reference: Boost
PluralSight

filesystem: status


*/
#include <boost/filesystem.hpp>
#include <iostream>

namespace fs = boost::filesystem;

// ==========================================
void check_file(fs::path p) {

  auto s = fs::status(p);
  auto t = s.type();

  std::cout << " the type is: " << t << std::endl;

  // permission
  auto ps = s.permissions(); // read only or not

  if ((ps & fs::owner_write) != fs::owner_write) {
    std::cout << " no permission to write\n";
  }
}

// ==========================================
void dir_navigation(fs::path dir) {
  fs::directory_iterator end;
  for (fs::directory_iterator i(dir); i != end; ++i) {
    fs::path p = i->path();
    if (fs::is_regular_file(p)) {
      std::cout << p.filename() << std::endl;
    } else {
      std::cout << " directory: " << p.filename() << std::endl;
      dir_navigation(p);
    }
  }
}

// ==========================================
int main(int argc, char *argv[]) {

  std::cout << " starts here ...\n";

  // auto parent = fs::path(argv[0]).parent_path().parent_path();
  auto parent2 =
      fs::path("/home/babak/Codes/Learning/C++/114_boost/6_filesystem");

  dir_navigation(parent2);

  std::cout << " finished.\n";

  return 0;
}
