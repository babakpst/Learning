#include <iostream>
#include <queue>
#include <stack>
#include <string>

// We do not/cannot iterate the stack

// STL/stack returns a reference to the object.

using namespace std;

class Test {
  string name;

public:
  // explicit Test(string name) : name(name) {}
  Test() : name("") { cout << "default ctor\n"; } // mine
  Test(string name) : name(name) { cout << "ctor\n"; }
  Test(const Test &rhs) {
    cout << "copy ctor\n";
    name = rhs.name;
  } // mine

  ~Test() { cout << "dtor\n"; }

  void print() const { cout << name << endl; }
};

// =============================================
int main(int argc, char const *argv[]) {

  //===============================
  // LIFO
  cout << "1==============\n";
  stack<Test> testStack;

  // This does not call the default ctor, but it calls ctor to create the test
  // with a name, then calls the copy cosntructor to copy to stack and then
  // destroys the original obj, ie calling the dtor.
  testStack.push(Test("Mike"));
  testStack.push(Test("John"));
  testStack.push(Test("Sue"));

  cout << endl;

  cout << "2==============\n";

  // STL/stack returns a reference to the object. If we generate a new object
  // the reference would be copies in the new object, but we can use a
  // reference. However, if we want to pop that obj out of the stack, that
  // reference is not valid anymore.
  // IMPORTANT: Since we did not defined the assignment operator, this would be
  // shallow copy.

  // Test test1 = testStack.top();
  Test &test1 = testStack.top(); // no copying
  test1.print();

  // important:
  /*
  This is invalid test2 points the obj in testStack, but after pop ing it out of
  stak, there is not such an object, i.e. test2 points to nothin. Randomly, this
  may work though.

  Test &test2 = testStack.top();
  testStack.pop();
  test2.print();  // reference refers to the destroyed object
  */

  cout << "3==============\n";
  testStack.pop();
  Test test2 = testStack.top();
  // Test &test2 = testStack.top();
  test2.print();

  //===============================
  cout << "4==============\n";
  // To iterate through the stock.
  while (testStack.size() > 0) {
    Test &test = testStack.top();
    test.print();
    testStack.pop();
  }

  cout << "5==============\n";
  //===============================
  // FIFO
  queue<Test> testQueue;

  testQueue.push(Test("Mike"));
  testQueue.push(Test("John"));
  testQueue.push(Test("Sue"));

  cout << endl;

  testQueue.back().print();

  while (testQueue.size() > 0) {
    Test &test = testQueue.front(); // no top here.
    test.print();
    testQueue.pop();
  }

  return 0;
}