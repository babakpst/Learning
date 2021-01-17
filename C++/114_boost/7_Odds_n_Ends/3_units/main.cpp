
/*

Babak Poursartip
01/17/2021

Reference: Boost
PluralSight
units


*/
#include <boost/units/make_scaled_unit.hpp>
#include <boost/units/quantity.hpp>
#include <boost/units/static_rational.hpp>
#include <boost/units/systems/si.hpp>
#include <boost/units/systems/si/prefixes.hpp>
#include <boost/units/unit.hpp>
#include <iostream>

void units() {
  typedef boost::units::make_scaled_unit<
      boost::units::si::length,
      boost::units::scale<10, boost::units::static_rational<-2>>>::type cm;
  boost::units::quantity<cm> d(2.0 * boost::units::si::meter);
  boost::units::quantity<boost::units::si::time> t(100.0 *
                                                   boost::units::si::second);
  boost::units::quantity<boost::units::si::velocity> x(d / t);
}

int main() {

  std::cout << " starts here ...\n";
  units();
  std::cout << " finished.\n";

  return 0;
}
