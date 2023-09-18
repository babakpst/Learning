
// Babak Poursartip
// 08/28/2020

// STL
// Udemy: Advanced c++

#include <iostream>
#include <vector>
using namespace std;

// ==============================
class A
{
 public:
  A() { cout << "ctor\n"; }
  ~A() { cout << "dtor\n"; }
  A(const A &a) { cout << "copy ctor\n"; }
  A &operator=(const A &a) { cout << "assingment operator\n"; }
};

// ==============================
int main()
{
  puts(" starts \n");

  puts("1a ================== ");
  vector<double> nums(20, 1);  // a vector of size 20, all 1
  cout << " size: " << nums.size() << endl;
  int capacity = nums.capacity();
  cout << "capacity: " << capacity << endl;  // 20

  // if the push_back increases the size of the vector beyond its capacity, the capacity for this
  // vector doubles.
  for (int i = 0; i < 100; ++i)
  {
    if (nums.capacity() != capacity)
    {
      capacity = nums.capacity();
      cout << i << " size: " << nums.size() << " Capacity:" << capacity << endl;
    }
    nums.push_back(i);
  }

  puts("1b clear ================== ");
  std::vector<int> anIntVec;
  cout << "size of an uninitialized vector: " << anIntVec.size() << endl;

  puts("2 clear ================== ");
  nums.clear();  // does not change the capacity of the array, just sets the size to zero.
  cout << "size:" << nums.size() << endl;
  cout << "Capacity:" << nums.capacity() << endl;

  puts("2 resize ================== ");
  nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  cout << "element:" << nums[2] << endl;
  nums.resize(100);  // does not change the elements or capacity
  cout << "element:" << nums[2] << endl;
  cout << "size:" << nums.size() << endl;
  cout << "Capacity:" << nums.capacity() << endl;

  puts("2 reserve ================== ");
  cout << "element:" << nums[2] << endl;
  nums.reserve(10000);  // does not change the elements or capacity
  cout << "element:" << nums[2] << endl;
  cout << "size:" << nums.size() << endl;
  cout << "Capacity:" << nums.capacity() << endl;

  puts("3 ================== ");
  // when we define a vector, it initiates three pointers:
  // pointer 1 points to the location of the first element,
  // pointer 2 points to the end of the vector,
  // pointer 3 points to the end of the memory, determined by the capacity
  vector<double> dvec;  //

  // returns 24, for three pointers
  cout << " size of an empty vector: " << sizeof(dvec) << endl;

  // The size of the vector is the number of elements in the vector.
  // The capacity of the vector is the actual size of the vector on memory,
  // befor another reallocation happens. Any time we push back a num to the
  // vector, if we have not filled the full capacity of the vector, i.e.
  // size<capacity, then the number push_backs in the vector(memory), but if the
  // size > capacity, the entire vector would be copied somewhere on the memory,
  // but this time the capacity would double.
  // Note that it does not always follow the doubling concept

  // See the output of this loop

  // vector, if the
  for (int i = 0; i < 100; ++i)
  {
    dvec.push_back(i);
    cout << " size of vec: " << dvec.size() << " capacity:" << dvec.capacity()
         << " sizeof:" << sizeof(dvec) << endl;
  }

  // =================
  // any time we reach the capacity, allocation deallocation happens.
  puts(" 4==================");
  A obj;
  vector<A> v2;
  for (int i = 0; i < 10; i++)
  {
    cout << " size of vec2: " << v2.size() << " capacity:" << v2.capacity() << endl;
    v2.push_back(obj);
    cout << "-------------\n";
    // getchar();
  }

  puts(" \n ends");

  return 0;
}
