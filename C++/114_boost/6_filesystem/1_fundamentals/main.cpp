
/*

Babak Poursartip
01/03/2021

Reference: Boost
PluralSight

filesystem


*/
#include <iostream>
#include <boost/filesystem.hpp>

// =========================================
void check_path(const char *p)
{
  boost::filesystem::path myPath(p);
  
  if (exists(myPath))
  {
    std::cout << " path " << myPath << " exists. \n";
    if (boost::filesystem::is_regular_file(myPath))
    {
      std::cout << " path: " << myPath.filename().replace_extension() << " is a regular file of size: " << file_size(myPath) << std::endl;
    }
    else if (is_directory(myPath))
    {
      std::cout << " path " << myPath.filename() << " is a directory. \n";
    }
  }
  else
  {
    std::cout << " path " << myPath << " does not exist. \n";
  }

}

// =========================================
int main(int argc, char* argv[]){

std::cout << " starts here ...\n";

std::cout << "\n 1 ===============\n";
check_path("babak"); // check whether there is dir
check_path("check_dir"); // check whether there is dir
check_path(argv[0]); // check whether there is file    

std::cout << "\n 2 ===============\n";
auto dir = boost::filesystem::path(argv[0]).parent_path(); // the dir that contains the executable
check_path(dir.string().c_str()); // not really working

// decomposition 
for (auto &child: dir)
{
  std::cout << child << std::endl;
}


std::cout << "\n 3 ===============\n";
auto dir2 = boost::filesystem::path("/home/babak/Codes/Learning/C++/114_boost/6_filesystem/1_fundamentals").parent_path(); // the dir that contains the executable

// decomposition
for (auto &child: dir2)
{
  std::cout << child << std::endl;
}

std::cout << "\n 4 exceptions ===============\n";
try{
  boost::filesystem::path p("not_exists");
  std::cout << file_size(p) << std::endl;
}
catch(const boost::filesystem::filesystem_error &e)
{
  std::cout << e.what() << std::endl;
}
std::cout << " finished.\n";

return 0;
}
