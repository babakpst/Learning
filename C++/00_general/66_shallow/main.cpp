
// 03/25/2021
// shallow copy
#include <vector>
#include "iostream"

class shallow{
public:
shallow(){}
~shallow(){
std::cout << " destroyed\n";
delete[] m_Int;
}

void def(int size){
m_Int = new int(size);
m_size = size;
}

void set(){
for (int i = 0; i<m_size; ++i){
  m_Int[i] = i;
}
}

int* get(int i){
return &(m_Int[i]);
}


void print(){
std::cout << " vec: ";
for (int i = 0; i<m_size; ++i){
  std::cout << m_Int[i] << "  ";
}
std::cout << "\n";
}

private:
int *m_Int;
int m_size;

};

//===================================
//===================================
int main(){

std::cout << "starts \n";

int size = 5;
std::vector<int*> myVec;
std::vector<int> intermediate;
std::vector<int*> myVec2;

{
  shallow obj;
  obj.def(size);
  obj.set();
  obj.print();

  for (int i = 0; i< size; ++i){
    myVec.push_back(obj.get(i));
    intermediate.push_back(*(obj.get(i)));
    //myVec2.push_back(&(intermediate[i]));
  }

  for (int i = 0; i< size; ++i){
    int *m =  &(intermediate[i]);
    
    myVec2.push_back(m);
  }

//  for (std::vector<int>::iterator it= intermediate.begin(); it!=intermediate.end();++it){
//    myVec2.push_back();
//  }

  std::cout << "my Vec: before ";
  for (int i = 0; i< size; ++i){
    std::cout << *myVec[i] << "  ";
  }
  std::cout << "\n";

  std::cout << "intermediate: before ";
  for (int i = 0; i< size; ++i){
    std::cout << intermediate[i] << "  ";
  }
  std::cout << "\n";

  std::cout << "my Vec2: before ";
  for (int i = 0; i< size; ++i){
    std::cout << *myVec2[i] << "  ";
  }
  std::cout << "\n";

}

std::cout << "my Vec: after ";
for (int i = 0; i< size; ++i){
  std::cout << *myVec[i] << "  ";
}
std::cout << "\n";


std::cout << "my Vec2: after ";
for (int i = 0; i< size; ++i){
  std::cout << *myVec2[i] << "  ";
}

std::cout << "ends \n";
return 0;
}
