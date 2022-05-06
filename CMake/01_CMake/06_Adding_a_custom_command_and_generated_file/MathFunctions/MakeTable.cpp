
// building the sqrt table

#include <cmath>
#include <fstream>
#include <iostream>

int main(int argc, char* argv[])
{
  if (argc<2) {
    return 1;
  }

  std::ofstream fout(argv[1], std::ios_base::out);
  const bool fileOpen = fout.is_open();
  if (fileOpen)
  {
    fout << "double sqrtTable[]={" << std::endl;
    for (int i = 0; i<10; i++){
      fout << sqrt(static_cast<double>(i)) << "," << std::endl;
      }
    fout << "0};\n";
    fout.close();
  }
  return fileOpen ? 0:1;
}