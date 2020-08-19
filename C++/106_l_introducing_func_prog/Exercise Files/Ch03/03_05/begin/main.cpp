#include <iostream>
#include <string>
#include <boost/hana.hpp>
namespace hana = boost::hana;
using namespace hana::literals;
using namespace std;

struct Truck {
  std::string name;
  double bed_length;
};
struct Car {
  std::string name;
};
struct Motorcycle {
  std::string name;
};

int main() {

    // hana::for_each(trucks, [](auto &vehicle){
    // cout << "Truck = " << vehicle.name << ", bed length = " << vehicle.bed_length << endl;
    // });
    // hana::for_each(nontrucks, [](auto &vehicle){
    // cout << "Vehicle = " << vehicle.name << endl;
    // });
    return 0;
}
