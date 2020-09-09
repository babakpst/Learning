

// Babak Poursartip
// 08/28/2020

// Formatting
// Udemy: Advanced c++

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
  puts(" starts \n");

  double pi = M_PI;
  double dvar = 0.123456789123456789;

  cout << " pi: " << pi << "\n";
  cout << " double: " << dvar << "\n";

  // You only need to define precision once.
  cout << " pi: "<< setprecision(16) << pi << "\n";
  cout << " double: " << dvar << "\n";

  // setw only affects the next output
  cout << " pi: "<< setw(30) << pi << "\n";
  cout << " pi: "<< setfill('-') << left <<setw(30) << pi << "\n";
  cout << " pi: "<< setfill('-') << right <<setw(30) << pi << "\n";


  cout << " pi: "<< scientific << dvar << "\n";

  cout << "=======\n";
  cout << "63 octal: "<< oct << 63 << "\n";
  cout << "63 hex: "<< hex << 63 << "\n";
  cout << "63 decimal: "<< dec << 63 << "\n";

  cout << "boolean=======\n";
  cout << "pi < 3? "<< (pi<3.0) << "\n";
  cout << "pi < 3? "<< boolalpha << (pi<3.0) << "\n";

  cout << "set=======\n";
  cout.setf(ios_base::showpos);
  cout << " pi: "<< scientific << pi << "\n";

  cout << "set=======\n";
  int old_precision = cout.precision();
  cout.unsetf(ios_base::adjustfield | ios_base::basefield | ios_base::floatfield | ios_base::showpos | ios_base::boolalpha);

  cout << " pi: " << pi << "\n";
  cout.precision(old_precision);

  double dvar = 4.0;
  cout << " pi: "<< setprecision(2) << fixed<< pi << "\n";

  puts(" \n ends");

  return 0;
}

