
/*

Babak Poursartip
11/04/2020

create a directory 

*/


#include <iostream>
#include <boost/filesystem.hpp>

void test1() {
	//const char dir_path[] = "c:\\temp\\cplusplus";
	const char dir_path[] = "../cplusplus";

	boost::filesystem::path dir(dir_path);
	if(boost::filesystem::create_directory(dir)) {
		std::cout << "Success" << "\n";
	}else std::cout << " The folder already exist\n";
}

void test2() {
	//const char dir_path[] = "c:\\temp\\cplusplus\\example\\test";
	const char dir_path[] = "test";	

	boost::filesystem::path dir(dir_path);
	if(boost::filesystem::create_directories(dir)) {
		std::cout << "Success" << "\n";
	}else std::cout << " The folder already exist\n";
}

int main() {

  fprintf (stderr, "Internal error: %s, line %d.\n",__FILE__, __LINE__);
  std::cout << "Internal error: "<< __FILE__ << " line " << __LINE__ 
            << " FUNC: " << __FUNCTION__
            << " DATE: " << __DATE__
            << " time: " << __TIME__    
            << std::endl;
	test1();
	test2();

	return 0;
}
