

#include <iostream>
using std::cout;
using std::string;

int main(){



//if (s=="12:00:00AM") return "00:00:00";
//if (s=="12:00:00PM") return "12:00:00";

string s ="12:25:34AM";
string hh,mm,ss;

if (s.substr(8,2) == "PM" && std::stoi(s.substr(0,2)) <12) 
hh = std::to_string(std::stoi(s.substr(0,2)) + 12);
else if (s.substr(8,2) == "AM" && std::stoi(s.substr(0,2)) ==12) {
hh = "00";
}else
hh = s.substr(0,2);

mm = s.substr(3,2);
ss = s.substr(6,2);
cout << (hh + ":" +mm +":" +ss) << std::endl;
return 0;
}
