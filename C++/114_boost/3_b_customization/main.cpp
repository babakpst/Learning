
/*

Babak Poursartip
12/25/2020

Reference: Boost
PluralSight

customization of the program option

make filesystem
./main -V 12 --files a.txt b.txt c.txt
./main a.txt b.txt c.txt -V 12 

*/

#include <iostream>
#include <vector>
#include <boost/program_options.hpp>

namespace po = boost::program_options;


int main(int argc, char* argv[]){

std::cout << " starts here ...\n";

int value;

po::options_description desc("my file processor");

// this means either --value or -V
desc .add_options()("value,V" , po::value<int>(&value)->default_value(43), "input value")("files", po::value<std::vector<std::string>>()->multitoken(), "input files");


po::positional_options_description pos;
pos.add("files", -1);  // The maximum number of files that can be in the argument list, by putting -1, there would be no max. 

po::variables_map vm;
po::command_line_parser parser(argc, argv);
auto parsed_options = parser.options(desc).positional(pos).run();
po::store(parsed_options, vm);
//po::store(po::parse_command_line(argc, argv, desc), vm);
po::notify(vm);

std::cout << " the value is: " << value << std::endl; 

if (vm.count("files")){
int i = 0;
auto files = vm["files"].as<std::vector<std::string>>();
for (auto s:files)
std::cout  << (++i) << ": " << s << std::endl;
}

std::cout << " finished.\n";

return 0;
}
