
// constructing vectors
#include <fstream>
#include <iostream>
#include <string>

int main()
{
  //====================================================================
  // prone to error if the file does not exist
  // method 1: we do not need to close the file, it automatically closes when it goes out of scope
  // std::fstream read_file("read_from_file.xyz");

  // method 2:
  std::fstream read_file;
  read_file.open("read_from_file.xyz", std::ios::in);

  int index;
  double res;

  for (int i = 0; i < 4; i++)
  {
    read_file >> index >> res;
    std::cout << " the index: " << index << " result is: " << res << "\n";
  }

  // read_file.rewind(); //not working
  // read_file.open("read_from_file.xyz", std::ios::in);
  for (int i = 0; i < 4; i++)
  {
    read_file >> index >> res;
    std::cout << " the index: " << index << " result is: " << res << "\n";
  }

  read_file.close();
  std::cout << "The end of the code! \n";
  std::cout << "done! \n";

  //====================================================================
  // will throw error
  std::ifstream Addressfile;
  Addressfile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
  std::string str;
  try
  {
    Addressfile.open("Address.txt", std::ios::in);
    Addressfile >> str;
    std::cout << " content of the Address file: " << str << std::endl;
  }
  catch (std::ifstream::failure &inputerr)
  {
    // here is the catch for opening the input file.
    std::cout << " Error while opening the address file. "
              << "\n";
    std::cout << " Please double check the address file in the cpp folder. "
              << "\n";
    std::cout << " The error message is: " << inputerr.what() << "\n";
  }

  //====================================================================
  std::ifstream infile;

  std::string filename{"some_missing_file.xyz"};

  // std::string filename;
  // filename ="some_missing_file.xyz";

  std::cout << filename << "\n";
  bool opened = false;

  while (!opened)
  {
    infile.open(filename.c_str());

    if (infile.good())
    {
      opened = true;
    }
    else
    {
      std::cout << " The file '" << filename << " ' does not exist, give a new file name: ";
      std::cin >> filename;
    }
  }

  std::cout << "The end of the code! \n";
  std::cout << "done! \n";
  return 0;
}
