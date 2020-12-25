
/*

Babak Poursartip
12/16/2020

Reference: Boost
PluralSight

Program options


*/

#include <iostream>
#include <string>
using namespace std;

#include <boost/program_options.hpp>
namespace po = boost::program_options;

/*============================================*/
int main(int argc, char *argv[]) {

  std::cout << " starts here ...\n";

  po::options_description desc("Program options");
  desc.add_options()("help", "print info")(
      "filename", po::value<string>()->default_value("default.txt"),
      "file to process");

  po::variables_map vm;
  auto parsed = po::parse_command_line(argc, argv, desc);

  po::store(parsed, vm);
  po::notify(vm);

  if (vm.count("help")) {
    cout << desc << endl;
    getchar();
    return 1;
  }

  string filename = vm["filename"].as<string>();

  cout << "processing file " << filename << endl;

  std::cout << " finished.\n";

  return 0;
}
