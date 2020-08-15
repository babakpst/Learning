
// Babak Poursartip
// 08/15/2020

// credit goes to linkedin course stl

#include <fstream>
#include <iostream>
#include <iterator>
#include <list>
#include <string>
#include <vector>

#define USE_VEC
//#define USE_LIST

// ==================
class guests {

public:
  int age;
  static float mean;
  std::string name;
  std::string gender;

public:
  guests() {}
  ~guests() {}

  void set_gender(std::string in) {
    char i = in.c_str()[0];
    if (i == 'b' || i == 'B' || i == 'm' || i == 'M')
      gender = "boy";
    else
      gender = "girl";
  }
};

float guests::mean = 0.0f;

#ifdef USE_VEC
typedef std::vector<guests> container;
#elif defined USE_LIST
typedef std::list<guests> container;
#endif // DEBUG

// ===========
// reading guests from file
void read_guests(container *my_guests) {
  std::ifstream input_guests("guest_file.txt");
  std::string str_tmp;

  if (input_guests.is_open()) {
    guests temp;

    while (getline(input_guests, str_tmp)) {
      // std::cout << "name: " << str_tmp << "\n";
      temp.name = str_tmp;
      getline(input_guests, str_tmp);
      // std::cout << "gender: " << str_tmp << "\n";
      temp.set_gender(str_tmp);
      getline(input_guests, str_tmp);
      // std::cout << "age: " << str_tmp << "\n";
      temp.age = std::atoi(str_tmp.c_str());
      temp.mean += temp.age;
      my_guests->push_back(temp);
    }
    input_guests.close();
    temp.mean = temp.mean / my_guests->size();
  } else
    puts(" error in opening the file.");
}

// ===========
// print guests
void print_guests(container *my_quests) {
  auto it = my_quests->begin();
  // std::vector<guests>::iterator it = my_quests->begin();
  printf(" mean age is: %f\n", it->mean);
  puts(" -------------container: ");
  while (it != my_quests->end()) {
    puts(" ..............: ");
    std::cout << " guest name: " << it->name << std::endl;
    std::cout << " gender: " << it->gender << std::endl;
    std::cout << " age: " << it->age << std::endl;
    ++it;
  }

  puts(" end of the container.");
}

// ===========
// print guests by index for vector
#ifdef USE_VEC
bool print_guests_by_index(container *my_quests, const int index) {
  if (my_quests->size() < index)
    return false;
  printf(" >>>>>>>>guest vector %d is: \n", index);
  std::cout << " guest name: " << my_quests->at(index).name << std::endl;
  std::cout << " gender: " << my_quests->at(index).gender << std::endl;
  std::cout << " age: " << my_quests->at(index).age << std::endl;
  puts(" end of index.");
  return true;
}
#elif defined USE_LIST
bool print_guests_by_index(container *my_quests, const int index) {
  auto it = my_quests->begin();
  for (int i = 0; i < index; ++i, ++it)
    if (it == my_quests->end())
      return false;
  printf(" >>>>>>>>guest list %d is: \n", index);
  std::cout << " guest name: " << it->name << std::endl;
  std::cout << " gender: " << it->gender << std::endl;
  std::cout << " age: " << it->age << std::endl;
  puts(" end of index.");
  return true;
}
#endif // DEBUG

int main() {
  puts(" code starts ... ");
  container *my_guests = new container;

  read_guests(my_guests);
  print_guests(my_guests);
  bool output = print_guests_by_index(my_guests, 3);
  if (!output)
    puts(" index is greated than the number of guests");

  puts("\n terminates successfully.");
  return 0;
}