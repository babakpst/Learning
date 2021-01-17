
/*

Babak Poursartip
01/16/2021

Reference: Boost
PluralSight

filesystem: status


*/
#include <iostream>
#include <boost/filesystem.hpp>

// ==========================================
void check_file(boost::filesystem::path p)
{
  
  auto s = boost::filesystem::status(p);
  auto t = s.type();
  
  std::cout << " the type is: " << t << std::endl;
  
  // permission
  auto ps = s.permissions(); // read only or not
  
  if ((ps & boost::filesystem::owner_write) != boost::filesystem::owner_write )
  {
    std::cout << " no permission to write\n";
  }
}
// ==========================================
int main(int argc, char* argv[]){

std::cout << " starts here ...\n";

check_file(boost::filesystem::path(argv[0]));


std::cout << " finished.\n";

return 0;
}
