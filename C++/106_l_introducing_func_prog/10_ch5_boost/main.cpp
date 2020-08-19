
// Babak Poursartip
// 08/19/2020

// linkedin functional programming

#include <boost/hana.hpp>
#include <iostream>
#include <vector>

namespace hana = boost::hana;
using namespace hana::literals;
using namespace std;

struct truck {
  std::string name;
  double bed_len;
};

struct car {
  std::string name;
};

struct motorcycle {
  std::string name;
};

int main() {
  puts(" code starts ... ");

  auto vehicles =
      hana::make_tuple(truck{"F-150", 8.5}, car{"camry"}, motorcycle{"honda"});

  auto has_bed_len =
      hana::is_valid([](auto &&x) -> decltype((void)x.bed_len) {});

  auto trucks = hana::filter(vehicles, has_bed_len);
  auto nontrucks =
      hana::filter(vehicles, hana::compose(hana::not_, has_bed_len));

  hana::for_each(trucks, [](auto &vehicle) {
    std::cout << "Truck = " << vehicle.name
              << ", bed length = " << vehicle.bed_len << std::endl;
  });
  hana::for_each(nontrucks, [](auto &vehicle) {
    std::cout << "Vehicle = " << vehicle.name << std::endl;
  });

  puts(" \n terminates successfully.");
  return 0;
}